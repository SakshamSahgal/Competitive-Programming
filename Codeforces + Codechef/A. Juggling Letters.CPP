#include<iostream>
#include<algorithm>
#include<vector>
#define usi unsigned short int
using namespace std;
void data_printer(vector <char> de,vector <int> freq)
{
cout<<"\n-----------\n";
for(usi i=0;i<de.size();i++)
    cout<<de[i]<<" ";
cout<<"\n";
for(usi i=0;i<freq.size();i++)
    cout<<freq[i]<<" ";
cout<<"\n-----------\n";
}
void printer(usi n,char arr[][1000],usi lengths[])
{
cout<<"\n-----------\n";
for(usi i=0;i<n;i++)
    {
    usi j = 0;
    for(usi j=0;j<lengths[i];j++)
        {
        cout<<arr[i][j];
        }
    cout<<"\n";
    }
cout<<"\n-----------\n";
}
int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);
usi t;
cin>>t;
while(t--)
    {
    usi n;
    cin>>n;
    usi lengths[n];
    char str[n][1000];
    string ip;
    unsigned int l = 0;
    for(usi i=0;i<n;i++)
        {
        cin>>ip;
        for(usi k=0;k<ip.length();k++)
            str[i][k] = ip[k];

        lengths[i] = ip.length();
        l+=ip.length();
        }
    //cout<<"length = "<<l<<"\n";
    //printer(n,str,lengths);
    char str2[l];

    for(usi i=0,k=0;i<n;i++)
        {
        for(usi j=0;j<lengths[i];j++,k++)
            {
                str2[k] = str[i][j];
            }
        }
    /*
    cout<<"\n";
    for(usi i=0;i<l;i++)
        cout<<str2[i];
            */
      bool found = 0;
    vector <char> distinct_elements;
    vector <int> frequency;
    unsigned int frequency_of_this_element = 0;
    for(usi i=0;i<l;i++)
        {
            frequency_of_this_element = 0;
            found  = 0;
           for(usi j=0;j<distinct_elements.size();j++)
            {
                if(distinct_elements[j] == str2[i])
                    {
                    found = 1;
                    break;
                    }
            }

        if(found == 0)
            {
            distinct_elements.push_back(str2[i]);
            for(usi k=0;k<l;k++)
                {
                if(str2[i] == str2[k])
                    frequency_of_this_element++;
                }
                frequency.push_back(frequency_of_this_element);
            }
        }

    //data_printer(distinct_elements,frequency);


    for(usi i=0;i<frequency.size();i++)
        {

        if(frequency[i]%n != 0)
            {
            cout<<"NO\n";
            goto z;
            }
        }
    cout<<"YES\n";
    z:
        n=n;
    }

return 0;
}
