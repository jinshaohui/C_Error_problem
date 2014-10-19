/*File : strcpy.c
 *Auth : sjin
 *Date : 20141019
 *Mail : 413977143@qq.com
 */

/*关于strcpy的一些重要的面试题
 * */
#include <stdio.h>
#include <string.h>

int main()
{
    char str[10] = {'\0'};
    char str1[10] = {'\0'};
    int i = 0;

    //for(i = 0; i < 10; i++){ 
    //上面的将会出现段错误。未考虑字符串的结束符
    for(i = 0; i < 9; i++){
        str1[i] = 'a';
    }
    strcpy(str,str1);
    printf("str is :%s\n",str);
    return 0;
}

