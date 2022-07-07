/*
2、统计一个英文文本文件中26个英文字母出现次数并按英文字母序输出统计结果，
查找并替换此英文文本文件中某字符串。
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
struct Alpha //字母 结构体，字母本身和键值
{
    char zm;
    int number;
}table[26];
//自定义的字符串替换函数（所有出现的匹配串都替换为目标串）
void strreplace(char * Src,char * From,char * To){
    int length_to,length_from;
    char *sf,*se,endBuf[1024]={0};
    length_from = strlen(From);
    length_to = strlen(To);
    while(sf = strstr(Src,From)){
        if(NULL == sf)
            break;
        else
        {
            se = sf + length_from;
            strcpy(endBuf,se);
            memset(se,0,strlen(endBuf));
            memcpy(sf,To,length_to);
            memcpy(sf+length_to,endBuf,strlen(endBuf));
            memset(endBuf,0,strlen(endBuf));
        }
    }
}

int main()
{
    char ch;
    char ZMB[]="abcdefghijklmnopqrstuvwxyz\0";
    char buf[1024]={0},*from,*to;
    int index = 0;
    FILE *fp,*fp1,*fp2;
    while(index<26){  //结构体表内容初始化，number都为0，字母分别是a~z
        table[index].zm = ZMB[index];
        table[index].number = 0;
        index++;
    }
    fp = fopen("words.txt","r");
    while(ch = fgetc(fp)) //循环读取字符
    {
        if(feof(fp))
            break;
        ch = tolower(ch); //小写
        if(ch >= 'a' && ch <= 'z') //是字母就更新结构体表统计频次
        {
            index = ch - 'a';
            table[index].number++;
        }
    }
    index = 0;
    while(index<26){ //输出统计结果
        printf("Char '%c' appears %d times in file.\n",table[index].zm,table[index].number);
        index++;
    }
    fclose(fp);
    // 输入想要搜寻的串和被替换成为目标字符串
    printf("Input string you shall find:\t");
    fgets(from,sizeof(from),stdin);
    from = strtok(from,"\n"); //去除换行符
    printf("Input string you shall replace to:\t");
    fgets(to,sizeof(to),stdin); //去除换行符
    to = strtok(to,"\n");
    // 把替换的串重新从words.txt读出、写入新文件words_2.txt
    fp1 = fopen("words.txt","r");
    fp2 = fopen("words_2.txt","w");
    while(!feof(fp1))
    {
        fgets(buf,sizeof(buf),fp1);
        strreplace(buf,from,to);  //每一行都查找、替换目标串
        fputs(buf,fp2);
        memset(buf,0,sizeof(buf));
    }
    fclose(fp1);
    fclose(fp2);
    // 把words.txt内容写入words_2.txt
    fp1 = fopen("words.txt","w");
    fp2 = fopen("words_2.txt","r");
    while(!feof(fp2))
    {
        fgets(buf,sizeof(buf),fp2);
        fputs(buf,fp1);
        memset(buf,0,sizeof(buf));
    }
    fclose(fp1);
    fclose(fp2);
    return 0;
}
