/*File : union.c
 *Auth : sjin
 *Date : 20141022
 *Mail : 413977243@qq.com
 */

#include <stdio.h>
/*这里来说明面试中经常问的一个问题
 *判断系统的大小端问题
 *存储模式：大端模式和小端模式。
 *   大端模式（Big_endian） ：字数据的 高字节存储在 低地址中，而字数据的 低字节 则存放在高地址中。
 *   小端模式（Little_endian） ：字数据的 高字节存储在 高地址中，而字数据的 低字节则存放在低地址中。
 *union 型数据所占的空间等于其最大的成员所占的空间。对 union 型的成员的存取都是
 *相对于该联合体基地址的偏移量为 0 处开始， 也就是联合体的访问不论对哪个变量的存取都
 *是从 union 的首地址位置开始.
 */

/* True: 小端模式
 * False：大端模式
 */
int checkSystem()
{
    union check{
        int i;
        char ch;
    }c;
    
    c.i = 1;
    
    return (c.ch == 1);
}
int main()
{
    if(checkSystem()){
        printf("当前系统为小端模式\n");
    }else{
        printf("当前系统为大端模式\n");
    }
    
    return 0;

}

