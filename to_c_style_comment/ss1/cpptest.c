#include<stdio.h>

/* this is c style comment
 * it can cross multiple lines
 * like this occasion
 */
int main()
{
/*//////////////////////// */
/********************************/

	int c = 2; /* this is c++ style comment;  */
	double d = 0.587112; /* This another c++ style comment and ine this comment there is a c style comment /* c style * / but this don't work. */
			     /* And the C style comment after // will be change to /* c style * /. Notice there is a space between * and /.  */
	printf("This is a string , in a string nothing can be changed: \nno matter the // C++ style comment\n or the C style comment /* kfjl */\n");
	printf("%d   %f", c, d);
	return 0;
	/* In the c style comment, nothing can be changed. and the " will not be the begining 
	 * of a string  and the // will not be treated as the c++ style comment 
	*/
	return 0;
}
