#include <Python.h>
#include <errno.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>

PyObject *dnslookup(PyObject *self, PyObject *args){
    int i;
    struct hostent *he;
    struct in_addr **addr_list;
    char *domainName;
    
    if (!PyArg_ParseTuple(args, "s", &domainName)){
        return NULL;
    }
    
    if ((he = gethostbyname(domainName)) == NULL) {  // get the host info
        herror("gethostbyname"); 
        return NULL;
    }
    
    addr_list = (struct in_addr **)he->h_addr_list;
    for(i = 0; addr_list[i] != NULL; i++) {
        return Py_BuildValue("s ", inet_ntoa(*addr_list[i]));
    }

}
 
static 
PyMethodDef lookup_methods[] = {
    {"lookup", dnslookup, METH_VARARGS, "dnslookup, eg. dnslookup.lookup('www.python.com')"},
    {NULL, NULL, 0, NULL}, /* Sentinel */
};
 
PyMODINIT_FUNC
initdnslookup(void){
    PyObject *m;
 
    m = Py_InitModule("dnslookup", lookup_methods);
    if (m == NULL)
        return;
}
