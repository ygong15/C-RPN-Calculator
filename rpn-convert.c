//
// Created by Aaron Gong on 4/16/21.
//

#include "rpn-convert.h"
#include "node.h"
#include "stack.h"
#include "errors.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct node{
    union{
        double value;
        char operator;
    } contents;
    int type;
    int precedence;
    node* next;
} node;
bool left_right_associative(node* peek_val){
    if (peek_val->contents.operator != '^'){
        return true;
    }
    return false;
}
int size_of_double(node* newNode){
    int cal = (int)newNode->contents.value;
    int result = 0;
    do{
        result++;

        cal/=10;
    }while(cal != 0);
        return result;
}
void conversion (char* infix_array, char* postfix_array, int* status){
    *status = SUCCESS;
    node* newNode = NULL;
    node* pop_val = NULL;
    bool is_left_encountered = false;
    char* token = strtok(infix_array, " ");
    while (token != NULL){
        newNode = createNode(token, status);
        if (newNode->type == NUMBER){
            int cal = size_of_double(newNode);
            strncat(postfix_array, token, cal);
            strncat(postfix_array, " ", 1);
        }else if (newNode->type == OPERATOR && newNode->contents.operator != '(' && newNode->contents.operator!=')'){
            //char B = newNode->contents.operator;
            //puts(&B);
            pop_val = peek();
            while ((is_Empty() != true) &&
            ((pop_val->precedence > newNode->precedence) || (pop_val->precedence == newNode->precedence && left_right_associative(pop_val) == true))
            && (newNode->contents.operator != '(')){
                pop_val = pop(status);
                if(*status != SUCCESS){
                    return;
                }
                strncat(postfix_array, &pop_val->contents.operator, 1);
                strncat(postfix_array, " ", 1);
                free(pop_val);
                pop_val = NULL;
                pop_val = peek();
            }
            push(newNode);
        }else if (newNode->contents.operator == '('){
            push(newNode);
        }else if (newNode->contents.operator == ')'){
            while(is_Empty() != true){
                pop_val = pop(status);
                if(*status != SUCCESS){
                    free(pop_val);
                    pop_val = NULL;
                    return;
                }
                if(pop_val->contents.operator != '('){
                    strncat(postfix_array, &pop_val->contents.operator, 1);
                    strncat(postfix_array, " ", 1);
                    free(pop_val);
                    pop_val = NULL;
                }else if(pop_val->contents.operator == '('){
                    free(pop_val);
                    pop_val = NULL;
                    is_left_encountered = true;
                    break;
                }
            }
            if (is_Empty() == true && is_left_encountered == false){
                *status = unpairedP;
                return;
            }
            is_left_encountered = false;
        }
        token = strtok(NULL, " ");
    }
    while(is_Empty() == false){
        if(*status != SUCCESS){
            return;
        }
        pop_val = pop(status);
        if (pop_val->contents.operator == '('){
            *status = unpairedP;
            break;
        }
        strncat(postfix_array, &pop_val->contents.operator,1);
        strncat(postfix_array, " ", 1);
        free(pop_val);
        pop_val = NULL;

    }

}