#include "../Headers/Client.h"

Client::Client(int minOrderTimeMs, int maxOrderTimeMs)
{
    this->minOrderTimeMs = minOrderTimeMs;
    this->maxOrderTimeMs = maxOrderTimeMs;
    randomGenerator = RandomGenerator();
}

Client::~Client()
{
}


void Client::Run()
{   
    std::thread clientThread([this](){
       
        while (true)
        {
            std::cout << "Client WAITS" << std::endl;

            std::this_thread::sleep_for(std::chrono::milliseconds(randomGenerator.GetRandomNumber(minOrderTimeMs, maxOrderTimeMs)));
            PancakeType pancakeType = static_cast<PancakeType>(randomGenerator.GetRandomNumber(0, 2));

            std::lock_guard<std::mutex> lock(Containers::buffetMutex);
            if(Containers::buffet[pancakeType] > 0)
            {
                std::cout << "Client TAKES PANCAKE" << std::endl;
                Containers::TakePancakeFromBuffet(pancakeType);
            }
            else
            {
                std::cout << "Client CAN NOT TAKE PANCAKE" << std::endl;
            }
        }
    });

    if(clientThread.joinable())
        clientThread.detach();
}