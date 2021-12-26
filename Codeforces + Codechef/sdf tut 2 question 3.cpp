#include<iostream>
using namespace std;
struct node
{
int data;
node *next;
}*head,*tail,*temp;

void insert_node(int n)
    {
    temp = new node;
    temp->data = n;
    temp->next = NULL;
    if(head == NULL)
        {
        head = temp;
        tail = temp;
        }
    else
        {
        tail->next = temp;
        tail = temp;
        }
    }
void delete_node()
    {
        temp = head;
        head = head->next;
        delete(temp);
    }
void display()
    {
        cout<<"\n";
        if(head == NULL)
            cout<<"nothing\n";
        else
            {
                temp = head;
                while(temp != NULL)
                {
                cout<<(temp->data)<<" ";
                temp = temp->next;
                }
            }
    }
int main()
{
insert_node(1);
insert_node(2);
insert_node(3);
insert_node(4);
insert_node(5);
display();
delete_node();
delete_node();
display();
return 0;
}

