#include <stdio.h>
#include "equationParser.h"
#include "ASTstack.h"
#include "ASTNode.h"
#include <time.h>

int main() {
    for (int i=0; i<20; i++) {
        char userInput[500];

        printf(": ");
        scanf("%s", userInput);

        int j = 0;
        for (;j<500;j++){
            if (userInput[j] == '\0'){
                break;
            }
        }

        struct ASTNode *tree = equationToAST(userInput, 0, j-1);
        struct ASTstack stack;
        ASTstackInit(&stack);
        solveAST(&stack, tree);

        float result = ASTstackPop(&stack);
        printf("%f\n", result);
    }
    return 0;
}
