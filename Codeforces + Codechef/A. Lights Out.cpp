#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
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
    int a[3][3];
    int b[3][3];

    memset(a,0, sizeof a);


    for(int i=0; i<3; i++)
    {
        for(int j=0; j<3; j++)
        {
            cin>>b[i][j];
            if(b[i][j] != 0)
            {
                a[i][j] += b[i][j];

                if( (i-1) >= 0)
                    a[i-1][j] +=b[i][j];

                if((i+1)<3)
                    a[i+1][j] += b[i][j];

                if((j-1)>=0)
                    a[i][j-1] += b[i][j];

                if( (j+1)<3)
                    a[i][j+1] += b[i][j];

                /*
                cout<<"\n-------------\n";
                for(int i=0; i<3; i++)
                {
                    for(int j=0; j<3; j++)
                        cout<<a[i][j]<<" ";
                    cout<<"\n";
                }
                cout<<"\n-------------\n"; */
            }
        }

    }

    for(int i=0; i<3; i++)
    {
        for(int j=0; j<3; j++)
        {
           if(a[i][j]%2 == 0)
            cout<<1;
           else
            cout<<0;
        }
        cout<<"\n";
    }




    return 0;
}
