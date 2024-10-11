#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

// @ocimatic should-fail=[st2,st3,st4]
int main(){
  ll n, m;
  cin >> n >> m;

  ll white=0, black=0;
  for(ll i=0; i<n; i++){
    for(ll j=0; j<m; j++){
      if((i+j)%2==0) white++;
      else black++;
    }
  }
  cout << white << ' ' << black << '\n';
}
