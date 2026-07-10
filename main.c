#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "macros.h"
#include "index.h"
#include "utils.h"

#define __MIN_ARRAY_SIZE 256

typedef struct __TODO_CLI__ {
    char command[__MIN_ARRAY_SIZE];
    list flags;
} CLI;

Status parse_command(CLI cli) {
    string cmd = cli.command;
    string task = "OPA!\0";
    list flags = cli.flags;

    #define X(use, fun)                \
        if (strcmp(cmd, use) == 0) return fun;
        __TODO_CMDS_FUNC
    #undef X

    message(MSG_ERROR, "Todofile (todo): Inexistent or incorrect command: \"%s\"\n", cmd);
    return FAILURE;
}

int main(int argc, char **argv) {
    if (argc < 2) {
        message(MSG_ERROR, "No command provided. Correct usage -> \'todo <COMMAND>\'\n");
        return 1;
    }

    CLI *cli = (CLI *) malloc(sizeof(CLI));   
    strcpy(cli->command, argv[1]);

    cli->flags = initialize_list();

    parse_command(*cli);

    free(cli);
    return 0;
}