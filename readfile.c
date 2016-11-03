/*
 * =====================================================================================
 *
 *       Filename:  readfile.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  10/28/2016 04:59:15 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *        Company:  
 *
 * =====================================================================================
 */

#include <stdio.h>
#include <stdlib.h>

struct ReadFile {
    int i;
    char c;
    short s;
    char buf[10];
};

int write_file(void)
{
    struct ReadFile r;
    memset((char*)&r, 0x00, sizeof(struct ReadFile));    
    r.i = 99;
    r.c = 'c';
    r.s = 88;
    strncpy(r.buf, "YYYYYY", 9);
    r.buf[9] = '\0';
    printf("ori i=%d, c=%c, s=%d, buf=%s\n", r.i, r.c, r.s, r.buf);
    
    FILE *pFile=fopen("tmp.test", "wb");
    if (NULL == pFile) {
        printf("open file error\n");
        return -1;
    }
    fwrite((void *)(&r), sizeof(struct ReadFile), 1, pFile);
    fclose(pFile);
    return 0;
}

int read_file(void)
{
    struct ReadFile r;
    FILE *pFile=fopen("tmp.test", "rb");
    if (NULL == pFile) {
        printf("open file error\n");
        return -1;
    }
    fseek(pFile, 0, SEEK_END);
    int len = ftell(pFile);
    rewind(pFile);
    fread((void *)(&r), sizeof(struct ReadFile), 1, pFile);
    fclose(pFile);
    printf("read i=%d, c=%c, s=%d, buf=%s\n", r.i, r.c, r.s, r.buf);
    return 0;
  
}

int main(void)
{
    write_file();
    printf("\n\n");
    read_file();
    return 0;
}
