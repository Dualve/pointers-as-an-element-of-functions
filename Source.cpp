#include <iostream>
#include <Windows.h>

using namespace std;

int fMin(int a, int b);
int fMax(int a, int b);
int fSum(int a, int b);
int fMult(int a, int b);

int(*funcArr[])(int, int) = { fMin, fMax, fSum, fMult };



int main()
{
	SetConsoleCP(1251);														
	SetConsoleOutputCP(1251);												
	unsigned short int ans = -1;											//variable for user's answer
	while (ans != 0)
	{

		cout << "Выберите тип операции:\n0 - Выход;\n1 - Поиск минимального;\n2 - Поиск максимального;\n3 - Сумма двух чисел;\n4 - Произведение двух чисел.\n";
		cin >> ans;															//input answer		
		int arg1, arg2;														//variables for arguments
		cout << "Введите аргументы\n";
		cin >> arg1 >> arg2;												//input arguments
		cout << "Результат: " << funcArr[ans - 1](arg1, arg2) << endl;		//call choosen function 
		system("pause");													//console pause
		system("cls");														//console clearing screen
	}
}


int fMin(int a, int b) {
	if (a > b) return b;
	else return a;
}

int fMax(int a, int b) {
	if (a > b) return a;
	else return b;
}

int fSum(int a, int b) {
	return a + b;
}

int fMult(int a, int b) {
	return a * b;
}

