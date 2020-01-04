#include"arr.h"

int main(int argc, const char *argv[])
{
	ARR ar;
	init_arr(&ar);
	
	int n=10;
	while(n--)
		add_tail(&ar,n);
	show(&ar);


	ARR brr;
	ARR *br=&brr;
	init_arr(br);

	int i=0;
	for(;i<10;i++)
		add_tail(br,i);
	show(br);

	return 0;
}
