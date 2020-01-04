#pragma once

#include <iostream>
#include <pthread.h>

using namespace std;

class Thread{
public:
	Thread();	//构造函数

	static const int THREAD_STATUS_NEW = 0;		//线程的状态-新建
	static const int THREAD_STATUS_RUNNING = 1;	//线程的状态-正在运行
	static const int THREAD_STATUS_EXIT = -1;	//线程的状态-运行结束

	virtual void run() = 0; //线程的执行内容
	bool start();			//开始执行线程
	pthread_t getThreadID(); //获取线程ID
	int getState();			//获取线程状态
	void join();			//等待线程直至退出
	void join(unsigned long millisTime); //等待线程退出或者超时

private:
	pthread_t tid;		//当前线程的id
	int threadStatus;	//线程的状态
	static void *thread_proxy_func(void *args); //获取执行方法的指针
	void *run1();		//内部执行方法
};

class MultiThread : public Thread{
public:
	void run()
	{
		int number = 0;
		for(int i = 0; i<10; ++i)
		{
			cout << "Current number is " << number++;
			cout << "PID is " << getpid() << "TID is " << getThreadID() << endl;
			sleep(1);
		}
	}
};

