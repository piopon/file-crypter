//---------------------------------------------------------------------------
#ifndef MainWindowH
#define MainWindowH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <System.ImageList.hpp>
#include <Vcl.Dialogs.hpp>
#include <Vcl.ImgList.hpp>
#include <memory>
#include <FilePath.h>
#include <FileContent.h>
//---------------------------------------------------------------------------
class TFormFileCrypt : public TForm
{
__published:	// IDE-managed Components
	TOpenDialog *FileSelectDialog;
	TButton *ButtonEncrypt;
	TButton *ButtonDecrypt;
	TEdit *EditPassPhrase;
	TButton *ButtonSelectFile;
	TLabel *LabelSelectedFile;
	TLabel *ValueSelectedFile;
	TImageList *AppImages;
	TSaveDialog *FileSaveDialog;
	void __fastcall EditPassPhraseEnter(TObject *Sender);
	void __fastcall EditPassPhraseExit(TObject *Sender);
	void __fastcall EditPassPhraseKeyUp(TObject *Sender, WORD &Key, TShiftState Shift);
	void __fastcall ButtonSelectFileClick(TObject *Sender);
	void __fastcall ButtonEncryptClick(TObject *Sender);
	void __fastcall ButtonDecryptClick(TObject *Sender);
private:	// User declarations
	const String emptyPassphrase = "passphrase";
	const int selectedFileMaxLen = 37;
	String currentPassphrase = "";
	std::unique_ptr<FileContent> fileContent;
	std::unique_ptr<FilePath> filePath;
	void enableButtonsIfInputOk(const std::vector<TButton*> &buttons);
public:		// User declarations
	__fastcall TFormFileCrypt(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormFileCrypt *FormFileCrypt;
//---------------------------------------------------------------------------
#endif
