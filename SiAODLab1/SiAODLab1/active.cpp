#include "iostream"
#include "Windows.h"
<<<<<<< HEAD
#include <vector>
#include <string>
#include <cmath>

using namespace std;

string CreateSpace(size_t num)
{
	//cout << endl << "-----------" << num << endl;
	string TmpStr;
	for (auto i = 0; i < num; ++i)
	{
		TmpStr += "  ";
	}
	return TmpStr;
}

void PrintArr(vector<int>& arr)
{
	cout << "[ ";
	for (auto& a : arr)
	{
		cout << a << " ";
	}
	cout <<"]"<< endl;
}

void GenerateArr(vector<int>& arr)
{
	for (auto& a : arr)
	{
		a = rand() % 100;
	}
}

void GenerateChildNodes(vector<int>& arr, int size, int i, int numOfIt)
{
	int ShiftChildId = 0;
	for (int j = 0; j < numOfIt; ++j)
	{
		cout << CreateSpace(size) << arr[2 * i + 1 + ShiftChildId] << CreateSpace(size * 2) << arr[2 * i + 2 + ShiftChildId] << CreateSpace(size);
		ShiftChildId += 2;
	}
}

void PrintArrAsTree(vector<int> arr)
{
	size_t size = arr.size();

	size_t powValue = floor(log(size) / log(2));
	size_t sumOfBottom = pow(2, powValue);
	
	size_t height = powValue + 1; 
	size_t width = ceil(sumOfBottom + sumOfBottom);

	if (size)
	{
		//Create root component and pop it from vector
		width = ceil(width / 2.);
		cout << CreateSpace(width - 1) << arr[0] << CreateSpace(width) << endl;
		arr.erase(arr.begin());
		width = ceil(width / 2.);
		
		int numOnLevel = 0;
		for (size_t indLevel = 1, indArray = 0; (indArray < arr.size()); ++indArray) //&& (indLevel <= height)
		{
			if (numOnLevel == pow(2, indLevel))
			{
				indLevel++;
				bool EndOfLevels = (indLevel == height - 1);
				width = EndOfLevels?1:ceil(width / 2.);
				numOnLevel = 0;
				cout << endl;
			}
			bool EndOfLevels = (indLevel == height - 1) || (indLevel == height - 2);

			cout << CreateSpace(width - 1) << arr[indArray] << CreateSpace(width);
			numOnLevel++;
		}
		//cout << "Высота: " << height << endl << "Ширина: " << width << endl;
		cout << endl;
	}
=======
#include <list>
#include <vector>

using namespace std;

enum SortBy
{
	EvenIndex,
	AbsNumbers
};

void GenerateList(list<int>& SomeList)
{
	for (auto& a : SomeList)
	{
		a = rand() % 1000 - 300;
	}
}

void PrintList(list<int>& SomeList)
{
	cout << "[ ";
	for (auto& a : SomeList)
	{
		cout << a << " ";
	}
	cout << "]"<<endl;
}

void quickSort(vector<int>& arr, int left, int right) {

	int i = left, j = right;
	int tmp;
	int pivot = arr[(left + right) / 2];

	/* partition */
	while (i <= j) {
		while (arr[i] < pivot)
			i++;
		while (arr[j] > pivot)
			j--;
		if (i <= j) {
			tmp = arr[i];
			arr[i] = arr[j];
			arr[j] = tmp;
			i++;
			j--;
		}
	};

	/* recursion */
	if (left < j)
		quickSort(arr, left, j);
	if (i < right)
		quickSort(arr, i, right);
}

list<int> GetTmpVectorByRule(list<int>& SomeList, SortBy Something)
{
	vector<int> TVector;
	int i = 0;

	for (auto it = SomeList.begin(); it != SomeList.end(); advance(it, 1),++i)
	{
		switch (Something)
		{
		case EvenIndex:
		{
			if (i % 2 == 0)
			{
				TVector.push_back(*it);
			}
		}
			break;

		case AbsNumbers:
		{
			if (*it >= 0) TVector.push_back(*it);
		}
			break;

		default:
			break;
		}
	}
	quickSort(TVector, 0, TVector.size()-1);


	list<int> TList;
	std::copy(TVector.begin(), TVector.end(), std::back_inserter(TList));

	return TList;
}


list<int> GetSortedListByRule(list<int> SomeList, SortBy Something)
{
	int i = 0;
	list<int> TmpList = GetTmpVectorByRule(SomeList, Something);

	for (auto it = SomeList.begin(); it != SomeList.end(); advance(it, 1), ++i)
	{
		switch (Something)
		{
		case EvenIndex:
		{
			if (i % 2 == 0)
			{
				*it = TmpList.front();
				TmpList.pop_front();
			}
		}
		break;

		case AbsNumbers:
		{
			if (*it >= 0)
			{
				*it = TmpList.front();
				TmpList.pop_front();
			}
		}
		break;

		default:
			break;
		}
	}
	return SomeList;
>>>>>>> master
}

int main()
{
	setlocale(0, "rus");

<<<<<<< HEAD
	cout << "Введите количество элементов массива: ";
	int size;
	cin >> size;

	vector<int> arr(size);
	GenerateArr(arr);
	PrintArr(arr);
	PrintArrAsTree(arr);
=======
	int size;
	cout << "Выберите количество элементов: ";
	cin >> size;
	list<int> CurrentList(size,0);
	list<int> PtrList;

	GenerateList(CurrentList);
	PrintList(CurrentList);

	cout << "Сортировка листа по четным индексам: " << endl;
	PtrList = GetSortedListByRule(CurrentList, SortBy::EvenIndex);
	PrintList(PtrList);
	
	cout << "Сортировка листа по положительным числам: " << endl;
	PtrList = GetSortedListByRule(CurrentList, SortBy::AbsNumbers);
	PrintList(PtrList);

>>>>>>> master

	system("pause");
	return 0;
}