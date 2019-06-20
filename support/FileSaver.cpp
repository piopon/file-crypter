//---------------------------------------------------------------------------
#pragma hdrstop
#include <FileSaver.h>
//---------------------------------------------------------------------------
#pragma package(smart_init)
//---------------------------------------------------------------------------
FileSaver::FileSaver(SaveOption option, TSaveDialog *dialog, FileContent *file)
	: dialog(dialog), file(file)
{
	if(option == encode) {
		titleText = "Save encoded file as...";
		confirmationText = "Saved encoded file.";
	} else if(option == decode) {
		titleText = "Save decoded file as...";
		confirmationText = "Saved decoded file.";
    }
}
//---------------------------------------------------------------------------
void FileSaver::execute(String ext, const std::string &content)
{
	dialog->Title = titleText;
	dialog->DefaultExt = ext;
	dialog->Filter = "Input file type|*." + ext + "|All files|*.*";
	if(dialog->Execute()) {
		file->update(content);
		file->save(dialog->FileName);
		String text = confirmationText;
		MessageBoxW(NULL, text.c_str(), L"File Crypter", MB_ICONINFORMATION);
	}
}
//---------------------------------------------------------------------------
