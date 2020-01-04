#include<iostream>
using namespace std;

class mylist{
private:
	struct Node{
		Node(int x, Node *ptr = NULL):data(x), next(ptr){ } //
		int data;
		Node* next;
	};	

public: //Node必须在前面声明
	class iterator{
	public:
		iterator(Node *ptr = NULL):pos(ptr){ }
		iterator &operator++(int)
		{
			if(NULL != pos)
				pos = pos->next;
			return *this;
		}
		int &operator*()
		{
			return pos->data;
		}
		bool operator!=(iterator x)
		{
			return pos != x.pos;
		}
	private:
		Node *pos;
	};

	iterator begin()
	{
		return iterator(head);
	}
	iterator end()
	{
		return iterator (NULL);
	}
public:
	mylist():head(NULL){ }
	~mylist(){
		Node *pcur;
		while(head != NULL)
		{
			pcur = head;
			head = head->next;
			delete pcur;
		}
	}
	void insert(int a)
	{
		Node *pnew = new Node(a);	
		pnew->next = head;
		head = pnew;
	}
	friend ostream &operator<<(ostream &out, mylist &list);

private:
	Node *head;
};

ostream &operator<<(ostream &out, mylist &list)
{
	mylist::Node *pcur = list.head;
	while(pcur != NULL)
	{
		out << pcur->data << ",";
		pcur = pcur->next;
	}
	out << endl;
	return out;
}

int main(int argc, const char *argv[])
{
	mylist l;
	l.insert(3);
	l.insert(2);
	l.insert(5);
	l.insert(1);
	cout << l;


	mylist::iterator i = l.begin();
	while(i != l.end())
	{
		cout << *i << endl;
		i++;
	}



	return 0;
}
