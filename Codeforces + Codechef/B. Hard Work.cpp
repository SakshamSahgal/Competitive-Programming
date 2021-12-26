#include<iostream>
#include<string>
#include<vector>
#include<set>
#include<map>
#include<algorithm>
#include<cmath>
#include<climits>
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

        string s1,s2,s3;
        cin>>s1>>s2>>s3;
        string a,b,c;
        for(int i=0;i<max(s1.length(),max(s2.length(),s3.length()));i++)
            {
                if( i < s1.length() && s1[i] != ';' && s1[i] != '_' && s1[i] != '-')
                {
                    if(s1[i] >= 65 && s1[i] <= 90) //capital
                            a+= (s1[i] + 32);
                        else
                            a += s1[i];
                }


                if( i < s2.length() && s2[i] != ';' && s2[i] != '_' && s2[i] != '-')
                {
                    if(s2[i] >= 65 && s2[i] <= 90) //capital
                            b += (s2[i] + 32);
                        else
                            b += s2[i];
                }

                if( i < s3.length() && s3[i] != ';' && s3[i] != '_' && s3[i] != '-')
                {
                    if(s3[i] >= 65 && s3[i] <= 90) //capital
                            c += (s3[i] + 32);
                        else
                            c += s3[i];
                }
            }

        int n;
        cin>>n;

        for(int i=0;i<n;i++)
            {
                string x;
                cin>>x;
                string y;
                for(int i=0;i<x.length();i++)
                {
                    if(x[i] != ';' && x[i] != '-' && x[i] != '_')
                    {
                        if(x[i] >= 65 && x[i] <= 90) //capital
                            y += (x[i] + 32);
                        else
                            y += x[i];
                    }
                }

                if(y == (a+b+c) || y == (a+c+b) || y == (b+a+c) || y == (b+c+a) || y == (c+a+b) || y == (c+b+a))
                    cout<<"ACC\n";
                else
                    cout<<"WA\n";
            }

    return 0;
}

