#include "MyForm.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThread]
void startForm(array<String^>^ arg) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	RubikPro::MyForm form; //WinFormsTest - имя вашего проекта
	Application::Run(%form);
}