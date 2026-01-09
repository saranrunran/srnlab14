#include<iostream>
using namespace std;

const int N = 5;

void inputMatrix(double [][N]);

void findLocalMax(const double [][N], bool [][N]);

void showMatrix(const bool [][N]);

int main(){
	double A[N][N]; 
	bool B[N][N]; 
	cout << "Input the matrix.....\n";
	inputMatrix(A);
	findLocalMax(A,B);
	cout << "Result is \n";
	showMatrix(B);
	return 0;
}

//Do not modify source code above this line 

void inputMatrix(double np[][N]) {
	for (int i = 1; i <= N; i++) {
		cout << "Row " << i << ": ";
		for (int j = 0; j < N; j++) {
			cin >> np[i-1][j];
		}
	}
}

void findLocalMax(const double x[][N], bool b[][N]) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)	{
			if (i == 0 || i == N-1 || j == 0 || j == N-1) {
				b[i][j] = 0;
			} else if (x[i][j] >= x[i][j+1] && x[i][j] >= x[i][j-1] && x[i][j] >= x[i+1][j] && x[i][j] >= x[i-1][j]) {
				b[i][j] = 1;
			} else {
				b[i][j] = 0;
			}
		}
	}
}

void showMatrix(const bool a[][N]) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++){
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
}