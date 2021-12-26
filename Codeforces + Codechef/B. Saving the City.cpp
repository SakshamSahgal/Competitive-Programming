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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t)
    {
        int a,b;
        cin>>a>>b;
        string s;
        cin>>s;
        int c=0;
        int noone=0;
        //int nozbtw=0;
        vector<pair<int,int>> freq;
        for(int i=0; i<s.size(); i++)
        {
            c=0;
            if(s[i] == '1')
            {
                noone++;
                int k=i;
                while(s[k]== '1' && k<s.size())
                {
                    c++;
                    k++;
                }

                freq.push_back(make_pair(1,c));
                i = k-1;
            }
            else
            {

                int k=i;
                while(s[k]=='0' && k<s.size())
                {
                    c++;
                    k++;
                }

                //nozbtw+=c;

                freq.push_back(make_pair(0,c));
                i = k-1;
            }
        }
            /*
        cout<<"\n------------------------\n";

        for(int i=0; i<freq.size(); i++)
            cout<<freq[i].first<<" ";

        cout<<"\n";

        for(int i=0; i<freq.size(); i++)
            cout<<freq[i].second<<" ";

        cout<<"\n------------------------\n"; */


        // if(freq[freq.size()-1].first == 0 )
        // nozbtw-=freq[freq.size()-1].second;

        //if(freq[0].first == 0)
        //nozbtw -= freq[0].second;

        // nozbtw = max(0,nozbtw);
       // cout<<"no of distinct one = "<<noone<<"\n";
        //cout<<"no of zero btw = "<<nozbtw<<"\n";
        if(noone == 0)
            cout<<"0\n";
        else if(noone == 1)
            cout<<a<<"\n";
        else
        {
            lli sum=0;
            bool found =0;
            for(int i=0; i<freq.size()-2; i++)
            {
                if(found == 0)
                {
                    if(freq[i].first == 1 && freq[i+1].first == 0 && freq[i+2].first == 1)
                    {
                        found = 1;
                        sum+= min(2*a,a+(b*freq[i+1].second));
                        //cout<<sum<<" \n";
                    }
                }
                else
                {
                    if(freq[i].first == 1 && freq[i+1].first == 0 && freq[i+2].first == 1)
                    {
                        sum+=min(a,b*freq[i+1].second);
                    }
                    //cout<<sum<<" \n";
                }
            }
            cout<<sum<<"\n";
        }


        t--;
    }

    return 0;
}
