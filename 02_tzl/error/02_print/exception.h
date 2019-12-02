#ifndef _EXCEPTION_H_
#define _EXCEPTION_H_

#define THROW_EXCEPTION(e, m) (throw e(m, __FILE__, __LINE__))

class Exception {
protected:
	char *m_message;
	char *m_location;

	void init(const char *message, const char *file, int line);

public:
	Exception(const char *message);
	Exception(const char *file, int line);
	Exception(const char *message, const char *file, int line);

	Exception(const Exception &e);
	Exception &operator=(const Exception &e);

	virtual const char *message() const;
	virtual const char *location() const;

	virtual ~Exception() = 0;
	//virtual ~Exception();
};
class IndexOutOfBoundsException : public Exception
{
public:
	IndexOutOfBoundsException() : Exception(0) { }
	IndexOutOfBoundsException(const char *message) : Exception(message) { }
	IndexOutOfBoundsException(const char *file, int line) : Exception(file, line) { }
	IndexOutOfBoundsException(const char *message, const char *file, int line) : Exception(message, file, line) { }

	IndexOutOfBoundsException(const IndexOutOfBoundsException &e) : Exception(e) { }

	IndexOutOfBoundsException& operator=(const IndexOutOfBoundsException &e)
	{
		Exception::operator=(e);
		return *this;
	}

};
class NoEnoughMemoryException : public Exception
{
public:
	NoEnoughMemoryException() : Exception(0) { }
	NoEnoughMemoryException(const char *message) : Exception(message) { }
	NoEnoughMemoryException(const char *file, int line) : Exception(file, line) { }
	NoEnoughMemoryException(const char *message, const char *file, int line) : Exception(message, file, line) { }

	NoEnoughMemoryException(const NoEnoughMemoryException &e) : Exception(e) { }

	NoEnoughMemoryException& operator=(const NoEnoughMemoryException &e)
	{
		Exception::operator=(e);
		return *this;
	}

};








#endif
