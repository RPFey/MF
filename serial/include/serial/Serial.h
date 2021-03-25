//
// Created by peter on 2021/3/25.
//

#ifndef SRC_SERIAL_H
#define SRC_SERIAL_H
#include <string>
#include "ros/ros.h"
#include "geometry_msgs/PoseStamped.h"
#include "serial/Device.h"

class Serial: public Device {
public:
    explicit Serial(std::string dev, size_t length);
    // receive pose msgs from vision node
    void pose_cb(const geometry_msgs::PoseStampedConstPtr& msg);

    // thread for serial port communication
    void stm32_uart(const ros::SteadyTimerEvent& event);

    ros::NodeHandle nh;
    ros::Subscriber target_pos;
    ros::SteadyTimer serial_timer;
};


#endif //SRC_SERIAL_H
