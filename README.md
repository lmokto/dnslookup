dnslookup
=========
gcc dnslookup.c -o dnslookup.so -fPIC -shared -I/usr/include/python2.7


sudo cp dnslookup.so /usr/lib/python2.7


python


>from dnslookup import lookup

>lookup("www.lanacion.com.ar")

>'54.225.126.106'
