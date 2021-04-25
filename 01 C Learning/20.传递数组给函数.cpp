# include "stdio.h"

double get_average(int arr[], int size);

int main() {
	int balance[5] = {500, 100, 100, 150, 150};
	double avg;
	
	avg = get_average(balance, 5);
	
	printf("平均值为：%.4f", avg);
	
	return 0;
} 

double get_average(int arr[], int size) {
	int i;
	double avg;
	double sum = 0;
	
	for (i=0; i < size; ++i) {
		sum += arr[i];
	}
	
	avg = sum / size;
	
	return avg;
}
