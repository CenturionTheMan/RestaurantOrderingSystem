#include "../Headers/Client.h"


RandomGenerator Client::randomGenerator = RandomGenerator();

Client::Client(Manager& manager, int minOrderTimeMs, int maxOrderTimeMs)
{
    this->minOrderTimeMs = minOrderTimeMs;
    this->maxOrderTimeMs = maxOrderTimeMs;
    this->state = ClientState::ClientIdle;
    this->conditionVariable = &manager.ClientsBuffetCondition;
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

            PancakeType pancakeType = static_cast<PancakeType>(Client::randomGenerator.GetRandomNumber(0, 2));
            this->state = ClientState::ClientWaitingForBuffet;
            std::unique_lock<std::mutex> lock(Containers::buffetMutex);
            Client::conditionVariable->wait(lock, [this, pancakeType] { 
                if(this->isStopRequested) return true;
                return Containers::buffet[pancakeType] > 0;
            });
            if(this->isStopRequested) break;
            Containers::TakePancakeFromBuffet(pancakeType);
            lock.unlock();
            this->state = ClientState::Eating;
            std::this_thread::sleep_for(std::chrono::milliseconds(Client::randomGenerator.GetRandomNumber(minOrderTimeMs, maxOrderTimeMs)));
        }
    });

    if(clientThread.joinable())
        clientThread.detach();
}

void Client::Stop()
{
    this->isStopRequested = true;
}

