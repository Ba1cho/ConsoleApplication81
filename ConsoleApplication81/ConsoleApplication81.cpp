#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int qsortRecursive(int* mas, int size, int* mas2 ) {
	int prew = 0;
	int next = 1;
	int size2 = 0;
	for (size_t i = 0; i < size-1; i++)
	{
		if (mas[prew] > 0 && mas[next] < 0) {
			mas2[size2] = mas[prew];
			size2++;
			mas2[size2] = mas[next];
			size2++;
			
		}
		prew++;
		next++;
	}
	return size2;
	
	
	
}
void vvod(int countes) {
	fstream fitt;
	fitt.open("c.txt", ios::out);
	if (!fitt.is_open())
		cout << "Ошибка открытия файла!";
	else {
		for (int i = 0; i < countes; i++) {
			fitt << 20 - rand() % 30 << '\t';
		}
	}
	fitt.close();

}
void read_file(int* arr, int counter) {
	int counter2 = 0;
	int* arr2 = new int[counter];
	fstream fitt;
	fitt.open("c.txt", ios::in);
	fstream fin;
	fin.open("g.txt", ios::out);


	if (!fitt.is_open())
		cout << "Ошибка открытия файла!";
	else {
		for (int i = 0; i < counter; i++) {
			int c = 0;
			fitt >> c;
			arr[i] = c;
		}

		counter2 = qsortRecursive(arr, counter, arr2);
		cout << counter2;
		for (int i = 0; i < counter2; i++) {
			fin << arr2[i] << '\t';
		}
	}
	fin.close();
	fitt.close();
	delete[] arr;
	arr = nullptr;
	delete[] arr2;
	arr2 = nullptr;


}
int main() {
	srand(time(0));
	int countes = 0;
	
	cout << "counter: ";
	cin >> countes;
	if (countes > 0) {
		setlocale(LC_ALL, "rus");
		string path = "c.txt";
		fstream fitt;
		fitt.open("c.txt", ios::in);
		vvod(countes);

		int* arr = new int[countes];
		
		read_file(arr, countes);
	}
	else
		cout << "Break";
}
