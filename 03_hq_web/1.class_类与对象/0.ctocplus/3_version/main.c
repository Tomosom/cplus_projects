#include"arr.h"

int main(int argc, const char *argv[])
{
	ARR ar;
	init_arr(&ar);
	
	int n=10;
	while(n--)
		ar.add_tail(&ar,n);
	ar.show(&ar);


	ARR br;
	init_arr(&br);

	int i=0;
	for(;i<10;i++)
		br.add_tail(&br,i);
	br.show(&br);

	return 0;
}
