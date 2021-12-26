#include<iostream>
#include<vector>
#include<algorithm>
#define usi unsigned short int
using namespace std;
void Printer(vector <int> even,vector <int> odd)
{
cout<<"\n----------------------\n";
cout<<"Even - \n";
for(usi i=0;i<even.size();i++)
    {
    cout<<even[i]<<" ";
    }
cout<<"\n";
cout<<"Odd - \n";
for(usi i=0;i<odd.size();i++)
    {
    cout<<odd[i]<<" ";
    }
cout<<"\n----------------------\n";
}
int main()
{
usi n;
cin>>n;
unsigned int a[n];
vector <int> even;
vector <int> odd;
for(usi i=0;i<n;i++)
    {
     cin>>a[i];

        if(a[i]%2 == 0)
            even.push_back(a[i]);
        else
            odd.push_back(a[i]);
    }
if(even.size() == odd.size() || (even.size() == (odd.size()+1)) || ((even.size()+1) == odd.size()) )
    {
    cout<<"0";
    return 0;
    }

else
    {
    unsigned int sum = 0;
    sort(even.begin(),even.end(),greater<int>());
    sort(odd.begin(),odd.end(),greater<int>());
    //Printer(even,odd);
    if( odd.size() > even.size() )
        {
        vector<int>::iterator pos;
        pos = odd.begin();
        for(usi i=0;i<(even.size()+1);i++)
            odd.erase(pos);

        //Printer(even,odd);

        for(usi i=0;i<odd.size();i++)
            sum += odd[i];
        cout<<sum;
        return 0;
        }
    else
        {
        vector <int>::iterator pos;
        pos = even.begin();
        //Printer(even,odd);
        for(usi i=0;i<(odd.size()+1);i++)
            even.erase(pos);
        //Printer(even,odd);
        for(usi i=0;i<even.size();i++)
            sum+=even[i];
        cout<<sum;
        return 0;
        }
    }

return 0;
}





