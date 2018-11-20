// Lab7-fmcilwai.h
// Finley McIlwaine
// COSC 2030
// 11/19/2018

#pragma once
#ifndef LAB_7H

#include <vector>
#include <algorithm>
using std::vector;

// sorting function definitions
// bubble sort
void bubbleSort(vector<double>& nums) {
	double tempVal;
	for (int i = 0; i < nums.size(); i++) {
		for (int j = 0; j < nums.size() - i - 1; j++) {
			if (nums[j] > nums[j + 1]) {
				tempVal = nums[j];
				nums[j] = nums[j + 1];
				nums[j + 1] = tempVal;
			}
		}
	}
}

// insertion sort
void insertionSort(vector<double>& nums) {
	double tempVal;
	for (int i = 1; i < nums.size(); i++) {
		for (int j = i; j > 0; j--) {
			if (nums[j] < nums[j - 1]) {
				tempVal     = nums[j];
				nums[j]     = nums[j - 1];
				nums[j - 1] = tempVal;
			}
			else { break; }
		}
	}
}

// selection sort
void selectionSort(vector<double>& nums) {
	double max;
	int maxInd;
	for (int i = nums.size()-1; i > 0; i--) {
		max = 0;
		for (int j = 0; j <= i; j++) {
			if (nums[j] > max) {
				max = nums[j];
				maxInd = j;
			}
		}
		nums[maxInd] = nums[i];
		nums[i] = max;
	}
}

// merge sort
void mergeSort(vector<double>& nums) {
	if (nums.size() > 1) {
		int half_size = nums.size() / 2;
		vector<double> lowHalf(nums.begin(), nums.begin() + half_size);
		vector<double> highHalf(nums.begin() + half_size, nums.end());

		mergeSort(lowHalf);
		mergeSort(highHalf);

		merge(lowHalf.begin(), lowHalf.end(), highHalf.begin(), highHalf.end(), nums.begin());
	}
}

// quick sort
void quickSort(vector<double>& nums, int left, int right) {
	int i = left;
	int j = right;
	double pivot = nums[(left + right) / 2];
	double temp;

	while (i <= j) {
		while (nums[i] < pivot) {
			i++;
		}
		while (nums[j] > pivot) {
			j--;
		}
		if (i <= j) {
			temp = nums[i];
			nums[i] = nums[j];
			nums[j] = temp;
			i++;
			j--;
		}
	}

	if (left < j) {
		quickSort(nums, left, j);
	}
	if (i < right) {
		quickSort(nums, i, right);
	}
}

#endif // !LAB_7H


