#include<iostream>
#include<algorithm>
#define usi unsigned short int
#define ui unsigned int
#define ulli unsigned long long int
#define lli long long int
using namespace std;
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
        lli s;
        cin>>n>>s;
        lli a[n];
        lli s1=0;
        lli m1=0;
        lli s2=0;
        lli m2=0;
        lli sum=0;
        lli s1_length=0;
        lli s2_length=0;
        lli max_index1=0;
        lli max_index2=0;
        bool close1=0;
        bool close2=0;
        for(int i=0; i<n; i++)
        {
            cin>>a[i];

            sum+=a[i];

            if(close1 == 0)
            {
                s1+=a[i];
                if(a[i]>m1)
                {
                    s1_length++;
                    m1 = a[i];
                    max_index1 = i;
                }

                if(s1>=s)
                    close1 = 1;
            }

            if(close2 == 0 && i>0)
            {
                s2_length++;
                s2+=a[i];
                if(a[i] > m2)
                {
                    m2 = a[i];
                    max_index2 = i;
                }

                if(s2>=s)
                    close2=1;
            }
        }

        if(sum<=s)
        {
            cout<<0<<"\n";
        }
        else
        {
           cout<<" s1 = "<<s1<<" m1 = "<<m1<<" s2 = "<<s2<<" m2 = "<<m2<<"\n";
            cout<<"max index1 = "<<max_index1<<" maxi index 2 = "<<max_index2<<"\n";
            cout<<"s1 length = "<<s1_length<<" "<<"s2 length = "<<s2_length<<"\n";
            if(max_index1 == max_index2)
                cout<<max_index1+1<<"\n";
            else if(max_index1 == 0 )
            {
                if(s1_length >= s2_length)
                    cout<<0<<"\n";
                else
                    cout<<1<<"\n";
            }
            else
            {
                if(a[max_index2] > a[max_index1])
                    cout<<max_index2+1<<"\n";
                else
                    cout<<max_index1+1<<"\n";
            }

        }

        t--;
    }

    return 0;
}

