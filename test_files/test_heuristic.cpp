// testing heuristic functions
#include "Heuristic.cpp"
#include <iostream>
#include <vector>

using namespace std;

int main() {
	vector<int> v1 = {0,2,3,4,5,6,7,8,1};
	vector<int> v2 = {1,2,3,4,5,6,7,8,0};
	MATRIX m1 = create_matrix(v1);
	MATRIX m2 = create_matrix(v2);

	int total = calculate_euclidean(m1, m2);

	cout << "Expecting rad 16 got: " << total << endl;

	return 0;
}