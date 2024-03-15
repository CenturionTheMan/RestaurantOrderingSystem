#include "../Headers/Client.h"

Client::Client(int minOrderTimeMs, int maxOrderTimeMs)
{
    this->minOrderTimeMs = minOrderTimeMs;
    this->maxOrderTimeMs = maxOrderTimeMs;
    randomGenerator = RandomGenerator();
    this->state = ClientState::ClientIdle;
}

Client::~Client()
{
}


void Client::Run()
{   
    std::thread clientThread([this](){
       
        while (this->isStopRequested == false)
        {
            this->state = ClientState::ClientGoingToBuffet;
            std::this_thread::sleep_for(std::chrono::milliseconds(1000));
            if(this->isStopRequested) break;

            PancakeType pancakeType = static_cast<PancakeType>(randomGenerator.GetRandomNumber(0, 2));

            this->state = ClientState::ClientWaitingForBuffet;
            std::unique_lock<std::mutex> lock(Containers::buffetMutex);
            if(this->isStopRequested)
            {
                break;
            }

            if(Containers::buffet[pancakeType] > 0)
            {
                this->state = ClientState::Eating;
                Containers::TakePancakeFromBuffet(pancakeType);
            }
            else
            {
                this->state = ClientState::NoFoodToEat;
            }
            lock.unlock();

            std::this_thread::sleep_for(std::chrono::milliseconds(randomGenerator.GetRandomNumber(minOrderTimeMs, maxOrderTimeMs)));
        }
    });

    if(clientThread.joinable())
        clientThread.detach();
}

void Client::Stop()
{
    this->isStopRequested = true;
}

