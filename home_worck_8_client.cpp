#include <iostream>
#include <windows.h>
#include <fstream>
#include <string>

using namespace std;

int main() {
	
	HANDLE eventClient = CreateEventA(0, FALSE, FALSE, "eventClient");
	HANDLE eventServer = CreateEventA(0, FALSE, FALSE, "eventServer");
	
	//������ �������
	SetEvent(eventClient);
	
	//���� ������ �� �������
	DWORD value_1 = WaitForSingleObject(eventServer, INFINITE);
	
	//������ ������ � �����
	ifstream fin;
	fin.open("data.txt");
	
	string str;
	getline(fin, str);
	
	//����� ������
	cout << str << endl;
	
	fin.close();
	
	cout << "EXIT ThreadClient" << endl;

	return 0;
}
