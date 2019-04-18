//#include <сmath>
#include <iostream>

using namespace std;

typedef double(*f)(double); // ф - указатель на функцию
double hord(f pf, double a, double b, double e);

double f1(double x) {
	return 3 * pow(x, 2) - 150 * sin(x);
}

double f2(double x) {
	return exp(x / 2) - pow(x, 3) + 50;
}

double f3(double x) {
	return pow(x, 3) - pow(x, 2) - 50;
}

double f4(double x) {
	return 3 * x - pow(x, 2);
}


int main()
{
	double a = 1.5;
	double b = 4.5;
	double e = 0.0001;
	f funcArray[4] = { f1, f2, f3, f4 }; // массив указателей на функции

	cout << "(x-1)^2/(x-1)-10=0 || x=";
	cout << hord(funcArray[0], a, b, e) << endl;
	cout << "10sin^2(x/10)-5=0 || x=";
	cout << hord(funcArray[1], a, b, e) << endl;
	cout << "x^3-130=0 || x=";
	cout << hord(funcArray[2], a, b, e) << endl;
	cout << "15x-105=0 || x=";
	cout << hord(funcArray[3], a, b, e) << endl;

	return 0;
}


double hord(f pf, double a_user, double b_user, double e_user)
{
	double x; // текущее приблежение
	double x_prev = 0; // предыдущее приблежение
	double a = a_user; // граница
	double b = b_user; // граница
	double e = abs(a - b); // задача точности
	if (pf(a) * pf(b) < 0) // проверка разных знаков на концах
	{
		while (e > e_user) // пока точность не станет меньше указанной 
		{
			x = a - pf(a) * (b - a) / (pf(b) - pf(a)); // приближение (расчет)
			if (pf(a) * pf(x) < 0) // если функция от а * функцию текущего приблежения
				b = x; // сдвиг границы
			else if (pf(x) * pf(b) < 0)
				a = x;
			e = abs(x - x_prev); // заново считаем точность (текущее и предыдщуее приблежение)
			x_prev = x; // предыдущий равен текущему
		}
	}
	return x;
}



