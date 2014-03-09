bool::FileHandler fileReady(string fileName)
{
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
			cout << OUTPUTMSG_WELCOME + fileName + OUTPUTMSG_READY_FOR_USE;
			return ready;
		}
	}
		
	else{
	
		ofstream create(fileName);
		cout << OUTPUTMSG_WELCOME + fileName + OUTPUTMSG_READY_FOR_USE;
		return ready;
	}
}

bool FileHandler::diskcopy(string fileName)  //to copy changes made to the .txt file are copied onto the harddisk
{
	ofstream ofile(fileName);
	int size = sentencesVector.size();
	if (ofile.is_open()){
		
		for (int i=0; i<size; i++)
		{
			ofile << sentencesVector[i] + "\n";
		}
			
		ofile.close();
	}
}