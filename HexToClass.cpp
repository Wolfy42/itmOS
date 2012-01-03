// basic file operations
#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;

int main(int argc, char *argv[]) {

	char* task = argv[1];

	char fileName[sizeof(task)+31];
	strcpy( fileName, "BOSS/Loader/TasksHex/");
	strcat( fileName, task );
	strcat( fileName, "Bytes.cpp" );

	ifstream i0("BOSS-Task/Debug/BOSS-Task.i0");
	ifstream i1("BOSS-Task/Debug/BOSS-Task.i1");
	ifstream i2("BOSS-Task/Debug/BOSS-Task.i2");
	ifstream i3("BOSS-Task/Debug/BOSS-Task.i3");

	ofstream classFile;
	classFile.open (fileName, ios::trunc);
	classFile << endl << "#include \"" << task << "Bytes.h\"" << endl << endl;
	classFile << task << "Bytes::" << task << "Bytes() {}" << endl << endl;
	classFile << "CodeBytes* " << task << "Bytes::getCodeBytes()  {" << endl << endl;
	classFile << "\tCodeBytes* cb = new CodeBytes();" << endl << endl;

	string line;
	if (i0.is_open())  {
		classFile << "\tcb->byte0 = \"";
	    while (i0.good())  {
	      getline (i0, line);
	      classFile << line;
	    }
	    classFile << "\";" << endl;
	}
	if (i1.is_open())  {
		classFile << "\tcb->byte1 = \"";
	    while (i1.good())  {
	      getline (i1, line);
	      classFile << line;
	    }
	    classFile << "\";" << endl;
	}
	if (i2.is_open())  {
		classFile << "\tcb->byte2 = \"";
	    while (i2.good())  {
	      getline (i2, line);
	      classFile << line;
	    }
	    classFile << "\";" << endl;
	}
	if (i3.is_open())  {
		classFile << "\tcb->byte3 = \"";
	    while (i3.good())  {
	      getline (i3, line);
	      classFile << line;
	    }
	    classFile << "\";" << endl;
	}

    i0.close();
    i1.close();
    i2.close();
    i3.close();

	classFile << endl << "\treturn cb;" << endl << "}" << endl << endl;

	classFile.close();
	return 0;
}
