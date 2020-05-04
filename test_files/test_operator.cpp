//Test Operators
#include "Operator.cpp"

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
	//solved matrix
	vector<int> v;
	for(int i = 1; i < 9; ++i) {
		v.push_back(i);
	}
	v.push_back(0);

	MATRIX matrix = create_matrix(v);
	int input;
	cout << "1 to test matrix operations\n2 to compare matrix to goal matrix\n3 to test expand func:  ";
	cin >> input;

	if(input == 1) {
		cout << "original" << endl;
		print_matrix(matrix);

		matrix = left(matrix);
		cout << "left" << endl;
		print_matrix(matrix);

		matrix = up(matrix);
		cout << "up" << endl;
		print_matrix(matrix);

		matrix = right(matrix);
		cout << "right" << endl;
		print_matrix(matrix);

		matrix = down(matrix);
		cout << "down" << endl;
		print_matrix(matrix);
	}
	else if(input == 2) {
		vector<int> input_vector;
		int in;

		cout << "input 8 puzzle" << endl;
		for(int i = 0; i < 9; ++i) {
			cin >> in;
			input_vector.push_back(in);
		}

		MATRIX input_matrix = create_matrix(input_vector);

		//bool match = compare_matrices(input_matrix, matrix);
		if(input_matrix == matrix) {
			cout << "match" << endl;
		}
		else {
			cout << "not a match" << endl;
		}
	}
	else if(input == 3) {
		priority_queue <Node, vector<Node>, compare_nodes> frontier;
		vector<Node> explored;

		vector<int> v1 = {0,1,2,3,4,5,6,7,8};
		MATRIX m1 = create_matrix(v1);

		vector<int> v2 = {1,0,2,3,4,5,6,7,8};
		MATRIX m2 = create_matrix(v2);

		vector<int> v3 = {3,1,2,0,4,5,6,7,8};
		MATRIX m3 = create_matrix(v3);

		Node *n1 = new Node(m1, 0, 0);
		Node *n2 = new Node(m2, 1, 0);
		Node *n3 = new Node(m3, 2, 0);

		frontier.push(*n2);
		frontier.push(*n3);
		frontier.push(*n1);

		cout << "should print out 0 1 2" << endl;
		print_matrix(frontier.top().matrix);
		frontier.pop();
		
		cout << "should print out 1 0 2" << endl;		
		print_matrix(frontier.top().matrix);
		frontier.pop();

		cout << "should print out 3 1 2" << endl;		
		print_matrix(frontier.top().matrix);
		frontier.pop();
		
		frontier.push(*n1);

		cout << "Priority queue size expecting 1 got: " << frontier.size() << endl;

		int expanded = expand(explored, frontier, n1);

		cout << "expanded nodes expecting 2 and got: " << expanded << endl;

		cout << "Priority queue after expand expecting 3 got: " << frontier.size() << endl;
		
		print_matrix(frontier.top().matrix);
	}

	return 0;
}