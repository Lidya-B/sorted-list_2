//*****************************************************************************************************
//
//		File:					Sortedlist.h
//
//		Student:				Lidya Belew
//
//		Assignment:				assigment 11
//
//		Course Name:			Data Structures II
//
//		Course Number:			COSC 3100
//
//		Due:					4/22/2024
//
//
//		This program will impliment and test sort types.
//	
//		Other files required: 
//         1. none 
//			
//*****************************************************************************************************

#ifndef SORTEDLIST2_H
#define SORTEDLIST2_H

//*****************************************************************************************************

#include <iostream>

//*****************************************************************************************************

using namespace std;

//*****************************************************************************************************

template<typename T>
class SortedList {
private:
    T* arr;
    int capacity;
    int size;

public:
    SortedList(int size = 10);
    ~SortedList();
    void insert(const T& item);
    void randomise();
    void selectionSortA();
    void selectionSortD();
    void quickSortA();
    void quickSortD();
    void quickSort(int left, int right, bool ascending);
    void heapSortA();
    void heapSortD();
    void heapify(int n, int i, bool ascending);
    void display() const;
};
//*****************************************************************************************************

#endif // !SORTEDLIST_H

//*****************************************************************************************************

template<typename T>
SortedList<T>::SortedList(int size)
{
    capacity = size;
    size = 0;
    arr = new T[capacity];
}

//*****************************************************************************************************

template<typename T>
SortedList<T>::~SortedList()
{
    delete[] arr;
}

//*****************************************************************************************************

template<typename T>
void SortedList<T>::insert(const T& item)
{
    if (size == capacity) {
        capacity += 10;
        T* newArr = new T[capacity];
        for (int i = 0; i < size; ++i) {
            newArr[i] = arr[i];
        }
        delete[] arr;
        arr = newArr;
    }
    arr[size++] = item;
}

//*****************************************************************************************************

template<typename T>
void SortedList<T>::randomise()
{
    for (int i = size - 1; i > 0; --i) {
        int j = rand() % (i + 1);
        swap(arr[i], arr[j]);
    }
}

//*****************************************************************************************************

template<typename T>
void SortedList<T>::selectionSortA()
{
    for (int i = 0; i < size - 1; ++i) {
        int minIndex = i;
        for (int j = i + 1; j < size; ++j) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        swap(arr[i], arr[minIndex]);
    }
}

//*****************************************************************************************************

template<typename T>
void SortedList<T>::selectionSortD()
{
    for (int i = 0; i < size - 1; ++i) {
        int maxIndex = i;
        for (int j = i + 1; j < size; ++j) {
            if (arr[j] > arr[maxIndex]) {
                maxIndex = j;
            }
        }
        swap(arr[i], arr[maxIndex]);
    }
}

//*****************************************************************************************************

template<typename T>
void SortedList<T>::quickSortA()
{
    quickSort(0, size - 1, true);
}

//*****************************************************************************************************

template<typename T>
void SortedList<T>::quickSortD()
{
    quickSort(0, size - 1, false);
}

//*****************************************************************************************************

template<typename T>
void SortedList<T>::quickSort(int left, int right, bool ascending)
{
    if (left < right) {
        int pivotIndex = (left + right) / 2;
        T pivotValue = arr[pivotIndex];

        int i = left;
        int j = right;

        while (i <= j) {
            if (ascending) {
                while (arr[i] < pivotValue) {
                    i++;
                }
                while (arr[j] > pivotValue) {
                    j--;
                }
            }
            else {
                while (arr[i] > pivotValue) {
                    i++;
                }
                while (arr[j] < pivotValue) {
                    j--;
                }
            }

            if (i <= j) {
                swap(arr[i], arr[j]);
                i++;
                j--;
            }
        }

        if (left < j) {
            quickSort(left, j, ascending);
        }
        if (i < right) {
            quickSort(i, right, ascending);
        }
    }
}

//*****************************************************************************************************

template<typename T>
 void SortedList<T>::heapSortA()
{
     for (int i = size / 2 - 1; i >= 0; --i)
     {
         heapify(size, i, true);
     }

     for (int i = size - 1; i >= 0; --i)
     {
         swap(arr[0], arr[i]);
         heapify(i, 0, true);
     }
}

//*****************************************************************************************************

template<typename T> void SortedList<T>::heapSortD()
{
    for (int i = size / 2 - 1; i >= 0; --i) 
    {
        heapify(size, i, false);
    }

    for (int i = size - 1; i >= 0; --i) 
    {
        swap(arr[0], arr[i]);
        heapify(i, 0, false);
    }
}

//*****************************************************************************************************

template<typename T>
 void SortedList<T>::heapify(int n, int i, bool ascending)
{
     int largest = i;
     int l = 2 * i + 1;
     int r = 2 * i + 2;

     if (ascending) {
         if (l < n && arr[l] > arr[largest]) {
             largest = l;
         }

         if (r < n && arr[r] > arr[largest]) {
             largest = r;
         }
     }
     else {
         if (l < n && arr[l] < arr[largest]) {
             largest = l;
         }

         if (r < n && arr[r] < arr[largest]) {
             largest = r;
         }
     }

     if (largest != i) {
         swap(arr[i], arr[largest]);
         heapify(n, largest, ascending);
     }
}

template<typename T>
void SortedList<T>::display() const
{
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
    cout << std::endl;

}

//*****************************************************************************************************
