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
    int counter[100] = {0};
    void Insert(int x,TreeNode *temp_root)
    {
        if(root == NULL)
        {
            temp_tree = new TreeNode;
            temp_tree->info = x;
            counter[x]++;
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
                    counter[x]++;
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
                    counter[x]++;
                    temp_tree->lc = temp_tree->rc = NULL;
                    temp_root->lc = temp_tree;
                }
                else
                    Insert(x,temp_root->lc);
            }
            else
            {
                //cout<<x<<" Already Exists\n";
                counter[x]++;
            }
        }
    }

    void Inorder_Traversal( TreeNode *temp_root )
    {
        if(temp_root == NULL)
            return;
        else
        {
            Inorder_Traversal(temp_root->lc);
            for(int i=0; i<counter[temp_root->info]; i++)
                cout<<temp_root->info<<" ";
            Inorder_Traversal(temp_root->rc);
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
    int a[] = {10,20,30,40,50,40,35,25,20,40,18,19,22,27,30,27};
    for(int i=0; i<16; i++)
        t.Insert(a[i],t.root);

    cout<<"Inorder Traversal : ";
    t.Inorder_Traversal(t.root);

    return 0;
}
