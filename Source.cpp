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

		cout << "�������� ��� ��������:\n0 - �����;\n1 - ����� ������������;\n2 - ����� �������������;\n3 - ����� ���� �����;\n4 - ������������ ���� �����.\n";
		cin >> ans;															//input answer		
		int arg1, arg2;														//variables for arguments
		cout << "������� ���������\n";
		cin >> arg1 >> arg2;												//input arguments
		cout << "���������: " << funcArr[ans - 1](arg1, arg2) << endl;		//call choosen function 
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

