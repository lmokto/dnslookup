#!/usr/bin/python
# -*- coding: utf-8 -*-
'''
    python dnslookup.py www.lanacion.com.ar www.telpin.com.ar
    www.telpin.com.ar : 201.219.64.50
    www.lanacion.com.ar : 23.21.247.181
'''

from dnslookup import lookup
import sys

domain = sys.argv[1:]


for x in domain:
    dns = lookup(x)
    print "{0} : {1}".format(x, dns)
