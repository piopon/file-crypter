//---------------------------------------------------------------------------
#ifndef FileSaverH
#define FileSaverH
//---------------------------------------------------------------------------
#include <vcl.h>
#include <FileContent.h>
//---------------------------------------------------------------------------
enum SaveOption {
	encode,
	decode
};
//---------------------------------------------------------------------------
class FileSaver {
	public:
		FileSaver(SaveOption option, TSaveDialog *dialog, FileContent *file);
		void execute(String ext, const std::string &content);
	private:
		TSaveDialog *dialog;
		FileContent *file;
		String titleText;
		String confirmationText;
};
#endif
