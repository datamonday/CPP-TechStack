# include <stdio.h>
# include <time.h>

void get_seconds(unsigned long *sec); 

int main(){
	unsigned long sec;
	
	get_seconds( &sec );
	
	printf("number of seconds: %ld\n", sec);
} 


void get_seconds(unsigned long *param){
	
	// 获取当前的秒数
	*param = time( NULL );
	
	return; 
}
