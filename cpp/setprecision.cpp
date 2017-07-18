

#include <iostream>     // std::cout, std::fixed
#include <iomanip>      // std::setprecision
#include <sstream>
#include <limits>
#include <math.h>

int test()
{
	double a = 0.3;
	std::cout << "std::numeric_limits<double>::digits10:" << std::numeric_limits<double>::digits10 << std::endl;
	std::cout.precision(std::numeric_limits<double>::digits10);
	std::cout << a << std::endl;
	double b = 0;
	for (char i = 1; i <= 50; i++) {
		b = b + a;
	};
	std::cout.precision(std::numeric_limits<double>::digits10);
	std::cout << b << std::endl;
}

int main () {
	double x = 116.41561001620494;
	double y = 40.05600600466512;
	double dst_x = 0.0;
	double dst_y = 0.0;
	std::stringstream iss;
	iss.setf(std::ios_base::fixed, std::ios_base::floatfield);
	iss.precision(std::numeric_limits<double>::digits10);
	iss << x << " " << y;
	iss >> dst_x;
	iss >> dst_y;
#if 0
	double dst_x1 = (double)(((long)(x*1000))/1000.0);
	std::stringstream iss;
	iss << std::fixed << std::setprecision(4) << x << " " << std::setprecision(6) << y << std::endl;
	std::cout << "iss : " << iss.str() << std::endl;
	iss >> dst_x;
	iss >> dst_y;
	std::cout << "x:" << x << " dst_x:" << dst_x << std::endl;
	std::cout << "y:" << y << " dst_y:" << dst_y << std::endl;
	std::cout << "x:" << x << " dst_x1:" << dst_x1 << std::endl;
	test();
#endif
	std::cout.precision(std::numeric_limits<double>::digits10);
	std::cout << "dst_x:" << dst_x << " dst_y:" << dst_y << std::endl;
	std::cout << "trunc(" << dst_x << ")=" << trunc(dst_x*1000000)/1000000.0 << " trunc(" << dst_y << ")=" << trunc(dst_y*1000000)/1000000.0 << std::endl;
	return 0;
}
