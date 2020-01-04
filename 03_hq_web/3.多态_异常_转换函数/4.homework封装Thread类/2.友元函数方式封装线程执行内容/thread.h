#pragma once

#include <iostream>
#include <pthread.h>

using namespace std;

class Thread
{
private:
	pthread_t tid;
	int threadStatus;
	void *run1();

public:
	friend void *thread_proxy_func(void *args);
	static const int THREAD_STATUS_NEW = 0;
	static const int THREAD_STATUS_RUNNING = 1;
	static const int THREAD_STATUS_EXIT = -1;
	Thread();
	virtual void run() = 0;
	bool start();
	pthread_t getThreadID();
	int getState();
	void join();
	void join(unsigned long millisTime);
};

class MultiThread : public Thread
{
public:
	void run()
	{
		int number = 0;
		for(int i = 0; i<10; ++i)
		{
			cout << "Current number is "<< number++;
			cout << "PID is "<< getpid() << "TID is "<<getThreadID() <<endl;
			sleep(1);
		}
	}
};
