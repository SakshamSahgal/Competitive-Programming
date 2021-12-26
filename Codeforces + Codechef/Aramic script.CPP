#include<iostream>
using namespace std;

string return_root(string str)
{
    bool check = 0;
    string root;

    int itssize=0;
    //size checker
    for(int i=0;i<str.size();i++)
        {
            check = 0;
        for(int j=0;j<i;j++)
            {
                    if(str[i] == str[j])
                        check = 1;
            }

                if(check == 0)
                    {
                    itssize++;
                    }
        }

 root.resize(itssize);
    int counter = 0;
for(int i=0;i<str.size();i++)
    {
        check = 0;
        for(int j=0;j<i;j++)
            {

                if(str[i] == str[j])
                    check = 1;
            }

            if(check == 0)
                {
                root[counter] = str[i];
                counter++;
                }

    }
         return root;

}
int main()
{
short int n;
cin>>n;
string str[n];
for(int i=0;i<n;i++)
    cin>>str[i];  //input

bool check=0;
int counter = 0;
for(int i=0;i<n;i++)
    {
        check = 0;
          for(int j=0;j<i;j++)
            {
             if(return_root(str[i]) == return_root(str[j]))
                {
                check = 1;
                }
            }

        if(check == 0)
            {
            counter++;
            }

    }
cout<<counter;
return 0;
}
