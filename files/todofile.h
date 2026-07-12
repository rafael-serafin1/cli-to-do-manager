#pragma once
#include <stdio.h>
#include <stdlib.h>

#include "config.h"
#include "../utils/utils.h"
#include "count.h"

#define CHECKBOX_UNCHECKED "[ ]"
#define CHECKBOX_CHECKED "[X]"

typedef struct __todo_task {
    int count;
    CHECKED isChecked;
    char task[__MAX_SIZE_BUFFER];
} Todo;

void create_todofile() {
    __todo_config CONFIGS = read_config_file();
    const char *mode = (CONFIGS.readable == verdade) ? "w\0" : "wb\0";

    if (CONFIGS.visible == verdade) {
        FILE *todofile = fopen(TODO, mode);

        fclose(todofile);
    } else {
        FILE *todofile = fopen(TODO_FILE, mode);

        fclose(todofile);
    }

    return;
}

void create_todofile_inPath(const char *_Path) {
    __todo_config cf = read_config_file();
    const char *mode = (cf.readable == verdade) ? "w\0" : "wb\0";

    if (remove("Todofile") != 0) {
        message(MSG_ERROR, "Error during Todofile exclusion.");
        return;
    }

    FILE *f = fopen(_Path, mode);
    fclose(f);
}

Status todofile_add_task(const char *task) {
    __todo_config CONFIGS = read_config_file();
    int count = read_counter_file();

    if (count < 0) {
        message(MSG_ERROR, "Error in counter file. Returned number: \"%d\"", count);
        return FAILURE;
    }

    const char *mode = (CONFIGS.readable == verdade) ? "w\0" : "wb\0" ;
    char buffer[__MAX_SIZE_BUFFER];

    if (CONFIGS.checkable == verdade)
        snprintf(buffer, sizeof(buffer), "%d %s %s", (count + 1), CHECKBOX_UNCHECKED, task);
    else 
        snprintf(buffer, sizeof(buffer), "%d %s", (count + 1), task);

    message(MSG_DEBUG, "Mensagem final: %s", buffer);
    return SUCCESS;
}

