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
			/* display Overdue
			 * while(false) { //date is overdue
			 *	displayTask();
			 *}
			 */
			/*
			// display Today
			if (true) { //first vector date is today
				displayTodayLabel();
			}
			while(true) { //date still today
				displayTask();
			}

			// display All Tasks
			if (false) {  //date is after today
				displayAllTaskLabel();
			}
			while (false) { // vector not finished
				displayTask();
			}
				*/
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
				richTaskList->SelectionFont = gcnew System::Drawing::Font("Calibri", 8);
			}
			richTaskList->SelectionColor = Color::Gray;
			
			String ^index = gcnew String(task.taskID.c_str());
			richTaskList->SelectedText = index;
		}
		void displayTaskInformation(Task task) {
			if (task.isBold) {
				richTaskList->SelectionFont = gcnew System::Drawing::Font("Calibri", 10, FontStyle::Bold);
			} else {
				richTaskList->SelectionFont = gcnew System::Drawing::Font("Calibri", 10);
			}
			richTaskList->SelectionColor = Color::Black;

			// ~~Spacing~~
			richTaskList->SelectedText = "  ";
			// - Date
			String ^startDate = gcnew String(task.startDate.c_str());
			richTaskList->SelectedText = startDate;
			// ~~Spacing~~
			richTaskList->SelectedText = "  ";
			// - Time
			String ^startTime = gcnew String(task.startTime.c_str());
			richTaskList->SelectedText = startTime;
			// ~~Spacing~~
			richTaskList->SelectedText = "  ";
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
	private: System::Windows::Forms::ListView^  taskList;
	private: System::Windows::Forms::ColumnHeader^  index;
	private: System::Windows::Forms::ColumnHeader^  startDate;
	private: System::Windows::Forms::ColumnHeader^  startTime;
	private: System::Windows::Forms::ColumnHeader^  task;
	private: System::Windows::Forms::Label^  title;
	private: System::Windows::Forms::RichTextBox^  richTaskList;

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
			this->richTaskList = (gcnew System::Windows::Forms::RichTextBox());
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
			this->taskList->Size = System::Drawing::Size(351, 35);
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
			// richTaskList
			// 
			this->richTaskList->Font = (gcnew System::Drawing::Font(L"Broadway", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->richTaskList->ForeColor = System::Drawing::SystemColors::InactiveCaption;
			this->richTaskList->Location = System::Drawing::Point(12, 79);
			this->richTaskList->Name = L"richTaskList";
			this->richTaskList->Size = System::Drawing::Size(351, 368);
			this->richTaskList->TabIndex = 4;
			this->richTaskList->Text = L"";
			// 
			// Interface
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::White;
			this->ClientSize = System::Drawing::Size(375, 587);
			this->ControlBox = false;
			this->Controls->Add(this->richTaskList);
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
					 std::vector<Task> receivedTaskList;

					 inputString = inputField->Text;
					 MarshalString(inputString, convertedInputString);

					 manager->receiveInput(convertedInputString);

					 receivedTaskList = manager->getTaskList();
					 receivedFeedback = manager->getFeedback();
					 receivedInput = manager->getInputField();
					 //receivedFeedback = convertedInputString;

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
