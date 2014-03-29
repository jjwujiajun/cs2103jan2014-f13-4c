#include "stdafx.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace workerTest {		
	TEST_CLASS(Easydone)
	{
	public:

/**********These tests check if the functions in Command class work successfully: ************
they are supposed to perform the CURD functions on the storage vector<Task> in Store class*/

		/*Tests if Add function in Command class successfully manages to Add a task to the storage vector */
		TEST_METHOD(testCommand_addTaskName)
		{
			
			Command test;
			Task userTask;
			vector<Task> getList;
			userTask.taskName = "Arun";
			userTask.startDate = "20141212";
			test.Add(userTask);
			

			getList = test.getTaskList();

			vector<Task> testHardCase;
			Task testTask;
			testTask.taskName = "Arun";
			testTask.startDate = "20141214";
			testHardCase.push_back(testTask);

			string test1 = getList[0].taskName;
			string test2 = testHardCase[0].taskName;

			
			
			Assert::AreEqual(test1, test2);
		
			
		}


		TEST_METHOD(testCommand_addStartDate)
		{
			
			Command test;
			Task userTask;
			vector<Task> getList;
			userTask.taskName = "Arun";
			userTask.startDate = "20141212";
			test.Add(userTask);
			

			getList = test.getTaskList();

			vector<Task> testHardCase;
			Task testTask;
			testTask.taskName = "Arun";
			testTask.startDate = "20141214";
			testHardCase.push_back(testTask);

			
			string test3 = getList[0].startDate;
			string test4 = testHardCase[0].startDate;
			
			
			Assert::AreNotEqual(test3, test4);
			
		}

		/*Tests if Delete function in Command class successfully manages to Delete a task in the storage vector
		while ensuring the tasks behind the deleted task get pushed forward by an index in the storage vector */

		TEST_METHOD(testCommand_delete)
		{
			
			Command test;
			Task userTask1;
			Task userTask2;
			vector<Task> getList;

			userTask1.taskName = "Arun";
			userTask1.taskID = "1";
			userTask1.startDate = "20141212";
			test.Add(userTask1);

			userTask2.taskName = "Daniel";
			userTask2.taskID = "2";
			userTask2.startDate = "20151212";
			test.Add(userTask2);
		
			test.Delete(userTask1);
		
			getList = test.getTaskList();

			vector<Task> testHardCase;
			Task testTask;

			testTask.taskName = "Arun";
			testTask.startDate = "20141212";
			testHardCase.push_back(testTask);

			string test3 = getList[0].startDate;
			string test4 = testHardCase[0].startDate;
		
			Assert::AreNotEqual(test3, test4);
			
		}
	
	};
}
