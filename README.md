#lidar_align_tool (lidar mounting calibration tool):

注：

1.这个工具是一个帮助大家校准激光雷达外部参数的程序，即获得激光坐标系到车体坐标系的（ x, y, z, roll, pith, yaw）6个参数，其中车体坐标系为：X轴正方向为⻋辆前进方向,Y轴正方向为⻋辆左方向,Z轴正方向指向天空,原点位于⻋辆正投影到地面的轮廓的几何中心点上,所以原点的z坐标在地面上。

2.使用方法：
　　1):首先设置/lidar_align_tool/launch/lidar_align.launch文件中的lidar_topic和lidar_frame_id两个参数；
  
　　2):catkin_make
  
 　 3):source devel/setup.bash
   
 　 4):roslaunch lidar_align_tool lidar_align.launch

3.如何校准？
　　1):roslaunch以后，在rviz里会看到数据，其中紫色透明平面是虚拟标准地面参考,⻘色框是虚拟⻋辆,轴(红色为x轴,绿色为y轴,蓝色为z轴)是⻋辆参考坐标系,⻩色小盒子和箭头是虚拟激光雷达及其方向；
  
　　2):设置⻋辆大小,调整激光雷达高度(set trans_z),调整激光雷达位置(set trans_x 和set	trans_y),调整偏航角度(set Rotation Yaw),通过调整roll角和pitch角来调整点云以保证大部分地面点能很好的隐藏在紫色平面中(set Rotation Roll和set Rotation Pitch);校准的标准是:保持调整直到大部分地面点水平对⻬并隐藏到参考紫色平面(可能需要调整激光雷达高度),并且在激光雷达和⻋辆之间具有正确的相对角度。需要提醒的是，旋转角度的正负服从右手坐标系准则。
  
 　3):校准完成后,点击save 保存结果到align_result文件夹的align.txt,如果想从上次最后的结果重新校准,点击load恢复到上次最后的结果并继续。
