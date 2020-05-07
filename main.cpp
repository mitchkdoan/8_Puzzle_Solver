/*
Name:	Mitchell Doan 
SID:	862022288

CS 170 Project 1 (8 puzzle solver)
*/
#include "Node.h"
#include "Heuristic.cpp"

#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <stack>

using namespace std;

//important data structures
priority_queue <Node, vector<Node>, compare_nodes> frontier;
vector<Node> explored;
stack<MATRIX> s;

//used to output max size of frontier
int frontier_max = 0;

//calculate goal matrix
MATRIX goal_matrix() {
	vector<int> v;
	for(int i = 1; i < 9; ++i) {
		v.push_back(i);
	}
	v.push_back(0);

	MATRIX matrix = create_matrix(v);

	return matrix;
}

//differs from print_matrix: doesnt print "Expanding"
void display_matrix(const MATRIX matrix) {
	int row;
	int col;
	find(matrix, row, col, 0);

	for (int i = 0; i < matrix.size(); i++) { 
        for (int j = 0; j < matrix[i].size(); j++) {
        	if((i == row) && (j == col)) {
        		cout << 'b' << " ";
        	}
            else {
            	cout << matrix[i][j] << " "; 
        	}
    	}
        cout << endl;
	}
}

//output success messages;
void success_message() {
	cout << "GOAL!!!\n\n";
	cout << "To solve this problem, the search algorithm expanded a total of " << explored.size() << " nodes." << endl;
	cout << "The maximum number of nodes in the queue at any one time: " << frontier_max << endl;
	return;
}

void load_stack(Node* curr) {
	while(curr != 0) {
		s.push(curr->matrix);
		curr = curr->parent;
	}
}

//expands passed in node and adds non-explored nodes to frontier.
int expand(Node *p, const string algorithm, const MATRIX goal) {
	int row = 0;
	int column = 0;
	vector<Node *> children;

	find(p->matrix, row, column, 0);
	
	if(column != 0) {
		MATRIX lm = left(p->matrix);
		int h_n = 0;
		int g_n = p->g_n + 1;
		if(algorithm != "1") {
			if(algorithm == "2") {
				h_n = calculate_misplaced(lm, goal);
			}
			else{
				//g_n = calculate_euclidean(lm, init);
				h_n = calculate_euclidean(lm, goal);
			}
		}
		Node *left_child = new Node(lm, g_n, h_n);
		left_child->parent = p;
		children.push_back(left_child);
	}

	if(column != 2) {
		MATRIX rm = right(p->matrix);
		int h_n = 0;
		int g_n = p->g_n + 1;
		if(algorithm != "1") {
			if(algorithm == "2") {
				h_n = calculate_misplaced(rm, goal);
			}
			else{
				//g_n = calculate_euclidean(rm, init);
				h_n = calculate_euclidean(rm, goal);
			}
		}
		Node *right_child = new Node(rm, g_n, h_n);
		right_child->parent = p;
		children.push_back(right_child);
	}

	if(row != 0) {
		MATRIX um = up(p->matrix);
		int h_n = 0;
		int g_n = p->g_n + 1;
		if(algorithm != "1") {
			if(algorithm == "2") {
				h_n = calculate_misplaced(um, goal);
			}
			else{
				//g_n = calculate_euclidean(um, init);
				h_n = calculate_euclidean(um, goal);
			}
		}
		Node *up_child = new Node(um, g_n, h_n);
		up_child->parent = p;
		children.push_back(up_child);
	}

	if(row != 2) {
		MATRIX dm = down(p->matrix);
		int h_n = 0;
		int g_n = p->g_n + 1;
		if(algorithm != "1") {
			if(algorithm == "2") {
				h_n = calculate_misplaced(dm, goal);
			}
			else{
				//g_n = calculate_euclidean(dm, init);
				h_n = calculate_euclidean(dm, goal);
			}
		}
		Node *down_child = new Node(dm, g_n, h_n);
		down_child->parent = p;
		children.push_back(down_child);
	}

	for(int i = 0; i < explored.size(); ++i) {
		for(int j = 0; j < children.size(); ++j) {
			if(((children.at(j))->matrix) == ((explored.at(i)).matrix)) {
				children.erase(children.begin() + j);
			}
		}
	}

	for(int i = 0; i < children.size(); ++i) {
		frontier.push(*(children.at(i)));
	}

	return children.size();
}

void search(const MATRIX init_state, const string algorithm) {
	//goal matrix which will be used to compare current state to goal state
	MATRIX goal = goal_matrix();

	//used when solution is found but still searching for better solution
	Node* solution = 0;
	bool found = false;

	//initial node
	Node *init_node = new Node(init_state, 0, 0);

	frontier.push(*init_node);
	frontier_max++;

	if(init_state == goal) {
		success_message();
		load_stack(init_node);
		return;
	}

	cout << "Expanding State" << endl;
	print_matrix(init_node->matrix);
	frontier.pop();
	explored.push_back(*init_node);
	expand(init_node, algorithm, goal);

	while(1) {
		if(frontier.empty()) {
			if(solution == 0){
				cout << "\nNo solution" << endl;
				return;
			}

			else {
				success_message();
				load_stack(solution);
				return;
			}
		}

		else{
			if(frontier.size() > frontier_max) {
				frontier_max = frontier.size();
			}

			Node* to_explore = new Node(frontier.top());
			frontier.pop();
			explored.push_back(*to_explore);

			if(to_explore->matrix == goal) {
				if(algorithm == "1") {
					success_message();
					load_stack(to_explore);
					return;
				}
				else if(solution == 0) {
					found = true;
					solution = to_explore;
				}
				else {
					if((to_explore->g_n) < (solution->g_n)){
						solution = to_explore;
					}
				}
			}

			else {
				if(found == false) {
					cout << "The best state to expand with g(n) = " << to_explore->g_n << " and h(n) = " << to_explore->h_n << " is..." << endl;
					print_matrix(to_explore->matrix);
					expand(to_explore, algorithm, goal);
				}
			}
		}
	}
}

void trace_back(){
	int moves = 0;
	cout << "\nTracing Back:\n\nInitial Matrix:" << endl;
	while(!(s.empty())) {
		display_matrix(s.top());
		cout << endl;
		s.pop();
		++moves;
	}
	cout << "Total of " << moves - 1 << " moves.\n\nTrace back complete.\n" << endl;
	return;
}

int main() {
	string input;
	string algorithm;
	vector<int> v = {1,2,3,4,5,6,7,8,0};
	vector<int> doable = {0,1,2,4,5,3,7,8,6};
	vector<int> ohboy = {8,7,1,6,0,2,5,4,3};

	//
	cout << "Welcome to Mitchell Doan's (862022288) 8 Puzzle Solver." << endl;

	while(1) {
		cout << "Type \"1\" to use a default puzzle, or \"2\" to enter your own puzzle: ";
		cin >> input; 

		if(input == "1") {
			while(1) {
				cout << "Choose Level (1-5): ";
				cin >> input;
				if(input == "1") {
					break;
				}
				else if(input == "2") {
					int temp = v.at(8);
					v.at(8) = v.at(7);
					v.at(7) = temp;
					break;
				}
				else if(input == "3") {
					int temp = v.at(8);
					v.at(8) = v.at(5);
					v.at(5) = v.at(2);
					v.at(2) = temp;
					break;
				}
				else if(input == "4") {
					v = doable;
					break;
				}
				else if(input == "5") {
					v = ohboy;
					break;
				}
				else {
					cout << "Invalid input." << endl;
				}
			}
			break;
		}

		else if(input == "2") {
			cout << "Enter your puzzle, use a zero to represent the blank. \nEnter the first row, use space between numbers: ";
			cin >> v.at(0) >> v.at(1) >> v.at(2);
			cout << "Enter the second row, use space between numbers: ";
			cin >> v.at(3) >> v.at(4) >> v.at(5);
			cout << "Enter the third row, use space between numbers: ";	
			cin >> v.at(6) >> v.at(7) >> v.at(8);
			break;
		}

		else {
			cout << "Invalid input." << endl;		
		}
	}


	//Make Matrix
	MATRIX matrix = create_matrix(v);

    //Display Matrix 
    cout << "\nYour Matrix:" << endl;
	display_matrix(matrix);

    //Choose Algorithm		
	while(1) {
		cout << "\nEnter your choice of algorithm\n1 Uniform Cost Search\n2 A* with the Misplaced Tile heuristic.\n3 A* with the Eucledian distance heuristic." << endl;
		cin >> algorithm;

		if((algorithm != "1") && (algorithm != "2") && (algorithm != "3")) {
			cout << "Invalid input. ";
		}
		else {
			if(algorithm == "1") {
				cout << "Uniform Cost Search\n\n";
			}

			else if(algorithm == "2") {
				cout << "A* with Misplaced Tile heuristic\n\n";
			}

			else if(algorithm == "3") {
				cout << "A* with Euclidian distacnce heuristic\n\n";
			}
			search(matrix, algorithm);
			break;
		}
	}

	cout << "\nInput 1 to view trace back, any other key to exit: " << endl;
	cin >> input;

	if(input == "1") {
		trace_back();
	}

	return 0;
}