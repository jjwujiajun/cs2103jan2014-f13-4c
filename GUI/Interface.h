#include "Headers.h"
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

			// manager->getTaskList();
			// displayTasksListBox();

			// display feedback
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
		void displayTasksListBox(vector<Task> taskList) {
			int i = 0;

			richTaskList->Clear();
			while (i < taskList.size() && i < 10) {
				displayTask(taskList[i]);
				i++;
			}
		}

		void displayTodayLabel() {
			richTaskList->SelectionFont = gcnew System::Drawing::Font("Broadway", 12);
			richTaskList->SelectionColor = Color::CornflowerBlue;
			richTaskList->SelectedText = "Today \n";
		}

		void displayAllTaskLabel() {	
			richTaskList->SelectionFont = gcnew System::Drawing::Font("Broadway", 12);
			richTaskList->SelectionColor = Color::CornflowerBlue;
			richTaskList->SelectedText = "All Tasks \n";
		}

		void displayTask(Task task) {
			displayTaskIndex(task);
			displayTaskInformation(task);
		}
		void displayTaskIndex(Task task) {
			if (task.isBold) {
				richTaskList->SelectionFont = gcnew System::Drawing::Font("Calibri", 8, FontStyle::Bold);
			} else {
				richTaskList->SelectionFont = gcnew System::Drawing::Font("Calibri", 8, FontStyle::Regular);
			}
			richTaskList->SelectionColor = Color::Gray;
			
			String ^index = gcnew String(task.taskID.c_str());
			richTaskList->SelectedText = "  ";
			richTaskList->SelectedText = index;
		}
		void displayTaskInformation(Task task) {
			if (task.isBold) {
				richTaskList->SelectionFont = gcnew System::Drawing::Font("Calibri", 11, FontStyle::Bold);
			} else {
				richTaskList->SelectionFont = gcnew System::Drawing::Font("Calibri", 11, FontStyle::Regular);
			}
			richTaskList->SelectionColor = Color::Black;

			// ~~Spacing~~
			richTaskList->SelectedText = "\t";
			// - Date
			String ^startDate = gcnew String(task.startDate.c_str());
			richTaskList->SelectedText = startDate;
			// ~~Spacing~~
			richTaskList->SelectedText = "\t";
			// - Time
			String ^startTime = gcnew String(task.startTime.c_str());
			richTaskList->SelectedText = startTime;
			// ~~Spacing~~
			richTaskList->SelectedText = "\t";
			// - Description
			String ^taskName = gcnew String(task.taskName.c_str());
			richTaskList->SelectedText = taskName;
			// ~~NewLine~~
			richTaskList->SelectedText = "\n";
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





	private: System::Windows::Forms::Label^  title;
	private: System::Windows::Forms::RichTextBox^  richTaskList;
private: System::Windows::Forms::Label^  label1;
private: System::Windows::Forms::Label^  label2;
private: System::Windows::Forms::Label^  label3;
private: System::Windows::Forms::Label^  label4;

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
			this->title = (gcnew System::Windows::Forms::Label());
			this->richTaskList = (gcnew System::Windows::Forms::RichTextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
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
			// title
			// 
			this->title->Anchor = System::Windows::Forms::AnchorStyles::Top;
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
			// richTaskList
			// 
			this->richTaskList->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) 
				| System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->richTaskList->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->richTaskList->Font = (gcnew System::Drawing::Font(L"Broadway", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->richTaskList->ForeColor = System::Drawing::SystemColors::InactiveCaption;
			this->richTaskList->Location = System::Drawing::Point(12, 61);
			this->richTaskList->Name = L"richTaskList";
			this->richTaskList->Size = System::Drawing::Size(351, 386);
			this->richTaskList->TabIndex = 4;
			this->richTaskList->Text = L"";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->ForeColor = System::Drawing::Color::SkyBlue;
			this->label1->Location = System::Drawing::Point(27, 42);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(18, 13);
			this->label1->TabIndex = 5;
			this->label1->Text = L"ID";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->ForeColor = System::Drawing::Color::SkyBlue;
			this->label2->Location = System::Drawing::Point(63, 42);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(30, 13);
			this->label2->TabIndex = 6;
			this->label2->Text = L"Date";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->ForeColor = System::Drawing::Color::SkyBlue;
			this->label3->Location = System::Drawing::Point(111, 42);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(30, 13);
			this->label3->TabIndex = 7;
			this->label3->Text = L"Time";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->ForeColor = System::Drawing::Color::SkyBlue;
			this->label4->Location = System::Drawing::Point(160, 42);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(31, 13);
			this->label4->TabIndex = 8;
			this->label4->Text = L"Task";
			// 
			// Interface
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::White;
			this->ClientSize = System::Drawing::Size(375, 587);
			this->ControlBox = false;
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->richTaskList);
			this->Controls->Add(this->title);
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
					 std::vector<Task> receivedTaskList;

					 inputString = inputField->Text;
					 MarshalString(inputString, convertedInputString);

					 manager->receiveInput(convertedInputString);

					 receivedTaskList = manager->getTaskList();
					 receivedFeedback = manager->getFeedback();
					 receivedInput = manager->getInputField();

					 feedbackToDisplay = gcnew String(receivedFeedback.c_str());
					 inputToDisplay = gcnew String(receivedInput.c_str());

					 displayTasksListBox(receivedTaskList);
					 feedbackBox->Text = feedbackToDisplay;
					 inputField->Text = inputToDisplay;

					 delete feedbackToDisplay;
				 }
			 }

};
}
