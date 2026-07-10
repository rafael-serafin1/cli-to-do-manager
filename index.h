#pragma once
#include "macros.h"
#include "utils.h"

Status _todo_help(list todo) {
    message(MSG_INFO, "All commands avaliable to usage (todo <COMMAND>):");
    #define X(cmd, usage)       \
        message(MSG_INFO, "\t - %s --> %s.", cmd, usage);
        __EXPLICIT_TODO_CMDS
    #undef X
    return SUCCESS;
}

Status _todo_version() {
    printf("%s\n", __TODO_VERSION);
    return SUCCESS;
}

Status _todo_config() {
    return SUCCESS;
}

Status _todo_add(string todo) {
    return SUCCESS;
}

Status _todo_remove(string todo) {
    return SUCCESS;
}

Status _todo_check(string todo) {
    return SUCCESS;
}

Status _todo_uncheck(string todo) {
    return SUCCESS;
}

Status _todo_list() {
    return SUCCESS;
}