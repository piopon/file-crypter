//---------------------------------------------------------------------------
#pragma hdrstop
#include <vcl.h>
#include <MainWindow.h>
#include <FileSaver.h>
#include <FileScrambler.h>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFormFileCrypt *FormFileCrypt;
//---------------------------------------------------------------------------
__fastcall TFormFileCrypt::TFormFileCrypt(TComponent* Owner) : TForm(Owner)
{
	EditPassPhrase->Text = emptyPassphrase;
}
//---------------------------------------------------------------------------
void __fastcall TFormFileCrypt::EditPassPhraseEnter(TObject *Sender)
{
	if (EditPassPhrase->Text == emptyPassphrase) {
		EditPassPhrase->Text = "";
		EditPassPhrase->Font->Color = clBlack;
	}
}
//---------------------------------------------------------------------------
void __fastcall TFormFileCrypt::EditPassPhraseExit(TObject *Sender)
{
	currentPassphrase = EditPassPhrase->Text;
	if (EditPassPhrase->Text.IsEmpty()) {
		EditPassPhrase->Text = emptyPassphrase;
		EditPassPhrase->Font->Color = clMedGray;
	}
}
//---------------------------------------------------------------------------
void __fastcall TFormFileCrypt::EditPassPhraseKeyUp(TObject *Sender, WORD &Key, TShiftState Shift)
{
	currentPassphrase = EditPassPhrase->Text;
	enableButtonsIfInputOk({ ButtonEncrypt, ButtonDecrypt });
}
//---------------------------------------------------------------------------
void __fastcall TFormFileCrypt::ButtonSelectFileClick(TObject *Sender)
{
	if(FileSelectDialog->Execute()) {
		String tempFile = FileSelectDialog->FileName;
		if(FileExists(tempFile)) {
			filePath = std::make_unique<FilePath>(tempFile);
			fileContent = std::make_unique<FileContent>(filePath->getPath());
			ValueSelectedFile->Hint = filePath->getPath();
			ValueSelectedFile->Caption = filePath->getLimitedPath(selectedFileMaxLen);
		}
	}
	enableButtonsIfInputOk({ ButtonEncrypt, ButtonDecrypt });
}
//---------------------------------------------------------------------------
void TFormFileCrypt::enableButtonsIfInputOk(const std::vector<TButton*> &buttons)
{
	bool pathOk = filePath != nullptr && !filePath->getPath().IsEmpty();
	bool passOk = !currentPassphrase.IsEmpty();
	for(const auto &button : buttons) {
		button->Enabled = pathOk && passOk;
	}
}
//---------------------------------------------------------------------------
void __fastcall TFormFileCrypt::ButtonEncryptClick(TObject *Sender)
{
	FileScrambler fileScrambler = {currentPassphrase};
	FileSaver saver = { encode, FileSaveDialog, fileContent.get() };
	saver.execute(filePath->getExtension(), fileScrambler.encrypt(fileContent->read()));
}
//---------------------------------------------------------------------------
void __fastcall TFormFileCrypt::ButtonDecryptClick(TObject *Sender)
{
	FileScrambler fileScrambler = {currentPassphrase};
	if(fileScrambler.isContentCryptedWithCurrentKey(fileContent->read())) {
		FileSaver saver = { decode, FileSaveDialog, fileContent.get() };
		saver.execute(filePath->getExtension(), fileScrambler.decrypt(fileContent->read()));
	} else {
		auto message = L"This file was not encrypted with this passphrase.";
		MessageBoxW(NULL, message, L"DECRYPT ERROR", MB_OK | MB_ICONERROR);
	}
}
//---------------------------------------------------------------------------

