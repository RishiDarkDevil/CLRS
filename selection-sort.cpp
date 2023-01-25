// In all cases it has O(n^2) time complexity
#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> arr;
	for (int i = 0; i < n; ++i) {
		int x;
		cin >> x;
		arr.push_back(x);
	}

	for (auto ele: arr)
		cout << ele << " ";
	cout << endl;

	for (int i = 0; i < n-1; ++i) {
		int min = i;

		for (int j = i+1; j < n; ++j) {
			if (arr[j] <= arr[min])
				min = j;
		}
		
		int temp = arr[i];
		arr[i] = arr[min];
		arr[min] = temp;
	}

	for (auto ele: arr)
		cout << ele << " ";
}