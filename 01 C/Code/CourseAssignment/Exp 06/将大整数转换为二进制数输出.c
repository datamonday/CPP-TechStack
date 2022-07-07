/*
用一个整型数组表示10进制大整数，数组的每个元素存储大整数的一位数字，将这个大整数转换为2进制数输出。

输入输出：
BigNumber = 1234567890
sArray = '1234567890',
length = 10
1 2 3 4 5 6 7 8 9 0
Number from array is 1234567890,
binary string is 1001001100101100000001011010010

*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int my_atoi(char s) //数字字符转数字
{
    return s-'0';
}

int main(){
    unsigned long BigNumber=0, num=0;
    int iArray[10]={0};
    char sArray[11]={0};
    char binBuffer[33]={0};
    int index=0;
    printf("Input a big number: ");
    scanf("%ld", &BigNumber);  //现有用户输入一个数字
    printf("BigNumber = %ld\n", BigNumber); //打印数字
    itoa(BigNumber, sArray, 10); // 十进制 整数转对应的十进制字符串
    //打印 数字字符串数组 和 长度
    printf("sArray = '%s', \nlength = %ld\n", sArray, strlen(sArray));
    while( index < strlen(sArray) ) //把数字字符串挨个转成整数填入数字数组
    {
        iArray[index] = my_atoi(sArray[index]);
        index += 1;
    }
    // 打印整数数组
    for(index=0;index<strlen(sArray);index++)
        printf("%d ", iArray[index]);
      printf("\n");
    index = 0;
    while( index < strlen(sArray) )//从整数数组累加恢复开始的整数数字
    {
        num *= 10;
        num += iArray[index];
        index += 1;
    }
    //调用itoa直接得到整数的二进制字符串，参数2代表二进制
printf("Number from array is %ld, \nbinary string is %s\n", num , itoa(num,binBuffer,2));
return 0;
}
