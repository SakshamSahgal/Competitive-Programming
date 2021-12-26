#include<iostream>
#include<stack>
#define usi unsigned short int
#define ui unsigned int
#define ulli unsigned long long int
using namespace std;


bool sequence_checker(usi n,char x[])
    {
    stack<char> s;

    for(usi i=0;i<n;i++)
        {
        if(x[i] == '(')
            {
            s.push('(');
            }
        else if(x[i] == ')')
            {
                if(s.size() > 0 )
                    s.pop();
                else
                 return 0;
            }
        //cout<<"i = "<<i<<" stack size = "<<s.size()<<"\n";
        }

        if(s.size() == 0)
            return 1;
        else
            return 0;
    }

int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);
usi t;
cin>>t;
while(t)
    {
    string a;
    cin>>a;
    int n = a.size();
    char b[n];
    char s1[n],s2[n];
    if( a[0] == a[n-1] )
        {
        cout<<"NO\n";
        }
    else
        {
        for(usi i=0;i<n;i++)
            {
                if(a[i] == a[0])
                    b[i] = '(';

                else if(a[i] == a[n-1])
                    b[i] = ')';

                else
                    b[i] = '-';

            }

        for(usi i=0;i<n;i++)
            {
            s1[i] = b[i];
            s2[i] = b[i];
            if(b[i] == '-')
                {
                s1[i] = '(';
                s2[i] = ')';
                }
            }

        if(sequence_checker(n,s1) == 1 || sequence_checker(n,s2) == 1)
            cout<<"YES\n";
        else
            cout<<"NO\n";
        }


    //cout<<"open = "<<op<<" "<<"close = "<<cl<<"Rem = "<<rem<<"\n";
   /*cout<<"\n------------\n";
    for(usi i=0;i<n;i++)
        cout<<s1[i];
    cout<<"\n------------\n";
    for(usi i=0;i<n;i++)
        cout<<s2[i];
    cout<<"\n------------\n";*/

    t--;
    }
return 0;
}

