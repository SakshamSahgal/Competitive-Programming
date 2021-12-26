#include<bits/stdc++.h>
using namespace std;


string reverseWord(string str);


int main() {

	int t;
	cin>>t;
	while(t--)
	{
	string s;
	cin >> s;

	cout << reverseWord(s) << endl;
	}
	return 0;

}

// } Driver Code Ends


//User function Template for C++

string reverseWord(string str){
    string rev = str;
    for(int i=(str.size()-1),j=0;i>=0;i--,j++)
    {
            rev[j] = str[i];
    }

    return rev;
  //Your code here
}
