//
// Created by Harris on 26/10/2023.
//
#include <string.h>
#include <stdio.h>
#include "ASTNode.h"

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

    if (equation[start] == '(' && equation[end] == ')') {
        start++;
        end--;
    }

    int head = start;
    enum Operators operator = NullOperator;
    int operatorIndex = -1;

    while (head <= end && equation[head] != '\0'){

        switch (equation[head]) {
            case '+':
                if (operator > Subtraction){
                    operator = Addition;
                    operatorIndex = head;
                    break;
                }

            case '-':
                if (operator > Subtraction){
                    operator = Subtraction;
                    operatorIndex = head;
                    break;
                }

            case '/':
                if (operator > Division){
                    operator = Division;
                    operatorIndex = head;
                    break;
                }

            case '*':
                if (operator > Division){
                    operator = Multiplication;
                    operatorIndex = head;
                    break;
                }

            case '(':
                head = findClosing(equation, head, end) + 1;
        }
        head++;
    }

    if (operator == NullOperator){
        struct ASTNode tree = {strToFloat(equation, start, end), NULL, NULL};
        return &tree;
    }

    struct ASTNode tree = {operator, equationToAST(equation, start, operatorIndex-1), equationToAST(equation, operatorIndex+1, end)};
    return &tree;
}
