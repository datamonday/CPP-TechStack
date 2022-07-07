# include <stdio.h>

int main(){
	int a[7] = {1, 2, 3, 4, 5, 6, 7};
	int i=0; 
	int j=6;
	int t;
	
	while(i < j){
		t = a[i];
		a[i] = a[j];
		a[j] = t;
		
		i++;
		j--;
	}
	
	int k;
	printf("After Reverse array: \n");
	for (k=0; k<7; ++k){
		printf("%d ", a[k]);
	}
	
	return 0;
} 
