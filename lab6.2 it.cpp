#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;

void Create(int* p, const int size, const int Low, const int High)
{
	for (int i = 0; i < size; i++)
		p[i] = Low + rand() % (High - Low + 1);
}
void Print(int* p, const int size)
{
	for (int i = 0; i < size; i++)
		cout << setw(4) << p[i];
	cout << endl;

}
int Max(int* a, const int size)
{
	int max = a[0];
	for (int i = 1; i < size; i++)
		if ( a[i] > max)
			max = a[i];
	return max;
}
int Min(int* a, const int size)
{
	int min = a[0];
	for (int i = 1; i < size; i++)
		if (a[i] < min)
			min = a[i];
	return min;
}
int Sum(int* a, const int size)
{
	return Max(a, size) + Min(a, size);
}
void Replace(int* p, const int size)
{
    int maxi = 0;
	int mini = 0;
	for (int i = 1; i < size; i++)
	{
		if (p[i] > p[maxi])
			maxi = i;
		if (p[i] < p[mini])
			mini = i;
	}
	p[maxi] = 0;
	p[mini] = 0;
}
int main()
{
	srand((unsigned)time(NULL)); // ініціалізація генератора випадкових чисел
	const int n = 20;
	int p[n];

	int Low = 1;
	int High = 100;

	Create(p, n, Low, High);
	Print(p, n);

	cout << "Max = " << Max(p, n) << endl;
	cout << "Min = " << Min(p, n) << endl;
	cout << "S = " << Sum(p, n) << endl;
	Replace(p, n);
	cout << "Modified mass = " << endl;
	Print(p, n);
	return 0;
}
