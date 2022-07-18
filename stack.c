//
// Created by Aaron Gong on 3/30/21.
//

#include "stack.h"
#include <stdlib.h>
#include <stdio.h>
#include "node.h"
#include "errors.h"

typedef struct node{
    union{
        double value;
        char operator;
    } contents;
    int type;
    int precedence;
    node* next;
} node;

node* HEAD = NULL;
node* VAL = NULL;

void push(node* node){
    if (HEAD == NULL){
        HEAD = node;
    }else{
        node->next = HEAD;
        HEAD = node;
    }
}

node* pop(int* status){
    if (HEAD == NULL){
        *status = incorrect_amount;
        return NULL;
    }else {
        VAL = HEAD;
        HEAD = HEAD->next;
        VAL->next = NULL;
        return VAL;
    }
}

node* peek(){
    return HEAD;
}

void printstack(){
    VAL = HEAD;
    while(VAL->next){
        printf("%f-->", VAL->contents.value);
        VAL = VAL->next;
    }
    printf("%f", VAL->contents.value);
}

void clearStack(int* status){
    while(HEAD){
        pop(status);
    }
}

bool is_Empty(){
    if (HEAD != NULL){
        return false;
    }else{
        return true;
    }
}