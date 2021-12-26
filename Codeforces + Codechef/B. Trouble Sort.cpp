#include<iostream>
#include<algorithm>
#include<climits>
#define usi unsigned short int
#define ui unsigned int
#define ulli unsigned long long int
#define lli long long int
using namespace std;
struct Trouble
{
    int value;
    bool type;
};
int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    usi t;
    cin>>t;
    while(t)
    {
        usi n;
        cin>>n;
        Trouble Elements[n];
        int a[n];
        for(int i=0;i<n;i++)
            {
             cin>>Elements[i].value;
            a[i] = Elements[i].value;
            }


        sort(a,a+n);
        bool all_Same = 1;
        for(int i=0; i<n; i++)
            {
             cin>>Elements[i].type;

            if(Elements[i].type != Elements[0].type )
                {
                all_Same = 0;
                }
            }

            if(all_Same == 0)
                cout<<"Yes\n";
            else
                {
                bool no=0;
                for(int i=0;i<n;i++)
                    {
                        if(a[i] != Elements[i].value)
                            {
                                no=1;
                                break;
                            }
                    }
                if(no == 1)
                 cout<<"No\n";
                else
                cout<<"Yes\n";
                }
        t--;
    }


    return 0;
}

