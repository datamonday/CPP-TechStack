#include <stdio.h>
 
int main()
{
    int c;
    int a = 10;
    c = a++; 
    printf("先赋值后运算：\n");
    printf("c = %d\n", c ); // c=10
    printf("a = %d\n", a ); // a=11
   
    a = 10;
    c = a--; 
    printf("c = %d\n", c ); // c=10
    printf("a = %d\n", a ); // a=9
 
    
    printf("先运算后赋值：\n");
    a = 10;
    c = ++a; 
    printf("c = %d\n", c ); // c=11
    printf("a = %d\n", a ); // a=11
    
    a = 10;
    c = --a; 
    printf("c = %d\n", c ); // c=9
    printf("a = %d\n", a ); // a=9
}
