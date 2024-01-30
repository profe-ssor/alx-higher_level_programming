#include <Python.h>
#include <stdio.h>

/**
 * print_python_list - Print information about Python lists.
 * @p: Pointer to the PyObject list.
 */
void print_python_list(PyObject *p) {
    Py_ssize_t size, i;

    if (!PyList_Check(p)) {
        fprintf(stderr, "Invalid List Object\n");
        return;
    }

    size = PyList_Size(p);

    printf("[*] Python list info\n");
    printf("[*] Size of the Python List = %ld\n", size);
    printf("[*] Allocated = %ld\n", ((PyListObject *)p)->allocated);

    for (i = 0; i < size; ++i) {
        printf("Element %ld: %s\n", i, Py_TYPE(PyList_GetItem(p, i))->tp_name);
    }
}

/**
 * print_python_bytes - Print information about Python bytes.
 * @p: Pointer to the PyObject bytes.
 */
void print_python_bytes(PyObject *p) {
    Py_ssize_t size, i;
    char *data;

    if (!PyBytes_Check(p)) {
        fprintf(stderr, "Invalid Bytes Object\n");
        return;
    }

    size = PyBytes_Size(p);
    data = PyBytes_AsString(p);

    printf("[.] bytes object info\n");
    printf("  size: %ld\n", size);
    printf("  trying string: %s\n", data);

    printf("  first %ld bytes: ", (size > 10) ? 10 : size);
    for (i = 0; i < size && i < 10; ++i) {
        printf("%02hhx", data[i]);
        if (i < size - 1)
            printf(" ");
    }
    printf("\n");
}

/**
 * print_python_float - Print information about Python float.
 * @p: Pointer to the PyObject float.
 */
void print_python_float(PyObject *p) {
    if (!PyFloat_Check(p)) {
        fprintf(stderr, "Invalid Float Object\n");
        return;
    }

    printf("[.] float object info\n");
    printf("  value: %lf\n", ((PyFloatObject *)p)->ob_fval);
}

