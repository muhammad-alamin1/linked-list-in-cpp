#include <iostream>

using namespace std;

typedef struct node Node;
struct node
{
    int data;
    Node *next;
};

Node *create_node(int item, Node *next);
void print_linked_list(Node *head);
Node *prepend(Node *head, int item);
Node *append(Node *head, int item);

int main()
{
    Node *head, *n1;

    head = create_node(20, NULL);
    //print_linked_list(head);

    head = prepend(head, 22);
    //print_linked_list(head);

    n1 = append(head, 24);
    head = n1;
    print_linked_list(head);

    return 0;
}

// Create Node
Node *create_node(int item, Node *next)
{
    Node *new_node;

    new_node = new Node;
    if(new_node == NULL)
    {
        cout << "Error! Could not create a new node." << endl;
        exit(1);
    }

    new_node->data = item;
    new_node->next = next;

    return new_node;
    delete new_node;
}

// print linked list
void print_linked_list(Node *head)
{
    Node *current_node;

    current_node = head;
    while(current_node != NULL)
    {
        cout << current_node->data << " "<<endl;
        current_node = current_node->next;
    }
}

// Prepend -> Add node starting point
Node *prepend(Node *head, int item)
{
    Node *new_node = create_node(item, head);
    return new_node;
}

// Append -> Add NOde ending point
Node *append(Node *head, int item)
{
    Node *new_node = create_node(item, NULL);

    if(new_node == NULL)
        return new_node;

    Node *current_node = head;
    while(current_node->next != NULL)
    {
        current_node = current_node->next;
    }
    current_node->next = new_node;

    return head;
}
