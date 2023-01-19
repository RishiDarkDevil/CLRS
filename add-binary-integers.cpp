#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;

	vector<int> A, B, C(n+1, 0);
	for (int i = 0; i < n; ++i) {
		bool x;
		cin >> x;
		A.push_back((int)x);
	}
	for (int i = 0; i < n; ++i) {
		bool x;
		cin >> x;
		B.push_back((int)x);
	}

	int carry = 0;
	for (int i = n-1; i >= 0; --i) {
		int add = A[i] + B[i] + carry;
		C[i+1] = add % 2;
		if (add <= 1)
			carry = 0;
		else
			carry = 1;
	}
	C[0] = carry;

	for (int i = 0; i < n+1; ++i)
		cout << C[i] << " ";

}