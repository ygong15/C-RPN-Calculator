//
// Created by Aaron Gong on 3/30/21.
//

#include "node.h"
#include <stdlib.h>
#include <stdio.h>
#include "errors.h"
#include "ctype.h"

typedef struct node{
    union{
        double value;
        char operator;
    } contents;
    int type;
    int precedence;
    node* next;
} node;


node* createNode(char *input, int* status){
    node* theNode;
    char value = *input;
    char **check_val = NULL;
    theNode = (struct node*) malloc(sizeof(node));
    if(theNode){
        if (value == '+' || value== '-' || value=='*' || value== '/' || value == '^' || value == '(' || value == ')'){
            theNode ->type = OPERATOR;
            switch (value) {
                case '+':
                    theNode->contents.operator = '+';
                    theNode->precedence = 2;
                    break;
                case '-':
                    theNode->contents.operator = '-';
                    theNode->precedence = 2;
                    break;
                case '*':
                    theNode->contents.operator = '*';
                    theNode->precedence = 3;
                    break;
                case '/':
                    theNode->contents.operator = '/';
                    theNode->precedence = 3;
                    break;
                case '^':
                    theNode->contents.operator = '^';
                    theNode->precedence = 4;
                    break;
                case '(':
                    theNode->contents.operator = '(';
                    break;
                case ')':
                    theNode->contents.operator = ')';
                    break;
                default:
                    theNode->contents.value = 0;
            }
            theNode->next = NULL;
        }else{
            double num = strtod(input, check_val);
            if(isdigit(value)!=0){
                theNode->contents.value = num;
                theNode->type = NUMBER;
                theNode->next = NULL;
            }else{
                *status = wrongoperator;
            }

        }
    }
    else{
        *status = nullpointer;
    }
    return theNode;
}
