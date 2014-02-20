#!/usr/bin/python
# -*- coding: utf-8 -*-

from dnslookup import lookup
import sys

domain = sys.argv[1:]

for x in domain:
    dns = lookup(x)
    print "{0} : {1}".format(x, dns)
    


# eg.
# python dnslookup.py www.somehost1.com www.somehost2.com www.somehostn.com
