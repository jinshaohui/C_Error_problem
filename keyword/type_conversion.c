/*File : type_conversion.c
 *Auth : sjin
 *Date : 20141018
 *Mail : 413977243@qq.com
 */

#include <stdio.h>
/*隐式类型转换带来的错误*/

int array[] = {10,20,30,40};
#define TOTAL_EMEMENTS (sizeof(array)/sizeof(array[0]))

/*另外一个例子
 *代码输出什么？为什么？
 * */
int fun()
{
    unsigned int a = 6;
    int b = -20;

    (a + b > 6)? puts("a + b > 6"):puts("a + b < 6");
}

int main()
{
    int d = -1;

    if (d <= TOTAL_EMEMENTS){
        printf("##[sjin] : the array total emements is %d\n",TOTAL_EMEMENTS);
    }else {
        printf("##[sjin] : the array is empty!\n");
    }

    fun();

    return 0;
}


