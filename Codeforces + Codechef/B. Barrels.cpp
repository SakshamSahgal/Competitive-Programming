#include<iostream>
using namespace std;
#define si short int
int main()
{
//ios_base::sync_with_stdio(false);
//cin.tie(NULL);
//cout.tie(NULL);

si t;

cin>>t;
while(t--)
    {
    long int n,k;
    long long int maximum;
    long long int second_max;
    cin>>n>>k;
    long long int a[n];
    si max_index =0;
    si second_max_index=0;
bool all_not_equal = 0;


    for(int i=0;i<n;i++)
        {
        cin>>a[i];
        }

        for(int i=0;i<n;i++)
            {
                if(a[i] != a[s])
                    {
                    all_not_equal = 1;
                    }
            }

        if(all_not_equal == 1)
    {

        a:

        maximum = a[0];
        for(int i=1;i<n;i++)
            {
                if(a[i]>maximum)
                    {
                        maximum = a[i];
                        max_index = i;
                    }
            }

        cout<<"max = "<<maximum<<" max index = "<<max_index<<"\n";

            if(a[0] != maximum)
                {
                second_max = a[0];
                }
            else
                {
              second_max = a[1];
                }


            for(int i=0;i<n;i++)
                {
                    if(a[i] != maximum)
                        {
                                if(a[i]>second_max)
                                    {
                                        second_max = a[i];
                                        second_max_index = i;
                                    }
                        }
                }
             cout<<"second max = "<<second_max<<" second max index "<<second_max_index<<"\n";
            a[max_index] += second_max;
            a[second_max_index] = 0;
            for(int i=0;i<n;i++)
                {
                cout<<a[i]<<" ";
                }
            cout<<"\n";
            k--;
            if(k>=0)
                {
                goto a;
                }
            else
                {
                cout<<maximum <<"\n";
                }
    }

        else
            {
                cout<<k*a[0]<<"\n";
            }
}



return 0;
}
