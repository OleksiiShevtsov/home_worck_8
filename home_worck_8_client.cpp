#include <iostream>
#include <windows.h>
#include <fstream>
#include <string>

using namespace std;
/* CLIENT */

int main() {
	
	HANDLE eventClient = CreateEventA(0, FALSE, FALSE, "eventClient");
	HANDLE eventServer = CreateEventA(0, FALSE, FALSE, "eventServer");
	
	//запрос клиента
	SetEvent(eventClient);
	
	//передача данных от сервера 
	DWORD value_1 = WaitForSingleObject(eventServer, INFINITE);
	
	//открытие файла с данными
	ifstream fin;
	fin.open("data.txt");
	
	string str;
	getline(fin, str);
	
	//вывод данных с файла
	cout << str << endl;
	
	fin.close();
	
	cout << "EXIT ThreadClient" << endl;

	return 0;
}
