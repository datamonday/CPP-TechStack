/*
检查C源程序的圆括号和大括号是否匹配。
正确的例子如：（{((…)(…))}()）,不正确的例子如：{(})
*/

#include<stdio.h>
#define True 1
#define False 0
char stack[1024]; //类似于栈
int top=-1; //栈顶指针，初始化为-1，表示空

int main()
{
    char inputC;
    int success = True;
    while((inputC = getchar()) != '#') //输入字符以#结尾
    {
        if(inputC == '(' || inputC == '{')
            stack[++top] = inputC;
        else if(inputC == ')')
        {
            if(top >= 0 && stack[top] == '(')
                top--;   //弹栈
            else{ //最内层不匹配马上结束循环，标志置位False
                success = False;
                break;
            }
        }
        else if(inputC == '}')
        {
            if(top >= 0 && stack[top] == '{')
                top--;   //弹栈
            else{  //最内层不匹配马上结束循环，标志置位False
                success = False;
                break;
            }
        }
    }
    if(success && top == -1)
    {
        printf("Match Success\n");
    }else
    {
        printf("Match Error\n");
    }
    return 0;
}
