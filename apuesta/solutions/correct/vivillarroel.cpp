#include <iostream>
#include <vector>
#include <stack>
using namespace std;
typedef long long ll;

// Solución lineal
int main() {
	int n;
	cin >> n;
	vector<ll> v(n);
	for (int i = 0; i < n; ++i) {
		cin >> v[i];
	}
	stack<ll> sl, sr;
	ll l = 0, r = 0, actual = 1;

	ll exitosos = 0, totales = 0;
	for (int i = 0; i < n; ++i) {
		if (v[i] == -1) {
			sr.push(actual);
			r += actual;
			if (!sl.empty()) {
				actual = sl.top();
				sl.pop();
				l -= actual;
				actual++;
			}
			else {
				actual = 1;
			}
		}
		else {
			sl.push(actual);
			l += actual;
			if (!sr.empty()) {
				actual = sr.top();
				sr.pop();
				r -= actual;
				actual++;
			}
			else {
				actual = 1;
			}
		}
		exitosos += l;
		totales += i+1;

	}
	// cout << exitosos << " " << totales << endl;
	cout << exitosos << endl;
}
