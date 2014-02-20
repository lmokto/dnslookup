from dnslookup import lookup
import sys

domain = sys.argv[1:]
dns = lookup(domain)
print "{0} : {1}".format(dmain, dns)
