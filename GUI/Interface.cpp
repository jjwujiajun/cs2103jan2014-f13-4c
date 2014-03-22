#include "Interface.h"

using namespace System; 
using namespace System::Windows::Forms; 

[STAThread] 
void main(array<String^>^ args) { 
 Application::EnableVisualStyles(); 
 Application::SetCompatibleTextRenderingDefault(false); 
 
 GUI::Interface mainWindow; 
 Application::Run(%mainWindow); 
} 

GUI::Interface::Interface(void) {
	InitializeComponent();
	// Add the constructor code here
	manager = new Manager();
	helpIsShown = false;

	// manager->getTaskList();
	// displayTasksListBox();

	// display feedback
	std::string receivedFeedback = manager->getFeedback();
	String ^feedbackToDisplay = gcnew String(receivedFeedback.c_str());
	feedbackBox->Text = feedbackToDisplay;
}

GUI::Interface::~Interface() {
	delete manager;
	if (components)	{
		delete components;
	}
}

void GUI::Interface::operateUserRequest() {
	receiveUserInput();

	displayTasksListBox();
	displayFeedbackBox();
	displayInputField();
}

// input functions
void GUI::Interface::receiveUserInput() {
	String ^inputString;
	std::string convertedInputString;

	inputString = inputField->Text;
	convertSysToStdString(inputString, convertedInputString);

	manager->receiveInput(convertedInputString);
}

void GUI::Interface::toggleHelpSection() {
	if (helpIsShown) {
		feedbackBox->Text = "Help page is closed\n";

		this->ClientSize = System::Drawing::Size(375, 587);
		this->helpBox->Visible = !this->helpBox->Visible;
	} else {
		feedbackBox->Text = "Show help page\n";
		this->ClientSize = System::Drawing::Size(674, 587);
		this->helpBox->Visible = !this->helpBox->Visible;
	}
	helpIsShown = !helpIsShown;
}

// display functions
void GUI::Interface::displayTasksListBox() {
	std::vector<Task> receivedTaskList;
	int i = 0;

	receivedTaskList = manager->getTaskList();

	richTaskList->Clear();
	while (i < receivedTaskList.size() && i < 10) {
		displayTask(receivedTaskList[i]);
		i++;
	}
}

void GUI::Interface::displayFeedbackBox() {
	String ^feedbackToDisplay;
	std::string receivedFeedback;

	receivedFeedback = manager->getFeedback();
	convertStdToSysString(receivedFeedback, feedbackToDisplay);
	feedbackBox->Text = feedbackToDisplay;

	delete feedbackToDisplay;
}

void GUI::Interface::displayInputField() {
	String ^inputToDisplay;
	std::string receivedInput;

	receivedInput = manager->getInputField();
	convertStdToSysString(receivedInput, inputToDisplay);
	inputField->Text = inputToDisplay;

	delete inputToDisplay;
}

// string conversion functions
void GUI::Interface::convertSysToStdString(String ^ s, string& os) {
	using namespace Runtime::InteropServices;
	const char* chars = 
		(const char*)(Marshal::StringToHGlobalAnsi(s)).ToPointer();
	os = chars;
	Marshal::FreeHGlobal(IntPtr((void*)chars));
}

void GUI::Interface::convertStdToSysString(string &os, String^ &s) {
	s = gcnew String(os.c_str());
}

// taskList display functions
void GUI::Interface::displayTask(Task task) {
	displayTaskIndex(task);
	displayTaskInformation(task);
}

void GUI::Interface::displayTaskIndex(Task task) {
	if (task.isBold) {
		richTaskList->SelectionFont = gcnew System::Drawing::Font("Calibri", 8, FontStyle::Bold);
	} else {
		richTaskList->SelectionFont = gcnew System::Drawing::Font("Calibri", 8, FontStyle::Regular);
	}
	richTaskList->SelectionColor = Color::Gray;
			
	String ^index = gcnew String(task.taskID.c_str());
	richTaskList->SelectedText = "  ";
	richTaskList->SelectedText = index;

	delete richTaskList->SelectionFont;
	delete index;
}

void GUI::Interface::displayTaskInformation(Task task) {
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

	delete richTaskList->SelectionFont;
	delete startDate;
	delete startTime;
	delete taskName;
}

void GUI::Interface::displayTodayLabel() {
	richTaskList->SelectionFont = gcnew System::Drawing::Font("Broadway", 12);
	richTaskList->SelectionColor = Color::CornflowerBlue;
	richTaskList->SelectedText = "Today \n";

	delete richTaskList->SelectionFont;
}

void GUI::Interface::displayAllTaskLabel() {	
	richTaskList->SelectionFont = gcnew System::Drawing::Font("Broadway", 12);
	richTaskList->SelectionColor = Color::CornflowerBlue;
	richTaskList->SelectedText = "All Tasks \n";

	delete richTaskList->SelectionFont;
}
