#include"mystring.h"

String::String(const char* str)
{//通用构造函数
	if(!str)
	{
		length = 0;
		data = new char[1];
		*data = '\0';
	}
	else
	{
		length = strlen(str);
		data = new char[length+1];
		strcpy(data, str);
	}
}

String::String(const String& str)
{//拷贝构造函数
	length = str.size();//??
	data = new char[length+1];
	strcpy(data, str.c_str());//??
}

String::~String()
{//析钩函数
	delete[] data;
	length = 0;
}

String String::operator+(const String& str) const
{//重载+
	String newString;
	newString.length = length + str.size();
	newString.data = new char[newString.length +1];
	strcpy(newString.data, data);
	strcat(newString.data, str.data);
	return newString;
}

String& String::operator=(const String& str)//是否有内存泄漏??
{//重载=
	if(this == &str)
		return *this;
	
	delete[] data;
	length = str.length;
	data = new char[length + 1];
	strcpy(data, str.c_str());
	return *this;
}

String& String::operator+=(const String& str)
{//重载+=
	length += str.length;
	char* newData = new char[length+1];
	strcpy(newData, data);
	strcat(newData, str.data);
	delete[] data;
	data = newData;
	return *this;
}

bool String::operator==(const String& str) const //该函数不能用内联函数 ??
{//重载==
	if(length != str.length)
		return false;

	return strcmp(data, str.data) ? false : true;
}

inline char& String::operator[](int n) const
{//重载[]
	if(n >= length)
		return data[length-1];
	else
		return data[n];
}

//重载两个读取私有成员的函数，分别读取长度和C字符串 ??
inline size_t String::size() const
{
	return length;
}
inline const char* String::c_str() const
{
	return data;
}

