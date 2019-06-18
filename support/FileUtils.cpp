//---------------------------------------------------------------------------
#pragma hdrstop
#include <FileUtils.h>
//---------------------------------------------------------------------------
#pragma package(smart_init)
//---------------------------------------------------------------------------
int FileUtils::countDigits(int number)
{
	int digits = 0;
	if (number < 0) digits = 1;
	while (number > 0) {
		number /= 10;
		digits++;
	}
	return digits;
}
//---------------------------------------------------------------------------
std::string FileUtils::toStdString(const String &input)
{
	std::string output(input.begin(), input.end());
	return output;
}
//---------------------------------------------------------------------------
