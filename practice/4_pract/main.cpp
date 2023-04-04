#include <iostream>
#include <Device.h>
#include <fstream>
#include <string>

Device* deviceFabric(const std::string& deviceName) {
    Device* currentDevice;
    switch (static_cast<int>((unsigned char)deviceName[0])) {
        case (204):
            currentDevice = new Mercury(deviceName);
            break;
        case (205):
            currentDevice = new Neva(deviceName);
            break;
        case (221):
            if (236 == static_cast<int>((unsigned char)deviceName[6])){
                currentDevice = new Energo(deviceName);
            }
            else {
                currentDevice = new ServiceEnergy(deviceName);
            }
            break;
        case (static_cast<int>('R')):
            currentDevice = new RealLab(deviceName);
            break;
        case (207):
            currentDevice = new DeviceElectro(deviceName);
            break;
        case (static_cast<int>('O')):
            currentDevice = new Ouman(deviceName);
            break;
        case (206):
            currentDevice = new Oven(deviceName);
            break;
        default:
            currentDevice = nullptr;
    }
    return currentDevice;
}

int main() {
    setlocale(LC_ALL, "ru");
    std::ifstream devicesList;
    devicesList.open("list.txt");
    std::string currentString;
    while (getline(devicesList, currentString)) {
        Device* currentDevice = deviceFabric(currentString);
        if (currentDevice != nullptr){
            currentDevice->poll();
        }
        else {
            std::cout << "Ошибка в названии прибора " << currentString << std::endl;
        }
    }

    devicesList.close();
    system("pause");
}
