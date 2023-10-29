//
// Created by Harris on 26/10/2023.
//

#ifndef PSEUDO_EQUATIONPARSER_H
#define PSEUDO_EQUATIONPARSER_H

#include "ASTstack.h"

float strToFloat(const char str[], int start, int end);
int findClosing(const char str[], int openIndex, int end);
struct ASTNode* equationToAST(const char equation[], int start, int end);
void solveAST(struct ASTstack* stack, struct ASTNode* tree);

#endif // PSEUDO_EQUATIONPARSER_H