#include<iostream>
#include<algorithm>
#include<vector>
#define usi unsigned short int
#define ui unsigned int
#define ulli unsigned long long int
using namespace std;
struct boat
{
int a;
int b;
int s;
};
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

        usi w[n];
        for(usi i=0;i<n;i++)
            cin>>w[i];
    if(n == 1)
        cout<<0<<"\n";
    else
    {
            boat b[n-1][n];
            vector<usi> de;
            bool found = 0;
            for(usi i=0;i<n;i++)
            {

                for(usi j=0,c=0;j<n;j++)
                    {
                        if(j!=i)
                            {
                             b[c][i].a = w[i];
                             b[c][i].b = w[j];
                             b[c][i].s = w[i] + w[j];
                             found  = 0;
                            for(usi k=0;k<de.size();k++)
                                {
                                    if(b[c][i].s == de[k])
                                        {
                                        found = 1;
                                        break;
                                        }
                                }
                            if(found == 0)
                                de.push_back(b[c][i].s);
                             c++;
                            }

                    }
            }
        int counter[de.size()][n];

        /////////////////////////////////////////////////////////
        for(usi i=0;i<n;i++)
            {
            for(usi j=0;j<(n-1);j++)
                {
                cout<<b[j][i].a<<"+"<<b[j][i].b<<" = "<<b[j][i].s<<"\n";
                }
           cout<<"\n";
            }
        /////////////////////////////////////////////////////////


        int c=0;
        int sum = 0;
        int max_sum = -1;
        int index;
        for(usi i=0;i<de.size();i++)
            {
                 sum = 0;
                for(usi j=0;j<n;j++)
                    {
                         c=0;

                        for(usi k=0;k<(n-1);k++)
                            {
                                if(b[k][j].s == de[i])
                                    c++;
                            }
                        sum+=c;
                        counter[i][j] = c;
                    }
;               //cout<<"sum  = "<<sum<<"\n";
                if(sum>max_sum)
                    {
                     max_sum = sum;
                        index = i;
                    }


            }
    /////////////////////////////////////////////////////////
        cout<<"\n";
        for(usi i=0;i<de.size();i++)
            {
               cout<<de[i]<<"->";
                for(usi j=0;j<(n);j++)
                    {
                        cout<<" "<<counter[i][j];
                    }
            cout<<"\n";
            }
        cout<<"max sum = "<<max_sum<<" at index"<<index<<"\n";
        /////////////////////////////////////////////////////////

        sum = de[index];
        int p=0;
        for(usi i=0;i<n;i++)
            {
                for(usi j=0;j<n;j++)
                    {
                        if(i!=j)
                            {
                                if(w[i] == 0)
                                    break;
                                else
                                {
                                    if(w[j] != 0)
                                    {
                                    if( (w[i]+w[j]) == sum)
                                        {
                                        w[i] = 0;
                                        w[j] = 0;
                                        //cout<<"i = "<<i<<"j = "<<j<<"\n";
                                        p++;
                                        break;
                                        }
                                    }
                                }
                            }


                    }

            }
        cout<<p<<"\n";
    }

        t--;
        }

//ios_base::sync_with_stdio(false);
//cin.tie(NULL);
//cout.tie(NULL);




return 0;
}
