/*
Name:	Mitchell Doan 
SID:	862022288

CS 170 Project 1 (8 puzzle solver)
*/
#include "Node.h"
#include "Operator.cpp"

#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;

priority_queue <Node, vector<Node>, compare_nodes> frontier;
vector<Node> explored;

MATRIX goal_matrix() {
	vector<int> v;
	for(int i = 1; i < 9; ++i) {
		v.push_back(i);
	}
	v.push_back(0);

	MATRIX matrix = create_matrix(v);

	return matrix;
}

void search(MATRIX init_state) {
	//goal matrix which will be used to compare current state to goal state
	MATRIX goal = goal_matrix();

	//initial node
	Node *init_node = new Node(init_state, 0, 0);

	frontier.push(*init_node);

	while(1) {
		if(frontier.empty()) {
			cout << "failed" << endl;
			return;
		}
		else{
			Node temp = frontier.top();
			frontier.pop();
			Node *to_explore = &temp;

			//bool compare = compare_matrices(to_explore->matrix, goal);
			if(to_explore->matrix == goal) {
				cout << "success!" << endl;
				return;
			}
			else {
				explored.push_back(*to_explore);
				expand(explored, frontier, to_explore);
			}
		}
	}
}

int main() {
	string input;
	string algorithm;
	vector<int> v = {1,2,3,4,8,0,7,6,5};


	cout << "Welcome to 862022288 8 Puzzle Solver." << endl;

	while(1) {
		cout << "Type \"1\" to use a default puzzle, or \"2\" to enter your own puzzle: ";
		cin >> input; 

		if(input == "1") {
			cout << "Default" << endl;
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
	print_matrix(matrix);

    //Choose Algorithm		
	while(1) {
		cout << "Enter your choice of algorithm\n1 Uniform Cost Search\n2 A* with the Misplaced Tile heuristic.\n3 A* with the Eucledian distance heuristic." << endl;
		cin >> algorithm;

		if(algorithm == "1") {
			cout << "Uniform Cost Search" << endl;
			search(matrix);
			break;
		}

		else if(algorithm == "2") {
			cout << "A* with Misplaced Tile heuristic" << endl;
			break;
		}

		else if(algorithm == "3") {
			cout << "A* with Euclidian distacnce heuristic" << endl;
			break;
		}

		else {
			cout << "Invalid input." << endl;		
		}
	}


	return 0;
}