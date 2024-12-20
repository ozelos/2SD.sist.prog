#pragma once

namespace CppCLRWinFormsProject {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;

	/// <summary>
	/// Summary for Form1
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	private:
		MenuStrip^ menuStrip;
		ToolStripMenuItem^ fileMenu;
		ToolStripMenuItem^ saveMenuItem;
		ToolStripMenuItem^ loadMenuItem;
		ToolStripMenuItem^ exitMenuItem;

		ToolStripMenuItem^ aboutMenu;

		TextBox^ textBox;
		Button^ encryptButton;
		Button^ decryptButton;

		String^ encryptionKey = "secret";
	public:
		Form1()
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			// Form setup
			this->Text = "Student Data Application";
			this->Width = 800;
			this->Height = 600;

			// Menu
			menuStrip = gcnew MenuStrip();
			fileMenu = gcnew ToolStripMenuItem("File");
			saveMenuItem = gcnew ToolStripMenuItem("Save");
			loadMenuItem = gcnew ToolStripMenuItem("Load");
			exitMenuItem = gcnew ToolStripMenuItem("Exit");
			aboutMenu = gcnew ToolStripMenuItem("About");

			fileMenu->DropDownItems->Add(saveMenuItem);
			fileMenu->DropDownItems->Add(loadMenuItem);
			fileMenu->DropDownItems->Add(exitMenuItem);
			menuStrip->Items->Add(fileMenu);
			menuStrip->Items->Add(aboutMenu);

			this->MainMenuStrip = menuStrip;
			this->Controls->Add(menuStrip);

			// TextBox
			textBox = gcnew TextBox();
			textBox->Multiline = true;
			textBox->Width = 750;
			textBox->Height = 400;
			textBox->Location = System::Drawing::Point(20, 50);
			this->Controls->Add(textBox);

			// Buttons
			encryptButton = gcnew Button();
			encryptButton->Text = "Encrypt";
			encryptButton->Location = System::Drawing::Point(20, 500);
			encryptButton->Click += gcnew EventHandler(this, &Form1::EncryptData);
			this->Controls->Add(encryptButton);

			decryptButton = gcnew Button();
			decryptButton->Text = "Decrypt";
			decryptButton->Location = System::Drawing::Point(120, 500);
			decryptButton->Click += gcnew EventHandler(this, &Form1::DecryptData);
			this->Controls->Add(decryptButton);

			// Event Handlers
			saveMenuItem->Click += gcnew EventHandler(this, &Form1::SaveToFile);
			loadMenuItem->Click += gcnew EventHandler(this, &Form1::LoadFromFile);
			exitMenuItem->Click += gcnew EventHandler(this, &Form1::ExitApp);
			aboutMenu->Click += gcnew EventHandler(this, &Form1::ShowAbout);

		}
#pragma endregion
	private: System::Void Form1_Load(System::Object^ sender, System::EventArgs^ e) {
	}

		   void SaveToFile(Object^ sender, EventArgs^ e) {
			   SaveFileDialog^ saveDialog = gcnew SaveFileDialog();
			   saveDialog->Filter = "Text Files|*.txt";
			   if (saveDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
				   File::WriteAllText(saveDialog->FileName, textBox->Text);
				   MessageBox::Show("File saved successfully!");
			   }
		   }

		   void LoadFromFile(Object^ sender, EventArgs^ e) {
			   OpenFileDialog^ openDialog = gcnew OpenFileDialog();
			   openDialog->Filter = "Text Files|*.txt";
			   if (openDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
				   textBox->Text = File::ReadAllText(openDialog->FileName);
				   MessageBox::Show("File loaded successfully!");
			   }
		   }

		   void EncryptData(Object^ sender, EventArgs^ e) {
			   textBox->Text = EncryptDecrypt(textBox->Text, encryptionKey);
			   MessageBox::Show("Data encrypted!");
		   }

		   void DecryptData(Object^ sender, EventArgs^ e) {
			   textBox->Text = EncryptDecrypt(textBox->Text, encryptionKey);
			   MessageBox::Show("Data decrypted!");
		   }

		   void ExitApp(Object^ sender, EventArgs^ e) {
			   Application::Exit();
		   }

		   void ShowAbout(Object^ sender, EventArgs^ e) {
			   MessageBox::Show("Student Data Application\nVersion 1.0\nCreated by [Your Name]", "About");
		   }

		   String^ EncryptDecrypt(String^ text, String^ key) {
			   array<wchar_t>^ textArray = text->ToCharArray();
			   array<wchar_t>^ keyArray = key->ToCharArray();
			   int keyLength = keyArray->Length;
			   for (int i = 0; i < textArray->Length; i++) {
				   textArray[i] = textArray[i] ^ keyArray[i % keyLength];
			   }
			   return gcnew String(textArray);
		   }
	};
}
