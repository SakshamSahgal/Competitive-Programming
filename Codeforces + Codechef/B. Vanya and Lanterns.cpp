#include<iostream>
#include<algorithm>
#include<iomanip>
#include<vector>
#define usi unsigned short int
#define ui unsigned int
#define ulli unsigned long long int
#define lli long long int
using namespace std;
int main()
{
//ios_base::sync_with_stdio(false);
//cin.tie(NULL);
//cout.tie(NULL);
    usi n;
    lli l,temp,diff,max_diff=0;
    cin>>n>>l;
    vector <lli> a;
    bool zero_found=0,end_found=0;
    for(usi i=0; i<n; i++)
    {
        cin>>temp;
        a.push_back(temp);
        if(temp == 0 && zero_found == 0)
            zero_found = 1;
        if(temp == l && end_found == 0)
            end_found = 1;
    }

    if(zero_found == 0)
        a.push_back(0);
    if(end_found == 0)
        a.push_back(l);

    sort(a.begin(),a.end());
    if(zero_found == 1 && end_found == 1)
    {

        for(usi i=0; i<(a.size()-1); i++)
        {
            diff = a[i+1] - a[i];
            if(  diff > max_diff)
                max_diff =  diff;
        }

       /*
        cout<<"\n--------\n";
        for(usi i=0; i<a.size(); i++)
            cout<<a[i]<<" ";
        cout<<"\n--------\n"; */


        cout << fixed << setprecision(12) <<(max_diff/2.0)<<"\n";
    }
    else if(zero_found == 1 && end_found == 0)
    {

        for(usi i=0; i<(a.size()-2); i++)
        {
            diff = a[i+1] - a[i];
            if(  diff > max_diff)
                max_diff =  diff;
        }

    /*
        cout<<"\n--------\n";
        for(usi i=0; i<a.size(); i++)
            cout<<a[i]<<" ";
        cout<<"\n--------\n"; */



        if( (max_diff/2.0) > (float)(l - a[a.size()-2]) )
            cout << fixed << setprecision(12) <<(max_diff/2.0)<<"\n";
        else
            cout << fixed << setprecision(12) <<(l - a[a.size()-2])<<"\n";

    }
    else if(zero_found == 0 && end_found == 1)
    {
        for(usi i=1; i<(a.size()-1); i++)
        {
            diff = a[i+1] - a[i];
            if(  diff > max_diff)
                max_diff =  diff;
        }

        /*
        cout<<"\n--------\n";
        for(usi i=0; i<a.size(); i++)
            cout<<a[i]<<" ";
        cout<<"\n--------\n"; */


        if( (max_diff/2.0) > (float)(a[1]) )
            cout << fixed << setprecision(12) <<(max_diff/2.0)<<"\n";
        else
            cout << fixed << setprecision(12) <<(float)(a[1])<<"\n";
    }
    else
    {
        for(usi i=1; i<(a.size()-2); i++)
        {
            diff = a[i+1] - a[i];
            if(  diff > max_diff )
                max_diff =  diff;
        }


       /*
        cout<<"\n--------\n";
        for(usi i=0; i<a.size(); i++)
            cout<<a[i]<<" ";
        cout<<"\n--------\n"; */

        if(    (max_diff/2.0) >= (float)(a[1])    &&     (max_diff/2.0) >= (float)(l-a[a.size()-2])    )
            cout << fixed << setprecision(12) <<(max_diff/2.0)<<"\n";
        else if( (float)(a[1])  >= (max_diff/2.0) && (float)(a[1]) >= (float)(l-a[a.size()-2])  )
            cout << fixed << setprecision(12) <<(float)(a[1])<<"\n";
        else
            cout << fixed << setprecision(12) <<(l - a[a.size()-2])<<"\n";
    }


    return 0;
}

