#include <string>
#include "Manager.h"

#pragma once

namespace GUI {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Interface
	/// </summary>
	public ref class Interface : public System::Windows::Forms::Form
	{
	public:
		Interface(void) {
			InitializeComponent();
			// Add the constructor code here
			manager = new Manager();

			std::string receivedFeedback = manager->getFeedback();
			String ^feedbackToDisplay = gcnew String(receivedFeedback.c_str());

			feedbackBox->Text = feedbackToDisplay;
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Interface() {
			delete manager;
			if (components)	{
				delete components;
			}
		}

	public:
		void MarshalString ( String ^ s, string& os ) {
		   using namespace Runtime::InteropServices;
		   const char* chars = 
			  (const char*)(Marshal::StringToHGlobalAnsi(s)).ToPointer();
		   os = chars;
		   Marshal::FreeHGlobal(IntPtr((void*)chars));
		}

	private: Manager *manager;
	private: System::Windows::Forms::TextBox^  inputField;
	private: System::Windows::Forms::TextBox^  feedbackBox;
	private: System::Windows::Forms::ListView^  taskList;
	private: System::Windows::Forms::ColumnHeader^  index;
	private: System::Windows::Forms::ColumnHeader^  startDate;
	private: System::Windows::Forms::ColumnHeader^  startTime;
	private: System::Windows::Forms::ColumnHeader^  task;
	private: System::Windows::Forms::Label^  title;

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
			this->inputField = (gcnew System::Windows::Forms::TextBox());
			this->feedbackBox = (gcnew System::Windows::Forms::TextBox());
			this->taskList = (gcnew System::Windows::Forms::ListView());
			this->index = (gcnew System::Windows::Forms::ColumnHeader());
			this->startDate = (gcnew System::Windows::Forms::ColumnHeader());
			this->startTime = (gcnew System::Windows::Forms::ColumnHeader());
			this->task = (gcnew System::Windows::Forms::ColumnHeader());
			this->title = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// inputField
			// 
			this->inputField->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->inputField->BackColor = System::Drawing::Color::White;
			this->inputField->ForeColor = System::Drawing::SystemColors::WindowText;
			this->inputField->Location = System::Drawing::Point(12, 555);
			this->inputField->Name = L"inputField";
			this->inputField->Size = System::Drawing::Size(351, 20);
			this->inputField->TabIndex = 0;
			this->inputField->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &Interface::enterPressed);
			// 
			// feedbackBox
			// 
			this->feedbackBox->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->feedbackBox->BackColor = System::Drawing::Color::White;
			this->feedbackBox->Cursor = System::Windows::Forms::Cursors::Arrow;
			this->feedbackBox->Location = System::Drawing::Point(12, 453);
			this->feedbackBox->Multiline = true;
			this->feedbackBox->Name = L"feedbackBox";
			this->feedbackBox->ReadOnly = true;
			this->feedbackBox->Size = System::Drawing::Size(351, 96);
			this->feedbackBox->TabIndex = 1;
			// 
			// taskList
			// 
			this->taskList->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) 
				| System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->taskList->BackColor = System::Drawing::Color::White;
			this->taskList->Columns->AddRange(gcnew cli::array< System::Windows::Forms::ColumnHeader^  >(4) {this->index, this->startDate, 
				this->startTime, this->task});
			this->taskList->ForeColor = System::Drawing::SystemColors::MenuBar;
			this->taskList->HeaderStyle = System::Windows::Forms::ColumnHeaderStyle::Nonclickable;
			this->taskList->LabelWrap = false;
			this->taskList->Location = System::Drawing::Point(12, 38);
			this->taskList->Name = L"taskList";
			this->taskList->Scrollable = false;
			this->taskList->Size = System::Drawing::Size(351, 409);
			this->taskList->TabIndex = 2;
			this->taskList->UseCompatibleStateImageBehavior = false;
			this->taskList->View = System::Windows::Forms::View::Details;
			// 
			// index
			// 
			this->index->Text = L"Index";
			this->index->Width = 38;
			// 
			// startDate
			// 
			this->startDate->Text = L"Date";
			this->startDate->Width = 35;
			// 
			// startTime
			// 
			this->startTime->Text = L"Time";
			this->startTime->Width = 37;
			// 
			// task
			// 
			this->task->Text = L"Task";
			this->task->Width = 235;
			// 
			// title
			// 
			this->title->AutoSize = true;
			this->title->BackColor = System::Drawing::Color::White;
			this->title->Font = (gcnew System::Drawing::Font(L"Buxton Sketch", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->title->ForeColor = System::Drawing::Color::CornflowerBlue;
			this->title->Location = System::Drawing::Point(143, 9);
			this->title->Name = L"title";
			this->title->Size = System::Drawing::Size(97, 29);
			this->title->TabIndex = 3;
			this->title->Text = L"EasyDone";
			this->title->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			// 
			// Interface
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::White;
			this->ClientSize = System::Drawing::Size(375, 587);
			this->ControlBox = false;
			this->Controls->Add(this->title);
			this->Controls->Add(this->taskList);
			this->Controls->Add(this->feedbackBox);
			this->Controls->Add(this->inputField);
			this->MaximizeBox = false;
			this->Name = L"Interface";
			this->ShowIcon = false;
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		//
		// function: press enter to take in string
		//
	private: System::Void enterPressed(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  keyPressed) {
				 if (keyPressed->KeyCode == Keys::Enter) {
					 String ^inputString;
					 String ^feedbackToDisplay;
					 String ^inputToDisplay;
					 std::string convertedInputString;
					 std::string receivedFeedback;
					 std::string receivedInput;
					 inputString = inputField->Text;
					 MarshalString(inputString, convertedInputString);

					 manager->receiveInput(convertedInputString);
					 receivedFeedback = manager->getFeedback();
					 receivedInput == "";
					 //receivedFeedback = convertedInputString;

					 feedbackToDisplay = gcnew String(receivedFeedback.c_str());
					 inputToDisplay = gcnew String(receivedInput.c_str());

					 feedbackBox->Text = feedbackToDisplay;
					 inputField->Text = inputToDisplay;

					 delete feedbackToDisplay;
				 }
			 }
	};
}
