#ifndef __OBJECT_H__
#define __OBJECT_H__
#include <cstdlib>

namespace DTLib{

class Object {
	
public:
	/* 重载new与delete函数，与Windows的区别，形参类型不同
		Windows：size_t ：unsigned int
		Linux 64bit: long unsigned int 
	*/
	void *operator new(size_t size) throw();
	void operator delete(void *p);
	void *operator new[](size_t size) throw();
	void operator delete[](void *p);
	
	
	virtual ~Object() = 0;
	
};

}

#endif