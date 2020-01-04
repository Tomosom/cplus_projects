#include"seqlist.h"

Seqlist::Seqlist()
{
	arraysize = 5;
	data = (int*)malloc(arraysize * sizeof(int));
	if(data == NULL)
	{
		printf("[%s]malloc failed\n", __FUNCTION__);

	}
	last = -1;
	increment = 5;
}

Seqlist::~Seqlist(){}

bool Seqlist::Insert_data(int input, int locate)
{
	//
	if(last+1 == arraysize)
		Incresize();

	int i;
	for(i=last; i>=locate; i--)
		data[i+1] = data[i];
	data[locate] = input;
	last++;
	return true;
}

bool Seqlist::Delete_data(int key)
{
	int i = 0;
	while(i != last+1 && data[i] != key)
		i++;
	if(i == last+1)
	{
		printf("[%s]no key found\n",__FUNCTION__);
		return false;
	}

	for(; i<last ;i++)
		data[i] = data[i+1];
	last--;
	return true;	
}

bool Seqlist::Traverse_seq()
{
	int i = 0;
	for(;i<=last; i++)
		printf("%4d", data[i]);
	putchar(10);
	return true;
}

int Seqlist::Incresize()
{
	int* pnew = (int*)malloc((arraysize+increment)*sizeof(int));
	if(pnew == NULL)
	{
		printf("[%s]malloc failed\n",__FUNCTION__);
		return -1;
	}

	int i = 0;
	for(; i<=last; i++)
		pnew[i] = data[i];
	free(data);
	data = pnew;
	arraysize += increment;
	printf("扩容%d,最大容量%d\n", increment, arraysize);	
	return arraysize;
}
