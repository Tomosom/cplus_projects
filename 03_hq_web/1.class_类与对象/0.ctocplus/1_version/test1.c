#include<stdio.h>
int main(int argc, const char *argv[])
{
	int arr[100] = {0};
	int tail = 0;
	
	int n = 10;
	while(n--)
		arr[tail++] = n;
	int i = 0;
	for(;i < tail;i++)
		printf("%d, ",arr[i]);
	printf("\n");

	n = 5;
	while(n--)
		arr[tail++] = n;
	i = 0;
	for(;i < tail;i++)
		printf("%d, ",arr[i]);
	printf("\n");
	

	return 0;
}
