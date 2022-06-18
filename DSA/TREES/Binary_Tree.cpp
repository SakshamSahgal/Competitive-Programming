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

////////////////////////////////////////////////////////////////////////////////////////



class Queue_using_Linked_list //for Level_Order_Traversal
{

    struct Node
    {
        TreeNode *value;
        Node *link;
    };
    public:
    Node *Front = NULL, *Rear = NULL, *temp = NULL;

    void enQueue(TreeNode *temp_root)
    {
        temp = NULL;
        temp = new Node;
        temp->value = temp_root;
        temp->link = NULL;

        if(Front == NULL && Rear == NULL)
        {
            Front = temp;
            Rear = temp;
        }
        else
        {
            Rear->link = temp;
            Rear = temp;
        }

    }

    void Dequeue()
    {
        if(Front == NULL)
            cout<<"UnderFlow\n";
        else if(Front == Rear)
            Front = Rear = NULL;
        else
        {
            temp = Front;
            Front = Front->link;
            delete(temp);
        }
    }

    bool Empty()
    {
        if(Front == NULL)
            return 1;
        else
            return 0;
    }
};

//////////////////////////////////////////////////////////////////////////////////////////////

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
            cout<<temp_root->info<<" \n";
        }
    }

    void Level_Order_Traversal(TreeNode *temp_root)
    {
        Queue_using_Linked_list q;
        q.enQueue(temp_root);

        while(!q.Empty())
        {
            cout<<q.Front->value->info<<" ";
            if(q.Front->value->lc != NULL)
                q.enQueue(q.Front->value->lc);
            if(q.Front->value->rc != NULL)
                q.enQueue(q.Front->value->rc);
            q.Dequeue();
        }
    }
};
//////////////////////////////////////////////////////////////////////////////////////////////

int main()
{
    Trees t;
    t.Insert_Node(1);
    t.Insert_Node(2);
    t.Insert_Node(3);
    t.Insert_Node(4);
    t.Insert_Node(5);
    t.Insert_Node(6);
    t.Insert_Node(7);
    cout<<"Preorder Traversal : \n";
    t.Traverse_Tree_Preorder(t.root);
    cout<<"Inorder Traversal : \n";
    t.Traverse_Tree_Inorder(t.root);
    cout<<"Postorder Traversal : \n";
    t.Traverse_Tree_Postorder(t.root);
    cout<<"LevelOrder Traversal : \n";
    t.Level_Order_Traversal(t.root);
    return 0;
}
