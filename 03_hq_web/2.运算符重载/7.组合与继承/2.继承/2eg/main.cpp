#include"arr.h"
#include<iostream>
using namespace std;

class ARRX:public ARR{
public:
	double getsum(void)
	{
		int i=0;
		int sum = 0;
		for(;i<tail ;i++)
			sum += data[i];

		return (double)sum/tail;
	}
};


class Stuma{
public:
	Stuma(){}
	~Stuma(){}

	void savescore(int score)
	{
		scorearr.addtail(score);
	}

	void showscore(void)
	{
		scorearr.show();
	}
	
	double averscore()
	{
		return scorearr.getsum();
	}
private:
	ARRX scorearr;
};

int main(int argc, const char *argv[])
{
	Stuma mm;

	mm.savescore(98);
	mm.savescore(99);
	mm.savescore(88);
	mm.showscore();

	cout<<mm.averscore()<<endl;
	return 0;
}
