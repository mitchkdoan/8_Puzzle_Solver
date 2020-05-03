#ifndef OPERATOR_H
#define OPERATOR_H

#include "Node.h"

#include <iostream>
#include <vector>

using namespace std;

void find(const MATRIX m, int &r, int &c);
void swap(MATRIX &m, const int r1, const int c1,const int r2, const int c2);
MATRIX left(MATRIX m);
MATRIX right(MATRIX m);
MATRIX up(MATRIX m);
MATRIX down(MATRIX m);
void print_matrix(const MATRIX m);
MATRIX create_matrix(const vector<int> v);

#endif