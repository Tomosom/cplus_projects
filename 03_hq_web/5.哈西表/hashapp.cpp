#include<iostream>
#include<stdbool.h>
#include<iomanip>

using namespace std;

class dataItem{
public:
	dataItem()
	{
	
	}
	dataItem(int value)
	{
		this->value = value;
	}
	int getValue()
	{
		return value;
	}
	void setValue(int value)
	{
		this->value = value;
	}

private:
	int value;
};

class HashApp{
public:
	dataItem* arr[13];
	
	//memset(arr,NULL,13);
	int size;
	dataItem* newItem;
	int currentSize;

	HashApp()
	{
		for(int i=0;i<13;++i)
			arr[i] = NULL;
		
		size = 13;
		currentSize = 0;
	}
#if 1
	int hash(int value)
	{
		return value%size;
	}

	bool isFull()
	{
		return currentSize == size;
	}
	//插入
	void insert(int data)
	{
		if( isFull() )
		{
			cout << "hashmap is full" <<endl;
			return;
		}

		newItem = new dataItem;
		newItem->setValue(data);
		
		int index = hash(data);

		while(arr[index] != NULL)
		{
			index++;
			index = hash(index);
		}
		arr[index] = newItem;
		currentSize++;
	}
	//删除
	void delete_data(int data)
	{
		int index = hash(data);
		while(arr[index] != NULL)
		{
			if(arr[index]->getValue() == data)
			{
				delete arr[index];
				arr[index] = NULL;
				currentSize--;
				return;
			}
			index ++;
			index = hash(index);
		}
	}
	//查找
	dataItem* find(int value)
	{
		int index = hash(value);
		while(arr[index] != NULL)
		{
			if(arr[index]->getValue() != value)
				return arr[index];

			index++;
			index = hash(index);
		}
		return NULL;
	}
	//遍历
	void display()
	{
		for(int i = 0; i<13; ++i)
		{
			if(arr[i] != NULL)
				cout << setw(2) << arr[i]->getValue() << " ";
			else
				cout << "# " << " ";
		}
		cout << endl;
	}
#endif
};


int main(int argc, const char *argv[])
{
	HashApp myhash;
	int a[10] = {12,23,45,57,20,03,65,31,15,36};
	for(int i = 0; i<10 ; ++i)
	{
		//int input;
		//cin >> input;
		//cout << input << endl;
		myhash.insert(a[i]);
	}	
	myhash.display();

	myhash.delete_data(45);
	myhash.display();

//	cout << myhash.arr[10]->getValue() <<endl;
	return 0;
}
