#pragma once

#include <thread>
#include <mutex>
#include <condition_variable>
#include "PancakesTypes.h"
#include "RestaurantContainers.h"
#include "RandomGenerator.h"

enum ClientState
{
    Idle,
    GoingTOBuffet,
    WaitingForBuffet,
    Eating,
};

/// @brief Class that represents a client that orders pancakes
class Client
{
private:
    RandomGenerator randomGenerator;

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
};

