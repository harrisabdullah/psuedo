//
// Created by Harris on 26/10/2023.
//

#ifndef PSUEDO_EQUATIONPARSER_H
#define PSUEDO_EQUATIONPARSER_H

float strToFloat(char str[], int start, int end);
int findClosing(char str[], int openIndex, int end);
struct ASTNode* equationToAST(char equation[], int start, int end);

#endif //PSUEDO_EQUATIONPARSER_H
