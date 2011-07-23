#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

// An unsigned char can store 1 Bytes (8bits) of data (0-255)
typedef unsigned char BYTE;
void _NOACTION_(){};

const char *cPath = "C:\\Users\\loxa winbox\\Desktop\\Meta-L\\HelloWorldTest.exe";	
BYTE *bFileBuffer;			
FILE *fFile = NULL;	
long fileSize;

//**********************************************************



BYTE* _remNOP_()
{
     //NULLs all NOPs (0x90->0x0)
     long lFileBufferSize = fileSize;
     for(int i=0;i<=lFileBufferSize;i++)
     {
        if(bFileBuffer[i]==0x90)
            bFileBuffer[i]=0x0;
     }
}


long _fFileSize(FILE *file)
{     
	long lCurPos, lEndPos;
	lCurPos = ftell(file);
	fseek(file, 0, 2);
	lEndPos = ftell(file);
	fseek(file, lCurPos, 0);
	return lEndPos;
}

void _fOpen()
{
    if ((fFile = fopen(cPath, "rb+")) == NULL){_NOACTION_();} else {_NOACTION_();}
}

void _fPrint(BYTE *buffer, int count )
{
        for (int i = 0; i < count; i++)     
             cout << buffer[i];
}

int main()
{
	_fOpen();

	fileSize = _fFileSize(fFile);
	bFileBuffer = new BYTE[fileSize];
	fread(bFileBuffer, fileSize, 1, fFile);
	_remNOP_();
	//_fPrint(bFileBuffer,500);

             
	cin.get();
	delete[]bFileBuffer;
    fclose(fFile);   
	system("pause");
}
