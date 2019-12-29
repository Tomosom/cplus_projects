#include <iostream>

using namespace std;

struct Node {
    int value;
    Node *next;
};

Node *create_list(int v, int len)
{
    Node *ret = NULL;
    Node *slider = NULL;

    for (int i = 0; i < len; i++) {
        Node *n = new Node();

        n->value = v++;
        n->next = NULL;

        if (slider == NULL) {
            slider = n;
            ret = n;
        } else {
            slider->next = n;
            slider = n;
        }
    }

    return ret;
}

void destroy_list(Node *list)
{
    while(list) {
        Node *del = list;
        list = list->next;
        delete del;
    }
}

void print_list(Node *list)
{
    while(list) {
        cout << list->value << "->";
        list = list->next;
    }
    cout << "NULL" << endl;
}

// 单链表递归转置
Node *reverse(Node *list)
{
    if ((list == NULL) || (list->next == NULL)) {
        return list;
    } else {
        Node *guard = list ->next;
        Node *ret = reverse(list->next);
        guard->next = list;
        list->next = NULL;
        return ret;
    }

}

// 单向已排好序的链表的合并，合并后仍是单向有序的


int main(int argc, char **argv)
{
    Node *list = create_list(3, 10);

    print_list(list);

    list = reverse(list);

    print_list(list);

    destroy_list(list);

    return 0;
}