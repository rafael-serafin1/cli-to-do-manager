#pragma once
#include "config.h"

void __readable(void);
void __checkable(void);
void __visible(void);

#define CONFIG_FLAGS_USAGE                              \
    X("--readable", "-r", __readable())                 \
    X("--checkable", "-c", __checkable())               \
    X("--visible", "-v", __visible())                 

void __readable(void) {
    __todo_config config = read_config_file();
    if (config.readable == falso) 
        config.readable = verdade;
    else 
        config.readable = falso;
    
    write_config_file(config);
}

void __checkable(void) {
    __todo_config config = read_config_file();

    if (config.checkable == falso) 
        config.checkable = verdade;
    else    
        config.checkable = falso;
    
    write_config_file(config);
}

void __visible(void) {
    __todo_config config = read_config_file();

    if (config.visible == falso) 
        config.visible = verdade;
    else   
        config.visible = falso;
    
    write_config_file(config);
}