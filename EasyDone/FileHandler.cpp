#include "FileHandler.h"

const string FileHandler::MESSAGE_OUTPUT_WELCOME = "WELCOME TO easyDone.txt!";
const string FileHandler::MESSAGE_READY_FOR_USE = "Ready for use";

FileHandler TB_Object;

void FileHandler::load(string inputString) {

	sentencesVector.push_back(inputString);

}

void FileHandler::remove() {
	sentencesVector.erase(sentencesVector.begin() + sentencesVector.size() -1);
}


bool FileHandler::fileReady(string fileName) {
	
	bool ready = 1;
	ifstream inputFile(fileName);

	if (inputFile){
		
		if (inputFile.is_open()){
			
			while (inputFile.good())
			{
				getline(inputFile, line);
				TB_Object.load(line);
			}

			TB_Object.remove();			
			cout << MESSAGE_OUTPUT_WELCOME + fileName + MESSAGE_READY_FOR_USE;
			return ready;
		}
	}
		
	else{
	
		ofstream create(fileName);
		cout <<  MESSAGE_OUTPUT_WELCOME + fileName + MESSAGE_READY_FOR_USE;
		return ready;
		
	}
	

	return 1;
}

bool FileHandler::diskcopy(string fileName)  //to copy changes made to the .txt file are copied onto the harddisk
{
	
	ofstream ofile(fileName);
	int size = sentencesVector.size();
	if (ofile.is_open()){
		
		for (int i=0; i<size; i++)
		{
			ofile << sentencesVector[i] << endl;//+ "\n";
		}
			
		ofile.close();
	}
	
	return 1;
}