#include <iostream>
#include <string>     // std::string, std::stol
#include <windows.h>
char* self;

void print_usage()
{
    std::cout << "usage: " << self << " percent";
}
int getBatteryLevel()
{
    SYSTEM_POWER_STATUS status;
    GetSystemPowerStatus(&status);
    return status.BatteryLifePercent;
}
int main(int argc, char* argv[])
{
    self=argv[0];
    if(argc!=2)
    {
        print_usage();
        exit(EXIT_FAILURE);
    }
    int percent=atol(argv[1]);
    std::cout << "when battery percent is < "<<percent << " , will PlaySound(\"battery_warning.mp3.wav\",NULL,SND_FILENAME);"<<std::endl;
    while(true)
    {
        if(getBatteryLevel()<percent)
        {
            PlaySound("battery_warning.mp3.wav",NULL,SND_FILENAME);
        }
        Sleep(5000);
    }
    return 0;
}
