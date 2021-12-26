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
    TreeNode *root = NULL,*temp_tree = NULL;
    queueNode *fnode= NULL,*rnode = NULL, *temp_queue = NULL;

    void Insert_Node(int x)
    {
        temp_tree = new TreeNode;
        temp_tree->info = x;
        temp_tree->lc = temp_tree->rc = NULL;

        if(root == NULL)
        {
            root = temp_tree;
            temp_queue = new queueNode;
            temp_queue->temp = root;
            temp_queue->next = NULL;
            temp_queue->flag = 0;
            fnode = rnode = temp_queue;
        }
        else
        {
            temp_queue = new queueNode;
            temp_queue->temp = temp_tree;
            temp_queue->next = NULL;
            temp_queue->flag = 0;

            if( fnode->flag == 0 ) //insert into left child
            {
                fnode->temp->lc = temp_tree;
                fnode->flag = 1;
                rnode->next = temp_queue;
                rnode = temp_queue;
            }
            else
            {
                fnode->temp->rc = temp_tree;
                rnode->next = temp_queue;
                rnode = temp_queue;
                fnode = fnode->next;
            }
        }
    }

    void Traverse_Tree_Preorder(TreeNode *temp_root)
    {
        if(temp_root == NULL)
            return;
        else
        {
            if(temp_root->info != -1)
                cout<<temp_root->info<<" \n";
            Traverse_Tree_Preorder(temp_root->lc);
            Traverse_Tree_Preorder(temp_root->rc);
        }
    }

    void Traverse_Tree_Inorder(TreeNode *temp_root)
    {
        if(temp_root == NULL)
            return;
        else
        {
            Traverse_Tree_Inorder(temp_root->lc);
            if(temp_root->info != -1)
                cout<<temp_root->info<<" \n";
            Traverse_Tree_Inorder(temp_root->rc);
        }
    }

    void Traverse_Tree_Postorder(TreeNode *temp_root)
    {
        if(temp_root == NULL)
            return;
        else
        {
            Traverse_Tree_Postorder(temp_root->lc);
            Traverse_Tree_Postorder(temp_root->rc);
            if(temp_root->info != -1)
                cout<<temp_root->info<<" \n";
        }
    }

};



int main()
{
    Trees t;
    t.Insert_Node(50);
    t.Insert_Node(35);
    t.Insert_Node(75);
    t.Insert_Node(25);
    t.Insert_Node(45);
    t.Insert_Node(60);
    t.Insert_Node(97);
    t.Insert_Node(8);
    t.Insert_Node(30);
    t.Insert_Node(-1);
    t.Insert_Node(-1);
    t.Insert_Node(-1);
    t.Insert_Node(-1);
    t.Insert_Node(-1);
    t.Insert_Node(-1);
    t.Insert_Node(4);
    cout<<"Inorder Traversal : \n";
    t.Traverse_Tree_Inorder(t.root);
    cout<<"Preorder Traversal : \n";
    t.Traverse_Tree_Preorder(t.root);
    cout<<"Postorder Traversal : \n";
    t.Traverse_Tree_Postorder(t.root);
    return 0;
}
