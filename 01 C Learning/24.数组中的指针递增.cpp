# include <stdio.h>

const int MAX = 3;

int main() {
	int var[] = {10, 100, 200};
	int i, j, *ptr1, *ptr2;
	
	// 指针中的数组地址（指针指向数组中第一个元素的地址） 
	ptr1 = var;
	
    // 递增一个指针
	for(i=0; i<MAX; i++){
		printf("存储地址： var[%d] = %p\n", i, ptr1);
		printf("存储值  ： var[%d] = %d\n", i, *ptr1);
		
		// 指向下一个位置
		ptr1++; 
	}
	
    // 递减一个指针
    // ptr2 = var; 做修改
	// 指针中最后一个元素的地址
	ptr2 = &var[MAX-1];
    
    for(j=MAX; j>0; j--){
        printf("存储地址：var[%d] = %p\n", j-1, ptr2);
        printf("存储值  ：var[%d] = %d\n", j-1, *ptr2);
        
        // 指向下一个位置
        ptr2--;
    }
	
	return 0;
} 
