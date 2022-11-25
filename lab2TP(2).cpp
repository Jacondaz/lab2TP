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

	cout << "������ � ���������� [1] \n������ �� ����� [2] \n����� [0]" << endl;
	int Menu;
	cin >> Menu;

	int b; //������� �����, � ������� ����������
	int n; //������� ���������� �����
	int m; //������� ���������� ��������

	if (Menu == 1) {


		cout << "������� ����� b: " << endl;
		cin >> b;

		cout << "������� ���������� ����� � �������: " << endl;
		cin >> n;

		cout << "������� ���������� �������� � �������: " << endl;
		cin >> m;


		int** arr = new int* [n]; // n ����� � �������
		for (int i = 0; i < n; i++)
			arr[i] = new int[m]; // m �������� � �������

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				arr[i][j] = 0;
			}
		}
		cout << endl;

		int l; // ���������� ��������� ���������
		int v, x; // ������ ������ � ������� ���������� ��������
		int z; // �������� ���������� ��������

		cout << "������� ���������� ��������� ���������: " << endl;
		cin >> l;


		for (int i = 0; i < l; i++) {
			cout << "������� �������� ��������: " << endl;
			cin >> z;
			cout << "������� ����� ������ � ����� ������� ��������: " << endl;
			cin >> v >> x;
			if (v > n - 1 || x > n - 1) {
				cout << "�������� ������" << endl;
				return -1;
			}
			arr[v][x] = z;
		}
		int* Value1 = new int[l];
		int* Num_rows1 = new int[n];
		int* arrNon = new int[l]; // �������� ������� ��� ��������� ��������
		int* Loc_first = new int[n + 1];
		Loc_first[0] = 1;
		int p = 0; // ������� ������� � ������� ��������� ���������
		int y = 0; // ������� ������� � ��������������� �������
		int c = 0;
		int o = 0;

		for (int i = 0; i < n; i++) { //���������� ������� �������� ?!??!?!?!
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
		/*for (int i = 0; i < n; i++) { // ���������� ������� ���������� �������
			for (int j = 0; j < m; j++) {
				int k = arr[i][j];
				if (k != 0) {
					arrNon[p] = k;
					p++;
				}
			}
		}*/

		for (int i = 0; i < n; i++) { // ����� ������� �� �����
			cout << endl;
			for (int j = 0; j < m; j++) {
				cout << arr[i][j] << " ";
			}
		}
		cout << endl << endl;

		cout << "����� b: " << b << endl;
		cout << "������ ��������: " << endl;
		for (int i = 0; i < l; i++) {
			cout << "[" << Value1[i] << "] ";
		}
		cout << endl;
		cout << "������ ������� �����: " << endl;
		for (int i = 0; i < l; i++) {
			cout << "[" << Num_rows1[i] << "] ";
		}
		cout << endl;
		cout << "������ �������������� ������ ��������� ������� �������" << endl;
		for (int i = 0; i < n + 1; i++) {
			cout << "[" << Loc_first[i] << "]";
		}
		cout << endl << endl;
		/*for (int i = 0; i < l; i++) { // ����� ������� �� �����
			cout << arrNon[i] << " ";
		}
		cout << endl;*/
		cout << "��������� �������: " << endl;

		for (int i = 0; i < n - 1; i++) { // ���������� ������� ������������ ����� b
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
		cout << "����� b: " << b << endl;
		for (int i = 0; i < n; i++) { // ����� ������� �� �����
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

			cout << "������������ ������!!!" << endl;
			system("pause");
			return -1;
		}

		ifstream File(argv[1]);
		File >> b;
		File >> n;

		int** arr = new int* [n]; // n ����� � �������
		for (int i = 0; i < n; i++)
			arr[i] = new int[n]; // m �������� � �������

		int* Loc_first = new int[n + 1];
		Loc_first[0] = 1;
		int p = 0; // ������� ������� � ������� ��������� ���������
		int y = 0; // ������� ������� � ��������������� �������
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
		for (int i = 0; i < n; i++) { //���������� ������� �������� ?!??!?!?!
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
		/*for (int i = 0; i < n; i++) { // ���������� ������� ���������� �������
			for (int j = 0; j < m; j++) {
				int k = arr[i][j];
				if (k != 0) {
					arrNon[p] = k;
					p++;
				}
			}
		}*/

		/*for (int i = 0; i < n; i++) { // ����� ������� �� �����
			cout << endl;
			for (int j = 0; j < n; j++) {
				cout << arr[i][j] << " ";
			}
		}*/
		for (int i = 0; i < n; i++) { // ����� ������� �� �����
			cout << endl;
			for (int j = 0; j < n; j++) {
				cout << arr[i][j] << " ";
			}
		}
		cout << endl << endl;

		cout << "����� b: " << b << endl;
		cout << "������ ��������: " << endl;
		for (int i = 0; i < l; i++) {
			cout << "[" << Value1[i] << "] ";
		}
		cout << endl;
		cout << "������ ������� �����: " << endl;
		for (int i = 0; i < l; i++) {
			cout << "[" << Num_rows1[i] << "] ";
		}
		cout << endl;
		cout << "������ �������������� ������ ��������� ������� �������" << endl;
		for (int i = 0; i < n + 1; i++) {
			cout << "[" << Loc_first[i] << "]";
		}
		cout << endl << endl;
		/*for (int i = 0; i < l; i++) { // ����� ������� �� �����
			cout << arrNon[i] << " ";
		}
		cout << endl;*/
		cout << "��������� �������: " << endl;

		for (int i = 0; i < n - 1; i++) { // ���������� ������� ������������ ����� b
			for (int j = 0; j < n - i - 1; j++) {
				if (arrNon[j] < b && arrNon[j + 1] > b) {

					arrNon[j] = arrNon[j] + arrNon[j + 1];
					arrNon[j + 1] = arrNon[j] - arrNon[j + 1];
					arrNon[j] = arrNon[j] - arrNon[j + 1];
				}
			}
		}
		cout << "����� b: " << b << endl;

		int bh = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {

				if (arr[j][i] != 0) {
					arr[j][i] = arrNon[bh];
					bh++;
				}

			}
		}
		for (int i = 0; i < n; i++) { // ����� ������� �� �����
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

		cout << "������ ������ �� ����������" << endl;
		return -1;

	}



}