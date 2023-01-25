// T(n) = T(n/2) + O(1) = O(log n)
#include <bits/stdc++.h>
using namespace std;

bool binary_search(vector<int> &arr, int p, int q, int x) {
	if (p <= q) {
		int mid = (p+q)/2;
		if (x > arr[mid]) {
			return binary_search(arr, mid+1, q, x);
		} else if (x < arr[mid]) {
			return binary_search(arr, p, mid-1, x);
		} else {
			return true;
		}
	}
	return false;
}

int main() {
	int n;
	cin >> n;
	vector<int> arr;
	for (int i = 0; i < n; ++i) {
		int x;
		cin >> x;
		arr.push_back(x);
	}
	int x;
	cin >> x;

	if (binary_search(arr, 0, n-1, x)) {
		cout << "Found";
	} else {
		cout << "Not Found";
	}
}