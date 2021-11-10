#include <iostream>

using namespace std;

typedef struct node Node;
struct node
{
    int data;
    Node *next;
};

Node *create_node(int item, Node *next);
void list_print(Node *head);
Node *append(Node *head, int item);
Node *remove_node(Node *head, Node *node);

int main(void)
{
    Node *head, *n1, *n2, *n3;

    n1 = create_node(65, NULL);
    head = n1;
    //list_print(head);

    head = append(head, 67);
    //list_print(head);

    head = append(head, 69);
    //list_print(head);

    head = remove_node(head, n1);
    //list_print(head);

    n2 = head;
    head = remove_node(head, n2);
    list_print(head);

    n3 = head;
    head = remove_node(head, n3);
    list_print(head);

    return 0;
}

// create_node
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

void list_print(Node *head)
{
    Node *current_node = head;

    while(current_node != NULL)
    {
        cout << current_node->data << " ";
        current_node = current_node->next;
    }
    cout << "\n";
}

// append -> Add node ending point
Node *append(Node *head, int item)
{
    Node *new_node = create_node(item, NULL);

    if(head == NULL)
        return new_node;

    Node *current_node = head;
    // Append function time complexity O(n)
    while(current_node->next != NULL)
    {
        current_node = current_node->next;
    }

    current_node->next = new_node;
    return head;
}

// Remove node
Node *remove_node(Node *head, Node *node)
{
    if(node == head)
    {
        head = node->next;
        free(node);
        return head;
    }

    Node *current_node = head;
    while(current_node != NULL)
    {
        if(current_node->next == node)
            break;
        else
            current_node = current_node->next;
    }

    if(current_node == NULL)
        return head;

    current_node->next = node->next;
    free(node);

    return head;
}
