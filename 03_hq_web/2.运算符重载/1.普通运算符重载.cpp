#include<stdio.h>


class Timer
{
public:
	Timer()
	{
		hour = 0;
		min = 0;
		sec = 0;
	}
	~Timer(){}

	void show()
	{
		printf("%2d:%2d:%2d\n",hour, min, sec);
	}

	void add(int n)
	{
		sec += n;
	}

	Timer operator+(int pl)
	{
		Timer temp;
		temp.sec = sec + pl;
		return temp;
	}

	Timer operator+(Timer &te) //使用引用可以减少拷贝过程
	{
		Timer temp;
		temp.sec = sec+te.sec;
		temp.min = min+te.min;
		temp.hour = hour+te.hour;
		return temp;
	}

	Timer operator++(int) //后++运算符重载
	{
		Timer temp = *this; //初始化可直接等号赋值
		//temp.sec = sec;
		sec++;
		return temp;
	}
	Timer operator++() //前++运算符重载
	{
		this->sec++;
		return *this;
	}


	bool operator==(Timer &te)
	{
		if(sec == te.sec && min == te.min && hour == te.hour)
			return true;
		else
			return false;
	}

private:
	int hour;
	int min;
	int sec;
};

int main(int argc, const char *argv[])
{
	Timer t1;
	t1.add(3);
	t1.show();
	t1 = t1+3;
	t1.show();


	Timer t2;
	t2.add(5);
	t2.show();

	Timer t3;
	t3 = t2+t1;
	t3.show();

	Timer t4;
	//t4 = ++t3;
	t4 = t3++;
	t4.show();
	t3.show();

	if(t3 == t4)
		printf("t3 = t4\n");
	else
		printf("not equal\n");

	return 0;
}
