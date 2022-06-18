#include<iostream>
using namespace std;

struct TreeNode
{
    char info;
    TreeNode *lc,*rc;
};

struct queueNode
{
    TreeNode *temp;
    queueNode *next;
    bool flag; //0 ->insert right child ... //1->insert left child
};

class Queue_using_Linked_list //for Zic-Zac Traversal
{
    struct Node
    {
        TreeNode *value;
        Node *link;
    };
public:

    Node *Front = NULL, *Rear = NULL, *temp = NULL;

    void enQueue(TreeNode *x)
    {
        temp = NULL;
        temp = new Node;
        temp->value = x;
        temp->link = NULL;

        if(temp == NULL)
            cout<<"Overflow\n";
        else
        {
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

    void Printer()
    {
        temp = Front;
        while(temp != NULL)
        {
            cout<<temp->value->info<<" ";
            temp = temp->link;
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

class Stack_Using_Linked_List //for Zic-Zac Traversal
{
    struct Node
    {
        TreeNode *value;
        Node *link;
    };

public:
    Node *top = NULL, *temp = NULL;
    void push(TreeNode *x)
    {
        temp = NULL;
        temp = new Node;
        temp->value = x;
        temp->link = NULL;
        if(top == NULL)
            top = temp;
        else
        {
            temp->link = top;
            top = temp;
        }
    }

    void pop()
    {
        if(top == NULL)
            cout<<"Underflow\n";
        else
        {
            temp = top;
            top = top->link;
            delete(temp);
        }
    }

    void Printer()
    {
        temp = top;

        while(temp != NULL)
        {
            cout<<temp->value->info<<" ";
            temp = temp->link;
        }
    }
};


class Trees
{
public:
    TreeNode *temp_tree = NULL, *root = NULL;
    queueNode *fnode = NULL, *rnode = NULL, *temp_queue = NULL;

    void Insert(char x)
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

    void Spiral_Travarsal(TreeNode *temp_root)
    {
        if(root == NULL)
            return;
        else
        {
            bool left_to_right = 1;
            Queue_using_Linked_list Nodes_Queue;
            Nodes_Queue.enQueue(temp_root);

            while(!Nodes_Queue.Empty())
            {
                Queue_using_Linked_list temp_Q; //Creating a temperory Queue to Store current Queue State
                Stack_Using_Linked_List temp_Stack; //Creating a temperory Stack
                Nodes_Queue.temp  = Nodes_Queue.Front;

                while(Nodes_Queue.temp != NULL)  //copying current state of queue in a temp queue
                {
                    temp_Q.enQueue(Nodes_Queue.temp->value);
                    Nodes_Queue.temp = Nodes_Queue.temp->link;
                }
                temp_Q.temp = temp_Q.Front;
                while( temp_Q.temp != NULL)
                {
                    if(left_to_right)
                        cout<<temp_Q.temp->value->info<<" ";
                    else
                        temp_Stack.push( temp_Q.temp->value );

                    if(temp_Q.temp->value->lc != NULL)
                        Nodes_Queue.enQueue(temp_Q.temp->value->lc);
                    if(temp_Q.temp->value->rc != NULL)
                        Nodes_Queue.enQueue(temp_Q.temp->value->rc);
                    Nodes_Queue.Dequeue();
                    temp_Q.temp = temp_Q.temp->link;
                }

                if(!left_to_right)
                    temp_Stack.Printer();

                left_to_right = !left_to_right;
            }
        }
    }

};

int main()
{
    char a[] = {'A','B','C','D','E','F','G','H','I'};
    Trees t;
    for(int i=0; i<sizeof(a)/sizeof(char); i++)
        t.Insert(a[i]);

    t.Spiral_Travarsal(t.root);
    return 0;
}
