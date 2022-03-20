#include<iostream>
#include<math.h>
#include<vector>
#include<algorithm>
using namespace std;

long double calc_dist(long double x,long double y)
{
    return sqrtl(x*x + y*y);
}

void insertion_Sort(int n,long double v[][3])
{
    cout<<"original array - \n";
    for(int i=0;i<n;i++)
        cout<<v[i][0]<<" "<<v[i][1]<<" "<<v[i][2]<<"\n";
    cout<<"\n";

    for(int i=1;i<n;i++)
    {
        long double key[3];
        key[0] = v[i][0]; //dist
        key[1] = v[i][1]; //x
        key[2] = v[i][2]; //y

        int j = i-1;
        while(j >=0 && v[j][0] > key[0])
        {
            v[j+1][0] = v[j][0];
            v[j+1][1] = v[j][1];
            v[j+1][2] = v[j][2];
            j--;
        }

        v[j+1][0] = key[0];
        v[j+1][1] = key[1];
        v[j+1][2] = key[2];
    }
    cout<<"sorted array \n";
    for(int i=0;i<n;i++)
        cout<<v[i][0]<<" "<<v[i][1]<<" "<<v[i][2]<<"\n";
}

int main()
{
    int n,k;
    cin>>n>>k;
    long double v[n][3]; //dist , x , y

    for(int i=0;i<n;i++)
    {
        cin>>v[i][1]>>v[i][2];
        v[i][0] = calc_dist(v[i][1],v[i][2]);
    }

    insertion_Sort(n,v);
    cout<<"\n\nK nearest points to the array are - \n";
    for(int i=0;i<k;i++)
        cout<<"( distance - "<<v[i][0]<<") "<<v[i][1]<<" "<<v[i][2]<<"\n";

    /*
    3 2
    3 3
    5 -1
    -2 4
    */

    return 0;
}
