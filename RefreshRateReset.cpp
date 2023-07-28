// RefreshRateReset.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <Windows.h>

int main()
{
    DEVMODE dm;
    ZeroMemory(&dm, sizeof(dm));
    dm.dmSize = sizeof(dm);
    if (0 != EnumDisplaySettings(NULL, ENUM_CURRENT_SETTINGS, &dm))
    {
        std::cout << "DisplayFrequency before setting = " << dm.dmDisplayFrequency << std::endl;
        dm.dmDisplayFrequency = 60; //set the DisplayFrequency
        LONG ret = ChangeDisplaySettingsEx(NULL, &dm, NULL, 0, NULL);
        std::cout << "ChangeDisplaySettingsEx returned " << ret << '\n';
        if (0 != EnumDisplaySettings(NULL, ENUM_CURRENT_SETTINGS, &dm))
        {
            std::cout << "DisplayFrequency after setting = " << dm.dmDisplayFrequency << std::endl;
        }
        switch (ret)
        {
            case DISP_CHANGE_SUCCESSFUL:
                std::cout << "display successfully changed\n";
                break;
            case DISP_CHANGE_BADDUALVIEW:
                std::cout << "The settings change was unsuccessful because the system is DualView capable\n";
                break;
            case DISP_CHANGE_BADFLAGS:
                std::cout << "An invalid set of flags was passed in.\n";
                break;
            case DISP_CHANGE_BADMODE:
                std::cout << "The graphics mode is not supported.\n";
                break;
            case DISP_CHANGE_BADPARAM:
                std::cout << "An invalid parameter was passed in. This can include an invalid flag or combination of flags.\n";
                break;
            case DISP_CHANGE_FAILED:
                std::cout << "The display driver failed the specified graphics mode.\n";
                break;
            case DISP_CHANGE_NOTUPDATED:
                std::cout << "Unable to write settings to the registry.\n";
                break;
            case DISP_CHANGE_RESTART:
                std::cout << "The computer must be restarted for the graphics mode to work.\n";
                break;
        }
    }
    system("pause");
}
