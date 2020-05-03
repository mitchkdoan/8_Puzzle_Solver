#include "Operator.h"
#include <iostream>
#include <vector>

using namespace std;

void find(const MATRIX m, int &r, int &c) {
	for(r = 0; r < MATRIX_SIZE; ++r) {
		for(c = 0; c < MATRIX_SIZE; ++c) {
			if(m.at(r).at(c) == 0) {
				return;
			}
		}
	}
	return;
}

void swap(MATRIX &m, const int r1, const int c1, const int r2, const int c2) {
	int temp = m.at(r1).at(c1);
	m.at(r1).at(c1) = m.at(r2).at(c2);
	m.at(r2).at(c2) = temp;
	return;
}

MATRIX left(MATRIX m) {
	int row = 0;
	int column = 0; 
	find(m, row, column);

	swap(m, row, column, row, column - 1);
	return m;
}

MATRIX right(MATRIX m) {
	int row = 0;
	int column = 0; 
	find(m, row, column);

	swap(m, row, column, row, column + 1);
	return m;
}

MATRIX up(MATRIX m) {
	int row = 0;
	int column = 0; 
	find(m, row, column);

	swap(m, row, column, row - 1, column);
	return m;
}
MATRIX down(MATRIX m) {
	int row = 0;
	int column = 0; 
	find(m, row, column);

	swap(m, row, column, row + 1, column);
	return m;
}

void print_matrix(const MATRIX m) {
	for (int i = 0; i < m.size(); i++) { 
        for (int j = 0; j < m[i].size(); j++) 
            cout << m[i][j] << " "; 
        cout << endl; 
    } 
}

MATRIX create_matrix(const vector<int> v) {
	MATRIX matrix;

	vector<int> row1;
	vector<int> row2;
	vector<int> row3;

	for (int i = 0; i < MATRIX_SIZE; ++i) {
		row1.push_back(v.at(i));
		row2.push_back(v.at(i + 3));
		row3.push_back(v.at(i + 6));
	}

	matrix.push_back(row1); 
    matrix.push_back(row2); 
    matrix.push_back(row3);

	return matrix;
}
