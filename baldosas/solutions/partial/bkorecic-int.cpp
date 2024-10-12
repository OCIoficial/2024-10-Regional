#include <bits/stdc++.h>

using namespace std;

// Debería fallar por no usar long long
// @ocimatic should-fail=[st2,st3,st4]
int main(){
  int n, m;
  cin >> n >> m;
  
  int white = ((n+1)/2) * ((m+1)/2) + (n/2) * (m/2);
  int black = ((n+1)/2) * (m/2) + (n/2) * ((m+1)/2);

  cout << white << ' ' << black << '\n';
}
