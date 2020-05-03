//Test Node
#include "Operator.cpp"

#include <iostream>
#include <vector>

using namespace std;

int main() {
	//create matrices
	vector<int> v1 = {1,2,3,4,5,6,7,8,0};
	vector<int> v2 = {4,5,6,7,8,0,1,2,3};
	vector<int> v3 = {7,8,0,1,2,3,4,5,6};
	MATRIX m1 = create_matrix(v1);
	MATRIX m2 = create_matrix(v2);
	MATRIX m3 = create_matrix(v3);

	//create nodes
	Node *grandpa = new Node(m1);
	Node *dad = new Node(m2);
	Node *son = new Node(m3);

	dad->parent = grandpa;
	son->parent = dad;

	cout << "dad's parent's matrix" << endl;
	print_matrix(dad->parent->matrix);
	cout << "son's parent's matrix" << endl;
	print_matrix(son->parent->matrix);
}