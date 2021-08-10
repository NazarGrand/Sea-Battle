#include "MyForm.h"
#include "GameForm.h"

using namespace System;
using namespace System::Windows::Forms;
[STAThread]
void main(array<String^>^ args) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Fight::MyForm form;
	Application::Run(% form);
}

System::Void Fight::MyForm::button1_Click(System::Object^ sender, System::EventArgs^ e)
{
	GameForm^ form = gcnew GameForm(); //створюється нова форма(для гри)
	form->Show(); //показуємо
	this->Hide();
}
