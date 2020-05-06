#include "Heuristic.h"
#include "Operator.cpp"
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

//calculates misplaced tile heuristic and returns for constructor to pass as h_n
int calculate_misplaced(const MATRIX m, const MATRIX goal) {
	int misplaced = 0;
		for(int i = 0; i < MATRIX_SIZE; ++i) {
			for(int j = 0; j < MATRIX_SIZE; ++j) {
				if((m.at(i).at(j)) != (goal.at(i).at(j))) {
					misplaced++;
				}
			}
		}
	return misplaced;
}

//calculates euclidean distance heuristic for each tile in matrix to each tile in goal matrix.
int calculate_euclidean(const MATRIX m, const MATRIX n) {
	double total = 0;
	double temp1 = 0;
	double temp2 = 0;
	int row = 0;
	int col = 0;
	int f; //number to find for euclidean distance algorithm

	for (int i = 0; i < MATRIX_SIZE; ++i) {
		for (int j = 0; j < MATRIX_SIZE; ++j) {
			if((m.at(i).at(j)) != (n.at(i).at(j))) {
				f = n.at(i).at(j);
				find(m, row, col, f);
				temp1 = (i-row);
				temp1 = pow(temp1, 2);
				//cout << temp1 << endl;
				temp2 = (j - col);
				temp2 = pow(temp2, 2);
				//cout << temp2 << endl;
				temp2 = sqrt((temp1 + temp2));
				//cout << temp2 << endl;
				total += temp2;

				total = round(total);
			}
		}
	}

	return total;
}

