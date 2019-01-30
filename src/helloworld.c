#include <Python.h>
#include "/home/mdledoux/test.cpp/python3_extension/src/mylib.h"

static PyObject* helloworld(PyObject* self)
{
   return Py_BuildValue("s", "Hello, Python3 extensions!!");
}

static PyObject* test(PyObject* self)
{
   return Py_BuildValue("s", "This is a test function!!");
}

static PyObject* str_func(PyObject* self)
{
   return Py_BuildValue("s", my_str_func() );
}

static PyObject* float_func(PyObject* self)
{
   return Py_BuildValue("f", my_float_func() );
}


static PyObject* multiply_ints(PyObject* self,  PyObject *args)
{
  /*
  PyObject *list;
  if (!PyArg_ParseTuple(args, "i", &list)) {
    return NULL;
  }
  PyObject **v = (PyObject **) malloc( sizeof(PyObject *) * 2 );
  v[0] = PyList_GetItem(list, 0);
  v[1] = PyList_GetItem(list, 1);
  const char* a = PyBytes_AsString(v[0]);
  const char* b = PyBytes_AsString(v[1]);
  return Py_BuildValue("i", my_multiply_ints(atoi(a), atoi(b) ) );
  */

  int a,b=0;
  if (!PyArg_ParseTuple(args, "ii", &a, &b)) {
    return NULL;
  }
  return Py_BuildValue("i", my_multiply_ints(a, b ) );
}




static char helloworld_docs[] =
   "helloworld( ): Any message you want to put here!!\n";

static PyMethodDef helloworld_funcs[] = {
   {"helloworld", (PyCFunction)helloworld, 
   METH_NOARGS, helloworld_docs},

   {"test", (PyCFunction)test, 
   METH_NOARGS, helloworld_docs},

   {"str_func", (PyCFunction)str_func, 
   METH_NOARGS, helloworld_docs},

   {"float_func", (PyCFunction)float_func, 
   METH_NOARGS, helloworld_docs},


  // NOTE:   METH_VARGES, not METH_NOARGS
   {"multiply_ints", (PyCFunction)multiply_ints, 
   METH_VARARGS, helloworld_docs},


   {NULL}
};


static struct PyModuleDef helloworld_module =
{
    PyModuleDef_HEAD_INIT,
    "helloworld", /* name of module */
    helloworld_docs,           /* module documentation, may be NULL */
//    "",           /* module documentation, may be NULL */
    -1,           /* size of per-interpreter state of the module, or -1 if the module keeps state in global variables. */
    helloworld_funcs
};

PyMODINIT_FUNC PyInit_helloworld(void)
{
    return PyModule_Create(&helloworld_module);
}
