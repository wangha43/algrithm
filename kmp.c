#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//calculate kmp pmt array.
void getkmpNext(const char *p,int * next)
{
	printf("get kmp next array...\n");
	next[0] = -1;
	int i=0,j=-1;
	printf("p length=%lu\n", strlen(p));

	while(i<(int)strlen(p))
	{
		printf("i:%d\n", i);
		if (j == -1 || p[i] == p[j] )
		{
			++i;
			++j;
			next[i] = j;
		}
		else
			j = next[j];
	}

}

int KMP(const char * t, const char * p) 
{

	int * next = (int *)malloc((size_t)strlen(p)*sizeof(int));
	getkmpNext(p,next);
	
	printf("the next value is :\n");
	for(int m = 0;m<strlen(p);m++)
	{
		printf("%d ",next[m]);
	}
	printf("\n");

	int i = 0; 
	int j = 0;

	while (i < strlen(t) && j < strlen(p))
	{
		if (j == -1 || t[i] == p[j]) 
		{
			i++;
           	j++;
		}
	 	else 
           	j = next[j];
    }

    free(next);

    if (j == strlen(p))
       return i - j;
    else 
       return -1;
}

int main()
{
	const char * str1 = "ababababca";
	const char * str2 = "abababca";

	int index = KMP(str1,str2);

	printf("%s and %s KMP:\n", str1,str2);
	printf("index of str is %d\n",index);

	return 0;
}