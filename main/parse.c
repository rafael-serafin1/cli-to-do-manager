#include "parse.h"

/// @brief parse flags given by usability on command
/// @param argc number of arguments
/// @param argv arguments
/// @return Status -> SUCCESS or FAILURE
Status parse_flags(int argc, char **argv) {
    if (argc < 3) 
        return SUCCESS;
    
    CLI helper = *cli;
    for (register int i = 0; i < argc; ++i) {
        #define X(flag, alias, desc)           \
            if (strcmp(flag, argv[i]) == 0 || strcmp(alias, argv[i]) == 0) { add_to_list(helper.flags, argv[i]); }
            CONFIG_FLAGS
        #undef X
    }

    if (helper.flags->item == NULL) {
        message(MSG_ERROR, "No such flag called: \'%s\'", argv[2]);
        return FAILURE;
    }
    cli->flags = helper.flags;
    return SUCCESS;
}

/// @brief parse command given
/// @param argc number of arguments
/// @param argv arguments
/// @return Status -> SUCCESS or FAILURE
Status parse_command(int argc, char **argv) {
    string cmd = cli->command;
    Status S = parse_flags(argc, argv);
    list flags = cli->flags;
    string task = "OPA!\0";

    #define X(use, fun)                \
        if (strcmp(cmd, use) == 0) return fun;
        __TODO_CMDS_FUNC
    #undef X

    message(MSG_ERROR, "Todofile (todo): Inexistent or incorrect command: \"%s\"\n", cmd);
    return FAILURE;
}
