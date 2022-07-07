/*
将输入的2进制字符串转换为10进制数输出。
*/
#include <stdio.h>
#include<string.h>

 int BinToDigit(const char *bin_str, int n_bin_str){
     int num = 0;
     for(int i=0; i<n_bin_str; i++)
     {
       num *= 2;  // 乘2 相当于左移一位
       if(bin_str[i] - '1' == 0){
         num += 1;
       }
       else if(bin_str[i] - '0' == 0){
         num += 0;
       }
       else{
         printf("[Error]只能输入0或1！");
         return -1;
       }
     }
     return num;
   }

   int main()
   {
     char bin_str[200];
     int N = 0;
     printf("输入二进制字符串：\n");
     gets(bin_str);
     N = BinToDigit(bin_str, strlen(bin_str));
     printf("N = %d\n", N);
     return 0;
   }
