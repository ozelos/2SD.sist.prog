#include "Form1.h"

using namespace System;
using namespace System::Windows::Forms;
using namespace StudentDataApp;

[STAThread]
void Main() {
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);
    Application::Run(gcnew MainForm());
}
