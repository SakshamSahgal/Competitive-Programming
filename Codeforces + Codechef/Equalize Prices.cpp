#include<iostream>
#include<cmath>
using namespace std;

#define usi unsigned short int



int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);
usi q;
cin>>q;
while(q--)
    {

    usi n;
    int k;
    cin>>n>>k;
    int a[n];
    for(usi i=0;i<n;i++)
        cin>>a[i];

    //bubble sorting dec
    bool checker = 0;

    int temp;
    for(usi i=0;i<n;i++)
        {
        checker = 1;
        for(usi j=0;j<(n-1-i);j++)
            {
                if(a[j] > a[j+1])
                    {
                        temp = a[j];
                        a[j] = a[j+1];
                        a[j+1] = temp;
                        checker = 0;
                    }

            }

            if(checker == 1)
            break;

        }

        long int sum = a[0] + k;
         checker = 0;
        for(usi i=0;i<n;i++)
            {
                if(abs(a[i] - sum)>k)
                    {
                    checker = 1;
                    cout<<"-1\n";
                    break;
                    }
            }

        if(checker == 0)
        cout<<sum<<"\n";

        }
return 0;
}
