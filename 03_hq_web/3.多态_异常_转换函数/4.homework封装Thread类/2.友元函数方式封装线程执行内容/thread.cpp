#include "thread.h"
void *thread_proxy_func(void *args)
{
	Thread* pThread = static_cast<Thread *>(args);
	pThread->run();
	return NULL;
}

void *Thread::run1()
{
	threadStatus = THREAD_STATUS_RUNNING;
	tid = pthread_self();
	run();
	threadStatus = THREAD_STATUS_EXIT;
	tid = 0;
	pthread_exit(0);
}

Thread::Thread()
{
	tid = 0;
	threadStatus = THREAD_STATUS_NEW;
}

bool Thread::start()
{
	int iRet = 0;
	return  pthread_create(&tid, NULL, thread_proxy_func, this) == 0;
}

pthread_t Thread::getThreadID()
{
	return tid;
}

int Thread::getState()
{
	return threadStatus;
}

void Thread::join()
{
	if(tid > 0)
	{
		pthread_join(tid, NULL);
	}
}


void Thread::join(unsigned long millisTime)
{
	if(tid == 0)
	{
		return;
	}
	if (0 == millisTime)
		join();
	else
	{
		unsigned long k = 0;
		while (threadStatus != THREAD_STATUS_EXIT && k <= millisTime)
		{
			usleep(100);
			k++;
		}
	}
}





