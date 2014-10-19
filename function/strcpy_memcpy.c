/*File : strcpy_memcpy.c
 *Auth : sjin
 *Date : 20141019
 *Mail : 413977143@qq.com
 */

/* 主要针对strcpy及与memcpy函数的区别
 * strcpy 函数在使用过程中的注意事项等等，在面试时及平时
 * 代码编写中经常遇到的问题。
 */

#include <stdio.h>

/*strcpy函数提供了字符串的复制，即只用于字符串的复制，并且它不仅复制
 * 字符串内容之外，还会复制字符串的结束符。遇到结束符则停止复制
 *函数原型char *strcpy(char *dest,const char *src)
 */
char * mystrcpy(char *dest,const char *src)
{
    if((dest == NULL) || (src == NULL)){
        return NULL;
    }

    char *strdest = dest; //保存目标字符串的首地址
    while((*strdest ++ = *src++) != '\0');

    return dest;
}

/*memcpy函数提供了一般内存的复制，即对需要复制的内容没有限制
 * 函数原型 void *memcpy(void * dest,const void * src,size_t count);
 * 
 * 对于地址重叠情况 ，该函数的是未定义的
 */
void * mymemcpy1(void *dest,const void *src,size_t count)
{
    /*未考虑内存重叠情况*/
    if((dest == NULL) || (src == NULL)){
        return NULL;
    }

    char *strdest = (char *)dest;
    char *strsrc =  (char *)src;

    while(count-- > 0){
         *strdest++ = *strsrc++;
    }

    return dest;
}


void * mymemcpy2(void *dest,const void *src,size_t count)
{
    char *strdest = NULL;
    char *strsrc =  NULL;
    /*内存重叠情况*/
    if((dest == NULL) || (src == NULL)){
        return NULL;
    }

    if((src < dest) && (((char *)src + count) > (char *)dest)){
        strdest = (char *)dest + count - 1;
        strsrc =  (char *)src + count - 1;

        while(count--){
            *strdest-- = *strsrc--;
        }
    }else{
        strdest = (char *)dest;
        strsrc =  (char *)src;

        while(count-- > 0){
            *strdest++ = *strsrc++;
        }
    }

    return dest;
}
/*strcpy 与memcpy区别:
 *1 复制的内容不同，strcpy 只能复制字符串，而memcpy复制任意内容。
 *2 复制的方法不同，strcpy不需要指定长度，它遇到字符串结尾符结束。
 *  所以容易溢出。memcpy则是根据第三参数聚丁复制的长度
 *3 用途不同。通常在复制字符串时用strcpy，而需要复制其他数据类型数据时则一般用memcpy
 *4 内存重叠时，strcpy会出现段错误，而memcpy不会
 */


int main()
{
    char buf[16] = "abcdefghijk";
    char buf1[16] = "abcdefghijk";
    char buf2[16] = "abcdefghijk";
    char buf3[16] = "abcdefghijk";

    //strcpy(buf+2,buf); ###程序崩溃，段错误
    memcpy(buf + 2,buf,5);
    memmove(buf1+2,buf1,5);
    mymemcpy1(buf2 + 2,buf2,5);
    mymemcpy2(buf4 + 2,buf3,5);
   
    printf(" end of memcpy(buf +2,buf,5), buf is :%s\n",buf);
    printf(" end of memmove(buf1 +2,buf1,5), buf1 is :%s\n",buf1);
    printf(" end of mymemcpy1(buf2 +2,buf2,5), buf2 is :%s\n",buf2);
    printf(" end of mymemcpy2(buf3 +2,buf3,5), buf3 is :%s\n",buf3);

    return 0;
}

