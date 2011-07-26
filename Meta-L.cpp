#include "Functions.h"
#include "Parser.h"

int main()
{
    //Objects
    Functions Functions;
    Parser Parser;
    
    
    //Temporary
    //cPath = ".\\HelloWorldTest.exe";
    //cPathW = ".\\HelloWorldTest2.exe";
        
    
   	Functions._fOpenRead();
	fileSize = Functions._fFileSize(fFile);
	bFileBuffer = new BYTE[fileSize];
	fread(bFileBuffer, fileSize, 1, fFile);
	Functions._remNOP_();
	Functions._fWriteFile();
	//_fPrint(bFileBuffer,500);

	cin.get();
	delete[]bFileBuffer;
	
    fclose(fFile);   
    fclose(fFileW); 
    
    
	system("pause");

}
