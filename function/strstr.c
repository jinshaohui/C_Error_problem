/*************************************************************************
 > File Name: strstr.c
 > Author:  jinshaohui
 > Mail:    jinshaohui789@163.com
 > Time:    18-11-08
 > Desc:    
 ************************************************************************/
#include<assert.h>

#include<string.h>
#include<stdlib.h>
#include<stdio.h>


char *mystrstr(const char* str1,const char *str2)
{
	char *pstr1 = str1;
	char *tmp = NULL;
	char *pstr2 = str2;

	if ((str1 == NULL) || (str2 == NULL))
	{
		return NULL;
	}

	while(*pstr1 != '\0')
	{
		tmp = pstr1;
		pstr2 = str2;
		while((*tmp != '\0') && (*pstr2 != '\0')&&(*tmp == *pstr2))
		{
			tmp++;
			pstr2++;
		}

		if (*pstr2 == '\0')
		{
			return pstr1;
		}
		pstr1++;
	}
    
	return NULL;
}

int main()
{
	char *str = "123abcd123";
    char *p = NULL;


	printf("%s",mystrstr(str,"abc"));
	printf("%s",mystrstr(str,"abc1"));

	return 0;
}
