//
// Created by Harris on 26/10/2023.
//

#ifndef PSUEDO_ASTNODE_H
#define PSUEDO_ASTNODE_H

enum Operators {Addition, Subtraction, Multiplication, Division, NullOperator};

union ASTData {
    enum Operators operators;
    float number;
};

struct ASTNode {
    union ASTData data;
    struct ASTNode* left;
    struct ASTNode* right;
};

#endif //PSUEDO_ASTNODE_H
