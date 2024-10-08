#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(){
  ll n, m;
  cin >> n >> m;
  
  ll white = ((n+1)/2) * ((m+1)/2) + (n/2) * (m/2);
  ll black = ((n+1)/2) * (m/2) + (n/2) * ((m+1)/2);

  cout << white << ' ' << black << '\n';
}
