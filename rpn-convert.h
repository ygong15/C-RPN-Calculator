//
// Created by Aaron Gong on 4/16/21.
//

#ifndef PS5_RPN_CONVERT_H
#define PS5_RPN_CONVERT_H

#include <stdbool.h>
#include "node.h"

void conversion (char*, char*, int*);
bool left_right_associative(node*);
int size_of_double(node*);
#endif //PS5_RPN_CONVERT_H
