#include<iostream>
#include<cstring>
#include<vector>
#include<set>
#include<map>
#include<algorithm>
#include<cmath>
#include<climits>
#define lli long long int
#define GO_FAST ios_base::sync_with_stdio(0);ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
int main(){
    lli t;
    cin>>t;
    while(t){
        lli n;
      cin >> n;
      lli a[n];
      for (lli i = 0; i < n; i++)
            cin >> a[i];
      lli res = 0;
      for (lli i = 0; i < n; i++) {
            lli maxi = a[i], minn = a[i];
            set<lli> set;
            for (lli j = i; j < n; j++) {
                  set.insert(a[j]);
                  maxi = max(maxi, a[j]);
                  minn = min(minn, a[j]);
                  if (j - i < 2) {
                        continue;
                  }
                  lli value = 0;
                  auto position = set.lower_bound((maxi + minn) / 2);
                  if (position != set.end()) {
                        value = max(value, (maxi - (*position)) * ((*position) - minn));
                  }
                  if (position != set.begin()) {
                        position--;
                        value = max(value, (maxi - (*position)) * ((*position) - minn));
                  }
                  res += value;
            }

      }
      cout << res << endl;
      t--;
    }

}
