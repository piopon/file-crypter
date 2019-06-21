//---------------------------------------------------------------------------
#pragma hdrstop
#include <vcl.h>
#include <MainWindow.h>
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
}
//---------------------------------------------------------------------------

