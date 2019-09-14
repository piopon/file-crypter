//---------------------------------------------------------------------------
#pragma hdrstop
#include <vcl.h>
#include <tchar.h>
#include <winuser.h>
//---------------------------------------------------------------------------
USEFORM("windows\MainWindow.cpp", FormFileCrypt);
//---------------------------------------------------------------------------
int WINAPI _tWinMain(HINSTANCE, HINSTANCE, LPTSTR, int)
{
	try {
		Application->Initialize();
		Application->MainFormOnTaskBar = true;
		Application->CreateForm(__classid(TFormFileCrypt), &FormFileCrypt);
		Application->Run();
	} catch (Exception &exception) {
		Application->ShowException(&exception);
	} catch (...) {
		try {
			throw Exception("");
		} catch (Exception &exception) {
			Application->ShowException(&exception);
		}
	}
	return 0;
}
//---------------------------------------------------------------------------
