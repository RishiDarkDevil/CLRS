#include <bits/stdc++.h>
using namespace std;

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

// prints matrice
void print_matrix(vector<vector<int>> &matrix, int n) {
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
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

int main() {
	// input matrix size -- powers of 2 allowed only
	int n;
	cin >> n;

	// input matrices
	vector<vector<int>> A, B, C;
	input_matrix(A, n);
	input_matrix(B, n);
	input_matrix(C, n, true);

	cout << "A" << endl;
	print_matrix(A, n);
	cout << endl;

	cout << "B" << endl;
	print_matrix(B, n);
	cout << endl;
	
	cout << "C" << endl;
	print_matrix(C, n);
	cout << endl;

	matrix_multiply(A, B, C, 0, n-1, 0, n-1, 0, n-1, 0, n-1);

	cout << "C" << endl;
	print_matrix(C, n);
	cout << endl;
	

}