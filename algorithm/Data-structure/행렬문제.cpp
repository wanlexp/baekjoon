#include <iostream>
#include <algorithm>
using namespace std;
int main() {
	int mat[5][5] = {
		{0, 0, 0, 0, 0},
		{0, 6, 7, 12, 5},
		{0, 5, 3, 11, 18},
		{0, 7, 17, 3, 3},
		{0, 8, 10, 14, 9}
	};
	for (int row = 1; row < 5; row++) {
		for (int col = 1; col < 5; col++) {
			mat[row][col] =mat[row][col]+ max( max( mat[row - 1][col], mat[row][col - 1]), mat[row - 1][col - 1]);
		}
	}

	cout << mat[4][4];
	return 0;
}