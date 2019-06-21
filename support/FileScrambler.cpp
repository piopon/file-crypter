//---------------------------------------------------------------------------
#pragma hdrstop
#include <sstream>
#include <FileScrambler.h>
#include <FileUtils.h>
//---------------------------------------------------------------------------
#pragma package(smart_init)
//---------------------------------------------------------------------------
FileScrambler::FileScrambler(const String &passphrase) : passphrase(passphrase)
{
	passLength = passphrase.Length();
	passDigits = FileUtils::countDigits(passLength);
}
//---------------------------------------------------------------------------
std::vector<int> FileScrambler::getRawCryptKey()
{
	std::vector<int> resultKey = {};
	for(auto el : passphrase) {
		resultKey.push_back(static_cast<int>(el));
	}
	return resultKey;
}
//---------------------------------------------------------------------------
String FileScrambler::getFileCryptKey()
{
	std::stringstream text;
	for(auto el : getRawCryptKey()) {
        text << std::hex << el;
	}
	return text.str().c_str();
}
//---------------------------------------------------------------------------
std::string FileScrambler::encrypt(const std::string &content)
{
	auto digitsString = std::to_string(passDigits);
	auto keyString = FileUtils::toStdString(getFileCryptKey());

	return digitsString + std::to_string(passLength) + keyString + content;
}
//---------------------------------------------------------------------------
std::string FileScrambler::decrypt(const std::string &content)
{
	int digitsSize = 1;
	auto keyString = FileUtils::toStdString(getFileCryptKey());
	int startIndex = digitsSize + passDigits + keyString.length();

	return content.substr(startIndex, content.length() - startIndex);
}
//---------------------------------------------------------------------------
bool FileScrambler::isContentCryptedWithCurrentKey(const std::string &content)
{
	auto key = FileUtils::toStdString(getFileCryptKey());

	return checkCryptHeader(content) && content.find(key) != std::string::npos;
}
//---------------------------------------------------------------------------
bool FileScrambler::checkCryptHeader(const std::string &content)
{
	if(content.empty()) {
        return false;
    }

	auto encryptedDigits = content[0];
	if (String(passDigits) != encryptedDigits) {
		return false;
	}

	String encryptedLength;
	for (int i = 0; i < passDigits; i++) {
		encryptedLength += content[i+1];
	}
	return passLength == encryptedLength.ToInt();
}
//---------------------------------------------------------------------------