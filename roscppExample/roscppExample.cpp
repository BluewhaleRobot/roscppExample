// roscppExample.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#define WIN32
#include "ros/ros.h"
#include "std_msgs/String.h"
#pragma comment(lib, "Ws2_32.lib")

int main(int argc, char **argv)
{
	std::map<std::string, std::string> params;
	// 设置 ros master地址
	params.insert(std::pair<std::string, std::string>("__master", "http://192.168.0.100:11311"));
	// 设置自己的地址，否则默认使用hostname会无法通信
	params.insert(std::pair<std::string, std::string>("__ip", "192.168.0.8"));
	ros::init(params, "talker");
	ros::NodeHandle n;
	ros::Publisher chatter_pub = n.advertise<std_msgs::String>("chatter", 1000);
	ros::Rate loop_rate(10);
	int count = 0;
	while (ros::ok())
	{
		std_msgs::String msg;
		std::stringstream ss;
		ss << "hello world " << count;
		msg.data = ss.str();
		std::cout << "send message: hello world" << std::endl;
		chatter_pub.publish(msg);
		ros::spinOnce();
		loop_rate.sleep();
		++count;
	}
	return 0;
}
