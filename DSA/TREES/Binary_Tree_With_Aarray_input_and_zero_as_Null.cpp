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


class Trees
{
public:
    TreeNode *temp_tree = NULL, *root = NULL;
    queueNode *fnode = NULL, *rnode = NULL, *temp_queue = NULL;

    void Insert(int x)
    {
        if(x != 0)
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
        else
        {
            if (fnode->flag == 0)
            {
                fnode->temp->lc = NULL;
                fnode->flag = 1;
            }
            else
            {
                fnode->temp->rc = NULL;
                fnode = fnode->next;
            }
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

int main()
{
    int a[] = {1,2,3,4,5,6,7,0,8,9,0,0,0,10,11,12,13,0,14,15,0,16,17};
    Trees t;

    for(int i=0;i< sizeof(a)/sizeof(int) ;i++)
        t.Insert(a[i]);

    cout<<"\nPre-Order : ";
    t.Preorder_Traversal(t.root);
    cout<<"\nIn-Order : ";
    t.Inorder_Traversal(t.root);
    cout<<"\nPost-Order : ";
    t.Post_Order_Traversal(t.root);
    cout<<"\nLevel-Order : ";
    t.Level_Order_Traversal(t.root);
    return 0;
}

