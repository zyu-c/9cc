#include "9cc.h"

int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Wrong number of arguments.\n");
        return 1;
    }

    // トークナイズする
    user_input = argv[1];
    token = tokenize(user_input);
    Node *node = expr();

    codegen(node);
    return 0;
}