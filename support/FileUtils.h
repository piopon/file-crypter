//---------------------------------------------------------------------------
#ifndef FileUtilsH
#define FileUtilsH
//---------------------------------------------------------------------------
#include <vcl.h>
#include <string>
//---------------------------------------------------------------------------
class FileUtils {
public:
	static int countDigits(int number);
	static std::string toStdString(const String &input);
};
#endif
