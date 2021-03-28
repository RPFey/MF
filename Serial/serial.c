//
// Created by tkm36 on 2021/3/28.
//

#include "serial.h"

// TODO: start head buffer
static char start_buffer[2] = {0x10, 0x20};
static int count = 0;
static int trial;
static char current;
static int success;

int open_serial(const char* dev, int baud){
    return serialOpen(dev, baud);
}

int stm32_uart(int fd, char* data, int max_length){
    count = 0;

    // read all data from serial
    while(serialDataAvail(fd) > 0){
        // exceed maximum length
        if(count > max_length){
            serialFlush(fd);
            serialPutchar(fd, 0x00);
#ifdef Bebug
            printf("Length exceeds max_length! \n");
#endif
            return 0;
        }

        data[count] = serialGetchar(fd);
        count ++;
    }

    // analyze data
    for(int i = 0; i < count; i++){
        if(i<2){
            if(data[i] != start_buffer[i]){
#ifdef Bebug
                printf("Start char mismatch! \n");
#endif
                serialPutchar(fd, 0x00);
                return 0;
            }
        }

        if((i - 1) % 5 == 0){
            if(data[i+1] == start_buffer[1] && data[i+2] == start_buffer[0]){
                return i;
            }
        }
    }

#ifdef Bebug
    printf("Missing end tag! \n");
#endif
    serialPutchar(fd, 0x00);
    return 0;
}

int stm32_uart_TX(int fd, char* data, int length, int num_trial){
    trial = 0;
    while(trial < num_trial){

        serialPutchar(fd, start_buffer[0]);
        serialPutchar(fd, start_buffer[1]);
        for(int i = 0; i < length; i++){
            serialPutchar(fd, data[i]);
        }
        serialPutchar(fd, start_buffer[1]);
        serialPutchar(fd, start_buffer[0]);

        current = serialGetchar(fd);
        if(current == 0x01){
            return 1;
        } else {
            trial ++;
        }
    }
    return 0;
}