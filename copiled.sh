#!/bin/bash
gcc dnslookup.c -o dnslookup.so -fPIC -shared -I/usr/include/python2.7
sudo cp dnslookup.so /usr/lib/python2.7
