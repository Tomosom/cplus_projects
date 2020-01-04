#include"mystring.h"
istream& operator>>(istream& is, String& str)
{//重载输入>>
	char tem[1000];
	is>>tem;
	str.length = strlen(tem);
	str.data = new char[str.length + 1];
	strcpy(str.data, tem);
	return is;
}

ostream& operator<<(ostream& os, String str) //str不能为引用，否则输出s1+s2不能成功
{//重载输出<<
	os<<str.data;
	return os;
}

int main(int argc, const char *argv[])
{
	String s;
	cin>>s;
	cout<<s<<": "<<s.size()<<endl;

	char a[] = "Hello",b[] = "world";
	String s1(a), s2(b);

	//cout<<s1<<"+"<<s2<<"="<<s1+s2<<endl;
	cout<<s1<<"+"<<s2<<"=";	
	cout<<s1+s2<<endl; //要想此句成功编译，输出<<重载中的形参不能为引用


#if 1
	String s3 = s1+s2;
	if(s1 == s3)
		cout<<"first : s1 ==s3"<<endl;
	s1+=s2;
	if(s1 == s3)
		cout<<"second : s1 ==s3"<<endl;
#endif
	return 0;
}
