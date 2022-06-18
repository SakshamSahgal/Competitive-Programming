#include<iostream>
using namespace std;


struct AVLNode
{
    int Data;
    int Height;
    AVLNode *lc;
    AVLNode *rc;
};

class Queue_using_Linked_list //for Level_Order_Traversal
{

    struct Node
    {
        AVLNode *value;
        Node *link;
    };
public:
    Node *Front = NULL, *Rear = NULL, *temp = NULL;

    void enQueue(AVLNode *temp_root)
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

class AVL_Tree
{


public:

    AVLNode *root = NULL, *temp = NULL;
// check for emptyness

    int isEmpty()
    {
        return ((root == NULL)?1:0);
    }

    int height(AVLNode *temp_root)
    {
        return ( (temp_root == NULL)?0:temp_root->Height );
    }


    AVLNode* Create_Node(int val)
    {
        temp = new AVLNode;
        temp->Data = val;
        temp->Height = 0;
        temp->lc = temp->rc = NULL;
        return temp;
    }

    int GetHeightBalance(AVLNode *temp_root)
    {
        return ( (temp_root == NULL) ? 0 : ( height(temp_root->lc) - height(temp_root->rc) ) );
    }


    AVLNode* left_rotate(AVLNode* A)
    {
        AVLNode* AR = A->rc;
        AVLNode* ARL = AR->lc;

        AR->lc = A;
        A->rc = ARL;

        A->Height = max(height(A->lc),height(A->rc)) + 1;
        AR->Height = max(height(AR->lc),height(AR->rc)) + 1;

        return AR;
    }

    AVLNode* right_rotate(AVLNode *A)
    {
        AVLNode* AL = A->lc;
        AVLNode* ALR = AL->rc;

        AL->rc = A;
        A->lc = ALR;

        A->Height = max(height(A->lc),height(A->rc)) + 1;
        AL->Height = max(height(AL->lc),height(AL->rc)) + 1;

        return AL;
    }

    AVLNode* Insert(AVLNode *temp_root,int val)
    {
        if(temp_root == NULL)
            return Create_Node(val);
        else if( val < temp_root->Data )  //goto left child
            temp_root->lc = Insert(temp_root->lc,val);
        else if( val > temp_root->Data ) //goto right child
            temp_root->rc = Insert(temp_root->rc,val);
        else
        {
            cout<<val<<" Already Exists \n";
            return temp_root;
        }

        temp_root->Height = max(height(temp_root->lc),height(temp_root->rc)) + 1;
        int balance = GetHeightBalance(temp_root);


        if(balance > 1 && val < temp_root->lc->Data ) //ll rotation
            return right_rotate(temp_root);
        else if(balance < -1 && val > temp_root->rc->Data) //rr rotation
            return left_rotate(temp_root);
        else if(balance > 1 && val > temp_root->lc->Data) //lr rotation
        {
            temp_root->lc = left_rotate(temp_root->lc);
            return right_rotate(temp_root);
        }
        else if(balance < -1 && val < temp_root->rc->Data ) //rl rotation
        {
            temp_root->rc = right_rotate(temp_root->rc);
            return left_rotate(temp_root);
        }

        return temp_root;
    }

    void Traverse_Tree_Inorder(AVLNode *temp_root)
    {
        if(temp_root == NULL)
            return;
        else
        {
            Traverse_Tree_Inorder(temp_root->lc);
            cout<<temp_root->Data<<" \n";
            Traverse_Tree_Inorder(temp_root->rc);
        }
    }

    void Traverse_Tree_Postorder(AVLNode *temp_root)
    {
        if(temp_root == NULL)
            return;
        else
        {
            Traverse_Tree_Postorder(temp_root->lc);
            Traverse_Tree_Postorder(temp_root->rc);
            cout<<temp_root->Data<<" \n";
        }
    }

    void Traverse_Tree_Preorder(AVLNode *temp_root)
    {
        if(temp_root == NULL)
            return;
        else
        {
            cout<<temp_root->Data<<" \n";
            Traverse_Tree_Preorder(temp_root->lc);
            Traverse_Tree_Preorder(temp_root->rc);
        }
    }

    void Level_Order_Traversal(AVLNode *temp_root)
    {
        Queue_using_Linked_list q;
        q.enQueue(temp_root);

        while(!q.Empty())
        {
            cout<<q.Front->value->Data<<" ";
            if(q.Front->value->lc != NULL)
                q.enQueue(q.Front->value->lc);
            if(q.Front->value->rc != NULL)
                q.enQueue(q.Front->value->rc);
            q.Dequeue();
        }
    }

    void Searching(int x,AVLNode *temp_root)
    {
        if(temp_root == NULL)
            cout<<x<<" NOT FOUND\n";
        else
        {
            if(temp_root->Data < x) //goto RC
                Searching(x,temp_root->rc);
            else if(temp_root->Data > x) //goto LC
                Searching(x,temp_root->lc);
            else
                cout<<"\n"<<x<<" FOUND \n";
        }
    }

    AVLNode *Find_Min(AVLNode *temp_root)
    {
        if(temp_root == NULL)
            return temp_root;
        else
        {
            AVLNode *current = temp_root;
            while(current->lc != NULL)
                current = current->lc;

            return current;
        }
    }

    AVLNode* deleteNode(AVLNode* Temp_root, int key)
    {
        if (Temp_root == NULL)
            return root;
        if ( key < Temp_root->Data ) //goto lc
            Temp_root->lc = deleteNode(Temp_root->lc,key);
        else if( key > Temp_root->Data ) //goto rc
            Temp_root->rc = deleteNode(Temp_root->rc,key);
        else
        {
            if(Temp_root->lc == NULL && Temp_root->rc == NULL) //case 1
            {
                delete(Temp_root);
                Temp_root = NULL;
            }
            else if(Temp_root->lc == NULL)
            {
                AVLNode *temp = Temp_root;
                Temp_root = Temp_root->rc;
                delete temp;
            }
            else if(Temp_root->rc == NULL)
            {
                AVLNode *temp = Temp_root;
                Temp_root = Temp_root->lc;
                delete temp;
            }
            else
            {
                AVLNode *temp = Find_Min(Temp_root->rc);
                Temp_root->Data = temp->Data;
                Temp_root->rc = deleteNode(Temp_root->rc,temp->Data);
            }

        }

        // If the tree had only one node
        // then return
        if (Temp_root == NULL)
            return Temp_root;

        Temp_root->Height = max(height(Temp_root->lc),height(Temp_root->rc)) + 1;
        int balance = GetHeightBalance(Temp_root);

        // If this node becomes unbalanced,
        // then there are 4 cases
        if(balance > 1 && key < Temp_root->lc->Data ) //ll rotation
            return right_rotate(Temp_root);
        else if(balance < -1 && key > Temp_root->rc->Data) //rr rotation
            return left_rotate(Temp_root);
        else if(balance > 1 && key > Temp_root->lc->Data) //lr rotation
        {
            Temp_root->lc = left_rotate(Temp_root->lc);
            return right_rotate(Temp_root);
        }
        else if(balance < -1 && key < Temp_root->rc->Data ) //rl rotation
        {
            Temp_root->rc = right_rotate(Temp_root->rc);
            return left_rotate(Temp_root);
        }

        return Temp_root;
    }
};


int main()
{
    AVL_Tree t;
    cout<<"\n---------------\n";
    t.root = t.Insert(t.root,4);
    t.Level_Order_Traversal(t.root);
    cout<<"\n---------------\n";
    t.root = t.Insert(t.root,5);
    t.Level_Order_Traversal(t.root);
    cout<<"\n---------------\n";
    t.root = t.Insert(t.root,6);
    t.Level_Order_Traversal(t.root);
    cout<<"\n---------------\n";
    t.root = t.Insert(t.root,7);
    t.Level_Order_Traversal(t.root);
    cout<<"\n---------------\n";
    t.root = t.Insert(t.root,15);
    t.Level_Order_Traversal(t.root);
    cout<<"\n---------------\n";
    t.root = t.Insert(t.root,14);
    t.Level_Order_Traversal(t.root);
    cout<<"\n---------------\n";
    t.root = t.Insert(t.root,13);
    t.Level_Order_Traversal(t.root);
    cout<<"\n---------------\n";

    t.Searching(20,t.root);
    t.Searching(7,t.root);
    cout<<"\n-----Inorder Traversal---------\n";
    t.Traverse_Tree_Inorder(t.root);

    cout<<"\n----Deleting 7---------\n";
    t.root = t.deleteNode(t.root,7);
    cout<<"\n---------------\n";
    t.Traverse_Tree_Inorder(t.root);
    return 0;
}
