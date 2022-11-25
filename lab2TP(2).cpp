#include <iostream>
#include <fstream>
using namespace std;

/*int Check_num(float n) {
	if (n == (int)n)
		return true;
	else
		return false;
}*/

int main(int argc, char* argv[]) {

	setlocale(LC_ALL, "Russian");

	cout << "Ввести с клавиатуры [1] \nВвести из файла [2] \nВыход [0]" << endl;
	int Menu;
	cin >> Menu;

	int b; //задаётся число, с которым сравниваем
	int n; //задаётся количество строк
	int m; //задаётся количество столбцов

	if (Menu == 1) {


		cout << "Введите число b: " << endl;
		cin >> b;

		cout << "Введите количество строк в матрице: " << endl;
		cin >> n;

		cout << "Введите количество столбцов в матрице: " << endl;
		cin >> m;


		int** arr = new int* [n]; // n строк в массиве
		for (int i = 0; i < n; i++)
			arr[i] = new int[m]; // m столбцов в массиве

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				arr[i][j] = 0;
			}
		}
		cout << endl;

		int l; // количество ненулевых элементов
		int v, x; // номера строки и столбца ненулевого элемента
		int z; // значение ненулевого элемента

		cout << "Введите количество ненулевых элементов: " << endl;
		cin >> l;


		for (int i = 0; i < l; i++) {
			cout << "Введите значение элемента: " << endl;
			cin >> z;
			cout << "Введите номер строки и номер столбца элемента: " << endl;
			cin >> v >> x;
			if (v > n - 1 || x > n - 1) {
				cout << "Неверный формат" << endl;
				return -1;
			}
			arr[v][x] = z;
		}
		int* Value1 = new int[l];
		int* Num_rows1 = new int[n];
		int* arrNon = new int[l]; // создание массива под ненулевые элементы
		int* Loc_first = new int[n + 1];
		Loc_first[0] = 1;
		int p = 0; // счётчик индекса в массиве ненулевых элементов
		int y = 0; // счётчик индекса в отсортированном массиве
		int c = 0;
		int o = 0;

		for (int i = 0; i < n; i++) { //заполнение массива столбцов ?!??!?!?!
			int count = 0;
			for (int j = 0; j < m; j++) {
				int zxc = arr[j][i];
				if (zxc != 0) {
					count += 1;
				}
				if (j == m - 1) {
					Loc_first[i + 1] = Loc_first[i] + count;
				}
			}
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				int qwe = arr[j][i];
				if (qwe != 0) {
					Value1[c] = qwe;
					Num_rows1[c] = j;
					c++;
					arrNon[o] = qwe;
					o++;
				}
			}
		}
		/*for (int i = 0; i < n; i++) { // заполнение массива ненулевыми числами
			for (int j = 0; j < m; j++) {
				int k = arr[i][j];
				if (k != 0) {
					arrNon[p] = k;
					p++;
				}
			}
		}*/

		for (int i = 0; i < n; i++) { // вывод матрицы на экран
			cout << endl;
			for (int j = 0; j < m; j++) {
				cout << arr[i][j] << " ";
			}
		}
		cout << endl << endl;

		cout << "Число b: " << b << endl;
		cout << "Массив значений: " << endl;
		for (int i = 0; i < l; i++) {
			cout << "[" << Value1[i] << "] ";
		}
		cout << endl;
		cout << "Массив номеров строк: " << endl;
		for (int i = 0; i < l; i++) {
			cout << "[" << Num_rows1[i] << "] ";
		}
		cout << endl;
		cout << "Массив местоположений первых элементов каждого столбца" << endl;
		for (int i = 0; i < n + 1; i++) {
			cout << "[" << Loc_first[i] << "]";
		}
		cout << endl << endl;
		/*for (int i = 0; i < l; i++) { // вывод массива на экран
			cout << arrNon[i] << " ";
		}
		cout << endl;*/
		cout << "Изменённая матрица: " << endl;

		for (int i = 0; i < n - 1; i++) { // сортировка массива относительно числа b
			for (int j = 0; j < n - i - 1; j++) {
				if (arrNon[j] < b && arrNon[j + 1] > b) {

					arrNon[j] = arrNon[j] + arrNon[j + 1];
					arrNon[j + 1] = arrNon[j] - arrNon[j + 1];
					arrNon[j] = arrNon[j] - arrNon[j + 1];
				}
			}
		}
		int k = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {

				if (arr[j][i] != 0) {
					arr[j][i] = arrNon[k];
					k++;
				}

			}
		}
		cout << "Число b: " << b << endl;
		for (int i = 0; i < n; i++) { // вывод матрицы на экран
			cout << endl;
			for (int j = 0; j < m; j++) {
				cout << arr[i][j] << " ";
			}
		}
		cout << endl << endl;

		for (int i = 0; i < n; i++)
			delete[]arr[i];
		delete[] arrNon;
		delete[] Loc_first;
		delete[] Value1;
		delete[] Num_rows1;
	}
	else if (Menu == 2) {

		if (argc < 1) {

			cout << "Недостаточно файлов!!!" << endl;
			system("pause");
			return -1;
		}

		ifstream File(argv[1]);
		File >> b;
		File >> n;

		int** arr = new int* [n]; // n строк в массиве
		for (int i = 0; i < n; i++)
			arr[i] = new int[n]; // m столбцов в массиве

		int* Loc_first = new int[n + 1];
		Loc_first[0] = 1;
		int p = 0; // счётчик индекса в массиве ненулевых элементов
		int y = 0; // счётчик индекса в отсортированном массиве
		int c = 0;
		int o = 0;
		int l = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				File >> arr[i][j];
			}

		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				int aaa = arr[j][i];
				if (aaa != 0) {
					l++;
				}
			}
		}
		int* Value1 = new int[l];
		int* arrNon = new int[l];
		int* Num_rows1 = new int[l];
		for (int i = 0; i < n; i++) { //заполнение массива столбцов ?!??!?!?!
			int count = 0;
			for (int j = 0; j < n; j++) {
				int zxc = arr[j][i];
				if (zxc != 0) {
					count += 1;
				}
				if (j == n - 1) {
					Loc_first[i + 1] = Loc_first[i] + count;
				}
			}
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				int qwe = arr[j][i];
				if (qwe != 0) {
					Value1[c] = qwe;
					Num_rows1[c] = j;
					c++;
					arrNon[o] = qwe;
					o++;
				}
			}
		}
		/*for (int i = 0; i < n; i++) { // заполнение массива ненулевыми числами
			for (int j = 0; j < m; j++) {
				int k = arr[i][j];
				if (k != 0) {
					arrNon[p] = k;
					p++;
				}
			}
		}*/

		/*for (int i = 0; i < n; i++) { // вывод матрицы на экран
			cout << endl;
			for (int j = 0; j < n; j++) {
				cout << arr[i][j] << " ";
			}
		}*/
		for (int i = 0; i < n; i++) { // вывод матрицы на экран
			cout << endl;
			for (int j = 0; j < n; j++) {
				cout << arr[i][j] << " ";
			}
		}
		cout << endl << endl;

		cout << "Число b: " << b << endl;
		cout << "Массив значений: " << endl;
		for (int i = 0; i < l; i++) {
			cout << "[" << Value1[i] << "] ";
		}
		cout << endl;
		cout << "Массив номеров строк: " << endl;
		for (int i = 0; i < l; i++) {
			cout << "[" << Num_rows1[i] << "] ";
		}
		cout << endl;
		cout << "Массив местоположений первых элементов каждого столбца" << endl;
		for (int i = 0; i < n + 1; i++) {
			cout << "[" << Loc_first[i] << "]";
		}
		cout << endl << endl;
		/*for (int i = 0; i < l; i++) { // вывод массива на экран
			cout << arrNon[i] << " ";
		}
		cout << endl;*/
		cout << "Изменённая матрица: " << endl;

		for (int i = 0; i < n - 1; i++) { // сортировка массива относительно числа b
			for (int j = 0; j < n - i - 1; j++) {
				if (arrNon[j] < b && arrNon[j + 1] > b) {

					arrNon[j] = arrNon[j] + arrNon[j + 1];
					arrNon[j + 1] = arrNon[j] - arrNon[j + 1];
					arrNon[j] = arrNon[j] - arrNon[j + 1];
				}
			}
		}
		cout << "Число b: " << b << endl;

		int bh = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {

				if (arr[j][i] != 0) {
					arr[j][i] = arrNon[bh];
					bh++;
				}

			}
		}
		for (int i = 0; i < n; i++) { // вывод матрицы на экран
			cout << endl;
			for (int j = 0; j < n; j++) {
				cout << arr[i][j] << " ";
			}
		}
		cout << endl << endl;
		for (int i = 0; i < n; i++)
			delete[]arr[i];
		delete[] arrNon;
		delete[] Loc_first;
		delete[] Value1;
		delete[] Num_rows1;
	}
	else if (Menu == 0) {

		return -1;

	}

	else {

		cout << "Такого номера не существует" << endl;
		return -1;

	}



}