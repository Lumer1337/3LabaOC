#include <iostream>
#include <conio.h>
#include <Windows.h>

using namespace std;
//n - строка m - столбец

void findMin(int** mass, int line, int col) {
	int min_lin = 0;
	int min_col = 0;
	for (int i = 0; i < line; i++) {
		for (int j = 0; j < col; j++) {
			if (mass[i][j] < mass[min_lin][min_col]) {
				min_lin = i;
				min_col = j;
			}
		}
	}
	cout << "Минимальный элемент: " << mass[min_lin][min_col] << endl;
	cout << "Расположение. Строка: " << min_lin + 1 << " Столбец: " << min_col + 1 << endl;
}

int main() {
    setlocale(LC_ALL, "rus");
    int n; int m;
    cout << "Введите количество строк массива: ";
	cin >> n; cout << endl;
	cout << "Введите количество столбцов массива: ";
	cin >> m; cout << endl;
    HANDLE heap = GetProcessHeap();
	if (heap != NULL)
	{
		int** numbers = (int**)HeapAlloc(heap, NULL, sizeof(int*) * n);
		cout << "Введите элементы массива: " << "\n";
		for (int i = 0; i < n; i++)
		{
			numbers[i] = (int*)HeapAlloc(heap, NULL, sizeof(int) * m);
			for (int j = 0; j < m; j++)
			{
				cin >> numbers[i][j];
			}
		}
		cout << endl;
		cout << "Массив, который вы ввели:" << endl;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				cout << numbers[i][j] << " ";
			}
			cout << endl;
		}
		findMin(numbers, n, m);
		for (int i = 0; i < n; i++)
		{
			HeapFree(heap, NULL, numbers[i]);
		}
		HeapFree(heap, NULL, numbers);
	}
	_getch();
	return 0;
}
