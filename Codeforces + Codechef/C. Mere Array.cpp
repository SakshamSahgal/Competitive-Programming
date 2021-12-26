#include<iostream>
#include<algorithm>
#include<vector>
#include<unordered_map>
#define usi unsigned short int
#define ui unsigned int
#define ulli unsigned long long int
#define lli long long int
using namespace std;

int Eular_GCD(int a,int b)
{
    int temp;
    if(a!=0 && b!=0)
    {
x:
        if(a == 0)
            return b;
        else if(b == 0)
            return a;
        else
        {
            temp = a;
            a = b;
            b = temp%b;
            goto x;
        }
    }
    else
        return max(a,b);
}

void vector_printer( vector<int> v)
{
    cout<<"\n------------------------\n";
    for(int i=0; i<v.size(); i++)
        cout<<v[i]<<" ";
    cout<<"\n------------------------\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t)
    {
        int n;
        cin>>n;
        int a[n];
        int b[n];
        for(int i=0; i<n; i++)
        {
            cin>>a[i];
            b[i] = a[i];
        }

        if(n == 1)
        {
            cout<<"YES\n";
            goto j;
        }
        else
        {
            sort(b,b+n);
            vector <int> x;
            for(int i=0; i<n; i++)
            {
                if(Eular_GCD(a[i],b[0]) == b[0])
                {
                    x.push_back(a[i]);
                    a[i] = -1;
                }
            }

            sort(x.begin(),x.end());

            for(int i=0,j=0; i<n; i++)
            {
                if(a[i] == -1)
                {
                    a[i] = x[j];
                    j++;
                }
                if(a[i] != b[i])
                {
                    cout<<"NO\n";
                    goto j;
                }
            }
            cout<<"YES\n";
        }
j:
        t--;
    }

    return 0;
}
