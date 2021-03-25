//
// Created by peter on 2021/3/25.
//

#include "serial/Serial.h"

Serial::Serial(std::string dev, size_t length):
    nh("~"), uart_length(length)
{
    target_pos = nh.subscribe("/camera/target", 100, &Serial::pose_cb, this);
    ros::WallDuration duration = ros::WallDuration();
    duration.fromSec(0.1);
    serial_timer = nh.createSteadyTimer(duration, &Serial::stm32_uart, this);
}

void Serial::pose_cb(const geometry_msgs::PoseStampedConstPtr &msg) {

}

void Serial::stm32_uart(const ros::SteadyTimerEvent& event){
    // Raspberry Implementation
}
