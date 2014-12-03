/** @author Adam Olękiewicz
 * 
 * Top-down survival post-apocalyptic shooter
 */

#include "ErrorHandler.h"
#include <cstdio>

ErrorHandler::ErrorHandler() {
	static ERROR errorTable[] = {
		{NO_ERROR,      "", NO_ERR},
		{MISSING_FILE,  "[ERROR] File not found: ", SOFT},
		{BAD_FORMAT,    "[ERROR] Bad file format: ", SOFT},
		{MISSING_RES,   "[ERROR] Resource not loaded: ", SOFT},
		{OUT_OF_MEMORY, "[ERROR] Memory limit exceeded: ", SOFT},
		{TOO_BIG_FILE,  "[ERROR] Too big file: ", SOFT},
		{ILLEGAL_ACTION,"[ERROR] Forbidden action: ", SOFT},
		{BAD_ALLOC,     "[ERROR] Could not allocate memory for ", HARD},
		{VAR_OVERFLOW,  "[ERROR] Variable overflown at ", WARN}
	};

	this->errorTable = errorTable;
}

ErrorHandler::~ErrorHandler() {
}

void ErrorHandler::_throwError(const ERR_CODE code,
						  const std::string additionalInfo,
						  const std::string filename,
						  const int lineNumber) {

	std::string errorMessage = ErrorHandler::errorTable[(int)code].errorString + additionalInfo;
	if(filename.empty() || lineNumber < 0)
		errorMessage += " file " + filename + " in line " + std::to_string(lineNumber);

	printError(&errorMessage);
}

void ErrorHandler::printError(const std::string* errorMessage) {
	fprintf(stderr, "%s\n", errorMessage->c_str());
}
