#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define exp_b 4 // размер блока в байтах
char* read_str();
char* dell(char *str);
int sizestr(char *str);
int n;

int main ()
{
	char *str = NULL;
	str = read_str(str);
	//printf("%s",str);
	str = dell(str);
	printf("\n%s\n",str);
	free(str);
	return 0;
}
char* dell(char *str)
{
	printf("1\n");
	char *c_str;
	int i = 0,n = sizestr(str)-1,b=1;
	printf("1\n");
	c_str = (char*)malloc(exp_b*sizeof(char)*n);
	printf("1\n");
	while(n-i != 0 && *(str+i) == ' ')
	{
		printf("ys\n");
		i++;
	}
	printf("n = %d\n",n);
	if (*(str+i-1)!= ' ' && n-i == 0)
	{ 
		printf("if\n");
		free(str);
		return NULL;
	}
	i=0;
	int j = 0,k=0;
	while (n-i != 0)
	{
		printf("while\n");
		while(*(str+i) != ' ' && n-i != 0 && b ==1)
		{
			printf("nc\n");
			i++;			
		}
		while(*(str+i) == ' ' && n-i != 0) 
		{
			printf("prob\n");
			i++;
			k++;
		}
		if (k!= 0)
		{
			 b = 0;
			 k=0;
		 }
		printf("%d",b);
		while(*(str+i) != ' ' && n-i != 0 && b==0)
		{
			printf("c\n");
			*(c_str+j) =*(str+i);
			i++; 
			j++;
		}
		if(n-i !=0)
		{
		*(c_str+j)=' ';
		j++;
		}
		else if(b==0)
		{
			printf("esle\n");
			*(c_str+j)=*(str+i);
			j++;
		}
		while(*(str+i) == ' ' && n-i != 0) 
		{
			printf("prob\n");
			i++;
			k++;
		}
		if (k!= 0)
		{
			 b = 1;
			 k=0;
		 }
		
	}
	*(c_str+i) = '\0';
	free(str);
	return c_str;
}
char* read_str()
{
	char *str = NULL;
	n=exp_b;
	str = (char*)malloc(exp_b*sizeof(char));
	char c;
	int i = 0;
	do
	{
		c = getchar();
		if ( i >= n)
		{
			n = n + exp_b;
			str = (char*) realloc(str,sizeof(char)*n);
		}
		*(str+i) = c;
		i++;
	}while (c != EOF && c != '\n');
	if ( c == '\n')
	{
		if ( i >= n)
		{
			n = n + exp_b;
			str = (char*) realloc(str,sizeof(char)*n);
		}
		*(str+i) = '\0';
	}
	else
	{
		i--;
		*(str+i) = '\0';
	}
	//printf("OK\n");
	return str;
}	
int sizestr(char *str)
{
	int n = 0;
	while (*str != '\n' && *str != EOF)
	{
		str++;
		n++;
	}
	return n;
}
