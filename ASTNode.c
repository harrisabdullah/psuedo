//
// Created by Harris on 26/10/2023.
//


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