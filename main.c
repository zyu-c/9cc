#include "9cc.h"

int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Wrong number of arguments.\n");
        return 1;
    }

    // トークナイズする
    user_input = argv[1];
    token = tokenize(user_input);
    Program *prog = program();

    int offset = 0;
    for (LVar *lvar = prog->locals; lvar; lvar = lvar->next) {
        offset += 8;
        lvar->offset = offset;
    }
    prog->stack_size = offset;

    codegen(prog);
    return 0;
}
