#include "QPyEngineUtils.h"
#include <frameobject.h>

// Converts Python object to standard string
int PyString_ToStdString(PyObject * pyString, std::string& stdString)
{
	PyObject * repr;
	PyObject * str;
	const char * bytes;

	if ((repr = PyObject_Repr(pyString)) == NULL) {
		return 0;
	}
	if ((str = PyUnicode_AsEncodedString(repr, "utf-8", "~E~")) == NULL) {
		Py_XDECREF(repr);
		return 0;
	}
	stdString = ((bytes = PyBytes_AS_STRING(str)) == NULL ? std::string() : std::string(bytes));
	Py_XDECREF(repr);
	Py_XDECREF(str);
	return 1;
}

// Returns 1 if the list contains an item, 0 if it doesn't, or -1 on error
int PyList_Contains(PyObject * list, PyObject * item)
{
	Py_ssize_t i;
	int retval = 0;

	if (!PyList_Check(list)) {
		return -1;
	}
	for (i = 0; i < PyList_Size(list); ++i) {
		if ((retval = PyObject_RichCompareBool(item, PyList_GetItem(list, i), Py_EQ)) != 0)
			break;
	}
	return retval;
}

// Returns 1 if path was added to the Python path variable or 0 if it wasn't
int AppendSystemPath(const char * path)
{
	PyObject * sysPath;
	PyObject * newPath;
	int retval = 0;

	if (path == NULL || std::char_traits<char>::length(path) == 0)
		return 0;

	if ((sysPath = PySys_GetObject("path")) == NULL)
		throw std::runtime_error("PYTHON API ERROR: PySys_GetObject(\"path\") failed");

	newPath = PyUnicode_FromString(path);
	switch (PyList_Contains(sysPath, newPath)) {
	case 0:
		if (PyList_Insert(sysPath, 0, newPath))
			throw std::runtime_error("PYTHON API ERROR: PyList_Insert failed");
		if (PySys_SetObject("path", sysPath))
			throw std::runtime_error("PYTHON API ERROR: PySys_SetObject(\"path\", ...) failed");
		retval = 1;
	case 1:
		break;
	default:
		throw std::runtime_error("PYTHON API ERROR: PyList_Contains failed");
	}
	Py_DECREF(newPath);
	return retval;
}

// If an error occurred, returns the error and a traceback (max 10 frames)
void ErrorReport(QString& qErrStr)
{
	if (PyErr_Occurred()) {
		std::string errStr;
		PyObject * pType, *pVal, *pTraceback;
		PyTracebackObject * ptb;

		PyErr_Fetch(&pType, &pVal, &pTraceback);
		PyString_ToStdString(pVal, errStr);
		if ((ptb = (PyTracebackObject *)pTraceback) != NULL) {
			int errLine = ptb->tb_lineno;
			unsigned int tb_no = 1;
			std::string errFile;

			PyString_ToStdString(ptb->tb_frame->f_code->co_filename, errFile);
			errStr.append("\nFile " + errFile + ", line " + std::to_string(errLine) + "\n");

			while (ptb->tb_next && tb_no < 10) {
				ptb = ptb->tb_next;
				errLine = ptb->tb_lineno;
				PyString_ToStdString(ptb->tb_frame->f_code->co_filename, errFile);
				errStr.append("File " + errFile + ", line " + std::to_string(errLine) + "\n");
				++tb_no;
			}
		}
		PyErr_Restore(pType, pVal, pTraceback);
		qErrStr = QString::fromStdString(errStr);
	}
}