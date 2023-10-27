//
// Created by Harris on 26/10/2023.
//

#ifndef PSUEDO_ASTSTACK_H
#define PSUEDO_ASTSTACK_H
#include <stdlib.h>
#define SIZE 100

struct ASTstack {
    float data[SIZE];
    int top;
};

void ASTstackInit(struct ASTstack* stack);
void ASTstackPush(struct ASTstack* stack, float data);
float ASTstackPop(struct ASTstack* stack);

#endif //PSUEDO_ASTSTACK_H
