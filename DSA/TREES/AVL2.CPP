#include<iostream>
using namespace std;

struct AVLNode
{
    int info;
    int Height;
    AVLNode *lc;
    AVLNode *rc;
};

class AVL_Tree
{
    AVLNode *root = NULL,*temp = NULL;

    bool is_Empty()
    {
        return( (root == NULL) ? 1 : 0);
    }

    int Height(AVLNode *temp_root)
    {
        return( temp_root == NULL ) ? 0 : temp_root->Height;
    }

    AVLNode *Create_Node(int x)
    {
        temp = new AVLNode;
        temp->info = x;
        temp->lc = temp->rc = NULL;
        temp->Height = 0;
        return temp;
    }

    int GetHeightBalance(AVLNode *temp_root)
    {
        return( temp_root == NULL ) ? 0 : (Height(temp_root->lc) - Height(temp_root->rc));
    }

    AVLNode *Insert(AVLNode *temp_Root, int val)
    {
        if(temp_Root == NULL)
         return Create_Node(val);
        else if(val < temp_Root->info ) //lc
         temp_Root->lc = Insert(temp_Root->lc,val);
        else if(val > temp_Root->info ) //rc
         temp_Root->rc = Insert(temp_Root->rc,val);
        else
        {
            cout<< val <<" already exist \n";
            return temp_Root;
        }
        temp_Root->Height = max(Height(temp_Root->lc),Height(temp_Root->rc)) + 1;
        int balance = GetHeightBalance(temp_Root);

        if(balance > 1 ) //ll lr

        return temp_Root;
    }


};

int main()
{
    AVL_Tree t;
    t.root = t.Insert(t.root,10);
    return 0;
}
