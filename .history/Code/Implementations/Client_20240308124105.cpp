#include "../Headers/Client.h"

Client::Client(int minOrderTimeMs, int maxOrderTimeMs)
{
    this->minOrderTimeMs = minOrderTimeMs;
    this->maxOrderTimeMs = maxOrderTimeMs;
    randomGenerator = RandomGenerator();
    this->state = ClientState::Idle;
}

Client::~Client()
{
}


void Client::Run()
{   
    std::thread clientThread([this](){
       
        while (true)
        {
            this->state = ClientState::GoingToBuffet;
            PancakeType pancakeType = static_cast<PancakeType>(randomGenerator.GetRandomNumber(0, 2));
            std::lock_guard<std::mutex> lock(Containers::buffetMutex);
            if(Containers::buffet[pancakeType] > 0)
            {
                Containers::TakePancakeFromBuffet(pancakeType);
            }
            else
            {
                // state
            }

            std::this_thread::sleep_for(std::chrono::milliseconds(randomGenerator.GetRandomNumber(minOrderTimeMs, maxOrderTimeMs)));
        }
    });

    if(clientThread.joinable())
        clientThread.detach();
}