// @author A0101681R
// Written by: Ramireddi Juhi Simanthika
#include "stdafx.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace workerTest {		
	TEST_CLASS(Easydone)
	{
	public:

/*These tests check if flow of actions from takeParsedCommand in Worker class to functions in  Command class takes place successfully i.e. 
***********************successful perfomation of CRUD is carried out for FlexiCommand on the vector in Store.*************************/

		// unit test
		TEST_METHOD(takeparsedCommand_create)
		{
			// TODO: Your test code here
			Worker test;
			string randomString = "create arun on 1000";
			string example;
			vector<string> randomCase;
			randomCase.push_back("create");
			randomCase.push_back("arun");
			randomCase.push_back("");
			randomCase.push_back("1000");
			randomCase.push_back("");
			randomCase.push_back("");


			example = test.takeparsedCommand(randomCase);

			 
			string testHardCase = "has been added successfully! :) \r\n";

			Assert::AreEqual(example, testHardCase);
		
		
		}
		// unit test
		// 
		TEST_METHOD(takeparsedCommand_new)
		{
			// TODO: Your test code here
			Worker test;
			string randomString = "Australia Holiday from 20141212 to 20141225 start 2300 end 2100";
			string example;
			vector<string> randomCase;
			randomCase.push_back("add");
			randomCase.push_back("Australia Holiday");
			randomCase.push_back("20141212");
			randomCase.push_back("20141225");
			randomCase.push_back("2300");
			randomCase.push_back("2100");

			// "\"" + task.taskName + "\" \r\n"

			example = test.takeparsedCommand(randomCase);

			 
			string testHardCase ="\"Australia Holiday\"\r\nStart date cannot be after end date. Similarly if the start date and end date are same, start time cannot be after end time.\r\n";

			Assert::AreEqual(example, testHardCase);
		
		
		}


		// test case of an undo
		TEST_METHOD(takeparsedCommand_3)
		{
			// TODO: Your test code here
			Worker test;
			string randomString = "undo";
			string example;
			vector<string> randomCase;
			randomCase.push_back("undo");
			//randomCase.push_back("");
			//randomCase.push_back("");
			//randomCase.push_back("");
			//randomCase.push_back("");
			//randomCase.push_back("");
			//randomCase.push_back("");
			//randomCase.push_back("20131212");
		
			example = test.takeparsedCommand(randomCase);

			 
			string testHardCase = "The most recent change has been removed.\r\n";

			Assert::AreEqual(example, testHardCase);
		
		
		}


		// unit test
		// boundary test: delete a neg index
		TEST_METHOD(takeparsedCommand_delete_negInt)
		{
			// TODO: Your test code here
			Worker test;
			string randomString = "delete -1";
			string example;
			vector<string> randomCase;
			randomCase.push_back("delete");
			randomCase.push_back("-1");
			//randomCase.push_back("");
			//randomCase.push_back("");
			//randomCase.push_back("");
			//randomCase.push_back("");
			//randomCase.push_back("");
			//randomCase.push_back("20131212");
		
			example = test.takeparsedCommand(randomCase);

			 
			string testHardCase = "TaskID is out of range. Please check again.\r\n";

			Assert::AreEqual(example, testHardCase);
		}

		// unit test
		// boundary test: delete 1000
		TEST_METHOD(takeparsedCommand_delete_taskID_greaterThanActual)
		{
			// TODO: Your test code here
			Worker test;
			string randomString = "delete 1000";
			string example;
			vector<string> randomCase;
			randomCase.push_back("delete");
			randomCase.push_back("1000");
			//randomCase.push_back("");
			//randomCase.push_back("");
			//randomCase.push_back("");
			//randomCase.push_back("");
			//randomCase.push_back("");
			//randomCase.push_back("20131212");
		
			example = test.takeparsedCommand(randomCase);
			 
			string testHardCase = "TaskID is out of range. Please check again.\r\n";

			Assert::AreEqual(example, testHardCase);
		}

		// unit test
		// boundary test: delete a neg index
		TEST_METHOD(takeparsedCommand_display_negInt)
		{
			// TODO: Your test code here
			Worker test;
			string randomString = "display -1";
			string example;
			vector<string> randomCase;
			randomCase.push_back("display");
			randomCase.push_back("-1");
			//randomCase.push_back("");
			//randomCase.push_back("");
			//randomCase.push_back("");
			//randomCase.push_back("");
			//randomCase.push_back("");
			//randomCase.push_back("20131212");
		
			example = test.takeparsedCommand(randomCase);

			 
			string testHardCase = "TaskID is out of range. Please check again.\r\n";

			Assert::AreEqual(example, testHardCase);
		}

		// unit test
		// boundary test: delete 1000
		TEST_METHOD(takeparsedCommand_display_taskID_greaterThanActual)
		{
			// TODO: Your test code here
			Worker test;
			string randomString = "display 1000";
			string example;
			vector<string> randomCase;
			randomCase.push_back("delete");
			randomCase.push_back("1000");
			//randomCase.push_back("");
			//randomCase.push_back("");
			//randomCase.push_back("");
			//randomCase.push_back("");
			//randomCase.push_back("");
			//randomCase.push_back("20131212");
		
			example = test.takeparsedCommand(randomCase);
			 
			string testHardCase = "TaskID is out of range. Please check again.\r\n";

			Assert::AreEqual(example, testHardCase);
		}

		// unit test
		// boundary test: delete a neg index
		TEST_METHOD(takeparsedCommand_update_negInt)
		{
			// TODO: Your test code here
			Worker test;
			string randomString = "edit -1 task 123";
			string example;
			vector<string> randomCase;
			randomCase.push_back("edit");
			randomCase.push_back("0");
			randomCase.push_back("task");
			randomCase.push_back("123");
			//randomCase.push_back("");
			//randomCase.push_back("");
			//randomCase.push_back("");
			//randomCase.push_back("20131212");
		
			example = test.takeparsedCommand(randomCase);

			 
			string testHardCase = "Either invalid field input or taskID is out of range! Please check again.\r\n";

			Assert::AreEqual(example, testHardCase);
		}

		// unit test
		// boundary test: delete 1000
		TEST_METHOD(takeparsedCommand_update_taskID_greaterThanActual)
		{
			// TODO: Your test code here
			Worker test;
			string randomString = "edit 1 sd 14 apr 14";
			string example;
			vector<string> randomCase;
			randomCase.push_back("edit");
			randomCase.push_back("1");
			randomCase.push_back("14");
			randomCase.push_back("1");
			//randomCase.push_back("");
			//randomCase.push_back("");
			//randomCase.push_back("");
			//randomCase.push_back("20131212");
		
			example = test.takeparsedCommand(randomCase);
			 
			string testHardCase = "Either invalid field input or taskID is out of range! Please check again.\r\n";

			Assert::AreEqual(example, testHardCase);
		}

		// unit test
		// boundary test: update 0
		TEST_METHOD(takeparsedCommand_update_taskID_0)
		{
			// TODO: Your test code here
			Worker test;
			string randomString = "edit 0 sd 14 apr 14";
			string example;
			vector<string> randomCase;
			randomCase.push_back("edit");
			randomCase.push_back("0");
			randomCase.push_back("14");
			randomCase.push_back("1");
			//randomCase.push_back("");
			//randomCase.push_back("");
			//randomCase.push_back("");
			//randomCase.push_back("20131212");
		
			example = test.takeparsedCommand(randomCase);
			 
			string testHardCase = "Either invalid field input or taskID is out of range! Please check again.\r\n";

			Assert::AreEqual(example, testHardCase);
		}

		// unit test
		// boundary test: good case of index 1
		TEST_METHOD(takeparsedCommand_update_taskID_1)
		{
			// TODO: Your test code here
			Worker test;
			string randomString = "edit 1 sd 14 apr 14";
			string example;
			vector<string> randomCase;
			randomCase.push_back("edit");
			randomCase.push_back("1");
			randomCase.push_back("14");
			randomCase.push_back("1");
			//randomCase.push_back("");
			//randomCase.push_back("");
			//randomCase.push_back("");
			//randomCase.push_back("20131212");
		
			example = test.takeparsedCommand(randomCase);
			 
			string testHardCase = "Either invalid field input or taskID is out of range! Please check again.\r\n";
			Assert::AreEqual(example, testHardCase);
		}


	};
}
