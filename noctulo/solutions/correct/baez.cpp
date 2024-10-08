#include <iostream>
#include <string>

using namespace std;

int main() {
  string s1,s2;
  cin >> s1 >> s2;

  string fs1 = s1+s1+s1+s1+s1;
  string fs2 = s2+s2+s2+s2+s2+s2+s2;
  int ans = -1;
  for (int i=0;i<fs1.size();i++){
    if (fs1[i] == fs2[i]){
      ans = i;
      break;
    }
  }

  if (ans == -1) cout<<"No nos vemos nunca\n";
  else cout<<ans<<endl;

  return 0;
}
