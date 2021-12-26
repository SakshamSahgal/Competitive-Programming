#include<iostream>
using namespace std;


struct TreeNode
{
    int info;
    TreeNode *lc,*rc;
};

struct queueNode
{
    TreeNode *temp;
    queueNode *next;
    bool flag; //0 ->insert right child ... //1->insert left child
};


class Trees
{
public:
    TreeNode *temp_tree = NULL, *root = NULL;
    queueNode *fnode = NULL, *rnode = NULL, *temp_queue = NULL;

    void Insert(int x)
    {
        temp_tree = new TreeNode;
        temp_tree->info = x;
        temp_tree->lc = temp_tree->rc = NULL;

        temp_queue = new queueNode;
        temp_queue->temp = temp_tree;
        temp_queue->next = NULL;
        temp_queue->flag = 0;

        if(root == NULL)
        {
            root = temp_tree;
            fnode = rnode = temp_queue;
        }
        else
        {
            if (fnode->flag == 0)
            {
                fnode->temp->lc = temp_tree;
                fnode->flag = 1;
            }
            else
            {
                fnode->temp->rc = temp_tree;
                fnode = fnode->next;
            }

            rnode->next = temp_queue;
            rnode = temp_queue;
        }

    }


    void Preorder_Traversal(  TreeNode *temp_root )
    {
        if(temp_root == NULL)
            return;
        else
        {
            cout<<temp_root->info<<" ";
            Preorder_Traversal(temp_root->lc);
            Preorder_Traversal(temp_root->rc);
        }
    }

    void Post_Order_Traversal( TreeNode *temp_root )
    {
        if(temp_root == NULL)
            return;
        else
        {
            Post_Order_Traversal(temp_root->lc);
            Post_Order_Traversal(temp_root->rc);
            cout<<temp_root->info<<" ";
        }
    }

    void Inorder_Traversal( TreeNode *temp_root )
    {
        if(temp_root == NULL)
            return;
        else
        {
            Inorder_Traversal(temp_root->lc);
            cout<<temp_root->info<<" ";
            Inorder_Traversal(temp_root->rc);
        }
    }
};




int main()
{
    Trees t;
    t.Insert(2);
    t.Insert(3);
    t.Insert(4);
    t.Insert(7);
    t.Insert(6);
    t.Insert(5);
    t.Insert(1);
    cout<<"Preorder_Traversal = \n";
    cout<<"\n---------------------------\n";
    t.Preorder_Traversal(t.root);
    cout<<"\n---------------------------\n";
    cout<<"Post_Order_Traversal = \n";
    cout<<"\n---------------------------\n";
    t.Post_Order_Traversal(t.root);
    cout<<"\n---------------------------\n";
    cout<<"Inorder_Traversal = \n";
    cout<<"\n---------------------------\n";
    t.Inorder_Traversal(t.root);
    cout<<"\n---------------------------\n";
    return 0;
}
