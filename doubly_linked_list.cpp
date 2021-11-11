#include <iostream>

using namespace std;

typedef struct node Node;
struct node
{
    int data;
    Node *next;
    Node *prev;
};

class Doubly_linked_list
{
public:
    Node *create_node(int item, Node *next, Node *prev);
    void print_doubly_linked_list(Node *head);
    Node *prepend(Node *head, int item);
    Node *append(Node *head, int item);
    void insert(Node *node, int item);
    Node *remove_node(Node *head, Node *node);
};

int main(void)
{
    Node *head, *n1;
    Doubly_linked_list Doubly;

    head = Doubly.create_node(31, NULL, NULL);
    Doubly.print_doubly_linked_list(head);

    Doubly.insert(head, 39); // add node anywhere

    n1 = Doubly.prepend(head, 35); // Add node first position
    head = n1;
    Doubly.print_doubly_linked_list(head);

    head = Doubly.append(head, 37); // Add node last position
    Doubly.print_doubly_linked_list(head);

    head = Doubly.append(head, 41); // Add node last position
    Doubly.print_doubly_linked_list(head);

    head = Doubly.remove_node(head, n1);
    Doubly.print_doubly_linked_list(head);

    return 0;
}

// Create node
Node *Doubly_linked_list::create_node(int item, Node *next, Node *prev)
{
    Node *new_node;

    new_node = new Node;
    if(new_node == NULL)
    {
        cout << "Error! Could not create a new Node.\n";
        exit(1);
    }

    new_node->data = item;
    new_node->next = next;
    new_node->prev = prev;

    return new_node;
    delete new_node;
}

// print node
void Doubly_linked_list::print_doubly_linked_list(Node *head)
{
    Node *current_node = head;

    while(current_node != NULL)
    {
        cout << current_node->data << " ";
        current_node = current_node->next;
    }
    cout << "\n";
}

// Prepend
Node *Doubly_linked_list::prepend(Node *head, int item)
{
    Node *new_node = create_node(item, head, NULL);
    //new_node->next->prev = new_node;
    // OR
    new_node->next = head;
    head = new_node;

    return new_node;
}

// Append
Node *Doubly_linked_list::append(Node *head, int item)
{
    Node *new_node = create_node(item, NULL, NULL);

    if(head == NULL)
        return new_node;

    Node *current_node = head;
    while(current_node->next != NULL)
    {
        current_node = current_node->next;
    }

    current_node->next = new_node;
    new_node->prev = current_node;

    return head;
}

// insert
void Doubly_linked_list::insert(Node *node, int item)
{
    Node *new_node = create_node(item, node->next, node->prev);

    new_node->next = node->next;
    node->next = new_node;
}

// Remove node
Node *Doubly_linked_list::remove_node(Node *head, Node *node)
{
    if(node == head)
    {
        head = node->next;
        node->prev = NULL;
        free(node);
        return head;
    }

    Node *current_node = head;
    while(current_node != NULL)
    {
        current_node = current_node->next;
    }

    Node *previous_node = node->prev;
    Node *next_node = node->next;

    previous_node->next = next_node;
    next_node->prev = previous_node;

    free(node);
    return head;
}
