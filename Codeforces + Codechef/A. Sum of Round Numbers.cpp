#include<iostream>
#include<cmath>
#include<vector>
#include<algorithm>
#define usi unsigned short int
#define ui unsigned int
#define ulli unsigned long long int
using namespace std;

vector <char> ninstring;



void reverser()
{
char temp;
for(usi i=0;i<(ninstring.size()/2);i++)
    {
       temp = ninstring[i];
       ninstring[i] = ninstring[ninstring.size()-1-i];
       ninstring[ninstring.size()-1-i] = temp;
    }

}

bool round(int n)
{
int d=0;
int temp = n;
while(temp!=0)
    {
        ninstring.push_back((temp%10)+48);
        temp/=10;
    }
    reverser();
   // cout<<"\n";
  //  for(usi i=0;i<ninstring.size();i++)
       // cout<<ninstring[i]<<"-";
    //cout<<"\n";
if(ninstring[ninstring.size()-1] != 0)
    {

        for(usi i=0;i<(ninstring.size()-1);i++)
        {
        if(ninstring[i] != '0')
            return 0;
        }

    return 1;
    }
else
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
    int n;
    cin>>n;
    if(round(n) == 1)
        {
        cout<<"1\n";
        cout<<n<<"\n";
        }
    else
        {
        int c=0;
        for(usi i=0;i<ninstring.size();i++)
            if(ninstring[i] != '0')
                c++;

        cout<<c<<"\n";

        for(usi i=0;i<ninstring.size();i++)
            {

                if(ninstring[i] != '0')
                    {
                         cout<<ninstring[i];
                        for(usi j=0;j<(ninstring.size()-i-1);j++)
                            cout<<"0";
                        cout<<" ";
                    }


            }
        cout<<"\n";
        }
    ninstring.clear();
    t--;
    }



return 0;
}
