#!/usr/bin/python
# -*- coding: utf-8 -*-

from dnslookup import lookup
import sys

domain = sys.argv[1:]
dns = lookup(domain[0])
print "{0} : {1}".format(domain, dns)
