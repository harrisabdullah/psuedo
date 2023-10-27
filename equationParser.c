//
// Created by Harris on 26/10/2023.
//
#include <string.h>
#include <stdio.h>
#include "ASTNode.h"
#include "ASTstack.h"

float strToFloat(char str[], int start, int end) {
    unsigned int length = end - start + 1;
    char extractedString[length + 1]; // +1 for null-terminator

    strncpy(extractedString, str + start, length);
    extractedString[length] = '\0';

    float number;
    sscanf(extractedString, "%f", &number);
    return number;
}

int findClosing(char str[], int openIndex, int end){
    int depth = 0;
    for (int i = openIndex+1; i<=end; i++){
        if (str[i] == ')' && depth == 0){
            return i;
        }
        if (str[i] == '('){
            depth++;
        }
        if (str[i] == ')'){
            depth--;
        }
    }
    return -1;
}

struct ASTNode* equationToAST(char equation[], int start, int end){

    if (equation[start] == '(' && findClosing(equation, start, end) == end) {
        start++;
        end--;
    }

    int head = start;
    enum Operators operator = NullOperator;
    int operatorIndex = -1;

    while (head <= end && equation[head] != '\0'){

        switch (equation[head]) {
            case '+':
                operator = Addition;
                operatorIndex = head;
                break;

            case '-':
                operator = Subtraction;
                operatorIndex = head;
                break;


            case '/':
                if (operator != Addition && operator != Subtraction) {
                    operator = Division;
                    operatorIndex = head;
                }
                break;

            case '*':
                if (operator != Addition && operator != Subtraction) {
                    operator = Multiplication;
                    operatorIndex = head;
                }
                break;

            case '(':
                head = findClosing(equation, head, end);
        }
        head++;
    }

    if (operator == NullOperator){
        struct ASTNode* tree = (struct ASTNode*)malloc(sizeof(struct ASTNode));
        tree->type = Float;
        tree->data.number = strToFloat(equation, start, end);
        tree->left = NULL;
        tree->right = NULL;

        return tree;
    }

    struct ASTNode* tree = (struct ASTNode*)malloc(sizeof(struct ASTNode));
    tree->data.operators = operator;
    tree->type = Operator;
    tree->left = equationToAST(equation, start, operatorIndex-1);
    tree->right = equationToAST(equation, operatorIndex+1, end);
    return tree;
}

void solveAST(struct ASTstack* stack, struct ASTNode* tree){

    if (tree->type == Float){
        ASTstackPush(stack, tree->data.number);
        return;
    }

    solveAST(stack, tree->right);
    solveAST(stack, tree->left);

    float num1 = ASTstackPop(stack);
    float num2 = ASTstackPop(stack);
    float result;

    switch (tree->data.operators) {
        case Addition:
            result = num1 + num2;
            printf("%f + %f = %f\n", num1, num2, result);
            break;
        case Subtraction:
            result = num1 - num2;
            printf("%f - %f = %f\n", num1, num2, result);
            break;
        case Multiplication:
            result = num1 * num2;
            printf("%f * %f = %f\n", num1, num2, result);
            break;
        case Division:
            result = num1 / num2;
            printf("%f / %f = %f\n", num1, num2, result);
            break;
        case NullOperator:
            result = 0;
            break;
    }

    ASTstackPush(stack, result);
}