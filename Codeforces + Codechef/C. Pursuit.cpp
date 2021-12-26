#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
#define usi unsigned short int
#define ui unsigned int
#define ulli unsigned long long int
#define lli long long int
using namespace std;

void array_printer(lli a[],lli n)
{
    cout<<"\n----------------\n";
    for(int i=0; i<n; i++)
        cout<<a[i]<<" ";
    cout<<"\n----------------\n";
}

void array_printer(int a[],lli n)
{
    cout<<"\n----------------\n";
    for(int i=0; i<n; i++)
        cout<<a[i]<<" ";
    cout<<"\n----------------\n";
}

int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);
    int t;
    cin>>t;
    while(t)
    {
        int n;
        cin>>n;
        int a[n];
        int b[n];

        for(int i=0; i<n; i++)
            cin>>a[i];
        for(int i=0; i<n; i++)
            cin>>b[i];

        sort(a,a+n);
        sort(b,b+n);

        lli suma=0;
        lli sumb=0;
        lli prefix_suma[n];
        lli prefix_sumb[n];
        lli sa=0;
        lli sb=0;

        for(int i=0; i<n; i++)
        {
            sa += a[i];
            sb += b[i];
            prefix_suma[i] = sa;
            prefix_sumb[i] = sb;
        }
        /*
        cout<<"a = \n";
        array_printer(a,n);
        cout<<"b = \n";
        array_printer(b,n);
        cout<<"prefix suma = \n";
        array_printer(prefix_suma,n);
        cout<<"prefix sumb = \n";
        array_printer(prefix_sumb,n); */

        if(n/4 == 0)
        {
            suma = sa;
            sumb = sb;
        }
        else
        {
            suma = sa - prefix_suma[ n/4 - 1 ];
            sumb = sb - prefix_sumb[ n/4 - 1 ];
        }


       // cout<<suma<<" "<<sumb<<"\n";

        if(suma >= sumb)
            cout<<0<<"\n";
        else
        {
            lli c=0;
            lli lower_index;
            lli noh=0;
            if(n/4 == 0)
                lower_index = -1;
            else
                lower_index = n/4 - 1;

            int j = n+1;

            for(int i = (n - n/4); i<n; i++,lower_index--,j++)
            {
                c++;
                if(lower_index >= 0)
                    sumb += b[lower_index];

                if( (j/4)%4 == 0)
                {
                    suma = sa - prefix_suma[j/4 - 1] + noh*100;
                    suma+=100;
                }
                else
                {
                    noh++;
                    suma+=100;
                }
                //cout<<suma<<" "<<sumb<<"\n";
                 if(suma >= sumb)
                 {
                     cout<<c<<"\n";
                     goto j;
                 }

            }

            if(suma >= sumb)
                cout<<c<<"\n";
            else
            {
                lli h=0;
                for(;; j++)
                {
                    c++;
                    if( (j/4 - 1) >= 0 )
                    {
                        if( j%4 == 0 )
                        {
                            suma = sa - prefix_suma[j/4 - 1] + noh*100;
                            suma+=100;
                        }
                        else
                        {
                            noh++;
                            suma+=100;
                        }

                        if(suma >= sumb)
                        {
                            cout<<c<<"\n";
                            break;
                        }

                    }
                    else
                    {
                        if( j%4  == 0 )
                        {
                            h++;
                            suma = noh*100 - h*100;
                        }
                        else
                        {
                             suma+=100;
                             noh++;
                        }

                    }

                   // cout<<suma<<" "<<sumb<<"\n";

                    if(suma >= sumb)
                    {
                        cout<<c<<"\n";
                        goto j;
                    }


                }
            }

        }
        j:
        t--;
    }

    return 0;
}

