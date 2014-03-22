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

void GUI::Interface::receiveUserInput() {
	String ^inputString;
	String ^feedbackToDisplay;
	String ^inputToDisplay;
	std::string convertedInputString;
	std::string receivedFeedback;
	std::string receivedInput;
	std::vector<Task> receivedTaskList;

	inputString = inputField->Text;
	convertSysToStdString(inputString, convertedInputString);

	manager->receiveInput(convertedInputString);

	receivedTaskList = manager->getTaskList();
	receivedFeedback = manager->getFeedback();
	receivedInput = manager->getInputField();

	//convertStdToSysString(receivedFeedback, feedbackToDisplay);
	feedbackToDisplay = gcnew String(receivedFeedback.c_str());
	inputToDisplay = gcnew String(receivedInput.c_str());

	displayTasksListBox(receivedTaskList);
	feedbackBox->Text = feedbackToDisplay;
	inputField->Text = inputToDisplay;

	delete feedbackToDisplay;
	delete inputToDisplay;
}

// string conversion
void GUI::Interface::convertSysToStdString(String ^ s, string& os) {
	using namespace Runtime::InteropServices;
	const char* chars = 
		(const char*)(Marshal::StringToHGlobalAnsi(s)).ToPointer();
	os = chars;
	Marshal::FreeHGlobal(IntPtr((void*)chars));
}

void GUI::Interface::convertStdToSysString(string &os, String ^s) {
	s = gcnew String(os.c_str());
}

// taskList display
void GUI::Interface::displayTasksListBox(vector<Task> taskList) {
	int i = 0;

	richTaskList->Clear();
	while (i < taskList.size() && i < 10) {
		displayTask(taskList[i]);
		i++;
	}
}

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
