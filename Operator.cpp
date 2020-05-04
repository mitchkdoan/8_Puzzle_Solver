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

// bool compare_matrices(const MATRIX m, const MATRIX goal_matrix) {
// 	for (int i = 0; i < MATRIX_SIZE; ++i) {
// 		for (int j = 0; j < MATRIX_SIZE; ++j) {
// 			if((m.at(i).at(j)) != (goal_matrix.at(i).at(j))) {
// 				return false;
// 			}
// 		}
// 	}
// 	return true;
// }

int expand(const vector<Node> explored, priority_queue<Node, vector<Node>, compare_nodes> &frontier, Node *parent) {
	// print_matrix(parent->matrix);
	// cout << "----------" << endl;

	int row = 0;
	int column = 0;
	vector<Node *> children;

	find(parent->matrix, row, column);
	
	if(column != 0) {
		//cout << "left" << endl;
		Node *left_child = new Node(left(parent->matrix), parent->g_n + 1, 0);
		children.push_back(left_child);
	}
	if(column != 2) {
		//cout << "right" << endl;
		Node *right_child = new Node(right(parent->matrix), parent->g_n + 1, 0);
		children.push_back(right_child);
	}
	if(row != 0) {
		//cout << "up" << endl;
		Node *up_child = new Node(up(parent->matrix), parent->g_n + 1, 0);
		children.push_back(up_child);
	}
	if(row != 2) {
		//cout << "down" << endl;
		Node *down_child = new Node(down(parent->matrix), parent->g_n + 1, 0);
		children.push_back(down_child);
	}

	for(int i = 0; i < explored.size(); ++i) {
		for(int j = 0; j < children.size(); ++j) {
			if(((children.at(j))->matrix) == ((explored.at(i)).matrix)) {
				children.erase(children.begin() + j);
				//cout << "here" << endl;
			}
		}
	}

	for(int i = 0; i < children.size(); ++i) {
		// print_matrix(children.at(i)->matrix);
		// cout << "---------------" << endl;
		frontier.push(*(children.at(i)));
	}

	return children.size();
}
