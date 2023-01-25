#include "helper.h"
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
	int sum;
	cin >> sum;

	merge_sort(arr, 0, n-1);

	bool flag = false;
	for (auto ele: arr) {
		if (binary_search(arr, 0, n-1, sum - ele)) {
			flag = true;
			break;
		}
	}
	if (flag)
		cout << "Contains";
	else
		cout << "Does Not Contain";

}