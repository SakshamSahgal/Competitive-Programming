#include<iostream>
#include<algorithm>
#include<map>
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
    map <int,string> student{{123444,"abcd"},{1234112,"xyzf"}}; //another way to insert

    student.insert(pair<int,string>(20103224,"Saksham")); //another way to insert
    student.insert(pair<int,string>(20103225,"xy"));

    student.insert({1234513,"ghty"}); //another way to insert

    cout<<student.size()<<"\n";


    map<int,string>::iterator itr = student.end();

    /*
    for(itr=student.begin(); itr!=student.end(); itr++)
    {
        cout<<itr->first<<" "<<itr->second<<"\n";

    } */


    cout<<itr->first<<" "<<itr->second<<"\n";
    return 0;
}
