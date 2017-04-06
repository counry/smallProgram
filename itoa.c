/*实现数字转字符串*/

char *reverse(char *s)  
{  
    char temp;  
    char *p = s;    //p指向s的头部  
    char *q = s;    //q指向s的尾部  
    while(*q)  
        ++q;  
    q--;  

    //交换移动指针，直到p和q交叉  
    while(q > p)  
    {  
        temp = *p;  
        *p++ = *q;  
        *q-- = temp;  
    }  
    return s;  
}  

void itoa(int n, char s[])
{
    int i,j,sign;
    if((sign = n) < 0)
        n = n * -1;
    i = 0;
    do {
        s[i++] = n % 10 + '0';
    } while((n/=10)>0);

    if (sign < 0)
        s[i++] = '-';
    s[i] = '\0';
    reverse(s);
}
