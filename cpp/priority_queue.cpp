/*
 * =====================================================================================
 *
 *       Filename:  priority_queue.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  06/21/2016 04:29:59 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *        Company:  
 *
 * =====================================================================================
 */


#include <iostream>
#include <queue>
#include <vector>


typedef struct _AppCache_entry
{
    unsigned long long appid;
    unsigned int updates; //流量匹配数
    unsigned int m_time; //更新时间
}AppCache_entry;

struct appcache_entry_cmp
{
    bool operator()(const AppCache_entry& a, const AppCache_entry& b)
    {
        if (a.updates != b.updates) {
            return (a.updates > b.updates);
        } else {
            return (a.m_time > b.m_time);
        }
    }
};

int main(void)
{
    std::priority_queue<AppCache_entry, std::vector<AppCache_entry>, appcache_entry_cmp> cacheq;
    AppCache_entry tmp = {123456, 10, 100};
    cacheq.push(tmp);
    tmp = {123456, 11, 100};
    cacheq.push(tmp);
    tmp = {123456, 12, 100};
    cacheq.push(tmp);
    tmp = {123456, 13, 101};
    cacheq.push(tmp);
    tmp = {123456, 13, 102};
    cacheq.push(tmp);
    tmp = {123456, 13, 103};
    cacheq.push(tmp);
    tmp = {123456, 13, 101};
    cacheq.push(tmp);
    while(!cacheq.empty()) {
        std::cout << " update:" <<  cacheq.top().updates << " time:" << cacheq.top().m_time << std::endl;
        cacheq.pop();
    }
    return 0;
}
