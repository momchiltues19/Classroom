#include <stdio.h>

char* strcat(char* dest, const char* source);

int main()
{
	char dest[50];
	char source[50];
	fgets(dest,5,stdin);
	fgets(source,5,stdin);
	printf("%s",dest);
	dest[0] = strcat(dest,source);
	return 0;
}

char* strcat(char* dest, const char* source)
{
	char zero = '\0';
	int i=0,l1=0,l2=0;
	while(*(dest+l1)!=zero)
	{
		l1++;
	}
	printf("%d,%d",l1,l2);
	while(*(source+l2)!=zero)
	{
		l2++;
	}
	printf("%d,%d",l1,l2);
	for(i=0;l1<(l1+l2);l1++,i++)
	{
		*(dest+l1)=*(source+i);
	}
	return dest;
}
