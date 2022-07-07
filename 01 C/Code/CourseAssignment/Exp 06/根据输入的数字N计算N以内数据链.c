/*
根据输入的数字N，计算N以内（包括N）数据链并统计数据链末尾数字是1的数据个数。
  例如N=44，则数字链为：44->32->13->10->1，
  其规则为：4*4+4*4=32，3*3+2*2=13，1*1+3*3=10，1*1+0*0=1。
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int Calc(int index,int len)  //计算按照规则本数字的下一个数字，len为数字长度
{
    int i = 0,res = 0,temp=0; //res累加其结果
    while(i < len)
    {
        index %= (int)pow(10,len-i);
        temp = index / (int)pow(10,len-i-1);
        res += (int)pow(temp,2);
        i += 1;
    }
    return res;
}
int print_link(int num,int len) //打印单行列表，num为初始数字，len为其长度
{
    char buf[10];
    itoa(num,buf,10); //这一步是为了后面求出数字长度
    while(num > 9)   //打印终止于小于10的数字
    {
        printf("%d -->",num);
        num = Calc(num,strlen(buf));
        memset(buf,0,sizeof(buf));
        itoa(num,buf,10);
    }
    printf("%d\n", num);
    return num;
}
int main(){
    unsigned int number = 0,temp = 0;
    char NumBuffer[10]={0};
    printf("Input a number: ");
    gets(NumBuffer);       //读取字符串形式整数
    temp = atoi(NumBuffer); //转成整数
    while(temp>=10)
    {
        if(1 ==print_link(temp,strlen(NumBuffer))) //记录结果为1的数目
            number++;;
        temp -= 1;
    }
    printf("Number of '1' is %d\n",number);
    return 0;
}
