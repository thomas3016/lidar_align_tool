//
// Created by qzkj on 19-5-20.
//
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <ros/ros.h>
#include <ros/package.h>
#include <pcl_ros/point_cloud.h>

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
Q_OBJECT

public:
    explicit MainWindow(ros::NodeHandle node, QWidget *parent = 0);
    ~MainWindow();
public slots:
    //adjust_node
    void trans_changed(const double&);
    void car_changed(const double&);
    void on_pushButton_save_adjust_clicked();
    void on_pushButton_load_adjust_clicked();
private:
    template<typename T>
    std::string num2str(T num) {
        std::stringstream ss;
        std::string st;
        ss << num;
        ss >> st;
        return st;
    }

    ros::Publisher pub_trans_vec_,pub_save_align_,pub_car_;
    std::string path_;

private:
    Ui::MainWindow *ui;
};

#endif 
