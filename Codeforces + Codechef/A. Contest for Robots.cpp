#include<iostream>
#define usi unsigned short int
using namespace std;
void input(usi r[],usi b[],usi n)
{
for(usi i=0;i<n;i++)
    cin>>r[i];

for(usi i=0;i<n;i++)
    cin>>b[i];
}

unsigned int total_calc(usi n,unsigned int marks[],usi x[])
{
unsigned int total=0;
for(usi i=0;i<n;i++)
    {
    total+=marks[i]*x[i];
    }
return total;
}

void debugger(usi n,usi r[],usi b[],unsigned int marks[])
{
cout<<"robocory = \n";
for(usi i=0;i<n;i++)
    cout<<r[i]<<" ";
cout<<"\nbionic = \n";
for(usi i=0;i<n;i++)
    cout<<r[i]<<" ";
cout<<"\nmarks = \n";
for(usi i=0;i<n;i++)
    cout<<marks[i]<<" ";
cout<<"\n";
}
int main()
{
usi n;
cin>>n;
usi r[n];
usi b[n];
unsigned int marks[n];
bool all_Same=1;
bool all_zero = 1;
bool all_one = 1;
input(r,b,n);

for(usi i=0;i<n;i++)
    {
    if(r[i] != 0)
        {
            all_zero = 0;
            break;
        }
    }

for(usi i=0;i<n;i++)
    {
        if(r[i] != b[i])
            {
            all_Same = 0;
            break;
            }
    }


for(usi i=0;i<n;i++)
    {
        if(b[i] != 1)
            {
            all_one = 0;
            break;
            }
    }
//if all same

unsigned int maximum;
if(all_Same == 1 || all_zero == 1 || all_one == 1)
    {
    cout<<"-1\n";
    return 0;
    }

for(usi i=0;i<n;i++)
    marks[i] = 1;

if(total_calc(n,marks,r) > total_calc(n,marks,b))
    {
    cout<<"1\n";
    goto g;
    }
else
    {
            k:
            for(usi i=0;i<n;i++)
            {
            if(r[i] == 1)
                marks[i]++;
            }

            if(total_calc(n,marks,r) <= total_calc(n,marks,b))
            goto k;
            //debugger(n,r,b,marks);
            maximum  = marks[0];
            for(usi i=0;i<n;i++)
            {
            if(marks[i]>maximum)
            maximum = marks[i];
            }
    }
cout<<maximum;
g:
return 0;
}
