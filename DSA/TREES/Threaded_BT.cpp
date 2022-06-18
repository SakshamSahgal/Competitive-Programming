#include<iostream>
using namespace std;

struct Node
{
    struct Node *lc, *rc;
    int info;
    bool lthread; //0-> left threading to ansistor, 1-> no thread (pointer to child)
    bool  rthread; //0-> right threading to ansistor, 1-> no thread (pointer to child)
};

class Threaded_BT
{
public:
    Node *root=NULL,*temp=NULL,*dummy_node=NULL;

    Node* Create(int x)
    {
        temp = new Node;
        temp->info = x;
        temp->lc = temp->rc = NULL;
        temp->lthread = 0;
        temp->rthread = 0;
    }

    void Insert(int x,Node *Temp_root)
    {
        if(root == NULL)
        {
            root = Create(x);
            dummy_node = new Node;
            dummy_node->rc = dummy_node;
            dummy_node->rthread = 1;
            dummy_node->lthread = 1;
            dummy_node->lc = root;
            root->lc = dummy_node;
            root->rc = dummy_node;
        }
        else
        {
            if(x < Temp_root->info) //goto lc
            {
                if(Temp_root->lthread == 0)
                {
                    temp = Create(x);
                    temp->lc = Temp_root->lc;
                    temp->rc = Temp_root;
                    Temp_root->lc = temp;
                    Temp_root->lthread = 1;
                }
                else
                    Insert(x,Temp_root->lc);
            }
            else if( x > Temp_root->info) //goto rc
            {
                if(Temp_root->rthread == 0)
                {
                    temp = Create(x);
                    temp->lc = Temp_root;
                    temp->rc = Temp_root->rc;
                    Temp_root->rc = temp;
                    Temp_root->rthread = 1;
                }
                else
                    Insert(x,Temp_root->rc);
            }
        }
    }

    void Inorder_Traversal()
    {
        temp = dummy_node->lc;
        do
        {
            while(temp->lthread != 0)
                temp = temp->lc;

            cout<<temp->info<<" ";

            while(temp->rthread == 0)
            {
                temp = temp->rc;
                if(temp == dummy_node)
                    return;
                cout<<temp->info<<" ";
            }
            temp = temp->rc;
        }
        while(temp != dummy_node);
    }
};
int main()
{
    Threaded_BT t;
    cout<<"\n-------inserting 10--------\n";
    t.Insert(10,t.root);
    t.Inorder_Traversal();
    cout<<"\n-------inserting 9--------\n";
    t.Insert(9,t.root);
    t.Inorder_Traversal();
    cout<<"\n-------inserting 8--------\n";
    t.Insert(8,t.root);
    t.Inorder_Traversal();
    cout<<"\n-------inserting 11--------\n";
    t.Insert(11,t.root);
    t.Inorder_Traversal();
    cout<<"\n-------inserting 12--------\n";
    t.Insert(12,t.root);
    t.Inorder_Traversal();
    cout<<"\n---------------------------\n";

    return 0;
}
