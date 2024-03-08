#include "../Headers/Gui.h"


void Gui::RunGui(EntityController& entityController, int refreshRateInMs)
{
    std::thread guiThread([&entityController, refreshRateInMs](){
        while (true)
        {
            printf("\033c"); //! for vscode specific
            std::stringstream stream;

            stream << Gui::BREAK_LINE <<"|          RESTAURANT SUPERVISOR \n" << Gui::BREAK_LINE;
            stream << "| Manager state: " << std::setw(4) << std::right << EntityStateToString(entityController.GetManagerState()) << std::endl << Gui::BREAK_LINE;
            

            std::cout << stream.str();
            std::this_thread::sleep_for(std::chrono::milliseconds(refreshRateInMs));
        }
    });

    if(guiThread.joinable())
            guiThread.detach();
}