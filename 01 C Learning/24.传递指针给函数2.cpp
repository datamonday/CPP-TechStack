# include <stdio.h>

double get_average(int *arr, int size);

int main(){
	int balance[5] = {2021, 4, 28, 11, 35};
	double avg;
	
	avg = get_average(balance, 5);
	
	printf("Average value is: %f\n", avg);
	
	return 0;
}

double get_average(int *arr, int size){
	int i, sum = 0;
	double avg;
	
	for(i=0; i<size; ++i){
		sum += arr[i];
	}
	avg = (double) sum/size;
	
	return avg;
}
