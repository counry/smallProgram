
#include <iostream>
#include <sys/vfs.h>

unsigned long getDiskFreeSize(std::string path)
{
    unsigned long mbFreedisk = 0;
    struct statfs diskInfo;  
    if (-1 != statfs(path.c_str(), &diskInfo)) {
        unsigned long long totalBlocks = diskInfo.f_bsize;  
        unsigned long long freeDisk = diskInfo.f_bfree*totalBlocks;  
        mbFreedisk = freeDisk>>20;  
    }
    return mbFreedisk;
}

int main(void)
{
	std::cout << "/ disk free size : " << getDiskFreeSize("/") << std::endl;
	return 0;
}

