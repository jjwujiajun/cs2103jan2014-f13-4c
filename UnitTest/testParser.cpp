#include "stdafx.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace parserTest {		
	TEST_CLASS(Easydone)
	{
	public:
		
		TEST_METHOD(parseUserInput)
		{
			// TODO: Your test code here

			Parser test;
			vector<string> testCase;
			string randomList = "add arun birthday on 20141212 1000";
			
			testCase = test.storeInformation(randomList);
			 
			vector<string> testHardCase;
			testHardCase.push_back("add");
			testHardCase.push_back("arun");
			testHardCase.push_back("birthday");
			testHardCase.push_back("on");
			testHardCase.push_back("20141212");
			testHardCase.push_back("1000");

			
			for (int i =0; i < 6; i++) {
				Assert::AreEqual(testCase[i], testHardCase[i]);
			}

		}

		TEST_METHOD(parseCommand)
		{
			// TODO: Your test code here

			Parser test;
			vector<string> testCase;
			string randomList = "delete 2";
			
			testCase = test.storeInformation(randomList);
			test.parseCommand(testCase);
			
			vector<string> testHardCase;
			testHardCase.push_back("delete");
		
			for (int i =0; i < 1; i++) {
				Assert::AreEqual(testCase[i], testHardCase[i]);
			}

		}

		TEST_METHOD(completeParse_1)
		{
			// TODO: Your test code here

			
			Parser test;
			vector<string> testCase;
			string randomList = "add arun birthday on 20141212 1000";
			
			testCase = test.completeParse(randomList);
			 
			vector<string> testHardCase;
			testHardCase.push_back("add");
			testHardCase.push_back("arun birthday ");
			testHardCase.push_back("20141212");
			testHardCase.push_back("1000");
			testHardCase.push_back("");
			testHardCase.push_back("");

			for (int i =0; i < 6; i++) {
				Assert::AreEqual(testCase[i], testHardCase[i]);
			}

		}

		TEST_METHOD(completeParse_2)
		{
			// TODO: Your test code here

			
			Parser test;
			vector<string> testCase;
			string randomList = "add arun birthday start 1000 end 1200 from 20141213";
			
			testCase = test.completeParse(randomList);
			 
			vector<string> testHardCase;
			testHardCase.push_back("add");
			testHardCase.push_back("arun birthday ");
			testHardCase.push_back("20141213");
			testHardCase.push_back("1000");
			testHardCase.push_back("");
			testHardCase.push_back("1200");
			
			for (int i =0; i < 6; i++) {
				Assert::AreEqual(testCase[i], testHardCase[i]);
			}	

		}

		TEST_METHOD(completeParse_3)
		{
			// TODO: Your test code here

			
			Parser test;
			vector<string> testCase;
			string randomList = "update 5 startDate 20140102";
			
			testCase = test.completeParse(randomList);
			 
			vector<string> testHardCase;
			testHardCase.push_back("update");
			testHardCase.push_back("5");
			testHardCase.push_back("startDate");
			testHardCase.push_back("20140102");
			
			
			for (int i =0; i < 4; i++) {
				Assert::AreEqual(testCase[i], testHardCase[i]);
			}	

		}
	};
}

