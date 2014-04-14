//@author A0094588J
#include "stdafx.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace parserTest {		
	TEST_CLASS(Easydone)
	{
	public:
		

		
		/*This tests if the breaking up of userInput string via spaces and the storage of this concated string in a vector<string> is successful. */

		//Unit test: if parsing breaks down user sentence via spaces
		TEST_METHOD(parseUserInput)
		{
			// TODO: Your test code here

			Parser test;
			vector<string> testCase;
			string randomList = "add arun birthday on 12/12/14 10.00";
			
			testCase = test.storeInformation(randomList);
			 
			vector<string> testHardCase;
			testHardCase.push_back("add");
			testHardCase.push_back("arun");
			testHardCase.push_back("birthday");
			testHardCase.push_back("on");
			testHardCase.push_back("12/12/14");
			testHardCase.push_back("10.00");

			
			for (int i =0; i < 6; i++) {
				Assert::AreEqual(testCase[i], testHardCase[i]);
			}

		}
		/*Unit Test: if parseCommand performs it's functionality: to retrieve the command from the concated userInput string*/
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
		// unit test: check if no command will means add
		TEST_METHOD(parseCommand2)
		{
			// TODO: Your test code here

			Parser test;
			vector<string> testCase;
			string randomList = "hahah hohohohoho on 12/12/12 10.00";
			
			testCase = test.completeParse(randomList);
			test.parseCommand(testCase);
			
			vector<string> testHardCase;
			testHardCase.push_back("add");
		
			for (int i =0; i < 1; i++) {
				Assert::AreEqual(testCase[i], testHardCase[i]);
			}

		}

	
		/*******These tests check if completeParse performs it's functionality for CRUD: to completely parse the 
		*************userInput string and store it in a vector<string> to be returned to Manager*******/


		//Unit test: case multiple inputs for keyWord "on"
		TEST_METHOD(completeParseOnCase)
		{
			// TODO: Your test code here

			
			Parser test;
			vector<string> testCase;
			string randomList = "add arun birthday on 12/12/14 10.00";
			
			testCase = test.completeParse(randomList);
			 
			vector<string> testHardCase;
			testHardCase.push_back("add");
			testHardCase.push_back("arun birthday");
			testHardCase.push_back("20141212");
			testHardCase.push_back("1000");
			testHardCase.push_back("");
			testHardCase.push_back("");

			for (int i =0; i < 6; i++) {
				Assert::AreEqual(testCase[i], testHardCase[i]);
			}

		}

		// Unit test: Partition away the add command to test if no add, will assume to be add	
		TEST_METHOD(completeParseOnCaseNoAdd)
		{
			// TODO: Your test code here
	
			Parser test;
			vector<string> testCase;
			string randomList = "arun birthday on 12/12/14 10.00";
			
			testCase = test.completeParse(randomList);
			 
			vector<string> testHardCase;
			testHardCase.push_back("add");
			testHardCase.push_back("arun birthday");
			testHardCase.push_back("20141212");
			testHardCase.push_back("1000");
			testHardCase.push_back("");
			testHardCase.push_back("");

			for (int i =0; i < 6; i++) {
				Assert::AreEqual(testCase[i], testHardCase[i]);
			}

		}

		//Unit test: Partition the on to see if can accept words after on
		TEST_METHOD(completeParseOnCaseNoAddWordsAfterOn)
		{
			// TODO: Your test code here
	
			Parser test;
			vector<string> testCase;
			string randomList = "arun birthday on the sentosa beach on 12/12/14 10.00";
			
			testCase = test.completeParse(randomList);
			 
			vector<string> testHardCase;
			testHardCase.push_back("add");
			testHardCase.push_back("arun birthday on the sentosa beach");
			testHardCase.push_back("20141212");
			testHardCase.push_back("1000");
			testHardCase.push_back("");
			testHardCase.push_back("");

			for (int i =0; i < 6; i++) {
				Assert::AreEqual(testCase[i], testHardCase[i]);
			}

		}

		// Unit test: Partioning the startDates and boundary case. Test 1, 31, 0, 32, 16
		// Unit test: Partioning the startTimes and boundary case. Test 00.00, 23.59, 24.00, 00.01, 12.00
		TEST_METHOD(completeParseOnCaseDateTime1)
		{
			// TODO: Your test code here
	
			Parser test;
			vector<string> testCase;
			string randomList = "arun birthday at the beach on 1/1/14 00.00";
			
			testCase = test.completeParse(randomList);
			 
			vector<string> testHardCase;
			testHardCase.push_back("add");
			testHardCase.push_back("arun birthday at the beach");
			testHardCase.push_back("20140101");
			testHardCase.push_back("0000");
			testHardCase.push_back("");
			testHardCase.push_back("");

			for (int i =0; i < 6; i++) {
				Assert::AreEqual(testCase[i], testHardCase[i]);
			}

		}

		TEST_METHOD(completeParseOnCaseDateTime2)
		{
			// TODO: Your test code here
	
			Parser test;
			vector<string> testCase;
			string randomList = "meet arun from japan on 16/6/14 12.01"; 
			
			testCase = test.completeParse(randomList);
			 
			vector<string> testHardCase;
			testHardCase.push_back("add");
			testHardCase.push_back("meet arun from japan");
			testHardCase.push_back("20140616");
			testHardCase.push_back("1201");
			testHardCase.push_back("");
			testHardCase.push_back("");

			for (int i =0; i < 6; i++) {
				Assert::AreEqual(testCase[i], testHardCase[i]);
			}

		}

			TEST_METHOD(completeParseOnCaseDateTime3)
		{
			// TODO: Your test code here
	
			Parser test;
			vector<string> testCase;
			string randomList = "arun birthday by the lake on 31/1/14 23.59";
			
			testCase = test.completeParse(randomList);
			 
			vector<string> testHardCase;
			testHardCase.push_back("add");
			testHardCase.push_back("arun birthday by the lake");
			testHardCase.push_back("20140131");
			testHardCase.push_back("2359");
			testHardCase.push_back("");
			testHardCase.push_back("");

			for (int i =0; i < 6; i++) {
				Assert::AreEqual(testCase[i], testHardCase[i]);
			}

		}

			// Unit test:
			// Boundary test case: date and time out of boundary
			TEST_METHOD(completeParseOnCaseDateTimeFail1)
		{
			// TODO: Your test code here
	
			Parser test;
			vector<string> testCase;
			string randomList = "arun birthday by the lake on 32/1/14 25.59";
			
			testCase = test.completeParse(randomList);
			 
			vector<string> testHardCase;
			testHardCase.push_back("add");
			testHardCase.push_back("arun birthday by the lake");
			testHardCase.push_back("1");
			testHardCase.push_back("0");
			testHardCase.push_back("");
			testHardCase.push_back("");

			for (int i =0; i < 6; i++) {
				Assert::AreEqual(testCase[i], testHardCase[i]);
			}

		}
			// Unit test:
			// Boundary test case: Leap year scenerio when correct
			TEST_METHOD(completeParseOnCaseDateTimeCheckLeap)
		{
			// TODO: Your test code here
	
			Parser test;
			vector<string> testCase;
			string randomList = "arun birthday to the lake on 29/2/16 23.59";
			
			testCase = test.completeParse(randomList);
			 
			vector<string> testHardCase;
			testHardCase.push_back("add");
			testHardCase.push_back("arun birthday to the lake");
			testHardCase.push_back("20160229");
			testHardCase.push_back("2359");
			testHardCase.push_back("");
			testHardCase.push_back("");

			for (int i =0; i < 6; i++) {
				Assert::AreEqual(testCase[i], testHardCase[i]);
			}

		}
			// Unit test:
			// Boundary test case: Leap year scenerio when fails
			TEST_METHOD(completeParseOnCaseDateTimeCheckLeapFail)
		{
			// TODO: Your test code here
	
			Parser test;
			vector<string> testCase;
			string randomList = "arun birthday to the lake on 29/2/15 23.59";
			
			testCase = test.completeParse(randomList);
			 
			vector<string> testHardCase;
			testHardCase.push_back("add");
			testHardCase.push_back("arun birthday to the lake");
			testHardCase.push_back("1");
			testHardCase.push_back("2359");
			testHardCase.push_back("");
			testHardCase.push_back("");

			for (int i =0; i < 6; i++) {
				Assert::AreEqual(testCase[i], testHardCase[i]);
			}

		}
			// Unit test:
			// multiple user test case to see if NLP format works
			TEST_METHOD(completeParseNlpFrom)
		{
			// TODO: Your test code here
	
			Parser test;
			vector<string> testCase;
			string randomList = "arun birthday from the cinema from 30 may 14 10.00";
			
			testCase = test.completeParse(randomList);
			 
			vector<string> testHardCase;
			testHardCase.push_back("add");
			testHardCase.push_back("arun birthday from the cinema ");
			testHardCase.push_back("20140530");
			testHardCase.push_back("1000");
			testHardCase.push_back("");
			testHardCase.push_back("");

			for (int i =0; i < 6; i++) {
				Assert::AreEqual(testCase[i], testHardCase[i]);
			}

		}
			// Unit test:
			// multiple user test case to see if NLP format works
			TEST_METHOD(completeParseNlpFrom2)
		{
			// TODO: Your test code here
	
			Parser test;
			vector<string> testCase;
			string randomList = "arun birthday from the cinema from 25 May 14 10.00";
		
			testCase = test.completeParse(randomList);
			 
			vector<string> testHardCase;
			testHardCase.push_back("add");
			testHardCase.push_back("arun birthday from the cinema ");
			testHardCase.push_back("20140525");
			testHardCase.push_back("1000");
			testHardCase.push_back("");
			testHardCase.push_back("");

			for (int i =0; i < 6; i++) {
				Assert::AreEqual(testCase[i], testHardCase[i]);
			}

		}


			// Unit test:
			// partiton test to see if can accept a number after a keyword "by"	
			TEST_METHOD(completeParseNlpByDate)
		{
			// TODO: Your test code hereOnly
	
			Parser test;
			vector<string> testCase;
			string randomList = "add arun 123 by 15";
			 
			testCase = test.completeParse(randomList);
			 
			vector<string> testHardCase;
			testHardCase.push_back("add");
			testHardCase.push_back("arun 123 by 15");
			testHardCase.push_back("");
			testHardCase.push_back("");
			testHardCase.push_back("");
			testHardCase.push_back("");

			for (int i =0; i < 6; i++) {
				Assert::AreEqual(testCase[i], testHardCase[i]);
			}

		}

			// Unit test:
			// partiton test to see if can accept a number after a keyword "from"	
			TEST_METHOD(completeParseNlpFromDate)
		{
			// TODO: Your test code hereOnly
	
			Parser test;
			vector<string> testCase;
			string randomList = "add arun haha from 150";
			 
			testCase = test.completeParse(randomList);
			 
			vector<string> testHardCase;
			testHardCase.push_back("add");
			testHardCase.push_back("arun haha from 150");
			testHardCase.push_back("");
			testHardCase.push_back("");
			testHardCase.push_back("");
			testHardCase.push_back("");

			for (int i =0; i < 6; i++) {
				Assert::AreEqual(testCase[i], testHardCase[i]);
			}

		}
			// Unit test:
			// Partiton test on keyword "from" and "to"
			TEST_METHOD(completeParseNlpFromNumberDate)
		{
			// TODO: Your test code here
	
			Parser test;
			vector<string> testCase;
			string randomList = "arun birthday to the cinema from 15/5/14 10.00";
			
			testCase = test.completeParse(randomList);
			 
			vector<string> testHardCase;
			testHardCase.push_back("add");
			testHardCase.push_back("arun birthday to the cinema ");
			testHardCase.push_back("20140515");
			testHardCase.push_back("1000");
			testHardCase.push_back("");
			testHardCase.push_back("");

			for (int i =0; i < 6; i++) {
				Assert::AreEqual(testCase[i], testHardCase[i]);
			}

		}
			// Unit test:
			// Partiton test on keyword "from" and "to" in word date format
			TEST_METHOD(completeParseNlpFromWordDate)
		{
			// TODO: Your test code here
	
			Parser test;
			vector<string> testCase;
			string randomList = "arun birthday to the cinema from 15 may 14 10.00";
			
			testCase = test.completeParse(randomList);
			 
			vector<string> testHardCase;
			testHardCase.push_back("add");
			testHardCase.push_back("arun birthday to the cinema ");
			testHardCase.push_back("20140515");
			testHardCase.push_back("1000");
			testHardCase.push_back("");
			testHardCase.push_back("");

			for (int i =0; i < 6; i++) {
				Assert::AreEqual(testCase[i], testHardCase[i]);
			}

		}
			// Unit test:
			// Partiton test on keyword "from" and "to" in word date format in caps
			
			TEST_METHOD(completeParseNlpFromWordDateInCaps)
		{
			// TODO: Your test code here
	
			Parser test;
			vector<string> testCase;
			string randomList = "arun birthday to the cinema from 15 DEC 14 10.00";
			
			testCase = test.completeParse(randomList);
			 
			vector<string> testHardCase;
			testHardCase.push_back("add");
			testHardCase.push_back("arun birthday to the cinema ");
			testHardCase.push_back("20141215");
			testHardCase.push_back("1000");
			testHardCase.push_back("");
			testHardCase.push_back("");

			for (int i =0; i < 6; i++) {
				Assert::AreEqual(testCase[i], testHardCase[i]);
			}

		}
			// Unit test: Partition test for keyword	
			TEST_METHOD(completeParseNlpOnNumberAfterKeyWord)
		{
			// TODO: Your test code here
	
			Parser test;
			vector<string> testCase;
			string randomList = "add arun birthday on 12th street on 15/5/14 10.00";
			
			testCase = test.completeParse(randomList);
			 
			vector<string> testHardCase;
			testHardCase.push_back("add");
			testHardCase.push_back("arun birthday on 12th street");
			testHardCase.push_back("20140515");
			testHardCase.push_back("1000");
			testHardCase.push_back("");
			testHardCase.push_back("");

			for (int i =0; i < 6; i++) {
				Assert::AreEqual(testCase[i], testHardCase[i]);
			}

		}
		
		// Unit test:
		// multiple user test case to see if "by" keyword works
		TEST_METHOD(completeParseByCase)
		{
			// TODO: Your test code here

			
			Parser test;
			vector<string> testCase;
			string randomList = "add complete homework by 12/12/14 10.00";
			
			testCase = test.completeParse(randomList);
			 
			vector<string> testHardCase;
			testHardCase.push_back("add");
			testHardCase.push_back("complete homework");
			testHardCase.push_back("20141212");
			testHardCase.push_back("1000");
			testHardCase.push_back("20141212");
			testHardCase.push_back("1000");

			for (int i =0; i < 6; i++) {
				Assert::AreEqual(testCase[i], testHardCase[i]);
			}

		}

//@author A0100705Y

		// Unit test: case on by using NLP
		TEST_METHOD(completeParseByCaseNlp)
		{
			// TODO: Your test code here
			
			
			Parser test;
			vector<string> testCase;
			string randomList = "add complete homework by 12 Dec 14 10.00";
			
			testCase = test.completeParse(randomList);
			 
			vector<string> testHardCase;
			testHardCase.push_back("add");
			testHardCase.push_back("complete homework");
			testHardCase.push_back("20141212");
			testHardCase.push_back("1000");
			testHardCase.push_back("20141212");
			testHardCase.push_back("1000");

			for (int i =0; i < 6; i++) {
				Assert::AreEqual(testCase[i], testHardCase[i]);
			}

		}

		// Unit test:
		// multiple user test case to see if "from....to..." keyword works
		TEST_METHOD(completeParseFromToCase)
		{
			// TODO: Your test code here

			
			Parser test;
			vector<string> testCase;
			string randomList = "add arun birthday from 10.00 to 12.00";
			
			testCase = test.completeParse(randomList);
			 
			vector<string> testHardCase;
			testHardCase.push_back("add");
			testHardCase.push_back("arun birthday");
			testHardCase.push_back("");
			testHardCase.push_back("1000");
			testHardCase.push_back("");
			testHardCase.push_back("1200");
			
			for (int i =0; i < 6; i++) {
				Assert::AreEqual(testCase[i], testHardCase[i]);
			}	

		

		}

		// Unit test:
		//user input: test to see if update works for start date
		TEST_METHOD(completeParseUpdateSd)
		{
			// TODO: Your test code here

			
			Parser test;
			vector<string> testCase;
			string randomList = "update 5 sd 2/1/14";
			
			testCase = test.completeParse(randomList);
			 
			vector<string> testHardCase;
			testHardCase.push_back("update");
			testHardCase.push_back("5");
			testHardCase.push_back("sd");
			testHardCase.push_back("20140102");
			
			
			for (int i =0; i < 4; i++) {
				Assert::AreEqual(testCase[i], testHardCase[i]);
			}	

		}

		// Unit test:
		// Partiton: user test case to see if update works with today keyword
		TEST_METHOD(completeParseUpdateEd)
		{
			// TODO: Your test code here

			
			Parser test;
			vector<string> testCase;
			string randomList = "update 15 ed today";
			
			testCase = test.completeParse(randomList);
			 
			vector<string> testHardCase;
			testHardCase.push_back("update");
			testHardCase.push_back("15");
			testHardCase.push_back("ed");
			testHardCase.push_back("today");
			
			
			for (int i =0; i < 4; i++) {
				Assert::AreEqual(testCase[i], testHardCase[i]);
			}	

		}

		
		// Unit test:
		// boudary case: useing date keywords for "today" and "tmo/tmr" for from and to
		// IT SHOULD NOT WORK!
		TEST_METHOD(completeParseNoDateKeywordFromTo)
		{
			// TODO: Your test code here

			
			Parser test;
			vector<string> testCase;
			string randomList = "add birthday from today to tmo";
			
			testCase = test.completeParse(randomList);
			 
			vector<string> testHardCase;
			testHardCase.push_back("add");
			testHardCase.push_back("birthday from today to tmo");
			testHardCase.push_back("");
			testHardCase.push_back("");
			testHardCase.push_back("");
			testHardCase.push_back("");
			
			for (int i =0; i < 6; i++) {
				Assert::AreEqual(testCase[i], testHardCase[i]);
			}	

		}

		// Unit test:
		// partion testing for key words
				TEST_METHOD(completeParseCheckAllKeywords)
		{
			// TODO: Your test code here
		
			Parser test;
			vector<string> testCase;
			string randomList = "birthday on sat by the beach from 19 april 14 10.00 to 12.00";
			
			testCase = test.completeParse(randomList);
			 
			vector<string> testHardCase;
			testHardCase.push_back("add");
			testHardCase.push_back("birthday on sat by the beach ");
			testHardCase.push_back("20140419");
			testHardCase.push_back("1000");
			testHardCase.push_back("");
			testHardCase.push_back("1200");
			
			for (int i =0; i < 6; i++) {
				Assert::AreEqual(testCase[i], testHardCase[i]);
			}	

		}

		// Unit test:
		// partion testing for dates by inputing a character
			TEST_METHOD(completeParseCheckCharactersInDate)
		{
			// TODO: Your test code here
		
			Parser test;
			vector<string> testCase;
			string randomList = "birthday on 1./1/14 10.00";
			
			testCase = test.completeParse(randomList);
			 
			vector<string> testHardCase;
			testHardCase.push_back("add");
			testHardCase.push_back("birthday");
			testHardCase.push_back("20140101");
			testHardCase.push_back("1000");
			testHardCase.push_back("");
			testHardCase.push_back("");
			
			for (int i =0; i < 6; i++) {
				Assert::AreEqual(testCase[i], testHardCase[i]);
			}	

		}

		// Unit test:
		// boundary cases of displaying negative index
			TEST_METHOD(completeParseDeleteNegInt)
		{
			// TODO: Your test code here
		
			Parser test;
			vector<string> testCase;
			string randomList = "delete -1";
			
			testCase = test.completeParse(randomList);
			 
			vector<string> testHardCase;
			testHardCase.push_back("delete");
			testHardCase.push_back("0");
			testHardCase.push_back("");
			testHardCase.push_back("");
			testHardCase.push_back("");
			testHardCase.push_back("");
			
			for (int i =0; i < 6; i++) {
				Assert::AreEqual(testCase[i], testHardCase[i]);
			}	

		}
			TEST_METHOD(completeParseDisplayNegInt)
		{
			// TODO: Your test code here
		
			Parser test;
			vector<string> testCase;
			string randomList = "display -1";
			
			testCase = test.completeParse(randomList);
			 
			vector<string> testHardCase;
			testHardCase.push_back("display");
			testHardCase.push_back("0");
			testHardCase.push_back("");
			testHardCase.push_back("");
			testHardCase.push_back("");
			testHardCase.push_back("");
			
			for (int i =0; i < 6; i++) {
				Assert::AreEqual(testCase[i], testHardCase[i]);
			}	

		}

			TEST_METHOD(completeParseEditNegInt)
		{
			// TODO: Your test code here
		
			Parser test;
			vector<string> testCase;
			string randomList = "edit -1 st 10.00";
			
			testCase = test.completeParse(randomList);
			 
			vector<string> testHardCase;
			testHardCase.push_back("edit");
			testHardCase.push_back("0");
			testHardCase.push_back("st");
			testHardCase.push_back("0");
			testHardCase.push_back("");
			testHardCase.push_back("");
			
			for (int i =0; i < 6; i++) {
				Assert::AreEqual(testCase[i], testHardCase[i]);
			}	

		}

























	};
}

