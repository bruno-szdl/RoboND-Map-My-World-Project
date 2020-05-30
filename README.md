# RoboND-Map-My-World-Project
Fourth project of the Robotics Course of Udacity

## Prerequisites 
* make >= 4.1
* gcc/g++ >= 5.4
* Gazebo >= 7.0  
* ROS Kinetic 

## Edit the .bashrc file
Insert the line `source /opt/ros/kinetic/setup.bash` in .bashrc  
Restart the terminal

## Clone the repo in your workspace
`$ git clone https://github.com/bruno-szdl/RoboCppND-Map-My-World-Project.git`

## Build the project
In the project folder  
`$ cd catkin_ws`  
`$ catkin_make`

## Launch the world
`$ source devel/setup.bash`  
`$ roslaunch my_robot world.launch`

## Launch mapping node
Open a new terminal  
`$ source devel/setup.bash`  
`$ roslaunch my_robot mapping.launch`

## Run the teleop node
Open a new terminal
`$ source devel/setup.bash`  
`$ rosrun teleop_twist_keyboard teleop_twist_keyboard.py`
Control de robot using the keyboard
