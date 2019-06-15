#!/usr/bin/env bash
docker run -ti -v $PWD:/test memory-test:0.1 bash -c "cd /test/; gcc checker/main.c checker/mode_debug.c checker/arguments_parse.c ./stack/src/*.c ./vector/*.c ./Libftprintf/libftprintf.a"
