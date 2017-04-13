/*
 * =====================================================================================
 *
 *       Filename:  dayOfYear.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  04/13/2017 10:52:03 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *        Company:  
 *
 * =====================================================================================
 */

#include <stdio.h>

static const int MON_SUM[12] = {0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334};

bool isLeapYear(int year)
{
    return (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
}

int dayOfYear(int year, int month, int day)
{
    int ret = -1;
    if (year > 0 && month > 0 && month < 13 && day > 0 && day < 32) {
        ret = MON_SUM[month-1] + day;
        if (isLeapYear(year) && month > 2) {
            ret += 1;
        }
    }
    return ret;
}

int main(void)
{
    int year = 2016;
    int month = 3;
    int day = 1;
    int td = dayOfYear(year, month, day);
    if (td != -1)
        printf("the date %d-%02d-%02d is the %d day of the year %d\n", year, month, day, td, year);
    else
        printf("input parameter error");
    return 0;
}

