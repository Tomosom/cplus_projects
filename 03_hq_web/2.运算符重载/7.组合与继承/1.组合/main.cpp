#include"arr.h"

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

private:
	ARR scorearr;

};

int main(int argc, const char *argv[])
{
	Stuma mm;

	mm.savescore(98);
	mm.savescore(99);
	mm.savescore(88);

	mm.showscore();
	return 0;
}
