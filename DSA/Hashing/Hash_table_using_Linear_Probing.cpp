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

struct Element
{
    int value=0;
    bool occupied=0;
};

class Hash_table
{
    int sz;
    Element *x;

    public:
    Hash_table(int sizze)
    {
        sz = sizze;
        x = new Element[sizze];
    }

    void Insert_using_Linear_Probing(int key)
    {
        if(x[key%9].occupied == 0)
        {
            x[key%9].value = key;
            x[key%9].occupied = 1;
        }
        else
        {
            int i=1;
            while(x[((key%9) + i)%sz].occupied != 0)
                i++;

            x[((key%9) + i)%sz].value = key;
            x[((key%9) + i)%sz].occupied = 1;
        }
    }

    void Display_Hash_Table()
    {
        cout<<"\n-----------------------\n";
        for(int i=0; i<10; i++)
        {
            if(x[i].occupied == 0)
                cout<<"NULL"<<" "<<x[i].occupied<<"\n";
            else
                cout<<x[i].value<<" "<<x[i].occupied<<"\n";
        }
        cout<<"\n-----------------------\n";
    }


};

int main()
{
    Hash_table h(10);
    int n;
    cout<<"Enter no of Keys : ";
    cin>>n;
    cout<<"Enter Keys : ";
    for(int i=0;i<n;i++)
    {
        int k;
        cin>>k;
        h.Insert_using_Linear_Probing(k);
    }
    h.Display_Hash_Table();
    return 0;
}

