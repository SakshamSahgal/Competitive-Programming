#include<iostream>
#include<cstring>
#include<vector>
#include<set>
#include<map>
#include<algorithm>
#include<cmath>
#include<climits>
#define lli long long int
#define GO_FAST ios_base::sync_with_stdio(0);ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
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
    int max_sum=0;

    void Max_sum_DFS(TreeNode *temp_root,int sum)
    {
        if(temp_root == NULL)
            return;

        sum += temp_root->info;
        //cout<<"Sum till "<<temp_root->info<<" = "<<sum<<"\n";
        max_sum = max(sum,max_sum);
        Max_sum_DFS(temp_root->lc,sum);
        Max_sum_DFS(temp_root->rc,sum);
    }
};

int main()
{
    int a[] = {1,2,3,4,5,6,7,0,8,9,0,0,0,10,11,12,13,0,14,15,0,16,17};
    Trees t;

    for(int i=0; i< sizeof(a)/sizeof(int) ; i++)
        t.Insert(a[i]);

    t.Max_sum_DFS(t.root,0);
    cout<<"\nMax Sum DFS : "<<t.max_sum<<"\n";
    return 0;
}


