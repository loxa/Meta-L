#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

// An unsigned char can store 1 Bytes (8bits) of data (0-255)
typedef unsigned char BYTE;
void _NOACTION_(){};

const char *cPath = "C:\\Users\\loxa winbox\\Desktop\\Meta-L\\HelloWorldTest.exe";	
const char *cPathW = "C:\\Users\\loxa winbox\\Desktop\\Meta-L\\HelloWorldTest2.exe";

BYTE *bFileBuffer;			
FILE *fFile = NULL;	
FILE *fFileW = NULL;	

long fileSize;

//**********************************************************


BYTE* _remNOP_()
{
     //NULLs most NOPs (0x90->0x0)
     long lFileBufferSize = fileSize;
     for(int i=0;i<=lFileBufferSize+1;i++)
     {
        if((bFileBuffer[i]==0x90) && (bFileBuffer[i+1]==0x90))
            {bFileBuffer[i]=0x0; bFileBuffer[i+1]=0x0;}
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

void _fOpenRead()
{
    if ((fFile = fopen(cPath, "rb+")) == NULL){_NOACTION_();} else {_NOACTION_();}
}

void _fOpenWrite()
{
    if ((fFileW = fopen(cPathW, "wb+")) == NULL){_NOACTION_();} else {_NOACTION_();}
}

void _fWriteFile()
{
    _fOpenWrite();
    fwrite(bFileBuffer, 1, fileSize, fFileW);     
}


void _fPrint(BYTE *buffer, int count )
{
        for (int i = 0; i < count; i++)     
             cout << buffer[i];
}

int main()
{
	_fOpenRead();

	fileSize = _fFileSize(fFile);
	bFileBuffer = new BYTE[fileSize];
	fread(bFileBuffer, fileSize, 1, fFile);
	_remNOP_();
	_fWriteFile();
	//_fPrint(bFileBuffer,500);

	cin.get();
	delete[]bFileBuffer;
	
    fclose(fFile);   
    fclose(fFileW); 
    
	system("pause");
}
