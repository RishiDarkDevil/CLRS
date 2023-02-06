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

// inputs matrices or fills them with zero
void input_matrix(vector<vector<int>> &matrix, int n, bool fill_zero = false) {
	for (int i = 0; i < n; ++i) {
		vector<int> row;
		for (int j = 0; j < n; ++j) {
			if (fill_zero) {
				row.push_back(0);
			} else {
				int x;
				cin >> x;
				row.push_back(x);
			}
		}
		matrix.push_back(row);
	}
}

void pad_matrix(vector<vector<int>> &matrix, int pad_length) {
	
	vector<int> zero_row;
	for (int i = 0; i < matrix[0].size(); ++i) {
		zero_row.push_back(0);
	}

	for (int i = 0; i < pad_length; ++i) {
		matrix.push_back(zero_row);
	}

	for (int i = 0; i < matrix.size(); ++i) {
		for (int j = 0; j < pad_length; ++j) {
			matrix[i].push_back(0);
		}
	}
}

// prints matrice
void print_matrix(vector<vector<int>> &matrix, int n) {
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
}

int bin_exp(int a, int b) {
	int res = 1;
	while(b) {
		if (b & 1)
			res *= a;
		a *= a;
		b >>= 1;
	}
	return res;
}

// multiplies A and B based on the partitions and stores the result in a partition of C
void matrix_multiply(
	vector<vector<int>> &A,
	vector<vector<int>> &B, 
	vector<vector<int>> &C,
	int a_r1, int a_r2, int a_c1, int a_c2,
	int b_r1, int b_r2, int b_c1, int b_c2) {

	// base case
	if ((a_r1 > a_r2) || (a_c1 > a_c2) || (b_r1 > b_r2) || (b_c1 > b_c2))
		return;

	if (a_r1 - a_r2 == 0) {
		C[a_r1][b_c1] += A[a_r1][a_c1] * B[b_r1][b_c1];
		return;
	}

	// divide
	// Initially I was doing lot of completed checks with ceil, min etc. 
	// Instead a better option was do the simple calculation here and restrict unwanted cases in the base case

	int mid_a_r = (a_r1 + a_r2) / 2;
	int mid_a_c = (a_c1 + a_c2) / 2;
	int mid_b_r = (b_r1 + b_r2) / 2;
	int mid_b_c = (b_c1 + b_c2) / 2;

	matrix_multiply(A, B, C, a_r1, mid_a_r, a_c1, mid_a_c, b_r1, mid_b_r, b_c1, mid_b_c);
	matrix_multiply(A, B, C, a_r1, mid_a_r, mid_a_c+1, a_c2, mid_b_r+1, b_r2, b_c1, mid_b_c);
	matrix_multiply(A, B, C, a_r1, mid_a_r, a_c1, mid_a_c, b_r1, mid_b_r, mid_b_c+1, b_c2);
	matrix_multiply(A, B, C, a_r1, mid_a_r, mid_a_c+1, a_c2, mid_b_r+1, b_r2, mid_b_c+1, b_c2);
	matrix_multiply(A, B, C, mid_a_r+1, a_r2, a_c1, mid_a_c, b_r1, mid_b_r, b_c1, mid_b_c);
	matrix_multiply(A, B, C, mid_a_r+1, a_r2, mid_a_c+1, a_c2, mid_b_r+1, b_r2, b_c1, mid_b_c);
	matrix_multiply(A, B, C, mid_a_r+1, a_r2, a_c1, mid_a_c, b_r1, mid_b_r, mid_b_c+1, b_c2);
	matrix_multiply(A, B, C, mid_a_r+1, a_r2, mid_a_c+1, a_c2, mid_b_r+1, b_r2, mid_b_c+1, b_c2);
}