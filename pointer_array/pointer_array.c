/*File : pointer_array.c
 *Auth : sjin
 *Date : 20141024
 *Mail : 413977243@qq.com
 */


/*指针数组及数组指针
 * 指针数组：首先它是一个数组，数组的元素都是指针，数组占多少字节由数组本身决定。
 *           它是“存储指针的数组”的简称，声明：int (*p2)[10]
 * 数组指针：首先它是一个指针，它指向一个数组，在32位系统下永远占4个字节，至于它
 *           指向的数组占多少字节，不知道，它是“指向数组的指针”简称
 *           声明 int *p1[10]
 *
 */
/*下面的例子可以看出数组和指针的区别*/

void test()
{
	struct Test{
        int num;
		char *pNum;
		short sDate;
		char c[2];
		short sBa[4];
	}*p;


	printf("\n\np = %x\n",p);
	printf("p + 0x1 = %x\n",p + 0x1);//结构体大小为20，所以p+1= p + 1*sizeof(struct test);
	printf("(unsigned long)p + 0x1 = %x\n",(unsigned long)p + 0x1);//p,被强转成unsigned long,就是一个长整型+1
	printf("(unsigned int *)p + 0x1 = %x\n",(unsigned int *)p + 0x1);//p,被强转成unsigned int *,是一个指针，+sizeof(unsigned int *)*1


}


int main()
{
	char a[5] = {'A','B','C','D'};
	char * p ="12345";
	char (*p1)[5] = &a;
	char (*p2)[5] = a;
	char (*p3)[5] = &p;
	char (*p4)[5] = p;

	printf("&a = %x\n",&a);
	printf("a = %x\n",a);
	printf("p1 = %x\n",p1);
	printf("p2 = %x\n",p2);
	printf("p3 = %x\n",p3);
	printf("p4 = %x\n",p4);
	printf("p1 + 1 = %x\n",p1 + 1);
	printf("p2 + 1 = %x\n",p2 + 1);
	printf("p3 + 1 = %x\n",p3 + 1);
	printf("p4 + 1 = %x\n",p4 + 1);

    test();
    return 0;
}
