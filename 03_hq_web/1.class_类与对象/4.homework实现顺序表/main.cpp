#include"seqlist.h"

int main(int argc, const char *argv[])
{
	Seqlist a;
	
	int i = 0;
	for(; i<8; i++)
	{
		int input;
		scanf("%d",&input);
		a.Insert_data(input, a.Getlast()+1);
	}
	a.Traverse_seq();
	a.Delete_data(5);
	a.Traverse_seq();
	return 0;
}
