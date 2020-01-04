#include<stdio.h>

class Timer
{
public:
	Timer()
	{
		hour = 0;
		min = 1;
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

	operator int(){		//自定义转换函数
		return sec+min*60+hour*60*60;
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

	int sec = t1;
	printf("sec = %d\n",sec);

	return 0;
}
