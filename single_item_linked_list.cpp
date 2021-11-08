#include <iostream>

using namespace std;

typedef struct node Node;
struct node
{
    int data;
    Node *next;
};

Node *create_node(int item, Node *next);

int main()
{
    Node *n;
    n = create_node(2247, NULL);
    cout << "Data -> " << n->data << endl;

    return 0;
}

// create linked list
Node *create_node(int item, Node *next)
{
    Node *new_node = new Node;
    if(new_node == NULL)
    {
        cout << "Error! Could not Create A new Node.\n";
        exit(1);
    }

    new_node->data = item;
    new_node->next = next;

    delete new_node;

    return new_node;
}
