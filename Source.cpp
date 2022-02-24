// ������������ ������ ������� C++
#include <iostream>

using namespace std;

template<typename T> void clearArray(T array1[], int length1, int key=0);
void showArray(int array[], int length);
//void showArrayFloat(float array[], float length);

int indexSum(int array1[], int length1, int array2[], int length2, int indexKey=0);

template<typename T> int maxSum(T array[], int length);

void primeRange(int start, int end);
bool simple(int end);

int main() {
	setlocale(LC_ALL, "Russian");
	//int n;

	// ������ 1

	int array[5] = { 1, 2, 3, 3, 4 };
	int key;

	cout << "������ 1.\n����������� ������ (���� Int): \n";
	showArray(array, 5);

	cout << "������� ����: ";
	cin >> key;
	cout << "�������� �������� �������, ������ �����: \n";
	clearArray(array, 5, key);
	showArray(array, 5);

	/*
	float array1[5] = { 1.0f, 2.0f, 2.0f, 3.0f, 4.0f };

	cout << "����������� ������ (���� float): \n";
	showArrayFloat(array1, 5);

	cout << "������� ����: ";
	cin >> key;
	cout << "�������� �������� �������, ������ �����: \n";
	clearArray(array1, 5, key);
	showArrayFloat(array1, 5); */

	// ������ 2

	int array1[4] = { 2, 3, 5, 3 };
	int array2[4] = { 6, 1, 9, 0 };


	cout << "\n������ 2.\n����������� ������� (���� Int): \n";
	const int length1 = 4;
	const int length2 = 4;
	showArray(array1, length1);
	showArray(array2, length2);
	cout << "������� �����-������: ";
	cin >> key;

	
	cout << indexSum(array1, length1, array2, length2, key);
	cout << endl;

	// ������ 3

	const int length3 = 10;
	int array3[length3] = { 1, 2, 3, 4, 5, 6, 7, 8, 10, 9 };

	cout << "\n������ 3.\n����������� ������: \n";
	showArray(array3, length3);

	cout << "����� ���� ������������ ���������, ����������� � �� �������: " << maxSum(array3, length3) << endl;

	// ������ 4
	int start = 2;
	int end = 100;
	cout << "������� ����� � ��������� �� " << start << " �� " << end << ":\n";
	primeRange(start, end);
	return 0;
}

// ������ 4
void primeRange(int start, int end) {
	
	for (int i = start; i <= end; i++)
		if (simple(i))
			cout << i << " ";
	cout << endl;

	return;
}

bool simple(int num) {
	int counter = 1;
	for (int i = 1; i <= num / 2; i++)
		if (num % i == 0)
			counter++;
	if (counter == 2)
		return true;
	return false;
}

// ������ 3

template<typename T> int maxSum(T array[], int length) {
	int max1 = 0;
	int max2 = 0;
	
	for (int i = 0; i < length; i++) {
		if (array[i] > array[i + 1]) {
			max1 = array[i];
			
		}

		else
			continue;
		if (array[i] > array[i + 1] && array[i] < max1)

			max2 = array[i];
		else
			if (max1 > max2)
				max2 = array[i - 1];
			else
				if (max1 < max2)
					max2 = array[i + 1];
	}

	cout << max1 << " " << max2 << endl;

	return max1 + max2;
}



// ������ 2
int indexSum(int array1[], int length1, int array2[], int length2, int indexKey) {
	if (indexKey < 0 || indexKey > length1 || indexKey > length2) {
		cout << "ERROR" << endl;
		return 0;
	}

	int index1 = 0;
	int index2 = 0;
	for (int i = 0; i < length1; i++) {
		if (i == indexKey)
			index1 = array1[i];
	}
	for (int j = 0; j < length2; j++) {
		if (j == indexKey)
			index2 = array2[j];
		}
	return index1 + index2;
}

// ������ 1
template<typename T> void clearArray(T array[], int length, int key) {
	for (int i = 0; i < length; i++) {
		if (array[i] == key)
			array[i] = 0;
	}
}

// ������ �������
void showArray(int array[], int length) {
	cout << "[";
	for (int i = 0; i < length; i++)
		cout << array[i] << ", ";
	cout << "\b\b]";
	cout << endl;
}

/*
void ShowArrayFloat(float array[], float length) {
	cout << "[";
	for (float i = 0; i < length; i++)
		cout << array[i] << ", ";
	cout << "\b\b]";
	cout << endl;
}*/
