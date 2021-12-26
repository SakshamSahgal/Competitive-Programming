#include<iostream>
#include<cstring>
using namespace std;


int ranker(char ch)
{
if(ch == 'a' || ch =='A')
    {
    return 1;
    }
else if(ch == 'b' || ch =='B')
    {
    return 2;
    }
else if(ch == 'c' || ch =='C')
    {
    return 3;
    }
else if(ch == 'd' || ch =='D')
    {
    return 4;
    }
else if(ch == 'e' || ch =='E')
    {
    return 5;
    }
else if(ch == 'f' || ch =='F')
    {
    return 6;
    }
else if(ch == 'g' || ch =='G')
    {
    return 7;
    }
else if(ch == 'h' || ch =='H')
    {
    return 8;
    }
else if(ch == 'i' || ch =='I')
    {
    return 9;
    }
else if(ch == 'j' || ch =='J')
    {
    return 10;
    }
else if(ch == 'k' || ch =='K')
    {
    return 11;
    }
else if(ch == 'l' || ch =='L')
    {
    return 12;
    }
else if(ch == 'm' || ch =='M')
    {
    return 13;
    }
else if(ch == 'n' || ch =='N')
    {
    return 14;
    }
else if(ch == 'o' || ch =='O')
    {
    return 15;
    }
else if(ch == 'p' || ch =='P')
    {
    return 16;
    }
else if(ch == 'q' || ch =='Q')
    {
    return 17;
    }
else if(ch == 'r' || ch =='R')
    {
    return 18;
    }
else if(ch == 's' || ch =='S')
    {
    return 19;
    }
else if(ch == 't' || ch =='T')
    {
    return 20;
    }
else if(ch == 'u' || ch =='U')
    {
    return 21;
    }
else if(ch == 'v' || ch =='V')
    {
    return 22;
    }
else if(ch == 'W' || ch =='w')
    {
    return 23;
    }
else if(ch == 'x' || ch =='X')
    {
    return 24;
    }
else if(ch == 'y' || ch =='Y')
    {
    return 25;
    }
else if(ch == 'z' || ch =='Z')
    {
    return 26;
    }
}


int main()
{
char s1[100];
char s2[100];
cin>>s1;
cin>>s2;
//cout<<"\nstring 1 = "<<s1;
//cout<<"\nstring 2 = "<<s2<<"\n";
//cout<<strlen(s1);
for(int i=0;i<=strlen(s1);i++)
    {
            if( ranker(s1[i])<ranker(s2[i]) )
            {
                cout<<"-1";
                break;
            }
            else if( ranker(s1[i])>ranker(s2[i]) )
            {
            cout<<"1";
            break;
            }

            if((i == strlen(s1)) && (ranker(s1[i]) == ranker(s2[i])))
                {
                cout<<"0";
                break;
                }
    //cout<<"AAiya\n";

    }
return 0;
}
