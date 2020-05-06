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
		Node *parent = NULL;
		int g_n;	//cost to get from initial node to current node
		int h_n;	//heuristic 
		int f_n;	//g_n + h_n

		//Constructor
		Node(MATRIX m, int g, int h) {
			matrix = m;
			g_n = g;
			h_n = h;
			f_n = g_n + h_n;
		}
};

//Used to order priority in priority queue
struct compare_nodes {  
	bool operator()(const Node &ln, const Node &rn) {  
		return ln.f_n > rn.f_n;  
	}  
};  

#endif