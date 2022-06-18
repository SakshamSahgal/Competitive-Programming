#include<iostream>
#include<list>
using namespace std;

struct Node
{
    int info;
    Node *link;
};

class Linked_List
{
public:
    Node *start = NULL,*last = NULL,*temp;

    void insert_Node(int val)
    {
        temp = new Node;
        temp->info = val;
        temp->link = NULL;

        if(start == NULL)
        {
            start = temp;
            last = temp;
        }
        else
        {
            last->link = temp;
            last = temp;
        }
    }

    void display()
    {
        cout<<"\n-------------------------\n";
        if(start != NULL)
        {
            temp = start;

            while(temp != NULL)
            {
                cout<<temp->info<<" ";
                temp = temp->link;
            }
            //cout<<"\nstart = "<<start->info<<" last = "<<last->info<<"\n";
        }
        else
            cout<<"Empty\n";
        cout<<"\n-------------------------\n";
    }

    void Delete_node()
    {
        if(start != NULL)
        {
            if(start->link == NULL)
            {
                delete(temp);
                start = NULL;
                last = NULL;
            }
            else
            {
                if(temp == start)
                {
                    start = start->link;
                    delete(temp);
                }
                else if(temp == last)
                {
                    Node *tt = start;

                    while(tt->link != last)
                        tt = tt->link;
                    last = tt;
                    delete(temp);
                }
                else
                {
                    Node *tt = start;

                    while(tt->link != temp)
                        tt = tt->link;
                    tt->link = temp->link;
                    delete(temp);
                }
            }
        }
        else
            cout<<"List is Empty\n";
    }

    void Delete_Item()
    {
        int val;
        cout<<"Enter the Item to be Deleted : ";
        cin>>val;

        temp = start;
        while(temp != NULL)
        {
            if(temp->info == val)
            {
                Delete_node();
                break;
            }
            temp = temp->link;
        }
    }

    void insert_elements()
    {
        int n;
        cout<<"Enter no of Elements :";
        cin>>n;
        for(int i=0; i<n; i++)
        {
            int x;
            cin>>x;
            insert_Node(x);
        }

    }
};

int main()
{
    Linked_List l1;
    l1.insert_elements();
    l1.display();
    l1.Delete_Item();
    l1.display();
    cout<<"\n-----------------------\n";
    cout<<"Name : Saksham Sahgal \n";
    cout<<"Batch : B8 \n";
    cout<<"Enroll no - 20103224";
    cout<<"\n-----------------------\n";
    return 0;
}
