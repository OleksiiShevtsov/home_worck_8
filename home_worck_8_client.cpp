#include <iostream>
#include <windows.h>
#include <fstream>
#include <string>

using namespace std;

int main() {
	
	HANDLE eventClient = CreateEventA(0, FALSE, FALSE, "eventClient");
	HANDLE eventServer = CreateEventA(0, FALSE, FALSE, "eventServer");
	
	//запрос клиента
	SetEvent(eventClient);
	
	//ждем данных от сервера
	DWORD value_1 = WaitForSingleObject(eventServer, INFINITE);
	
	//чтение данных с файла
	ifstream fin;
	fin.open("data.txt");
	
	string str;
	getline(fin, str);
	
	//вывод данных
	cout << str << endl;
	
	fin.close();
	
	cout << "EXIT ThreadClient" << endl;

	return 0;
}
