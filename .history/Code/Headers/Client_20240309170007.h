#pragma once

#include <thread>
#include <mutex>
#include <condition_variable>
#include "PancakesTypes.h"
#include "RestaurantContainers.h"
#include "RandomGenerator.h"
#include "EntityEnums.h"


/// @brief Class that represents a client that orders pancakes
class Client
{
private:
    RandomGenerator randomGenerator;

    /// @brief Client current state
    ClientState state;

    /// @brief flag that indicates if thread should stop
    bool isStopRequested = false;

    /// @brief The maximum and minimum time in milliseconds that the client will wait before ordering again
    /// (final value will be random between minOrderTimeMs and maxOrderTimeMs)
    int maxOrderTimeMs, minOrderTimeMs;

public:
    /// @brief Construct a new Client object
    Client(int minOrderTimeMs, int maxOrderTimeMs);
    /// @brief Destroy the Client object
    ~Client();

    /// @brief Method that starts the client thread
    void Run();

    /// @brief Method that stops the client thread
    void Stop();

    /// @brief Method that returns the state of the client
    ClientState GetState() { return state; }
};

