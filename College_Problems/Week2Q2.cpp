#include<iostream>
using namespace std;

int main()
{
    int red[100] = {0};
    int yellow[100] = {0};
    int blue[100] = {0};

    for(int i=0;i<5;i++)
    {
        int n;
        string s;
        cin>>n>>s;
        if(s == "red")
            red[n] = 1;
        else if(s == "yellow")
            yellow[n] = 1;
        else
            blue[n] = 1;
    }

    for(int i=0;i<10;i++)
    {
        if(red[i] != 0)
            cout<<"( Red "<<i<<" ) ";
    }

    for(int i=0;i<10;i++)
    {
        if(blue[i] != 0)
            cout<<"( blue "<<i<<" ) ";
    }

    for(int i=0;i<10;i++)
    {
        if(yellow[i] != 0)
            cout<<"( yellow "<<i<<" ) ";
    }

    return 0;
}
