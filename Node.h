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
		int g_n;
		int h_n;
		int f_n;

		//fucnctions
		Node(MATRIX m, int g, int h) {
			parent = 0;
			matrix = m;
			g_n = g;
			h_n = h;
			f_n = g_n + h_n;
		}
};

struct compare_nodes {  
	bool operator()(const Node &ln, const Node &rn) {  
		return ln.f_n > rn.f_n;  
	}  
};  

#endif