#include <iostream>
#include <vector>
using namespace std;

// Solución cúbica
// @ocimatic should-fail=[st3,st4]
int main() {
	int n;
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; ++i) {
		cin >> v[i];
	}
	int exitosos = 0, totales = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = i; j < n; ++j) {
			int actual = 0;
			for (int k = i; k <= j; ++k) {
				actual += v[k];
			}
			if (actual > 0) exitosos++;
			totales++;
		}
	}
	cout << exitosos << " " << totales << endl;
}
