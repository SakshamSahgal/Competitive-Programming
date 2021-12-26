#include<iostream>
#include<algorithm>
#include<vector>
#define usi unsigned short int
#define ui unsigned int
#define ulli unsigned long long int
#define lli long long int
using namespace std;
int main()
{
//ios_base::sync_with_stdio(false);
//cin.tie(NULL);
//cout.tie(NULL);
    usi t;
    cin>>t;
    while(t--)
    {
        int n;
        lli s;
        cin>>n>>s;
        lli a[n];
        vector<lli> s1;
        vector <lli> s2;
        lli s1_max=0;
        lli s_tot=0;
        lli s1_i=0;
        bool close1=0;
        bool close2=0;
        lli sum1=0;
        lli sum2=0;
        for(int i=0; i<n; i++)
        {

            cin>>a[i];
            s_tot+=a[i];
            if(close1 == 0)
            {
                sum1+=a[i];
                s1.push_back(a[i]);
                if(a[i] > s1_max)
                {
                    s1_max = a[i];
                    s1_i = i;
                }
                if(sum1<= s)
                {

                }
                else
                    close1=1;
            }
            if(close2 == 0 && i>0)
            {

                sum2+=a[i];
                s2.push_back(a[i]);

                if(sum2 + a[i] <= s)
                {
                }
                else
                    close2=1;
            }
        }

        if(s_tot <= s)
            cout<<0<<"\n";
        else
        {
            cout<<"\n------------------\n";
            for(int i=0; i<s1.size(); i++)
                cout<<s1[i]<<" ";
            cout<<"\n";

            for(int i=0; i<s2.size(); i++)
                cout<<s2[i]<<" ";
            cout<<"\n------------------\n";

            lli temp1 = sum1-a[s1_i];
            cout<<temp1<<"\n";
            int k=0;
            for(int j=s1.size(); j<n; j++)
            {
                if(temp1 + a[j] <= s)
                {
                    k++;
                    temp1+=a[j];
                }
                else
                    break;
            }
            cout<<"added in s1 = "<<k<<"\n";

            if(k>=1)
                cout<<s1_i+1<<"\n";
            else
            {
                if(s1.size() > s2.size())
                    cout<<s1.size()+1<<"\n";
                else
                    cout<<0<<"\n";
            }

        }

    }


    return 0;
}

