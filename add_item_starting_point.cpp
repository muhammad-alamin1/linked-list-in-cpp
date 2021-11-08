#include <iostream>

using namespace std;

typedef struct node Node;
struct node
{
    int data;
    Node *next;
};

Node *create_node(int item, Node *next);
Node *prepent(Node *head, int item);

int main()
{
    Node *head, *n1, *n2, *n3;

    n1 = create_node(23, NULL);
    head = n1;

    // prepent assign value assign head
    head = prepent(head, 25);
    n2 = head;
    cout << "First data -> " << n2->data << endl;

    n3 = n2->next;
    cout << "Second data -> " << n3->data;

    return 0;
}

// create Node
Node *create_node(int item, Node *next)
{
    Node *new_node;

    new_node = new Node;
    if(new_node == NULL)
    {
        cout << "Error! Could not create a Node." << endl;
        exit(1);
    }

    new_node->data = item;
    new_node->next = next;
}

// Add node starting point
Node *prepent(Node *head, int item)
{
    Node *new_node = create_node(item, head);
    return new_node;
}
