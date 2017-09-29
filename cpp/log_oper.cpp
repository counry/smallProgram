#include <iostream>
#include <iomanip>
#include <vector>

struct log {
	struct log operator<<(std::string) {
		return *this;
	}
#if 0
	struct log operator<<(char *str) {
		return *this;
	}
#endif
};

class log glog;

#define LOG glog

int main(void)
{
 LOG << "aaa" << std::string("bbb");
return 0;
}
