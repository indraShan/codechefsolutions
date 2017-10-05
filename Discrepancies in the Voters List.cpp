#include <iostream> 
#include <limits.h>
#include <string.h>
#include <map>
#include <algorithm>
#include <vector>

bool binarySearch(int number, int *array, int size, int start, int end) {
	if (start > end || start == size || end == size) {
		return false;
	}
	int mid = (start + end)/2;
	if (array[mid] > number) {
		// Left
		return binarySearch(number, array, size, start, mid - 1);
	}
	else if (array[mid] < number) {
		// Right
		return binarySearch(number, array, size, mid+1, end);
	}
	return true;
}

void print(int * array, int size) {
	std::cout << "[";
	for (int counter = 0; counter < size; counter++) {
		if (counter != 0) {
			std::cout << ",";
		}
		std::cout << array[counter];
	}
	std::cout << "]" << std::endl;
}

int main() { 
	int list1_size = 0;
	std::cin >> list1_size;
	
	int list2_size = 0;
	std::cin >> list2_size;
	
	int list3_size = 0;
	std::cin >> list3_size;
	
	int list1[list1_size];
	for (int counter = 0; counter < list1_size; counter++) {
		std::cin >> list1[counter];
	}
	
	int list2[list2_size];
	for (int counter = 0; counter < list2_size; counter++) {
		std::cin >> list2[counter];
	}
	
	
	int list3[list3_size];
	for (int counter = 0; counter < list3_size; counter++) {
		std::cin >> list3[counter];
	}
	
	int max = list1_size > list2_size ? list1_size : list2_size;
	max = max > list3_size ? max : list3_size;
	
	int list1Counter = 0;
	int list2Counter = 0;
	int list3Counter = 0;
	int outoutIndex = 0;
	int result[max];
	memset(result, -1, sizeof(result));
	for (int counter = 0; (list1Counter < list1_size || list2Counter < list2_size || list3Counter < list3_size); counter++) {
		int number1 = list1Counter < list1_size? list1[list1Counter] : INT_MAX;
		int number2 = list2Counter < list2_size? list2[list2Counter] : INT_MAX;
		int number3 = list3Counter < list3_size? list3[list3Counter] : INT_MAX;
		
		int min = number1 < number2 ? number1 : number2;
		min = min < number3 ? min : number3;
		
		int count = 0;
		if (min == number1) {
			list1Counter++;
			if (min == number2 || min == number3) {
				count = 2;
			}
		}
		if (min == number2) {
			list2Counter++;
			if (min == number1 || min == number3) {
				count = 2;
			}
		}
		if (min == number3) {
			list3Counter++;
			if (min == number2 || min == number1) {
				count = 2;
			}
		}
		
		if (count > 0) {
			result[outoutIndex] = min;
			outoutIndex++;
		}
	}
	
	std::cout << outoutIndex << std::endl;
	for (int counter = 0; counter < max; counter++) {
		if (result[counter] != -1) {
			std::cout <<result[counter] << std::endl;
		}
	}
		  
	return 0;
}