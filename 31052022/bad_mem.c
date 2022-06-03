#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void test1()
{
	const int NUM_HEIGHTS=3;
	int *heights=(int *) malloc(NUM_HEIGHTS*sizeof(int));
	for(int i=0; i<NUM_HEIGHTS; i++)
	{
		heights[i]=i*i;
		printf("%d:%d\n",i,heights[i]);
	}
}
void test2()
{
	const int NUM_WEIGHTS=3;
	long long *weights=malloc(NUM_WEIGHTS*sizeof(weights));
	for(int i=0;i<NUM_WEIGHTS;i++)
	{
		weights[i]=i+100;
		printf("%d:%lld\n",i,weights[i]);
	}
	weights[0]=0;
	free(weights);
}
void test3()
{
	const int NUM_HEIGHTS=10;
	int *heights=malloc(NUM_HEIGHTS * sizeof(heights));
	for(int i=0; i<NUM_HEIGHTS; i++)
	{
		if(heights == NULL)
		{
       			 heights=malloc(NUM_HEIGHTS * sizeof(heights));
		}
	}
	free(heights);
}
char *getstring()
{
        char msg[100]="HELLO ALL HERE";
        char *ret=msg;
        return msg;
}
void test4()
{
	printf("String is %s",getstring());
}
int main (int argc, char * argv[])
{
	test1();
 	test2();
 	test3();
 	test4();
 	return(0);
}
