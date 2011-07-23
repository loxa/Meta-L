#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

// An unsigned char can store 1 Bytes (8bits) of data (0-255)
typedef unsigned char BYTE;

long getFileSize(FILE *file)
{
	long lCurPos, lEndPos;
	lCurPos = ftell(file);
	fseek(file, 0, 2);
	lEndPos = ftell(file);
	fseek(file, lCurPos, 0);
	return lEndPos;
}

void _print(BYTE *buffer, long fileSize )
     {
        for (int i = 0; i < fileSize; i++)     
             cout << buffer[i];
     }

int main()
{
	const char *filePath = "C:\\Dev-Cpp\\HelloWorldTest.exe";	
	BYTE *fileBuf;			
	FILE *file = NULL;		

	if ((file = fopen(filePath, "rb+")) == NULL)`
		cout << "Could not open specified file" << endl;
	else
		cout << "File opened successfully" << endl;

	long fileSize = getFileSize(file);
	fileBuf = new BYTE[fileSize];
	fread(fileBuf, fileSize, 1, file);

             
	cin.get();
	delete[]fileBuf;
    fclose(file);   
	system("pause");
}
