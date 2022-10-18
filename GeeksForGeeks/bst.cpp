#include<bits/stdc++.h>
#define lli long long int
#define ld long double
#define GO_FAST ios_base::sync_with_stdio(0);ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
// basic debugging macros
lli __i__,__j__;
lli inf = 9e18;
#define line_printer(l) cout<<"\n"; for(__i__=0;__i__<l;__i__++){cout<<"-";}cout<<endl;
#define array_printer(a,l) cout<<#a<<": ";for(__i__=0;__i__<l;__i__++){cout<<a[__i__]<<" ";}cout<<"\n";
#define array_2d_printer(a,r,c) cout<<"\n"<<#a<<":\n";for(__i__=0;__i__<r;__i__++){for(__j__=0;__j__<c;__j__++){cout<<a[__i__][__j__]<<" ";}cout<<"\n";}
using namespace std;

//remember to use endl instead of \n for interactive problems.



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

    bool search_it(TreeNode *Temp_root,int data)
    {
        if(Temp_root == NULL)
            return false;
        else
        {
            if(Temp_root->info == data)
                return true;
            else if(Temp_root->info < data)
                return search_it(Temp_root->rc,data);
            else
                return search_it(Temp_root->lc,data);
        }
    }

    bool dfs(TreeNode *Temp_root,int target)
    {
        if(Temp_root == NULL)
            return false;

        int to_search = target - Temp_root->info;
        if(search_it(root,to_search))
            return true;

        if(dfs(Temp_root->lc,target) || dfs(Temp_root->rc,target) )
            return true;
        else
            false;
    }
};

int main()
{
    //GO_FAST
    //freopen("input.txt", "r", stdin);
    //freopen("myout.txt", "w", stdout);
    BST t;
    t.Insert(4,t.root);
    t.Insert(2,t.root);
    t.Insert(6,t.root);
    t.Insert(1,t.root);
    t.Insert(3,t.root);
    t.Insert(5,t.root);
    t.Insert(7,t.root);
    t.Preorder_Traversal(t.root);
    int target;
    cin>>target;
    cout<<"\n";
    //cout<<t.search_it(t.root,7);
    cout<<t.dfs(t.root,target)<<"\n";

    return 0;
}

