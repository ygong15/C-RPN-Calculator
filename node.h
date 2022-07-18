//
// Created by Aaron Gong on 3/30/21.
//

#ifndef PS4_NODE_H
#define PS4_NODE_H
typedef struct node node;

enum type{NUMBER, OPERATOR};

node* createNode(char*, int*);

#endif //PS4_NODE_H
