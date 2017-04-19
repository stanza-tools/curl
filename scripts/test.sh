#!/bin/bash
stanza compile t/test010-simple.stanza -ccfiles src/curl.c -ccflags -lcurl -o bin/testbin
./bin/testbin
