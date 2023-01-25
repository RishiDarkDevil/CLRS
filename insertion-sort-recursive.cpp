// T(n) = T(n-1) + O(n) = O(n^2)
#include <bits/stdc++.h>
using namespace std;

void insertion_sort(vector<int> &arr, int i) {
	// Base Case
	if (i == 0)
		return;

	// sorting all the previous elements before ith index -- Induction Hypothesis
	insertion_sort(arr, i-1);

	// Induction step assuming prev 1... i-1 elements sorted, insert ith element in the correct spot
	int j = 0, k = i, ele = arr[i];
	while (j < i) {
		if (arr[j] > arr[i])
			break;
		j++;
	}
	while (k > j) {
		arr[k] = arr[k-1];
		k--;
	}
	arr[j] = ele;
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

	for (auto ele: arr)
		cout << ele << " ";
	cout << endl;

	insertion_sort(arr, n-1);

	for (auto ele: arr)
		cout << ele << " ";
	cout << endl;

}