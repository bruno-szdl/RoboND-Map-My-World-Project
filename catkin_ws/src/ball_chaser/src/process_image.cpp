#include "ros/ros.h"
#include "math.h"
#include "ball_chaser/DriveToTarget.h"
#include <sensor_msgs/Image.h>

// Define a global client that can request services
ros::ServiceClient client;

// This function calls the command_robot service to drive the robot in the specified direction
void drive_robot(float lin_x, float ang_z){

    ROS_INFO_STREAM("Driving the robot");

    // Request velocities
    ball_chaser::DriveToTarget srv;
    srv.request.linear_x = lin_x;
    srv.request.angular_z = ang_z;

    // Display error if the service is not called
    if(!client.call(srv))
        ROS_ERROR("Failed to call servicedrive_robot");
}

// This callback function continuously executes and reads the image data
void process_image_callback(const sensor_msgs::Image img){

    int white_pixel = 255;

    bool white_pixel_found = false;

    // Loop through each pixel in the image and check if there's a bright white one
    int ball_column;
    for(int i = 0; i < img.height; i++){
        for(int j = 0; j < img.step; j++){
            if(img.data[i*img.step + j] == white_pixel){
                white_pixel_found = true;
                ball_column = j;
                break;
            }
        }
    }

    if(white_pixel_found){

        // Identify if this pixel falls in the left, mid or right side of the image
        // Depending on the white ball position, call the drive_bot function and pass velocities to it
        if(ball_column < floor(img.step/3)){
            drive_robot(0, 2);
        } 
        else if(ball_column > ceil(img.step*2/3)){
            drive_robot(0, -2);
        }
        else{
            drive_robot(2, 0.0);
        }

    }
    // Request a stop when there's no white ball seen by the camera
    else{
        drive_robot(0, 0);
    }
}


int main(int argc, char** argv){

    // Initialize the process_image node and create a handle to it
    ros::init(argc, argv, "process_image");
    ros::NodeHandle n;

    // Define a client service capable of requesting services from command_robot
    client = n.serviceClient<ball_chaser::DriveToTarget>("/ball_chaser/command_robot");

    // Subscribe to /camera/rgb/image_raw topic to read the image data inside the process_image_callback function
    ros::Subscriber sub1 = n.subscribe("/camera/rgb/image_raw", 10, process_image_callback);

    // Handle ROS communication events
    ros::spin();

    return 0;
}