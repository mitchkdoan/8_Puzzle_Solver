//Test Operators
#include "Operator.cpp"

#include <iostream>
#include <vector>

using namespace std;

int main() {
	vector<int> v;
	for(int i = 0; i < 9; ++i) {
		v.push_back(i);
	}

	MATRIX matrix = create_matrix(v);

	cout << "original" << endl;
	print_matrix(matrix);

	matrix = right(matrix);
	cout << "right" << endl;
	print_matrix(matrix);

	matrix = down(matrix);
	cout << "down" << endl;
	print_matrix(matrix);

	matrix = left(matrix);
	cout << "left" << endl;
	print_matrix(matrix);

	matrix = up(matrix);
	cout << "up" << endl;
	print_matrix(matrix);

	return 0;
}