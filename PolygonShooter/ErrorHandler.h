/** @author Adam Olękiewicz
 * 
 * Top-down survival post-apocalyptic shooter
 * 
 * Abstract class ErrorHandler:
 * - provides error-code table
 * - manages displaying error messages
 */

#ifndef ERRORHANDLER_H
#define	ERRORHANDLER_H

#include <string>
#include <map>


class ErrorHandler {
public:


	enum ERR_CODE {
		NO_ERROR = 0,		// Default value    info: filename
		BAD_ALLOC = 7,		// Memory allocation error  info: none
		MISSING_FILE = 1,	// Self-explanatory
		BAD_FORMAT = 2,		// Incorrect file format (e.g. in config file or images)
		MISSING_RES = 3,	// Resource not loaded
		OUT_OF_MEMORY = 4,	// Reached data size limit (too much objects, memory usage beyond expected, etc.)
		TOO_BIG_FILE = 5,	// Reached file size limit
		ILLEGAL_ACTION = 6,	// Forbidden action (e.g. creating another Program object)
		VAR_OVERFLOW = 8,   // Variable overflow
	};
	
	enum ERR_TYPE {
		NO_ERR = 0, 		// Default value
		WARN = 1,			// Displays warning in logs
		SOFT = 2,			// Allows safe exi
		HARD = 3,			// Immediately stops program
	};
	
	typedef struct _errorCode {
		ERR_CODE code;
		const char* errorString;
		ERR_TYPE type;
	} ERROR;
	

	ErrorHandler();
	~ErrorHandler();

	void _throwError(const ERR_CODE code,
							const std::string additionalInfo,
							const std::string filename,
							const int lineNumber);

private:
	void printError(const std::string* errorMessage);
	ERROR* errorTable;
};



#ifdef DEBUG_MODE
#define sThrowError(x, y) ErrorHandler::_throwError((x), (y), __FILE__, __LINE__)
#else
#define sThrowError(x, y) ErrorHandler::_throwError((x), (y), "", -1)
#endif

#endif	/* ERRORHANDLER_H */
