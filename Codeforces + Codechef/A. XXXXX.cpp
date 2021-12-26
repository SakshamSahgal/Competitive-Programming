#include<iostream>
#include<algorithm>
#include<vector>
#define usi unsigned short int
#define ui unsigned int
#define ulli unsigned long long int
using namespace std;
void vector_printer(vector<int> v1)
{
cout<<"\n--------\n";
for(int i=0;i<v1.size();i++)
    printf("%d ",(v1[i]));
cout<<"\n--------\n";
cout<<"\n";
}
int main()
{
//ios_base::sync_with_stdio(false);
//cin.tie(NULL);
//cout.tie(NULL);
usi t;
cin>>t;
while(t)
    {
    int n,x;
    cin>>n>>x;
    int a[n];
    int s = 0;
    bool all_div=1;
    int l,r;
    bool go = 1;
    for(int i=0;i<n;i++)
        {
        scanf("%d",&a[i]);
        s+=a[i];
        if(a[i]%x!=0)
            {
                if(go == 1)
                    {
                    l = i;
                    all_div = 0;
                    go = 0;
                    }
                r = i;
            }
        }
    //cout<<"l = "<<l<<"r = "<<r<<"\n";
    if(all_div == 1)
        cout<<"-1\n";
    else
        {
            if(s%x != 0)
                cout<<n<<"\n";
            else
                {
                cout<<n - min(l+1,n-r)<<"\n";
                }
        }
    t--;
    }



return 0;
}
