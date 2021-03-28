//
// Created by tkm36 on 2021/3/28.
//

#include "Device.h"

Device::Device(const char *dev, int baud) {
    fd = open_serial(dev, baud);
}

Device::Device() {
    fd = open_serial("/dev/serial0", 115200);
}

void Device::UART_RX() {
    int trial = 0;
    int length = 0;
    while(trial < 5) {
        length = stm32_uart(fd, buffer, 60);
        if (length <= 0){
            trial ++;
        } else {
            for(int i = 2; i < length; i += 5){
                switch (buffer[i]) {
                    case 'x':
                        std::memcpy(message, buffer + (i+1), sizeof(float));
                        break;
                    case 'y':
                        std::memcpy(message + 1, buffer + (i+1), sizeof(float));
                        break;
                    case 'z':
                        std::memcpy(message + 2, buffer + (i+1), sizeof(float));
                        break;
                    case 'r':
                        std::memcpy(message + 3, buffer + (i+1), sizeof(float));
                        break;
                    case 'p':
                        std::memcpy(message + 4, buffer + (i+1), sizeof(float));
                        break;
                    case 'a':
                        std::memcpy(message + 5, buffer + (i+1), sizeof(float));
                        break;
                    case 'X':
                        std::memcpy(message + 6, buffer + (i+1), sizeof(float));
                        break;
                    case 'Y':
                        std::memcpy(message + 7, buffer + (i+1), sizeof(float));
                        break;
                    case 'Z':
                        std::memcpy(message + 8, buffer + (i+1), sizeof(float));
                        break;
                    case 'R':
                        std::memcpy(message + 9, buffer + (i+1), sizeof(float));
                        break;
                    case 'P':
                        std::memcpy(message + 10, buffer + (i+1), sizeof(float));
                        break;
                    case 'A':
                        std::memcpy(message + 11, buffer + (i+1), sizeof(float));
                        break;
                    default:
                        // TODO Use ROs here
                        std::cout<<"Invalid char here\n";
                        break;
                }
            }
        }
    }
}
