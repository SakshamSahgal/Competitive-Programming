#include<bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *Head = NULL;
    Node *Tail = NULL;

    Node Insert_into(int x)
    {
        Node *temp = new Node;
        temp->data = x;
        temp->next = NULL;

        if(Head == NULL)
        {
            Head = temp;
            Tail = temp;
        }
        else
        {
            Tail->next = temp;
            Tail = Tail->next;
        }
    }

    void Print_linked_list()
    {
        Node *temp = Head;
        while(temp != NULL)
        {
            cout<<temp->data<<" ";
            temp = temp->next;
        }
    }
};

Node n2;

void reverse_link_list(Node *cur)
{
    if(cur == NULL)
        return;
    else
    {
        reverse_link_list(cur->next);
        n2.Insert_into(cur->data);
    }
}

int main()
{
    Node n1;

    n1.Insert_into(2);
    n1.Insert_into(3);
    n1.Insert_into(4);
    n1.Print_linked_list();
    reverse_link_list(n1.Head);
    cout<<"\n";
    n2.Print_linked_list();
    return 0;
}
