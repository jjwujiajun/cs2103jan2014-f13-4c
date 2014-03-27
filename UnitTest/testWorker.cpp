#include "stdafx.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace workerTest {		
	TEST_CLASS(Easydone)
	{
	public:
		
		TEST_METHOD(takeparsedCommand)
		{
			// TODO: Your test code here
			Worker test;
			string randomString = "create arun start 1000";
			string example;
			vector<string> randomCase;
			randomCase.push_back("create");
			randomCase.push_back("arun ");
			randomCase.push_back("");
			randomCase.push_back("1000");
			randomCase.push_back("");
			randomCase.push_back("");


			example = test.takeparsedCommand(randomCase);

			 
			string testHardCase = " has been added successfully! :) \n";

			Assert::AreEqual(example, testHardCase);
		
		
		}

		TEST_METHOD(takeparsedCommand_2)
		{
			// TODO: Your test code here
			Worker test;
			string randomString = "new Australia Holiday from 20141212 to 20141225 start 2300 end 2100";
			string example;
			vector<string> randomCase;
			randomCase.push_back("");
			randomCase.push_back("Australia Holiday 1 ");
			randomCase.push_back("20141212");
			randomCase.push_back("20141225");
			randomCase.push_back("2300");
			randomCase.push_back("2100");


			example = test.takeparsedCommand(randomCase);

			 
			string testHardCase = " has been added successfully! :) \n";

			Assert::AreNotEqual(example, testHardCase);
		
		
		}

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

			 
			string testHardCase = "";

			Assert::AreEqual(example, testHardCase);
		
		
		}
	};
}
