#include<iostream>
#include<algorithm>
#define usi unsigned short int
#define ui unsigned int
#define si short int
#define ulli unsigned long long int
using namespace std;
int a;

struct node
{
int data;
node *next;
}*head=NULL,*tail=NULL,*ptr;

void add_value(int a)
    {
        ptr = NULL;
        ptr = new node;
        ptr->data = a;
        ptr->next = NULL;

       if(head == NULL)
            {
            head = ptr;
            tail = ptr;
            }
        else
            {
                tail-> next = ptr;
                tail = tail->next;
            }
    }
void printer()
    {
      node  *temp;
      temp = head;
      while(temp != NULL)
        {
            cout<<temp->data<<" ";
            temp=temp->next;
        }
    }
void Delete_it()
    {
      node *temp;
      temp = head;
      head= head->next;
      delete(temp);
    }
int main()
{
//ios_base::sync_with_stdio(false);
//cin.tie(NULL);
//cout.tie(NULL);
add_value(1);
add_value(2);
add_value(3);
add_value(4);
printer();
cout<<"\n";
Delete_it();
printer();
return 0;
}

