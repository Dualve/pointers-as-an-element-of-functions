#include "pch.h"
#include <iostream>
#include <Windows.h>
#include <ctype.h>

using namespace std;

//Functions 
bool check(char a[]) {
	for (int i = 0; i <= strlen(a) - 1; i++) {
		if (a[i] <= '0' || a[i] >= '9')
			return false;
	}
	return true;
}
//Functions end



int main(int argc, char* argv[])
{
	SetConsoleCP(1251);														//setting input to 1251
	SetConsoleOutputCP(1251);												//setting output to 1251
	int sum = 0;
	for (int i = 0; i < argc; i++) {
	//	cout << argv[i] << ' ' << check(argv[i]) << endl;
		if (check(argv[i])) {
			sum += atoi(argv[i]);
		}
	}
	cout << "Сумма: " << sum;
	return 0;
}