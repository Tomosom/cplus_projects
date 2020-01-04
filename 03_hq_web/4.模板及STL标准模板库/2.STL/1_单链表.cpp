#include<iostream>
//#include<ostream>
using namespace std;

class mylist{
public:
#if 1
	mylist():head(NULL){ }
#else
	mylist(){
		head = NULL;
	}
#endif
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
	//	Node *pnew = new Node;
	//	pnew->data = a;
		Node *pnew = new Node(a);	
		pnew->next = head;
		head = pnew;
	}
	friend ostream &operator<<(ostream &out, mylist &list);

private:
	struct Node{
		Node(int x, Node *ptr = NULL):data(x), next(ptr){ } //
		int data;
		Node* next;
	};
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
	return 0;
}
