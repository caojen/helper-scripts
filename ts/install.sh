#!/bin/sh

gcc main.c -o ts.bin
sudo cp ./ts.bin /usr/local/bin/ts
