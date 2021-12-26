#include<iostream>
using namespace std;
int main()
{
int n;
cin>>n;
char a[n];
int checker[26];
for(int i=0;i<26;i++)
    {
    checker[i] = 0;
    }
cin>>a;
for(int i=0;i<n;i++)
    {
        if(a[i]== 'A' || a[i]== 'a')
            {
            checker[0] = 1;
            }
        else if(a[i]== 'B' || a[i]== 'b')
            {
            checker[1] = 1;
            }
        else if(a[i]== 'C' || a[i]== 'c')
            {
            checker[2] = 1;
            }
        else if(a[i]== 'D' || a[i]== 'd')
            {
            checker[3] = 1;
            }
        else if(a[i]== 'E' || a[i]== 'e')
            {
            checker[4] = 1;
            }
        else if(a[i]== 'F' || a[i]== 'f')
            {
            checker[5] = 1;
            }
         else if(a[i]== 'G' || a[i]== 'g')
            {
            checker[6] = 1;
            }
        else if(a[i]== 'H' || a[i]== 'h')
            {
            checker[7] = 1;
            }
        else if(a[i]== 'I' || a[i]== 'i')
            {
            checker[8] = 1;
            }
        else if(a[i]== 'J' || a[i]== 'j')
            {
            checker[9] = 1;
            }
        else if(a[i]== 'K' || a[i]== 'k')
            {
            checker[10] = 1;
            }
        else if(a[i]== 'L' || a[i]== 'l')
            {
            checker[11] = 1;
            }
        else if(a[i]== 'M' || a[i]== 'm')
            {
            checker[12] = 1;
            }
        else if(a[i]== 'N' || a[i]== 'n')
            {
            checker[13] = 1;
            }
        else if(a[i]== 'O' || a[i]== 'o')
            {
            checker[14] = 1;
            }
        else if(a[i]== 'P' || a[i]== 'p')
            {
            checker[15] = 1;
            }
        else if(a[i]== 'Q' || a[i]== 'q')
            {
            checker[16] = 1;
            }
        else if(a[i]== 'R' || a[i]== 'r')
            {
            checker[17] = 1;
            }
        else if(a[i]== 'S' || a[i]== 's')
            {
            checker[18] = 1;
            }
        else if(a[i]== 'T' || a[i]== 't')
            {
            checker[19] = 1;
            }
        else if(a[i]== 'U' || a[i]== 'u')
            {
            checker[20] = 1;
            }
        else if(a[i]== 'V' || a[i]== 'v')
            {
            checker[21] = 1;
            }
        else if(a[i]== 'W' || a[i]== 'w')
            {
            checker[22] = 1;
            }
        else if(a[i]== 'X' || a[i]== 'x')
            {
            checker[23] = 1;
            }
        else if(a[i]== 'Y' || a[i]== 'y')
            {
            checker[24] = 1;
            }
        else if(a[i]== 'Z' || a[i]== 'z')
            {
            checker[25] = 1;
            }
    }

for(int i=0;i<26;i++)
    {
    if(checker[i] == 0)
        {
        cout<<"NO";
        return 0;
        }
    }
cout<<"YES";
return 0;
}
