#include<iostream>
using namespace std;

struct Node
{
    int info;
    Node *link;
};

class Linked_list_using_Closed_Addressing
{

    Node **hash_table;
    int sz;

    int hash_func(int k)
    {
        return (k%11);
    }

    Linked_list_using_Closed_Addressing(int sizze)
    {
        sz = sizze;
        hash_table = new Node* [sizze];
    }

    void Insert(int x)
    {


    }

};

int main()
{

    return 0;
}
