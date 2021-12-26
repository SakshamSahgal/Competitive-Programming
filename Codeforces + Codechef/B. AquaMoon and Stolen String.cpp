#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
#include<unordered_map>
#define usi unsigned short int
#define ui unsigned int
#define ulli unsigned long long int
#define lli long long int
using namespace std;


void matrix_printer(int r,int c,int *x)
{
    cout<<"\n";
    for(int i=0; i<r; i++)
    {
        for(int j=0; j<c; j++)
            cout<<*((x+i*c)+j)<<" ";
        cout<<"\n";
    }
    cout<<"\n";
}

differ(int r,int c,int *c1,int *c2)
{
        for(int i=0;i<c;i++)
        {
            for(int j=0;j<26;j++)
            {
                //cout<<"comparing = "<<(*((c1+c*j)+i))<<" "<<(*((c2+c*j)+i))<<"\n";
                if( (*((c1+c*j)+i)) != (*((c2+c*j)+i)) )
                {
                    cout<< (char)(j+97);
                    break;
                }
            }
        //cout<<"\n--------------------------\n";
        }
}

int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);
    int t;
    cin>>t;
    while(t)
    {
        vector<string> before;
        vector<string> after;
        string s;
        int n,m;
        cin>>n>>m;
        int counter1[26][m];
        int counter2[26][m];
        memset(counter1,0,(sizeof(counter1[0][0])*26*m));
        memset(counter2,0,(sizeof(counter2[0][0])*26*m));
        for(int i=0; i<n; i++)
        {
            cin>>s;
            before.push_back(s);
            for(int j=0; j<m; j++)
                counter1[before[i][j]-97][j]++;
        }

        //matrix_printer(26,m,(int*)counter1);

        for(int i=0; i<n-1; i++)
        {
            cin>>s;
            after.push_back(s);
            for(int j=0; j<m; j++)
                counter2[after[i][j]-97][j]++;
        }

        //matrix_printer(26,m,(int*)counter2);

        if(n == 1)
            cout<<before[0]<<"\n";
        else
        {
            differ(26,m,(int*)counter1,(int*)counter2);
        }
        cout<<endl;
        t--;
    }



    return 0;
}
