#include<iostream>
using namespace std;

struct TreeNode
{
    int info;
    TreeNode *lc,*rc;
};

class BST
{
public:
    TreeNode *root = NULL, *temp_tree = NULL;

    void Insert(int x,TreeNode *temp_root)
    {
        if(root == NULL)
        {
            temp_tree = new TreeNode;
            temp_tree->info = x;
            temp_tree->lc = temp_tree->rc = NULL;
            root = temp_tree;
        }
        else
        {
            if(temp_root->info < x) //goto RC
            {
                if(temp_root->rc == NULL)
                {
                    temp_tree = new TreeNode;
                    temp_tree->info = x;
                    temp_tree->lc = temp_tree->rc = NULL;
                    temp_root->rc = temp_tree;
                }
                else
                    Insert(x,temp_root->rc);
            }
            else if (temp_root->info > x) //got LC
            {
                if(temp_root->lc == NULL)
                {
                    temp_tree = new TreeNode;
                    temp_tree->info = x;
                    temp_tree->lc = temp_tree->rc = NULL;
                    temp_root->lc = temp_tree;
                }
                else
                    Insert(x,temp_root->lc);
            }
            else
                cout<<x<<" Already Exists\n";
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

    void Searching(int x,TreeNode *temp_root)
    {
        if(temp_root == NULL)
            cout<<x<<" NOT FOUND\n";
        else
        {
            if(temp_root->info < x) //goto RC
              Searching(x,temp_root->rc);
            else if(temp_root->info > x) //goto LC
              Searching(x,temp_root->lc);
            else
                cout<<"\n"<<x<<" FOUND \n";
        }
    }
};

int main()
{
    BST t;
    t.Insert(20,t.root);
    t.Insert(30,t.root);
    t.Insert(10,t.root);
    t.Insert(15,t.root);
    t.Inorder_Traversal(t.root);
    t.Searching(15,t.root);
    t.Searching(12,t.root);
    return 0;
}
