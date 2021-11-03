#include <iostream>
#include <cstdlib>

using namespace std;

struct Node *link_list(int arr[], int n);

struct Node
{
    int data;
    struct Node *next;
};

int main()
{
    int A[] = {12, 14, 16, 21};
    int n = sizeof(A)/sizeof(A[0]);

    struct Node *head;
    head = link_list(A, n);
    while(head != NULL)
    {
        cout << "-> " << head->data;
        head = head->next;
    }
    cout<<" NULL\n";

    return 0;
}

struct Node *link_list(int arr[], int n)
{
    struct Node *head = NULL, *temp = NULL, *current = NULL;

    int i;
    for(i = 0; i < n; i++)
    {
        temp = new (struct Node);
        temp->data = arr[i];
        temp->next = NULL;

        if(head == NULL)
        {
            head = temp;
            current = temp;
        }
        else
        {
            current->next = temp;
            current = current->next;
        }
    }
    return head;
}
