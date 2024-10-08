#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

// Debería fallar cuando no hay igual cantidad de blancos y negros
// (n y m impares). Solo pasa st3
// @ocimatic should-fail=[st1,st2,st4]
int main(){
  ll n, m;
  cin >> n >> m;
  
  ll white = n*m/2;
  ll black = white;

  cout << white << ' ' << black << '\n';
}
