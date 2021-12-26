#include<iostream>
#include<algorithm>
#define usi unsigned short int
#define ui unsigned int
#define ulli unsigned long long int
#define lli long long int
using namespace std;
bool string_checker(string s1,string s2)
{
    //k1>k2
    int k1 = s1.length();
    int k2 = s2.length();
    bool ne = 0;
    for(int i=0; i<(k1-k2+1); i++)
    {
        ne = 0;
        //cout<<"i = "<<i<<"\n";
        for(int j=i,k=0; j<k1,k<k2; j++,k++)
        {
           // cout<<"s1[j] = "<<s1[j]<<" s2[k] = "<<s2[k]<<"\n";
            if(s2[k] != s1[j])
            {
                ne = 1;
                break;
            }
        }
        if(ne == 0)
            return 1;
    }
    return 0;
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
        string s1,s2;

        cin>>s1>>s2;
        int k = min(s1.length(),s2.length());
        for(int i=k; i>=1; i--)
        {
            //cout<<"length = "<<i<<"\n";
            for(int j=k-i,st=0,ed=st+i-1; j>=0; j--,st++,ed++)
            {
                string temp;


                //cout<<"st = "<<st<<" ed = "<<ed;
                for(int l=st; l<=ed; l++)
                {
                    if(s2.length() < s1.length())
                        temp += s2[l];
                    else
                        temp += s1[l];
                }


                //cout<<" temp = "<<temp<<"\n";

                if(s2.length() < s1.length())
                {
                    if(string_checker(s1,temp))
                    {
                        cout<< s1.length() - temp.length() + s2.length()-temp.length()<<"\n";
                        goto h;
                    }
                }
                else
                {
                    if(string_checker(s2,temp))
                    {
                        cout<< s1.length() - temp.length() + s2.length()-temp.length()<<"\n";
                        goto h;
                    }
                }

            }
        }

        cout<<(s1.length() + s2.length())<<"\n";
h:
        t--;
    }

    return 0;
}

