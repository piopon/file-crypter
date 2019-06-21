//---------------------------------------------------------------------------

#ifndef FileScramblerH
#define FileScramblerH
//---------------------------------------------------------------------------
#include <vcl.h>
#include <vector>
//---------------------------------------------------------------------------
class FileScrambler {
public:
	FileScrambler(const String &passphrase);
	bool isContentCryptedWithCurrentKey(const std::string &content);
	std::string encrypt(const std::string &content);
	std::string decrypt(const std::string &content);
private:
	String passphrase;
	String getFileCryptKey();
	int passLength;
	int passDigits;
	std::vector<int> getRawCryptKey();
	bool checkCryptHeader(const std::string &content);
};
#endif
