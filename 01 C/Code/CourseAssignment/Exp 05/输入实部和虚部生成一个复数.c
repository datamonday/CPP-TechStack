/*
设计一个复数类型，输入实部和虚部生成一个复数，
可进行两个复数求和、两个复数求差、两个复数求积运算。

输入输出：
Input c1 : 1 2
Input c2 : 3 4
c1 is: 1.000000 + 2.000000j
c2 is: 3.000000 + 4.000000j
c1 + c2 =  4.000000 + 6.000000j
c1 - c2 =  -2.000000 - 0.000000j
c1 * c2 =  -5.000000 + 10.000000j
*/

#include<stdio.h>
#include<string.h>
#include<math.h>
struct complex  //定义复数结构体
{
    float real;
    float maginary;
};
void PrintComplex(struct complex *member){ //打印复数
    if(member->maginary < 0)  //这里的操作是为了输出的美观
        printf(" %f - %fj \n",member->real,abs(member->maginary));
    else
        printf(" %f + %fj \n",member->real,member->maginary);
}//复数加法，返回复数结构体
struct complex AddComplex(struct complex *member1,struct complex *member2){
    struct complex child;
    child.real = member1->real + member2->real; //实部1+实部2
    child.maginary = member1->maginary + member2->maginary;//虚部1+虚部2
    //printf("c1 + c2 = ");
    //PrintComplex(&child);
    return child;
}
//复数减法，返回复数结构体
struct complex SubComplex(struct complex *member1,struct complex *member2){
    struct complex child;
    child.real = member1->real - member2->real;
    child.maginary = member1->maginary - member2->maginary;
    return child;
}
//复数乘法，返回复数结构体
struct complex MulComplex(struct complex *member1,struct complex *member2){
    struct complex child;
    child.real = (member1->real * member2->real) - (member1->maginary * member2->maginary);
    child.maginary = (member1->maginary * member2->real) + (member1->real * member2->maginary);
    return child;
}
int main(int argc, char const *argv[])
{
    struct complex c1,c2,temp;
    printf("Input c1 : ");      //分别输入两个结构体的实部、虚部值
    scanf("%f %f",&c1.real,&c1.maginary);
    printf("Input c2 : ");
    scanf("%f %f",&c2.real,&c2.maginary);
    printf("c1 is:");           //打印原始的两个复数
    PrintComplex(&c1);
    printf("c2 is:");
    PrintComplex(&c2);
    temp = AddComplex(&c1,&c2); //复数加，函数结果赋值给中间变量结构体temp
    printf("c1 + c2 = ");
    PrintComplex(&temp);
    temp = SubComplex(&c1,&c2); //复数减，函数结果赋值给中间变量结构体temp
    printf("c1 - c2 = ");
    PrintComplex(&temp);
    temp = MulComplex(&c1,&c2); //复数乘，函数结果赋值给中间变量结构体temp
    printf("c1 * c2 = ");
    PrintComplex(&temp);
    return 0;
}
