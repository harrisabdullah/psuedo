//
// Created by Harris on 26/10/2023.
//
#include "ASTstack.h"
#include <stdlib.h>

void ASTstackInit(struct ASTstack* stack){
    stack->top = -1;
}

void ASTstackPush(struct ASTstack* stack, float data){
    stack->data[stack->top + 1] = data;
    stack->top++;
}

float ASTstackPop(struct ASTstack* stack) {
    float value = stack->data[stack->top];
    stack->data[stack->top] = 0;
    stack->top--;
    return value;
}