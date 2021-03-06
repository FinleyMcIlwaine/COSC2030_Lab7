// Lab7-fmcilwai.cpp
// Finley McIlwaine
// COSC 2030
// 11/19/2018

#include "pch.h"
#include <iostream>
#include "Lab7-fmcilwai.h"
#include "RandomUtilities.h"
#include "winTimer.h"

using std::cout;
using std::cin;
using std::endl;

// post: a vector of listSize random doubles from
//         the range minNum to maxNum has been returned.
vector<double> getNums(size_t listSize, double minNum, double maxNum)
{
	vector<double> theList;
	for (size_t i = 0; i < listSize; ++i)
	{
		theList.push_back(randReal(minNum, maxNum));
	}

	return theList;
}

int main()
{
	double maxNum = 500;
	double minNum = 1;

	// size of vectors that take ~4 seconds to solve
	int stlSize       = 2090000;
	int bubbleSize    = 3300;
	int insertionSize = 4100;
	int selectionSize = 7000;
	int mergeSize     = 300000;
	int quickSize     = 550000;

	// double sizes
	stlSize *= 2;
	bubbleSize *= 2;
	insertionSize *=2;
	selectionSize *= 2;
	mergeSize *= 2;
	quickSize *= 2;

	// quadruple sizes
	stlSize *= 2;
	bubbleSize *= 2;
	insertionSize *= 2;
	selectionSize *= 2;
	mergeSize *= 2;
	quickSize *= 2;

	// generate the vectors to be sorted vector
	vector<double> stlNums       = getNums(stlSize, minNum, maxNum);
	vector<double> bubbleNums    = getNums(bubbleSize, minNum, maxNum);
	vector<double> insertionNums = getNums(insertionSize, minNum, maxNum);
	vector<double> selectionNums = getNums(selectionSize, minNum, maxNum);
	vector<double> mergeNums     = getNums(mergeSize, minNum, maxNum);
	vector<double> quickNums     = getNums(quickSize, minNum, maxNum);
	
	// sort using the stl sort algorithm
	Timer stlTime;
	stlTime.start();
	std::sort(stlNums.begin(), stlNums.end());
	cout << "STL Sort Time:       " << stlTime() << " seconds" << endl;
	stlTime.stop();

	// sort using the bubble sort algorithm
	Timer bubbleTime;
	bubbleTime.start();
	bubbleSort(bubbleNums);
	cout << "Bubble Sort Time:    " << bubbleTime() << " seconds" << endl;
	bubbleTime.stop();

	// sort using the insertion sort algorithm
	Timer insertionTime;
	insertionTime.start();
	insertionSort(insertionNums);
	cout << "Insertion Sort Time: " << insertionTime() << " seconds" << endl;
	insertionTime.stop();

	// sort using the selection sort algorithm
	Timer selectionTime;
	selectionTime.start();
	selectionSort(selectionNums);
	cout << "Selection Sort Time: " << selectionTime() << " seconds" << endl;
	selectionTime.stop();

	// sort using the merge sort algorithm
	Timer mergeTime;
	mergeTime.start();
	mergeSort(mergeNums);
	cout << "Merge Sort Time:     " << mergeTime() << " seconds" << endl;
	mergeTime.stop();

	// sort using the quick sort algorithm
	Timer quickTime;
	quickTime.start();
	quickSort(quickNums, 0, quickNums.size() - 1);
	cout << "Quick Sort Time:     " << quickTime() << " seconds" << endl;
	quickTime.stop();

}
