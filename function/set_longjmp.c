/*File : set_longjmp.c
 *Auth : sjin
 *Date : 20141026
 *Mail : 413977143@qq.com
 */

/*使用setjmp,longjmp从信号中恢复
 * */
#include <stdio.h>
#include <string.h>
#include <setjmp.h>
#include <signal.h>

jmp_buf buf;

void handler(int signal)
{
    if(signal == SIGINT){
        printf("now ,got a SIGINT signal\n");
    }

    longjmp(buf,1);
}

int main()
{
    int flag = 1; 
    //注册信号回调函数
    //signal(SIGINT,handler);
    sigset(SIGINT,handler);
    if(setjmp(buf)){
        printf("back in main\n");
        flag = 0;
    }else{
        printf("first time throught\n");
    }

loop:
    if(flag == 0){
        printf("got a signal SIGINT,back in here\n");
        printf("main exit \n");
        return 0;
    }
    goto loop;

    return 0;
}

