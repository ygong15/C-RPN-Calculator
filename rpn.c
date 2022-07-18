//
// Created by Aaron Gong on 3/30/21.
//

#include "rpn.h"
#include "node.h"
#include "stack.h"

#include "errors.h"
#include <stdlib.h>
#include <stdio.h>
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


double add (double int1, double int2){
    double value = int1 + int2;
    return value;
}

double subtract (double int1, double int2){
    double value = int1 - int2;
    return value;
}

double multiply (double int1, double int2){
    double value = int1 * int2;
    return value;
}

double divide (double int1, double int2, int* status){
    if (int2 == 0){
        *status = dividebyzero;
        return 0.0;
    }else {
        double value = int1 / int2;
        return value;
    }
}

double exponential (double key_val, double power){
    if(power != 0){
        return (key_val * exponential(key_val, power-1));
    }else{
        return 1;
    }
}


double evaluate (char* expression, int* status){
    if (*status != SUCCESS){
        return 0.0;
    }
    node* NewNode = NULL;
    node* val1 = NULL;
    node* val2 = NULL;
    char* token;
    double result;
    node* final_result;
    const char par[1] = " ";
    if(strlen(expression) < 3){
        *status = incorrect_amount;
        return 0.0;
    }
    token = strtok(expression, par);
    while(token != NULL){
        NewNode = createNode(token, status);
        if (*status != SUCCESS){
            return 0.0;
        }else if (NewNode->type == NUMBER){
            push(NewNode);
        }else{
            val2 = pop(status);
            val1 = pop(status);
            if (*status != SUCCESS){
                return 0.0;
            }else{
                switch (NewNode->contents.operator) {
                    case '+':
                        result = add(val1->contents.value, val2->contents.value);
                        free(val1);
                        val1 = NULL;
                        val2->contents.value = result;
                        push(val2);
                        break;
                    case '-':
                        result = subtract(val1->contents.value, val2->contents.value);
                        free(val1);
                        val1 = NULL;
                        val2->contents.value = result;
                        push(val2);
                        break;
                    case '*':
                        result = multiply(val1->contents.value, val2->contents.value);
                        free(val1);
                        val1 = NULL;
                        val2->contents.value = result;
                        push(val2);
                        break;
                    case '/':
                        result = divide(val1->contents.value, val2->contents.value, status);
                        free(val1);
                        val1 = NULL;
                        val2->contents.value = result;
                        push(val2);
                        break;
                    case '^':
                        result = exponential(val1->contents.value, val2->contents.value);
                        free(val1);
                        val1 = NULL;
                        val2->contents.value = result;
                        push(val2);
                        break;
                    default:
                        break;
                }
                if (*status != SUCCESS){
                    clearStack(status);
                    return 0.0;
                }

            }

        }
        token = strtok(NULL, par);

    }
    final_result = pop(status);
    result = final_result->contents.value;
    final_result = peek();
    if (final_result != NULL){
        *status = incorrect_amount;
        clearStack(status);
        return 0.0;
    }
    return  result;




}
