//
// Created by Harris on 26/10/2023.
//

#ifndef PSUEDO_ASTNODE_H
#define PSUEDO_ASTNODE_H

enum Operators {NullOperator, Addition, Subtraction, Multiplication, Division, Exponentiation};
enum ASTDataType {Operator, Float};

union ASTData {
    enum Operators operators;
    float number;
};

struct ASTNode {
    enum ASTDataType type;
    union ASTData data;
    struct ASTNode* left;
    struct ASTNode* right;
};

#endif //PSUEDO_ASTNODE_H
