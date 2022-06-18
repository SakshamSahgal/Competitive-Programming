#include<iostream>
using namespace std;

struct TreeNode
{
    int info;
    TreeNode *lc,*rc;
};

int ans[9];
int index=0;
class BST
{
public:
    TreeNode *root = NULL, *temp_tree = NULL;

    TreeNode *create_Node(int x)
    {
        temp_tree = new TreeNode;
        temp_tree->info = x;
        temp_tree->lc = temp_tree->rc = NULL;
        return temp_tree;
    }

    void Insert(int x,TreeNode *temp_root)
    {
        if(root == NULL)
            root = create_Node(x);
        else
        {
            if(temp_root->info < x) //goto RC
            {
                if(temp_root->rc == NULL)
                    temp_root->rc = create_Node(x);
                else
                    Insert(x,temp_root->rc);
            }
            else if (temp_root->info > x) //got LC
            {
                if(temp_root->lc == NULL)
                    temp_root->lc = create_Node(x);
                else
                    Insert(x,temp_root->lc);
            }
            else
                cout<<x<<" Already Exists\n";
        }
    }

    void Inorder_Traversal( TreeNode *temp_root )
    {
        if(temp_root == NULL)
            return;
        else
        {
            Inorder_Traversal(temp_root->lc);
            //cout<<temp_root->info<<" ";
            ans[index++] = temp_root->info;
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


    TreeNode *Find_Min(TreeNode *temp_root)
    {
        if(temp_root == NULL)
            return temp_root;
        else
        {
            TreeNode *current = temp_root;
            while(current->lc != NULL)
                current = current->lc;

            return current;
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

    TreeNode *Delete_Node(TreeNode *Temp_root,int data)
    {
        if(Temp_root == NULL)
            return Temp_root;

        else if(data < Temp_root->info ) Temp_root->lc = Delete_Node(Temp_root->lc,data);
        else if(data > Temp_root->info) Temp_root->rc = Delete_Node(Temp_root->rc,data);
        else
        {
            if(Temp_root->lc == NULL && Temp_root->rc == NULL) //case 1
            {
                delete(Temp_root);
                Temp_root = NULL;
            }
            else if(Temp_root->lc == NULL)
            {
                TreeNode *temp = Temp_root;
                Temp_root = Temp_root->rc;
                delete temp;
            }
            else if(Temp_root->rc == NULL)
            {
                TreeNode *temp = Temp_root;
                Temp_root = Temp_root->lc;
                delete temp;
            }
            else
            {
                TreeNode *temp = Find_Min(Temp_root->rc);
                Temp_root->info = temp->info;
                Temp_root->rc = Delete_Node(Temp_root->rc,temp->info);
            }
        }
        return Temp_root;
    }

};

int main()
{
    BST t;
    int a[] = {50,30,70,40,35,60,90,80,85};
    for(int i=0;i<9;i++)
        t.Insert(a[i],t.root);
    cout<<"Initial Order Of INSERTION into BST = \n\n";
    for(int i=0;i<9;i++)
        cout<<a[i]<<" ";
    cout<<"\n\n";
    cout<<"ITs post Order Traversal - \n";

    cout<<"\n--------------------------------\n";
    t.Post_Order_Traversal(t.root);
    cout<<"\n--------------------------------\n\n";

    cout<<"DELETING NODE "<<85<<"\n\n";
    t.Delete_Node(t.root,85);
    cout<<"inserting 45\n";
    t.Insert(45,t.root);
    cout<<"\n------The new Post-Order Traversal is = ----------\n";
    t.Post_Order_Traversal(t.root);
    cout<<"\n------------------------------------------------\n\n";
    cout<<"\n------The new Pre-Order Traversal is = ----------\n";
    t.Preorder_Traversal(t.root);
    cout<<"\n------------------------------------------------\n\n";
    cout<<"Now keys in BST in decending order = \n\n";
    t.Inorder_Traversal(t.root);
    cout<<"\n------------------------------------------------\n";
    for(int i=8;i>=0;i--)
        cout<<ans[i]<<" ";
    cout<<"\n------------------------------------------------\n";

    return 0;
}

