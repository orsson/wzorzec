#pragma once
#include <fstream>
#include <string>
#include <time.h>
#include <sstream>
#include <list>
#include <iostream>
#include <cstddef>

using namespace std;
using namespace System::Threading;
using namespace System;
/////////////////////////////////////////////////////////////////////////////////////////////////
std::list<int> lista;
list<int> list2;
list<int>::iterator iter;
int leng;
bool blokada;
///////////////////////////////////
string dlugieslowo;

/////////////////////
namespace wzorzec {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class Form1 : public System::Windows::Forms::Form
	{

	public:

	static String^ richText;
	static String^ ValToSearchFor;
	static String^ Timess;

		Form1(void)
		{
			InitializeComponent();
		}

	protected:

		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	public:
	static  System::Windows::Forms::RichTextBox^  richTextBox1;
	public: System::Windows::Forms::Button^  button1;

	public: System::Windows::Forms::TextBox^  textBox1;
	public: System::Windows::Forms::TextBox^  textBox2;
	public: System::Windows::Forms::Button^  button2;
	public: System::Windows::Forms::ListBox^  listBox1;
	protected: 

	private:
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code

		void InitializeComponent(void)
		{
			blokada=false;
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->listBox1 = (gcnew System::Windows::Forms::ListBox());
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(58, 527);
			this->button1->Name = L"Szukaj";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Szukaj";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(12, 501);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(172, 20);
			this->textBox1->TabIndex = 1;
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(350, 501);
			this->textBox2->Name = L"Czaswykonania";
			this->textBox2->Size = System::Drawing::Size(100, 20);
			this->textBox2->TabIndex = 0;
			this->textBox2->ReadOnly = true;
			this->textBox2->Text = L"Czas wykonania";
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(350, 530);
			this->button2->Name = L"Dalej";
			this->button2->Size = System::Drawing::Size(75, 23);
			this->button2->TabIndex = 1;
			this->button2->Text = L"Dalej";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Form1::button2_Click);
			// 
			// listBox1
			// 
			this->listBox1->FormattingEnabled = true;
			this->listBox1->Items->AddRange(gcnew cli::array< System::Object^  >(3) {L"1 Rdzeń", L"2 Rdzenie", L"4 Rdzenie"});
			this->listBox1->Location = System::Drawing::Point(206, 501);
			this->listBox1->Name = L"listBox1";
			this->listBox1->Size = System::Drawing::Size(120, 50);
			this->listBox1->TabIndex = 2;
			this->listBox1->SelectedIndexChanged += gcnew System::EventHandler(this, &Form1::listBox1_SelectedIndexChanged);
			////////////////////////////////////////////////////////////////////////////////

			this->richTextBox1 = (gcnew System::Windows::Forms::RichTextBox());
			this->SuspendLayout();
			this->richTextBox1->AutoWordSelection = true;
			this->richTextBox1->Location = System::Drawing::Point(-2, -2);
			this->richTextBox1->Name = L"richTextBox1";
			this->richTextBox1->ReadOnly = true;
			this->richTextBox1->Size = System::Drawing::Size(800, 490);
			this->richTextBox1->TabIndex = 1;

/////####################### LOAD FILE TO SCREEN #############################################

	  // Create an OpenFileDialog to request a file to open.
      OpenFileDialog^ openFile1 = gcnew OpenFileDialog;
      // Initialize the OpenFileDialog to look for RTF files.
      openFile1->DefaultExt = "*.rtf";
      openFile1->Filter = "RTF Files|*.rtf";
      // Determine whether the user selected a file from the OpenFileDialog.
      if ( openFile1->ShowDialog() == System::Windows::Forms::DialogResult::OK &&
         openFile1->FileName->Length > 0 )
      {
         // Load the contents of the file into the RichTextBox.
         richTextBox1->LoadFile( openFile1->FileName );
      }

	  richText = richTextBox1->Text;

			this->richTextBox1->TextChanged += gcnew System::EventHandler(this, &Form1::richTextBox1_TextChanged);
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(800, 490);
			this->Controls->Add(this->richTextBox1);
			this->Name = L"Form1";
			this->Text = L"Form1";
			this->ResumeLayout(false);
////////////////////////////////////////////////////////////////////////////////////////////////////////////////

			// 
			// Form1
			// 
			this->ClientSize = System::Drawing::Size(800, 560);
			this->Controls->Add(this->listBox1);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->button2);
			this->Name = L"Form1";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->ResumeLayout(false);
			this->PerformLayout();

		}

#pragma endregion
	private: System::Void label1_Click(System::Object^  sender, System::EventArgs^  e) {
			 }
	private: System::Void richTextBox1_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 }

static void Threaad()
{

int pos = 0;
pos = richText->IndexOf(ValToSearchFor, 0);

for (;pos != -1;) 
{   
    pos = richText->IndexOf(ValToSearchFor, pos + 1);
	lista.push_back(pos);
}

}

//odpala szukanie 
private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) 
{
//czysczenie ekranu
//richTextBox1->SelectAll();
//richTextBox1->SelectionColor = Color::Black;		

ValToSearchFor = textBox1->Text;
leng=ValToSearchFor->Length;

//jezeli pusty string wyszkuiwan
if (leng==0)
MessageBox::Show("Poszukiwany tekst nie może być pusty !");
else
{

int pos = 0;
pos = richText->IndexOf(ValToSearchFor, 0);
std::list<int> lista;

// glowna petla
clock_t start = clock();

for (;pos != -1;) 
{
    richTextBox1->Select(pos, ValToSearchFor->Length);
    richTextBox1->SelectionColor = Color::Red;
    pos = richText->IndexOf(ValToSearchFor, pos + 1);
	lista.push_back(pos);
}

//kalkuluj czas
std::ostringstream ss;
clock_t end2 = clock();
ss << (end2 - start);
std::string Time(ss.str());
String^ Times = gcnew String(Time.c_str());
this->textBox2->Text = Times;

//skroluj to zaznaczonego
list2=lista;
iter=list2.begin();
blokada=true;

//obsluga rdzeni 
if(listBox1->SelectedItem)
if(listBox1->SelectedItem->ToString()=="2 Rdzenie")
{
clock_t start2 = clock();

ThreadStart^ threadDelegate = gcnew ThreadStart(&Form1::Threaad);
Thread^ newThread = gcnew Thread( threadDelegate );
newThread->Start();

while (newThread->IsAlive);   // wait for the thread to start  
	Thread::Sleep(20);  

int pos2=richTextBox1->Lines->Length;
pos2=pos2/2;

for (;pos2 != -1;) 
{
	richTextBox1->Select(pos2, ValToSearchFor->Length);
	pos2 = richText->IndexOf(ValToSearchFor, pos2 + 1);
}

std::ostringstream ss;
clock_t end = clock();
ss << (end - start2);
std::string Time(ss.str());
Timess = gcnew String(Time.c_str());
this->textBox2->Text = Timess;
}
//////////////////////////////////////////////////////////////4
if(listBox1->SelectedItem)
if(listBox1->SelectedItem->ToString()=="4 Rdzenie")
{
ThreadStart^ threadDelegate = gcnew ThreadStart(&Form1::Threaad);
Thread^ newThread1 = gcnew Thread( threadDelegate );
newThread1->Start();

Thread^ newThread2 = gcnew Thread( threadDelegate );
newThread2->Start();

Thread^ newThread3 = gcnew Thread( threadDelegate );
newThread3->Start();

int pos2=richTextBox1->Lines->Length;
pos2 = richText->IndexOf(ValToSearchFor, (pos2/2) + 1);
clock_t start2 = clock();

for (;pos2 != -1;) 
{
	richTextBox1->Select(pos2, ValToSearchFor->Length);
	pos2 = richText->IndexOf(ValToSearchFor, pos2 + 1);
}
clock_t end = clock();
std::ostringstream ss;
ss << (end - start2);
std::string Time(ss.str());
Timess = gcnew String(Time.c_str());
this->textBox2->Text = Timess;
}

}
}

private: System::Void listBox1_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
			 }

// Scrolluje nas do nastepnego znalezionego slowa
private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) 
{	
if(blokada==true)
{
 int position;
 position=*iter;

 richTextBox1->Select(position,leng);
 richTextBox1->ScrollToCaret();
 richTextBox1->Focus();
 ++iter;
 }

}


};
}

