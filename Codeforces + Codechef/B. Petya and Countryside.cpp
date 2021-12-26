#include<iostream>
#include<cstring>
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

void array_printer(int a[],int n)
{
    cout<<"\n----------------\n";
    for(int i=0; i<n; i++)
        cout<<a[i]<<" ";
    cout<<"\n----------------\n";
}

int main()
{
//ios_base::sync_with_stdio(false);
//cin.tie(NULL);
//cout.tie(NULL);
    int n;
    cin>>n;
    int a[n];

    for(int i=0; i<n; i++)
        cin>>a[i];

    int right_prefix[n]= {0};
    int left_prefix[n] = {0};
    int right[n]= {0};
    int left[n]= {0};

    memset(right_prefix, -1, sizeof(right_prefix));

    memset(left_prefix, -1, sizeof(left_prefix));

    for(int i=0,j=n-1; i<(n-1); i++,j--)
    {
        if(a[i]>=a[i+1])
            right[i] = 1;

        if(a[j-1]<=a[j])
            left[j] = 1;
    }

    //cout<<"\nRight = \n";
    //array_printer(right,n);
   //cout<<"\nleft = \n";
    //array_printer(left,n);

    //right prefix ko right se bhar rahe h
    //left prefix ko left se bhar rahe h


    int right_update=-1;
    int left_update=-1;

    for(int i=0,j=n-1; i<n; i++,j--)
    {
        if(right[j] == 0)
            right_update = j;

        if(left[i] == 0)
            left_update = i;


        right_prefix[j] = right_update;
        left_prefix[i] = left_update;
    }


    //cout<<"\nright prefix = \n";
    //array_printer(right_prefix,n);
    //cout<<"\nleft prefix = \n";
    //array_printer(left_prefix,n);


    if(n == 1)
        cout<<1<<"\n";
    else
    {
        int maxx = INT_MIN;
        for(int i=0; i<n; i++)
        {
            int right_index = -1;
            int left_index = -1;
            int d=0;
            //cout<<"i = "<<i<<" ";
            if(i == 0)
            {
                right_index = right_prefix[i];
            }
            else if( i == n-1)
            {
                left_index = left_prefix[i];
            }
            else
            {
                right_index = right_prefix[i];
                left_index = left_prefix[i];
            }


            if(right_index != -1 && left_index != -1)
                d  = right_index - left_index + 1;
            else
                {
                    if(right_index != -1 && left_index == -1)
                        d = right_index-i+1;
                    else if(right_index == -1 && left_index != -1)
                        d = i - left_index + 1;
                    else
                        d = 1;
                }

            maxx = max(d,maxx);
            //cout<<"left index = "<<left_index<<" "<<"right index = "<<right_index<<" distance = "<<d<<"\n";
        }
        cout<<maxx<<"\n";
    }



    return 0;
}


