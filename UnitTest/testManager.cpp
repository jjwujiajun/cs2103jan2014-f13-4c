//@author A0100705Y
#include "stdafx.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace managerTest {		
	TEST_CLASS(Easydone)
	{
	public:
		
		TEST_METHOD(testReceiveInput)
		{
			string input = "add arun on 20141212";
			Manager test;
			
			test.receiveInput(input);
			string testCase = test.userInput;

			string testHardCase = "add arun on 20141212";

			Assert::AreEqual(testCase, testHardCase);

		}
		
		// Unit test: partition case to
		TEST_METHOD(testgetTaskList)
		{

			Manager test;
			
			Task userTask;
			vector<Task> getList;
			userTask.taskName = "Arun";
			userTask.startDate = "20141212";
			userTask.startTime = "1000";
			
			
			getList = *test.GUITaskList;

			vector<Task> testHardCase;
			Task testTask;
			testTask.taskName = "";
			testTask.startDate = "";
			testTask.startTime = "10:00";
			testHardCase.push_back(testTask);

			string test1 = getList[0].startTime;
			string test2 = testHardCase[0].startTime;

			Assert::AreEqual(test1, test2);
			

		}

		TEST_METHOD(testgetTaskList_2)
		{

			Manager test;
			
			Task userTask;
			vector<Task> getList;
			userTask.taskName = "Arun";
			userTask.startDate = "20141212";
			userTask.startTime = "1000";
			
			
			getList = *test.GUITaskList;

			vector<Task> testHardCase;
			Task testTask;
			testTask.taskName = "";
			testTask.startDate = "";
			testTask.startTime = "10:00";
			testHardCase.push_back(testTask);

			string test1 = getList[0].startTime;
			string test2 = testHardCase[0].startTime;

			Assert::AreEqual(test1, test2);
			

		}



	};

}