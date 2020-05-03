#ifndef NODE_H
#define NODE_H
#define MATRIX_SIZE 3

#include <iostream>
#include <vector>

using namespace std;

typedef vector<vector<int> > MATRIX;

struct Node {
		//variables
		MATRIX matrix;
		Node *parent;

		//fucnctions
		Node(MATRIX m) {
			parent = 0;
			matrix = m;
		}
};

#endif