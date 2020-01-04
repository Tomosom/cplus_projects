#include "thread.h"
int main(int argc, const char *argv[])
{
	MultiThread tt;
	tt.start();
	tt.join();
	return 0;
}
