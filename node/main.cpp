//
// Created by qzkj on 19-5-20.
//

#include <QApplication>
#include <ros/ros.h>
#include "lidar_align_tool/mainwindow.h"

int main(int argc, char *argv[])
{
    ros::init(argc, argv, "control");
    ros::NodeHandle node;
    ros::NodeHandle private_nh("~");

    QApplication a(argc, argv);
    MainWindow w(node);
    w.show();

    return a.exec();
}
