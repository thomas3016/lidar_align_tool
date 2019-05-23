//
// Created by qzkj on 19-5-20.
//
#include <ros/ros.h>
#include <ros/package.h>
#include "std_msgs/String.h"
#include <pcl/point_cloud.h>
#include <pcl/point_types.h>
#include <pcl_ros/point_cloud.h>
#include <pcl/common/transforms.h>
#include <pcl_conversions/pcl_conversions.h>
#include <sensor_msgs/PointCloud2.h>
#include <tf/tf.h>
#include "Eigen/Dense"
#include <opencv2/opencv.hpp>
#include <visualization_msgs/Marker.h>

typedef pcl::PointCloud<pcl::PointXYZ> PointCloud;
typedef pcl::PointCloud<pcl::PointXYZ>::Ptr PointCloudPtr;

#define PI_OVER_180 (0.0174532925)

static ros::Publisher pub_trans_frame_;
static ros::Publisher pub_ground_plane_;
static ros::Publisher pub_car_;
static ros::Publisher pub_lidar_;

static ros::Publisher pub_dir_x_;
static ros::Publisher pub_dir_y_;
static ros::Publisher pub_dir_z_;

static std::string g_save_path_;
static std::string lidar_topic_;
static std::string lidar_frame_id_;
static PointCloud g_cloud_;

static std::vector<float> trans_vec_;
static std::vector<float> car_vec_;

static std_msgs::Header header_;


void getTransformMat(const std::vector<float> &in_vec, Eigen::Matrix4f &out_tranform_mat);

void publishGroundPlane();

void publishCar();

void publishLidarPos();

void publishDirection_x();

void publishDirection_y();

void publishDirection_z();

void publishCloud();

void pushlishAll();


void fullscanCallback(const sensor_msgs::PointCloud2::ConstPtr& msg)
{
    ROS_WARN("receive a new frame!");
    header_ = msg->header;
    pcl::fromROSMsg(*msg, g_cloud_);
    pushlishAll();
}

void adjustCallback(const std_msgs::String msg)
{
    if(g_cloud_.empty()) {
        std::cerr << "has not get a pcd!" << std::endl;
    }
    std::string tmp_str = msg.data;
    std::cout << tmp_str << std::endl;
    std::istringstream infile(tmp_str);

    char c[100];
    for(int i = 0; i < 6; ++i) {
        infile >> c;
        trans_vec_[i] = atof(c);
    }

    pushlishAll();
}

void saveCallback(const std_msgs::String msg)
{
    std::ofstream outfile;
    outfile.open(g_save_path_.c_str());
    assert(outfile.is_open());

    outfile << "vehicle_size:" << " ";
    for(int i = 0; i < 3; ++i) {
        outfile << car_vec_[i] << " ";
    }
    outfile << std::endl;

    outfile << "lidar_config:" << " ";
    for(int i = 0; i < 6; ++i) {
        outfile << trans_vec_[i] << " ";
    }
    outfile << std::endl;
    outfile.close();
    std::cout << "succeed save align info!" << std::endl;
}

void carCallback(const std_msgs::String msg)
{
    std::string tmp_str = msg.data;
    std::cout << tmp_str << std::endl;
    std::istringstream infile(tmp_str);

    char c[100];
    for(int i = 0; i < 3; ++i) {
        infile >> c;
        car_vec_[i] = atof(c);
    }
    pushlishAll();
}


void getTransformMat(const std::vector<float> &in_vec, Eigen::Matrix4f &out_tranform_mat)
{
    out_tranform_mat = Eigen::Matrix4f::Identity();
    float tx = in_vec[0];
    float ty = in_vec[1];
    float tz = in_vec[2];
    float rx = in_vec[3] * PI_OVER_180;
    float ry = in_vec[4] * PI_OVER_180;
    float rz = in_vec[5] * PI_OVER_180;

    Eigen::AngleAxisf init_rotation_x(rx, Eigen::Vector3f::UnitX());
    Eigen::AngleAxisf init_rotation_y(ry, Eigen::Vector3f::UnitY());
    Eigen::AngleAxisf init_rotation_z(rz, Eigen::Vector3f::UnitZ());

    Eigen::Translation3f init_translation(tx, ty, tz);

    Eigen::Matrix4f init_guess =
          (init_translation * init_rotation_x * init_rotation_y * init_rotation_z).matrix();
    out_tranform_mat = init_guess;
}

void pushlishAll()
{
    publishGroundPlane();
    publishCar();
    publishLidarPos();
    publishDirection_x();
    // publishDirection_y();
    // publishDirection_z();
    publishCloud();
}

void publishCloud()
{
    //publish
    sensor_msgs::PointCloud2 pcMsg;

    Eigen::Matrix4f tranfor_mat;
    std::vector<float> final_trans_vec(6, 0);
    final_trans_vec = trans_vec_;
    getTransformMat(final_trans_vec, tranfor_mat);


    PointCloudPtr transfor_cloud_ptr(new PointCloud);
    pcl::transformPointCloud(g_cloud_, *transfor_cloud_ptr, tranfor_mat);
    pcl::toROSMsg(*transfor_cloud_ptr, pcMsg);

    pcMsg.header = header_;
    pub_trans_frame_.publish(pcMsg);
}

void publishDirection_x()
{
    visualization_msgs::Marker marker;
    marker.header.frame_id = header_.frame_id;
    marker.ns = "my_namespace";
    marker.id = 3;
    marker.type = visualization_msgs::Marker::ARROW;
    marker.action = visualization_msgs::Marker::ADD;

    marker.scale.x = 2;
    marker.scale.y = 0.1;
    marker.scale.z = 0.1;
    marker.color.a = 1.0; // Don't forget to set the alpha!
    marker.color.r = 1.0;
    marker.color.g = 1.0;
    marker.color.b = 0.0;

    marker.pose.position.x = trans_vec_[0];
    marker.pose.position.y = trans_vec_[1];
    marker.pose.position.z = trans_vec_[2];

    tf::Quaternion quat = tf::createQuaternionFromRPY(trans_vec_[3]*PI_OVER_180, trans_vec_[4]*PI_OVER_180, trans_vec_[5]*PI_OVER_180);
    tf::quaternionTFToMsg(quat, marker.pose.orientation);

    pub_dir_x_.publish(marker);
}

void publishDirection_y()
{
    visualization_msgs::Marker marker;
    marker.header.frame_id = header_.frame_id;
    marker.ns = "my_namespace";
    marker.id = 4;
    marker.type = visualization_msgs::Marker::ARROW;
    marker.action = visualization_msgs::Marker::ADD;

    marker.scale.x = 0.05;
    marker.scale.y = 0.1;
    marker.scale.z = 0.3;
    marker.color.a = 1.0; // Don't forget to set the alpha!
    marker.color.r = 0.0;
    marker.color.g = 1.0;
    marker.color.b = 0.0;

    geometry_msgs::Point start;
    start.x = trans_vec_[0];
    start.y = trans_vec_[1];
    start.z = trans_vec_[2];

    marker.points.push_back(start);
    start.y+=1.0;
    marker.points.push_back(start);

    marker.pose.position.x = trans_vec_[0];
    marker.pose.position.y = trans_vec_[1];
    marker.pose.position.z = trans_vec_[2];

    tf::Quaternion quat = tf::createQuaternionFromRPY(trans_vec_[3]*PI_OVER_180, trans_vec_[4]*PI_OVER_180, trans_vec_[5]*PI_OVER_180);
    tf::quaternionTFToMsg(quat, marker.pose.orientation);

    pub_dir_y_.publish(marker);
}

void publishDirection_z()
{
    visualization_msgs::Marker marker;
    marker.header.frame_id = header_.frame_id;
    marker.ns = "my_namespace";
    marker.id = 5;
    marker.type = visualization_msgs::Marker::ARROW;
    marker.action = visualization_msgs::Marker::ADD;

    marker.scale.x = 0.05;
    marker.scale.y = 0.1;
    marker.scale.z = 0.3;
    marker.color.a = 1.0; // Don't forget to set the alpha!
    marker.color.r = 0.0;
    marker.color.g = 0.0;
    marker.color.b = 1.0;

    geometry_msgs::Point start;
    start.x = trans_vec_[0];
    start.y = trans_vec_[1];
    start.z = trans_vec_[2];

    marker.points.push_back(start);
    start.z+=1.0;
    marker.points.push_back(start);

    marker.pose.position.x = trans_vec_[0];
    marker.pose.position.y = trans_vec_[1];
    marker.pose.position.z = trans_vec_[2];

    tf::Quaternion quat = tf::createQuaternionFromRPY(trans_vec_[3]*PI_OVER_180, trans_vec_[4]*PI_OVER_180, trans_vec_[5]*PI_OVER_180);
    tf::quaternionTFToMsg(quat, marker.pose.orientation);

    pub_dir_z_.publish(marker);
}

void publishCar()
{
    visualization_msgs::Marker marker;
    marker.header.frame_id = header_.frame_id;
    marker.ns = "my_namespace";
    marker.id = 0;
    marker.type = visualization_msgs::Marker::CUBE;
    marker.action = visualization_msgs::Marker::ADD;
    marker.pose.position.x = 0;
    marker.pose.position.y = 0;
    marker.pose.position.z = car_vec_[2] / 2.;
    marker.pose.orientation.x = 0.0;
    marker.pose.orientation.y = 0.0;
    marker.pose.orientation.z = 0.0;
    marker.pose.orientation.w = 1.0;
    marker.scale.x = car_vec_[0];
    marker.scale.y = car_vec_[1];
    marker.scale.z = car_vec_[2];
    marker.color.a = 0.5; // Don't forget to set the alpha!
    marker.color.r = 0.0;
    marker.color.g = 0.5;
    marker.color.b = 0.5;

    pub_car_.publish(marker);
}

void publishLidarPos()
{
    visualization_msgs::Marker marker;
    marker.header.frame_id = header_.frame_id;
    marker.ns = "my_namespace";
    marker.id = 1;
    marker.type = visualization_msgs::Marker::CUBE;
    marker.action = visualization_msgs::Marker::ADD;

    marker.pose.position.x = trans_vec_[0];
    marker.pose.position.y = trans_vec_[1];
    marker.pose.position.z = trans_vec_[2];


    tf::Quaternion quat = tf::createQuaternionFromRPY(trans_vec_[3]*PI_OVER_180, trans_vec_[4]*PI_OVER_180, trans_vec_[5]*PI_OVER_180);
    tf::quaternionTFToMsg(quat, marker.pose.orientation);

    marker.scale.x = 0.3;
    marker.scale.y = 0.3;
    marker.scale.z = 0.3;
    marker.color.a = 1.0; // Don't forget to set the alpha!
    marker.color.r = 1.0;
    marker.color.g = 1.0;
    marker.color.b = 0.0;

    pub_lidar_.publish(marker);
}

void publishGroundPlane()
{
    visualization_msgs::Marker marker;
    marker.header.frame_id = header_.frame_id;
    marker.ns = "my_namespace";
    marker.id = 2;
    marker.type = visualization_msgs::Marker::CUBE;
    marker.action = visualization_msgs::Marker::ADD;
    marker.pose.position.x = 0;
    marker.pose.position.y = 0;
    marker.pose.position.z = 0;
    marker.pose.orientation.x = 0.0;
    marker.pose.orientation.y = 0.0;
    marker.pose.orientation.z = 0.0;
    marker.pose.orientation.w = 1.0;
    marker.scale.x = 30.;
    marker.scale.y = 30.;
    marker.scale.z = 0.1;
    marker.color.a = 0.95; // Don't forget to set the alpha!
    marker.color.r = 0.2;
    marker.color.g = 0.1;
    marker.color.b = 0.3;

    pub_ground_plane_.publish(marker);
}


int main(int argc, char *argv[])
{
    ros::init(argc, argv, "adjust_node");
    ros::NodeHandle node;
    //ros::NodeHandle private_nh("~");

    node.param("lidar_topic", lidar_topic_, std::string(""));
    node.param("lidar_frame_id", lidar_frame_id_, std::string(""));
    std::cout << "lidar_frame_id:" << lidar_frame_id_ << std::endl;
    ros::Subscriber sub_fullscan = node.subscribe(lidar_topic_, 10, fullscanCallback);
    ros::Subscriber sub_adjust = node.subscribe("/adjust_order", 10, adjustCallback);
    ros::Subscriber sub_save = node.subscribe("/save_order", 10, saveCallback);
    ros::Subscriber sub_car = node.subscribe("/car_order", 10, carCallback);

    pub_trans_frame_ = node.advertise<sensor_msgs::PointCloud2>("/adjust", 1);
    pub_ground_plane_ = node.advertise<visualization_msgs::Marker>("/ground_plane", 1);
    pub_car_ = node.advertise<visualization_msgs::Marker>("/car", 1);
    pub_lidar_ = node.advertise<visualization_msgs::Marker>("/lidar", 1);
    pub_dir_x_ = node.advertise<visualization_msgs::Marker>("/direction_x", 1);
    pub_dir_y_ = node.advertise<visualization_msgs::Marker>("/direction_y", 1);
    pub_dir_z_ = node.advertise<visualization_msgs::Marker>("/direction_z", 1);

    car_vec_.assign(3, 2);
    car_vec_[0] = 5;
    car_vec_[1] = 2;
    car_vec_[2] = 1.8;
    trans_vec_.assign(6, 0.);
    trans_vec_[2] = 2;
    header_.frame_id = lidar_frame_id_;
    std::string tmp_save_path = ros::package::getPath("lidar_align_tool") + "/align_result/";
    g_save_path_ = tmp_save_path + "align.txt";

    ros::spin();

    return 0;
}
