#include<iostream>
#include<algorithm>
#define usi unsigned short int
#define ui unsigned int
#define ulli unsigned long long int
using namespace std;
int main()
{
//ios_base::sync_with_stdio(false);
//cin.tie(NULL);
//cout.tie(NULL);
usi a[6];
for(usi i=0;i<6;i++)
   cin>>a[i];
sort(a,a+6);
usi index;
bool sf=0;
for(usi i=0;i<=2;i++)
    {
        if(a[i] == a[i+1] && a[i+1] == a[i+2] && a[i+2] == a[i+3] )
            {
            sf = 1;
            index = i;
            break;
            }

    }
usi b[2];
usi c=0;
if(sf == 1)
    {
        for(usi i=0;i<6;i++)
            {
                if( i!=index && i!=(index+1) && i!=(index+2) && i!=(index+3) )
                    {
                        b[c] = a[i];
                        c++;
                    }
            }

       // cout<<b[0]<<" "<<b[1]<<"\n";

        if(b[0] == b[1])
            cout<<"Elephant\n";
        else
            cout<<"Bear\n";
    }
else
    cout<<"Alien\n";
return 0;
}
