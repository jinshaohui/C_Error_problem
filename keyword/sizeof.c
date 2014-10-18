/*File : sizeof.c
 *Auth : sjin
 *Date : 20141018
 *Mail : 413977243@qq.com
 */
#include <stdio.h>
/*sizeof 是关键字，不是函数
 *计算数据空间的字节数
 * */

void fun(char b[100])
{
    printf("##[sjin] in fun sizeof(b):\t%d \n",sizeof(b));
  
}

int main()
{
    double *p = NULL;
    char a[100] = {'\0'};
    double *(*b)[3][6];
    int d = 0;

    printf("##[sjin] sizeof(int):\t%d \n",sizeof(int));
    printf("##[sjin] sizeof(d):\t%d \n",sizeof(d));
    printf("##[sjin] sizeof d:\t%d \n\n",sizeof d );

    //下面编译错误 
    //printf("##[sjin] sizeof int:\t%d \n\n",sizeof int );

    printf("##[sjin] sizeof(p):\t%d \n",sizeof(p)); //p是一个指针
    printf("##[sjin] sizeof(*p):\t%d \n",sizeof(*p));//*p 为一个double的变量
    printf("##[sjin] sizeof(a):\t%d \n",sizeof(a));//a是一个数组
    printf("##[sjin] sizeof(a[0]):\t%d \n",sizeof(a[0]));//a[0] 是一个char型变量
    printf("##[sjin] sizeof(&a):\t%d \n",sizeof(&a));//&a 是a的地址
    printf("##[sjin] sizeof(&a[0]):\t%d \n",sizeof(&a[0]));//&a[0] 是a[0]的地址
    printf("##[sjin] sizeof(b):\t%d \n",sizeof(b));
    printf("##[sjin] sizeof(*b):\t%d \n",sizeof(*b));
    printf("##[sjin] sizeof(**b):\t%d \n",sizeof(**b));
    printf("##[sjin] sizeof(***b):\t%d \n",sizeof(***b));
    printf("##[sjin] sizeof(****b):\t%d \n",sizeof(****b));

    fun(a);

}
