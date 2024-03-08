#pragma once

#include <thread>
#include <string>
#include <iostream>
#include <iomanip>

#include "EntityController.h"


namespace Gui
{
    const std::string BREAK_LINE = "-------------------------------------------------------\n";

    void RunGui(EntityController& entityController, int refreshRateInMs);


} // namespace Gui


