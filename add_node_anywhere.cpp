#include <iostream>

using namespace std;

typedef struct node Node;
struct node
{
    int data;
    Node *next;
};

Node *create_node(int item, Node *next);
void print_list(Node *head);
Node *append(Node *head, int item);
void insert(Node *node, int item);

int main(void)
{
    Node *head;

    head = create_node(45, NULL);
    print_list(head);

    // insert call
    insert(head, 34);

    head = append(head, 71);
    print_list(head);


    return 0;
}

// create node
Node *create_node(int item, Node *next)
{
    Node *new_node;

    new_node = new Node;
    if(new_node == NULL)
    {
        cout << "Error! Could not create a new node.\n";
        exit(1);
    }
    new_node->data = item;
    new_node->next = next;

    return new_node;
    delete new_node;
}

void print_list(Node *head)
{
    Node *current_node = head;
    while(current_node != NULL)
    {
        cout << current_node->data << " ";
        current_node = current_node->next;
    }
    cout << "\n";
}

// append
Node *append(Node *head, int item)
{
    Node *new_node = create_node(item, NULL);

    if(head == NULL)
        return new_node;

    Node *current_node = head;
    while(current_node->next != NULL)
    {
        current_node = current_node->next;
    }
    current_node->next = new_node;

    return head;
}

// Node add anywhere
void insert(Node *node, int item)
{
    Node *new_node = create_node(item, node->next);
    node->next = new_node;
}
