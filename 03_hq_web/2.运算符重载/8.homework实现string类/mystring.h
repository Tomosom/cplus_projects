#pragma once
#include<iostream>
using namespace std;
#include<string.h>
#include<stdbool.h>


class String
{
public:
	String(const char* = NULL); //通用构造函数
	String(const String& str); //拷贝构造函数
	~String();

	String operator+(const String& str) const;
	String& operator=(const String& str);
	String& operator+=(const String& str);
	
#if 0
	bool operator==(const String& str) const;//不能用inline??
	inline char& operator[](int n) const;
	const size_t size() const; //为什么此项声明不能加 inline ???
	inline const char* c_str() const;
#else
	bool operator==(const String& str) const;
	char& operator[](int n) const;
	size_t size() const;
	const char* c_str() const;
#endif
	friend istream& operator>>(istream& is, String& str);
	friend ostream& operator<<(ostream& os, String str);

private:
	char* data;
	size_t length;

};
