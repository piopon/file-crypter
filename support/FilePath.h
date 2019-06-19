//---------------------------------------------------------------------------
#ifndef FilePathH
#define FilePathH
//---------------------------------------------------------------------------
#include <vcl.h>
#include <vector>
//---------------------------------------------------------------------------
class FilePath {
public:
	FilePath(const String &path);
    String getPath();
    String getLimitedPath(int maxLength);
	String getFilename();
	String getDriveLetter();
	String getExtension();
private:
	std::vector<String> decompose(String path);
	std::vector<String> contents;
	String path;
	String delimiter;
	String filename;
	String extension;
};
#endif
