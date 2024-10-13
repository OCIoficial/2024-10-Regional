#include <iostream>
#include <vector>
using namespace std;

// Solución cuadráticaj
// @ocimatic should-fail=[st4]
int main() {
	int n;
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; ++i) {
		cin >> v[i];
	}

	// pfx[i+1] guarda la suma acumulada hasta i
	vector<int> pfx(n+1);
	pfx[0] = 0;
	for (int i = 0; i < n; ++i) {
		pfx[i+1] = pfx[i] + v[i];
	}

	int exitosos = 0, totales = 0;
	for (int i = 1; i <= n; ++i) {
		for (int j = i; j <= n; ++j) {
			if (pfx[j] - pfx[i-1] > 0) exitosos++;
			totales++;
		}
	}
	// cout << exitosos << " " << totales << endl;
	cout << exitosos << endl;
}
