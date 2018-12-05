# include <ros/ros.h>
# include <geometry_msgs/PoseStamped.h>
# include <geometry_msgs/Pose.h> 
# include <mav_msgs/RollPitchYawrateThrust.h>
# include <stdio.h>

int count=1;
geometry_msgs::Pose current
void pose_sub(const geometry_msgs::Pose& msg)
{
    current_pose=msg.position.z;
}

int main(int argc, char** argv)
{
    ros::init(argc,argv,"flip_node");
    ros::NodeHandle nh;
    ros::Publisher initial_pose_pub =nh.advertise<geometry_msgs::PoseStamped>("/firefly/command/pose",10);
    ros::Publisher thrust_pub = nh.advertise<mav_msgs::RollPitchYawrateThrust>("/firefly/command/roll_pitch_yawrate_thrust",10);
    ros::Subscriber current_pose_sub = nh.subscribe<geometry_msgs::Pose>("/firefly/ground_truth/pose", 10, pose_sub);

    while (ros::ok())
    {
        geometry_msgs::PoseStamped initial_pose;
        initial_pose.pose.position.z= 3.0;
        
        // if(count==1)
        // {
        //     initial_pose_pub.publish(initial_pose);

        // }

        geometry_msgs::Pose msg;
        msg.position.z=current_pose;

        std::cout<<"The height is "<< msg.position.z << std::endl;       
        




        count=0;        
    }

}