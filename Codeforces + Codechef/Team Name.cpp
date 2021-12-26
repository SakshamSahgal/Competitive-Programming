#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#define usi unsigned short int
#define ui unsigned int
#define si short int
#define ulli unsigned long long int
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
    usi n;
    cin>>n;
    cin.ignore(256,'\n');
    string s;
    getline(cin,s);
    //cout<<s<<"\n";
	vector <string> words(n);
	for(usi i=0,j=0;i<n,j<s.size();i++,j++)
		{
			while( j<s.size() && s[j] != ' ')
				{
				    //cout<<" j = "<<j<<"\n";
					words[i] += s[j];
					j++;
				}
            //cout<<"--";
		}
    /*
	for(usi i=0;i<n;i++)
		cout<<words[i]<<"\n"; */

     string x;
     string y;
     int counter = 0;
    bool found = 0;
    for(usi i=0;i<(n-1);i++)
        {
            for(usi j=i+1;j<n;j++)
                {

                    if( words[i][0] != words[j][0] )
                        {
                           x = words[i];
                           y = words[j];
                           x[0] = words[j][0];
                           y[0] = words[i][0];
                           //cout<<x<<" "<<y<<"\n";
                           found = 0;
                           for(int k=0;k<n;k++)
                            {
                                if(words[k] == x || words[k] == y)
                                    {
                                    found = 1;
                                    break;
                                    }
                            }

                        if(found == 0)
                            counter+=2;
                        }

                }

        }
    cout<<counter<<"\n";
    t--;
    }


return 0;
}
