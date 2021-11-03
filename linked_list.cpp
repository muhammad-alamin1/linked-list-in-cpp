#include <iostream>

using namespace std;

struct Node
{
    int data;
    struct Node *next;
};

int main()
{
    Node *x = NULL, *y = NULL, *z = NULL;

    x = new Node;
    y = new Node;
    z = new Node;
    if(!x || !y || !z)
        cout << "Memory allocation failed.\n";

    x->data = 15;
    y->data = 20;
    z->data = 25;

    x->next = y;
    y->next = z;
    z->next = NULL;

    while(x != NULL)
    {
        cout << "-> " << x->data << " ";
        x = x->next;
    }
    cout << "NULL";

    delete x;
    delete y;
    delete z;

    return 0;
}
