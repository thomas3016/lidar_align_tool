//
// Created by qzkj on 19-5-20.
//
#include <std_msgs/String.h>
#include "lidar_align_tool/mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(ros::NodeHandle node, QWidget *parent) :
        QMainWindow(parent),
        ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    pub_trans_vec_ = node.advertise<std_msgs::String>("adjust_order",1);
    pub_save_align_ = node.advertise<std_msgs::String>("save_order",1);
    pub_car_ = node.advertise<std_msgs::String>("car_order",1);
    path_ = ros::package::getPath("lidar_align_tool") + "/align_result/";

    connect(ui->doubleSpinBox_set_x,SIGNAL(valueChanged(double)),this,SLOT(trans_changed(double)));
    connect(ui->doubleSpinBox_set_y,SIGNAL(valueChanged(double)),this,SLOT(trans_changed(double)));
    connect(ui->doubleSpinBox_set_z,SIGNAL(valueChanged(double)),this,SLOT(trans_changed(double)));
    connect(ui->doubleSpinBox_set_roll,SIGNAL(valueChanged(double)),this,SLOT(trans_changed(double)));
    connect(ui->doubleSpinBox_set_pitch,SIGNAL(valueChanged(double)),this,SLOT(trans_changed(double)));
    connect(ui->doubleSpinBox_set_yaw,SIGNAL(valueChanged(double)),this,SLOT(trans_changed(double)));

    connect(ui->doubleSpinBox_set_car_length,SIGNAL(valueChanged(double)),this,SLOT(car_changed(double)));
    connect(ui->doubleSpinBox_set_car_width,SIGNAL(valueChanged(double)),this,SLOT(car_changed(double)));
    connect(ui->doubleSpinBox_set_car_height,SIGNAL(valueChanged(double)),this,SLOT(car_changed(double)));
}

void MainWindow::on_pushButton_load_adjust_clicked(){
    std::cout<<1<<std::endl;
    std::string load_path = path_ + "align.txt";
    std::ifstream ifile;
    ifile.open(load_path.c_str());

    if(!ifile.is_open()){
        std::cerr<<"align file do not exits!!"<<std::endl;
        return;
    }

    std::string line;
    while(getline(ifile, line))
    {
        std::istringstream infile(line);
        std::string tmp_str;
        infile >> tmp_str;

        if(tmp_str == "vehicle_size:")
        {
            infile >> tmp_str;
            ui->doubleSpinBox_set_car_length->setValue(atof(tmp_str.c_str()));
            infile >> tmp_str;
            ui->doubleSpinBox_set_car_width->setValue(atof(tmp_str.c_str()));
            infile >> tmp_str;
            ui->doubleSpinBox_set_car_height->setValue(atof(tmp_str.c_str()));
        }


        if(tmp_str == "lidar_config:")
        {
            infile >> tmp_str;
            ui->doubleSpinBox_set_x->setValue(atof(tmp_str.c_str()));
            infile >> tmp_str;
            ui->doubleSpinBox_set_y->setValue(atof(tmp_str.c_str()));
            infile >> tmp_str;
            ui->doubleSpinBox_set_z->setValue(atof(tmp_str.c_str()));

            infile >> tmp_str;
            ui->doubleSpinBox_set_roll->setValue(atof(tmp_str.c_str()));
            infile >> tmp_str;
            ui->doubleSpinBox_set_pitch->setValue(atof(tmp_str.c_str()));
            infile >> tmp_str;
            ui->doubleSpinBox_set_yaw->setValue(atof(tmp_str.c_str()));
        }
    }

    ifile.close();
}

void MainWindow::trans_changed(const double& trans_value){
    std::string str_msg;

    std::cout<<"new transform input: "<<ui->doubleSpinBox_set_roll->value()<<std::endl;

    str_msg += num2str(ui->doubleSpinBox_set_x->value());
    str_msg += " ";
    str_msg += num2str(ui->doubleSpinBox_set_y->value());
    str_msg += " ";
    str_msg += num2str(ui->doubleSpinBox_set_z->value());
    str_msg += " ";
    str_msg += num2str(ui->doubleSpinBox_set_roll->value());
    str_msg += " ";
    str_msg += num2str(ui->doubleSpinBox_set_pitch->value());
    str_msg += " ";
    str_msg += num2str(ui->doubleSpinBox_set_yaw->value());

    std_msgs::String msg;
    msg.data = str_msg.c_str();
    pub_trans_vec_.publish(msg);
}

void MainWindow::car_changed(const double& car){
    std::string str_msg;

    str_msg += num2str(ui->doubleSpinBox_set_car_length->value());
    str_msg += " ";
    str_msg += num2str(ui->doubleSpinBox_set_car_width->value());
    str_msg += " ";
    str_msg += num2str(ui->doubleSpinBox_set_car_height->value());

    std_msgs::String msg;
    msg.data = str_msg.c_str();
    pub_car_.publish(msg);
}

void MainWindow::on_pushButton_save_adjust_clicked(){
    std_msgs::String tmp_str;
    pub_save_align_.publish(tmp_str);
}


MainWindow::~MainWindow()
{
    delete ui;
}