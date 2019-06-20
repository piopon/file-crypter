//---------------------------------------------------------------------------
#ifndef FileContentH
#define FileContentH
//---------------------------------------------------------------------------
#include <vcl.h>
#include <string>
//---------------------------------------------------------------------------
class FileContent {
public:
	FileContent(const String &file);
	void update(const std::string &newContent);
	void save(const String &file);
	std::string read();
private:
	std::string content;
    void storeContent(const String &file);
};
#endif
