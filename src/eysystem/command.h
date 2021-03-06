#pragma once
#ifndef __COMMAND_H__
#define __COMMAND_H__
#include "../osstd.h"
#include "../eylexer/lex.h"
#include "../eyparser/parser.h"
#include "../eycodegen/generator.h"
#include "../eyexec/executer.h"
#include "econfig.h"
using namespace osstd;

namespace eysys{
    typedef void (*command_event)(string argv);
    class eycommand{
    public:
        int toggle;
        string _cond;
        command_event _event;
        bool _active;

        eycommand()=default;
        eycommand(string cond, command_event event, bool active);

        void run(string argv);
        void toggle_active();
    };

    void run(std::string text);
}

#endif