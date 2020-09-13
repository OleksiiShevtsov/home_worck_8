#include <iostream>
#include <windows.h>
#include <string>

using namespace std;
/*	CLIENT -> SERVER: */

int main() {
	
	HANDLE eventClient = CreateEventA(0, FALSE, FALSE, "eventClient");
	HANDLE eventServer = CreateEventA(0, FALSE, FALSE, "eventServer");
	
	//���� ������� �� �������
	WaitForSingleObject(eventClient, INFINITE);

	//������ ������ � ����
	char DataBuffer[] = "text_data";
	DWORD dwBytesToWrite = (DWORD)strlen(DataBuffer);
	DWORD dwBytesWritten = 0;
	BOOL bErrorFlag = FALSE;
	
	HANDLE hFileData = CreateFileA("E:\\programming\\C++\\System programming\\Junior\\8)������. �����\\home_worck_8\\data.txt",
		GENERIC_WRITE | GENERIC_READ,
		0,
		NULL,
		OPEN_ALWAYS,
		FILE_ATTRIBUTE_NORMAL,
		NULL);
	
	WriteFile(
		hFileData,
		DataBuffer,
		dwBytesToWrite,
		&dwBytesWritten,
		NULL);
		
	CloseHandle(hFileData);
	
	//�������� �������
	SetEvent(eventServer);
	
	cout << "EXIT ThreadServer" << endl;

	return 0;
}
