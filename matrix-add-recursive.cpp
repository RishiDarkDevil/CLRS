#include "helper.h"
#include <bits/stdc++.h>
using namespace std;

void matrix_add(
	vector<vector<int>> &A, 
	vector<vector<int>> &B, 
	vector<vector<int>> &C,
	int a_r1, int a_r2, int a_c1, int a_c2,
	int b_r1, int b_r2, int b_c1, int b_c2) {

	// base case
	if ((a_r1 > a_r2) || (a_c1 > a_c2) || (b_r1 > b_r2) || (b_c1 > b_c2))
		return;

	if (a_r1 - a_r2 == 0) {
		C[a_r1][b_c1] = A[a_r1][a_c1] + B[b_r1][b_c1];
		return;
	}

	// divide

	int mid_a_r = (a_r1 + a_r2) / 2;
	int mid_a_c = (a_c1 + a_c2) / 2;
	int mid_b_r = (b_r1 + b_r2) / 2;
	int mid_b_c = (b_c1 + b_c2) / 2;

	matrix_add(A, B, C, a_r1, mid_a_r, a_c1, mid_a_c, b_r1, mid_b_r, b_c1, mid_b_c);
	matrix_add(A, B, C, a_r1, mid_a_r, mid_a_c+1, a_c2, b_r1, mid_b_r, mid_b_c+1, b_c2);
	matrix_add(A, B, C, mid_a_r+1, a_r2, a_c1, mid_a_c, mid_b_r+1, b_r2, b_c1, mid_b_c);
	matrix_add(A, B, C, mid_a_r+1, a_r2, mid_a_c+1, a_c2, mid_b_r+1, b_r2, mid_b_c+1, b_c2);
}

int main() {
	// input matrix size
	int n;
	cin >> n;

	// pad length
	int pad_length = bin_exp(2, (int)log2(n)+1) - n;

	// input matrices
	vector<vector<int>> A, B, C;
	input_matrix(A, n);
	input_matrix(B, n);
	input_matrix(C, n, true);

	pad_matrix(A, pad_length);
	pad_matrix(B, pad_length);
	pad_matrix(C, pad_length);

	cout << "A" << endl;
	print_matrix(A, n);
	cout << endl;

	cout << "B" << endl;
	print_matrix(B, n);
	cout << endl;
	
	cout << "C" << endl;
	print_matrix(C, n);
	cout << endl;

	matrix_add(A, B, C, 0, n+pad_length-1, 0, n+pad_length-1, 0, n+pad_length-1, 0, n+pad_length-1);

	cout << "C" << endl;
	print_matrix(C, n);
	cout << endl;
}