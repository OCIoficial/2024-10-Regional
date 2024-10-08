#include <bits/stdc++.h>

using namespace std;

// @ocimatic should-fail=[st2,st3,st4]
int main(){
  int n, m;
  cin >> n >> m;

  int white=0, black=0;
  for(int i=0; i<n; i++){
    for(int j=0; j<m; j++){
      if((i+j)%2==0) white++;
      else black++;
    }
  }
  cout << white << ' ' << black << '\n';
}
