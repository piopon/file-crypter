//---------------------------------------------------------------------------
#pragma hdrstop
#include <fstream>
#include <FileContent.h>
//---------------------------------------------------------------------------
#pragma package(smart_init)
//---------------------------------------------------------------------------
FileContent::FileContent(const String &file)
{
    content.clear();
    storeContent(file);
}
//---------------------------------------------------------------------------
void FileContent::storeContent(const String &file)
{
	std::ifstream source {file.c_str(), ios::in | ios::binary};
	do {
		char element;
		source.read(&element, source);
		content += element;
	} while(!source.eof());
	source.close();
	content = content.substr(0, content.length()-1);
}
//---------------------------------------------------------------------------
std::string FileContent::read()
{
    return content;
}
//---------------------------------------------------------------------------
void FileContent::update(const std::string &newContent)
{
    content = newContent;
}
//---------------------------------------------------------------------------
void FileContent::save(const String &file)
{
	std::ofstream outputContent {file.c_str(), ios::out | ios::binary };
	outputContent.write(content.c_str(), content.length());
	outputContent.close();
}
//---------------------------------------------------------------------------
