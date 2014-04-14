//@author A0099326U
#include "stdafx.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace systemTest {		
	TEST_CLASS(Easydone)
	{
	public:

		// system test
		// Partition test
		TEST_METHOD(systemTest1)
		{
			
			Manager test;
			Parser trial;
			Worker work;
			vector<Task> allTask;
			string sendToParser = "add gorilla's birthday on 12/12/14 10.00";

			vector<string> getfromParser = trial.completeParse(sendToParser);
			string getfromWorker = work.takeparsedCommand(getfromParser);

			string compare = "\"gorilla's birthday\"\r\nhas been added successfully! :) \r\n";

			/*test.receiveInput("add arun birthday on 12/12/14 10:00");
			allTask.clear();
			allTask = test.getAllTaskList();
			
			testTask.taskName = "arun birthday ";
			testTask.startDate = "12 Dec";
			testTask.startTime = "10:00";
			testTaskList.push_back(testTask);*/

			Assert::AreEqual(getfromWorker, compare);

			/*Assert::AreEqual((int)allTask.size(), (int) 1);
			Assert::AreEqual(allTask[0].taskName, testTaskList[0].taskName);*/
			//Assert::AreSame

			

		}

		// system test
		// boundary test: startDate
		TEST_METHOD(systemTestBoundaryDateCase)
		{
			
			Manager test;
			Parser trial;
			Worker work;
			vector<Task> allTask;
			string sendToParser = "add gorilla's birthday on 32/12/14 10.00";

			vector<string> getfromParser = trial.completeParse(sendToParser);
			string getfromWorker = work.takeparsedCommand(getfromParser);

			string compare = "\"gorilla's birthday\"\r\nInvalid date! Is it a 30th or 31st?? Ensure time format is correct too! =) \r\nTask has not been added successfully! ): ";

			/*test.receiveInput("add arun birthday on 12/12/14 10:00");
			allTask.clear();
			allTask = test.getAllTaskList();
			
			testTask.taskName = "arun birthday ";
			testTask.startDate = "12 Dec";
			testTask.startTime = "10:00";
			testTaskList.push_back(testTask);*/

			Assert::AreEqual(getfromWorker, compare);

			/*Assert::AreEqual((int)allTask.size(), (int) 1);
			Assert::AreEqual(allTask[0].taskName, testTaskList[0].taskName);*/
			//Assert::AreSame

			

		}

		// system test
		// boundary test: startDate for leap year
		TEST_METHOD(systemTestBoundaryDateCase2)
		{
			
			Manager test;
			Parser trial;
			Worker work;
			vector<Task> allTask;
			string sendToParser = "add gorilla's birthday on 29/2/16 10.00";

			vector<string> getfromParser = trial.completeParse(sendToParser);
			string getfromWorker = work.takeparsedCommand(getfromParser);

			string compare = "\"gorilla's birthday\"\r\nhas been added successfully! :) \r\n";

			/*test.receiveInput("add arun birthday on 12/12/14 10:00");
			allTask.clear();
			allTask = test.getAllTaskList();
			
			testTask.taskName = "arun birthday ";
			testTask.startDate = "12 Dec";
			testTask.startTime = "10:00";
			testTaskList.push_back(testTask);*/

			Assert::AreEqual(getfromWorker, compare);

			/*Assert::AreEqual((int)allTask.size(), (int) 1);
			Assert::AreEqual(allTask[0].taskName, testTaskList[0].taskName);*/
			//Assert::AreSame

			

		}

		// system test
		// boundary test: endtime & by
		TEST_METHOD(systemTestBoundaryDateCase3)
		{
			
			Manager test;
			Parser trial;
			Worker work;
			vector<Task> allTask;
			string sendToParser = "add gorilla's birthday by 28/2/15 00.00";

			vector<string> getfromParser = trial.completeParse(sendToParser);
			string getfromWorker = work.takeparsedCommand(getfromParser);

			string compare = "\"gorilla's birthday\"\r\nhas been added successfully! :) \r\n";

			/*test.receiveInput("add arun birthday on 12/12/14 10:00");
			allTask.clear();
			allTask = test.getAllTaskList();
			
			testTask.taskName = "arun birthday ";
			testTask.startDate = "12 Dec";
			testTask.startTime = "10:00";
			testTaskList.push_back(testTask);*/

			Assert::AreEqual(getfromWorker, compare);

			/*Assert::AreEqual((int)allTask.size(), (int) 1);
			Assert::AreEqual(allTask[0].taskName, testTaskList[0].taskName);*/
			//Assert::AreSame

			

		}

		// system test
		// boundary test: starttime 23.59
		TEST_METHOD(systemTestBoundaryDateCase4)
		{
			
			Manager test;
			Parser trial;
			Worker work;
			vector<Task> allTask;
			string sendToParser = "add gorilla's birthday on 28 apr 14 23.59";

			vector<string> getfromParser = trial.completeParse(sendToParser);
			string getfromWorker = work.takeparsedCommand(getfromParser);

			string compare = "\"gorilla's birthday\"\r\nhas been added successfully! :) \r\n";

			/*test.receiveInput("add arun birthday on 12/12/14 10:00");
			allTask.clear();
			allTask = test.getAllTaskList();
			
			testTask.taskName = "arun birthday ";
			testTask.startDate = "12 Dec";
			testTask.startTime = "10:00";
			testTaskList.push_back(testTask);*/

			Assert::AreEqual(getfromWorker, compare);

			/*Assert::AreEqual((int)allTask.size(), (int) 1);
			Assert::AreEqual(allTask[0].taskName, testTaskList[0].taskName);*/
			//Assert::AreSame

			

		}

		// system test
		// boundary test: from time boundary
		TEST_METHOD(systemTestBoundaryDateCase5)
		{
			
			Manager test;
			Parser trial;
			Worker work;
			vector<Task> allTask;
			string sendToParser = "add gorilla's birthday on the beach from 30 apr 14 00.01";

			vector<string> getfromParser = trial.completeParse(sendToParser);
			string getfromWorker = work.takeparsedCommand(getfromParser);

			string compare = "\"gorilla's birthday on the beach \"\r\nhas been added successfully! :) \r\n";

			/*test.receiveInput("add arun birthday on 12/12/14 10:00");
			allTask.clear();
			allTask = test.getAllTaskList();
			
			testTask.taskName = "arun birthday ";
			testTask.startDate = "12 Dec";
			testTask.startTime = "10:00";
			testTaskList.push_back(testTask);*/

			Assert::AreEqual(getfromWorker, compare);

			/*Assert::AreEqual((int)allTask.size(), (int) 1);
			Assert::AreEqual(allTask[0].taskName, testTaskList[0].taskName);*/
			//Assert::AreSame

			

		}
		// system test
		// boundary test: from time... to boundary for date
		TEST_METHOD(systemTestBoundaryDateCase6)
		{
			
			Manager test;
			Parser trial;
			Worker work;
			vector<Task> allTask;
			string sendToParser = "add gorilla's birthday by the beach from 30 apr 14 00.01 to 30 apr 14 12.00";

			vector<string> getfromParser = trial.completeParse(sendToParser);
			string getfromWorker = work.takeparsedCommand(getfromParser);

			string compare = "\"gorilla's birthday by the beach \"\r\nhas been added successfully! :) \r\n";

			/*test.receiveInput("add arun birthday on 12/12/14 10:00");
			allTask.clear();
			allTask = test.getAllTaskList();
			
			testTask.taskName = "arun birthday ";
			testTask.startDate = "12 Dec";
			testTask.startTime = "10:00";
			testTaskList.push_back(testTask);*/

			Assert::AreEqual(getfromWorker, compare);

			/*Assert::AreEqual((int)allTask.size(), (int) 1);
			Assert::AreEqual(allTask[0].taskName, testTaskList[0].taskName);*/
			//Assert::AreSame

			

		}

	};


}