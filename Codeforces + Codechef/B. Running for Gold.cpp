#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<unordered_map>
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
        int n;
        cin>>n;
        int ranking [n][5];
        for(int i=0; i<n; i++)
        {
            int a,b,c,d,e;
            cin>>a>>b>>c>>d>>e;
            ranking[i][0] = a;
            ranking[i][1] = b;
            ranking[i][2] = c;
            ranking[i][3] = d;
            ranking[i][4] = e;
        }

        int most_probable = 0;

        for(int i=1; i<n; i++)
        {
            int counter=0;
            //cout<<"comparing "<<most_probable<<" && "<<i<<"\n";
            for(int j=0; j<5; j++)
            {
                if(  (ranking[most_probable][j]  < ranking[i][j]) )
                {
                    counter++;
                }
            }
            if(counter < 3)
                most_probable = i;
            //cout<<"most probable is "<<most_probable<<"\n";
        }

        int counter=0;
        bool found=0;


        for(int i=0; i<n; i++)
        {
            int counter=0;
            if( i != most_probable )
            {
                for(int j=0; j<5; j++)
                {
                    if(ranking[most_probable][j] < ranking[i][j])
                        counter++;
                }
                if(counter < 3)
                {
                    cout<<"-1\n";
                    goto h;
                }
            }

        }

    cout<<most_probable+1<<"\n";


h:
        t--;
    }



    return 0;
}
