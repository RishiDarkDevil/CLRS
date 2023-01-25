#include <bits/stdc++.h>
using namespace std;

void merge(vector<int> &arr, int p, int q, int r) {
	vector<int> temp;
	int i = p, j = r+1;

	while (i <= r && j <= q) {
		if (arr[i] > arr[j]) {
			temp.push_back(arr[j]);
			j++;
		} else {
			temp.push_back(arr[i]);
			i++;
		}
	}

	while (j <= q) {
		temp.push_back(arr[j]);
		j++;
	}
	while (i <= r) {
		temp.push_back(arr[i]);
		i++;
	}

	int m = 0;
	for (int k = p; k <= q; ++k) {
		arr[k] = temp[m++];
	}
}

void merge_sort(vector<int> &arr, int p, int q) {
	
	if (p >= q) 
		return;
	int r = (p+q)/2;

	merge_sort(arr, p, r);
	merge_sort(arr, r+1, q);
	merge(arr, p, q, r);
}

bool binary_search(vector<int> &arr, int p, int q, int x) {
	if (p > q)
		return false;
	int mid = (p+q)/2;
	if (x > arr[mid]) {
		return binary_search(arr, mid+1, q, x);
	} else if (x < arr[mid]) {
		return binary_search(arr, p, mid-1, x);
	} else {
		return true;
	}
}