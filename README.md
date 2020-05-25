# RoboND-Go-Chase-It-Project
Second project of the Robotics Course of Udacity

## Install ROS
Follow the steps in http://wiki.ros.org/kinetic/Installation

## Edit the .bashrc file
Insert the line `source /opt/ros/melodic/setup.bash` in .bashrc  
Restart the terminal

## Clone the repo in your workspace
`$ git clone https://github.com/bruno-szdl/RoboCppND-Go-Chase-It-Project.git`

## Build the project
In the project folder  
`$ cd catkin_ws`  
`$ catkin_make`

## Launch the world
`$ source devel/setup.bash`  
`$ roslaunch my_robot world.launch`

## Launch the drive_bot and process_image nodes
Open a new terminal  
`$ source devel/setup.bash`  
`$ roslaunch ball_chaser ball_chaser.launch`

## Run the camera viewer
Open a new terminal  
`$ source devel/setup.bash`  
`$ rosrun rqt_image_view rqt_image_view`

## Test the robot
Move the white ball into the robot field of view and see the robot chasing the ball
