//---------------------------------------------------------------------------
#pragma hdrstop
#include <FilePath.h>
//---------------------------------------------------------------------------
#pragma package(smart_init)
//---------------------------------------------------------------------------
FilePath::FilePath(const String &path) : path(path), delimiter("\\")
{
    contents = decompose(path);
}
//---------------------------------------------------------------------------
std::vector<String> FilePath::decompose(String path)
{
    std::vector<String> result = {};
	int delimiterPos = path.Pos(delimiter);
	while(delimiterPos > 0) {
		String part = path.SubString(1, delimiterPos - 1);
		result.push_back(part);
		path = path.SubString(delimiterPos + 1, path.Length() - delimiterPos);
		delimiterPos = path.Pos(delimiter);
	}
	result.push_back(path);

	return result;
}
//---------------------------------------------------------------------------
String FilePath::getPath()
{
    return path;
}
//---------------------------------------------------------------------------
String FilePath::getLimitedPath(int maxLength)
{
	if(path.Length() > maxLength) {
		String dots = "...";
		String filename = getFilename();
		String limitedPath = getDriveLetter() + "\\";

		int charsLeft = maxLength-filename.Length()-limitedPath.Length()-dots.Length()-1;
		int elementNo = 1;
		while(contents.at(elementNo).Length() + 1 <= charsLeft) {
			charsLeft -= contents.at(elementNo).Length();
			limitedPath += contents.at(elementNo) + "\\";
            elementNo++;
		}

		limitedPath += dots + "\\" + filename;
		if(limitedPath.Length() > maxLength) {
			limitedPath = filename;
        }

		return limitedPath;
	}
    return path;
}
//---------------------------------------------------------------------------
String FilePath::getFilename()
{
    return contents.at(contents.size()-1);
}
//---------------------------------------------------------------------------
String FilePath::getDriveLetter()
{
    return contents.at(0);
}
//---------------------------------------------------------------------------
String FilePath::getExtension()
{
	String filename = getFilename();
	int dotPosition = filename.Pos(".");

	return filename.SubString(dotPosition+1, filename.Length()-dotPosition);
}
//---------------------------------------------------------------------------
