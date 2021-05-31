/*
2、	现有两个文本文件db1.txt和db2.txt。
	db1.txt中第一列为姓名，第二列为英语成绩；
	db2.txt中第一列为姓名，第二列为数学成绩。

  通过姓名字段将db1.txt文件关联到db2.txt文件生成db3.txt文件。

db3.txt文件第一列为姓名，第二列为英语成绩，第三列为数学成绩，第四列为平均成绩，如下图所示。

a)
Bob 90
David 80
George 84
Jack 64

b)
Jim 95
George 74
David 82
Paul 70
Jack 70
Bob 86

c)
Bob 90 86 88
David 80 82 81
George 84 74 79
Jack 64 70 67
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct student /*包含学生姓名和成绩*/
{
    char name[16];
    int english;
    int math;
};

#define MAX_SIZE 100

int main()
{
    FILE *fp1 = fopen("db1.txt", "r");
    if (!fp1)
        exit(0);
    FILE *fp2 = fopen("db2.txt", "r");
    if (!fp2)
        exit(0);
    FILE *fp3 = fopen("db3.txt", "w");
    if (!fp3)
        exit(0);

    struct student info[MAX_SIZE] = { 0 };
    char name[32];
    int ret, score;
    int i = 0, num;

    while (!feof(fp1))
    {
        ret = fscanf(fp1, "%s %d\n", name, &score);
        if (ret < 2)
            break;
        //printf("1. name = %s, score = %d\n", name, score);
        strcpy(info[i].name, name);
        info[i].english = score;
        i++;
        if (i >= MAX_SIZE)
            break;
    }
    fclose(fp1);

    num = i;
    i = 0;
    while (!feof(fp2))
    {
        ret = fscanf(fp2, "%s %d\n", name, &score);
        if (ret < 2)
            break;
        //printf("2. name = %s, score = %d\n", name, score);

        while (i < num) {
            if (strcmp(info[i].name, name) == 0) {
                info[i].math = score;
                break;
            }
            i++;
        }
        if (i >= num && i < MAX_SIZE) {
            strcpy(info[i].name, name);
            info[i].math = score;
            num++;
        }
        if (num >= MAX_SIZE)
            break;
        i = 0;
    }
    fclose(fp2);

    //printf("Num = %d\n", num);
    i = 0;
    while (i < num) {
        fprintf(fp3, "%s %d %d %.1lf\n",
                info[i].name,
                info[i].english,
                info[i].math,
                (info[i].english + info[i].math)*1.0 / 2);
        i++;
    }
    fclose(fp3);
    return 0;
}
