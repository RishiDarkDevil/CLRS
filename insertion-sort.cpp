#include <bits/stdc++.h>
using namespace std;

void insertion_sort(vector<int> &arr) {
	for (int i = 1; i < arr.size(); ++i) {
		int key = arr[i];
		int j = i-1;
		while (j >= 0 && key >= arr[j]) {
			arr[j+1] = arr[j];
			j -= 1;
		}
		arr[j+1] = key;
	}
}

void print_arr(vector<int> &arr) {
	for (int i = 0; i < arr.size(); ++i)
		cout << arr[i] << " ";
}

int main() {
	int n;
	vector<int> arr;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		int x;
		cin >> x;
		arr.push_back(x);
	}
	print_arr(arr);
	cout << endl;
	insertion_sort(arr);
	print_arr(arr);
}