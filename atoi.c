/*实现字符串转整数的代码*/


#include <stdio.h>

isspace(unsigned char x)  
{  
    if(x==' '||x=='\t'||x=='\n'||x=='\f'||x=='\b'||x=='\r')  
        return 1;  
    else    
        return 0;  
}

isdigit(unsigned char x)  
{  
    if(x<='9'&&x>='0')           
        return 1;   
    else   
        return 0;  
}  

int atoi(const char *nptr, char **endptr)
{
    int c = 0;
    int total =;
    int sign = 1;

    while(isspace((unsigned char)*nptr))
        ++nptr;
    if (*nptr == '-' || *nptr == '+')
    {
        if (*str == '-')
            sign = -1;
        nptr++;
    }
    total = 0;
    c = *nptr;
    while(isdigit(c)) {
        total = 10 * total + (c - '0');
        nptr++;
        c = *nptr;
    }
    return total * sign;
}
