#include<iostream>
#include<algorithm>
#define usi unsigned short int
#define ui unsigned int
#define ulli unsigned long long int
#define lli long long int
using namespace std;

void Bubble_Sort(int n, pair<int,int> a[])
{
    bool check=0;
    pair <int,int> temp;
    for(int i=1; i<n; i++)
    {
        check=0;
        for(int j=0; j<=(n-1-i); j++)
        {
            if( a[j].first < a[j+1].first && a[j].second == 0 && a[j+1].second == 0 )
            {
                temp = a[j+1];
                a[j+1] = a[j];
                a[j] = temp;
                check=1;
            }

        }

        if(check == 0)
            break;
    }
}

int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);
    usi t;
    cin>>t;
    while(t)
    {
        int n;
        cin>>n;
        bool all_p=1;
        pair<int,int> a[n];
        for(int i=0; i<n; i++)
            {
            cin>>a[i].first;
            if(a[i].first < 0)
                all_p=0;
            }


        for(int i=0; i<n; i++)
            cin>>a[i].second;

        if(all_p == 0)
            Bubble_Sort(n,a);


        /*
        cout<<"\n---\n";
        for(int i=0; i<n; i++)
            cout<<a[i].first<<" ";
        cout<<"\n";
        for(int i=0; i<n; i++)
            cout<<a[i].second<<" ";;
        cout<<"\n---\n";


        int prefix[n] = {0};
        int sum=0;
        cout<<"\nprefix = \n";
        for(int i=0;i<n;i++)
        {
        sum +=a[i].first;
           prefix[i] = sum;
           cout<<prefix[i]<<" ";
        }
        */
         for(int i=0;i<n;i++)
          cout<<a[i].first<<" ";
    cout<<"\n";

        t--;
    }

    return 0;
}

