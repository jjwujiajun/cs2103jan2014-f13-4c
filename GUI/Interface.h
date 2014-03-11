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
		Interface(void)
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
		~Interface()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^  inputField;
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::ListView^  listView1;
	private: System::Windows::Forms::ColumnHeader^  index;
	private: System::Windows::Forms::ColumnHeader^  startDate;
	private: System::Windows::Forms::ColumnHeader^  startTime;
	private: System::Windows::Forms::ColumnHeader^  task;
	private: System::Windows::Forms::Label^  title;
	protected: 

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
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->listView1 = (gcnew System::Windows::Forms::ListView());
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
			this->inputField->Location = System::Drawing::Point(12, 555);
			this->inputField->Name = L"inputField";
			this->inputField->Size = System::Drawing::Size(351, 20);
			this->inputField->TabIndex = 0;
			// 
			// textBox1
			// 
			this->textBox1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->textBox1->Location = System::Drawing::Point(12, 455);
			this->textBox1->Multiline = true;
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(351, 94);
			this->textBox1->TabIndex = 1;
			// 
			// listView1
			// 
			this->listView1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) 
				| System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->listView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::ColumnHeader^  >(4) {this->index, this->startDate, 
				this->startTime, this->task});
			this->listView1->Location = System::Drawing::Point(12, 38);
			this->listView1->Name = L"listView1";
			this->listView1->Size = System::Drawing::Size(351, 409);
			this->listView1->TabIndex = 2;
			this->listView1->UseCompatibleStateImageBehavior = false;
			this->listView1->View = System::Windows::Forms::View::Details;
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
			this->task->Width = 234;
			// 
			// title
			// 
			this->title->AutoSize = true;
			this->title->Font = (gcnew System::Drawing::Font(L"Buxton Sketch", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->title->ForeColor = System::Drawing::Color::CornflowerBlue;
			this->title->Location = System::Drawing::Point(143, 9);
			this->title->Name = L"title";
			this->title->Size = System::Drawing::Size(86, 26);
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
			this->Controls->Add(this->listView1);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->inputField);
			this->MaximizeBox = false;
			this->Name = L"Interface";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	};
}
