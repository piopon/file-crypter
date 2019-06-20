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
private:	// User declarations
public:		// User declarations
	__fastcall TFormFileCrypt(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormFileCrypt *FormFileCrypt;
//---------------------------------------------------------------------------
#endif
