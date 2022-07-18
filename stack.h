//
// Created by Aaron Gong on 3/30/21.
//
#include <stdbool.h>
#include "node.h"

#ifndef PS4_STACK_H
#define PS4_STACK_H
void push(node*);
node* peek();
node* pop(int*);
void printstack();
void clearStack(int*);
bool is_Empty();

#endif //PS4_STACK_H
