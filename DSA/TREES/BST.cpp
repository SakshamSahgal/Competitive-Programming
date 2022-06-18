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

    TreeNode *Find_Max(TreeNode *temp_root)
    {
        if(temp_root == NULL)
            return temp_root;
        else
        {
            TreeNode *current = temp_root;
            while(current->rc != NULL)
                current = current->rc;

            return current;
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

    t.Insert(12,t.root);
    t.Insert(15,t.root);
    t.Insert(17,t.root);
    t.Insert(20,t.root);
    t.Insert(18,t.root);
    t.Insert(13,t.root);
    t.Insert(14,t.root);
    t.Insert(5,t.root);
    t.Insert(7,t.root);
    t.Insert(9,t.root);
    t.Insert(11,t.root);
    t.Insert(8,t.root);
    t.Insert(3,t.root);
    t.Insert(1,t.root);
    cout<<"\n-------------initial tree-------------------\n";
    t.Inorder_Traversal(t.root);
    cout<<"\n------------------deleting 7----------------\n";
    t.root = t.Delete_Node(t.root,7);
    t.Inorder_Traversal(t.root);
    cout<<"\n-----------inserting 27---------------------\n";
    t.Insert(27,t.root);
    t.Inorder_Traversal(t.root);
    cout<<"\n------------------deleting 5----------------\n";
    t.root = t.Delete_Node(t.root,5);
    t.Inorder_Traversal(t.root);
    cout<<"\n-----------inserting 6---------------------\n";
    t.Insert(6,t.root);
    t.Inorder_Traversal(t.root);
    cout<<"\n--------------------------------------------\n";
    return 0;
}
