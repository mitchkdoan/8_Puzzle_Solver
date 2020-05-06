#ifndef HEURISTIC_H
#define HEURISTIC_H

#include "Node.h"

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int calculate_misplaced(const MATRIX m, const MATRIX goal);
int calculate_euclidean(const MATRIX m, const MATRIX goal);

#endif