/*
编写程序XMLtoTXT自动将XML文件email.xml转换为文本文件email.txt。

命令行格式：XMLtoTXT email.xml email.txt。
*/


#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
//函数用于去除字符串首尾的空格、制表符和回车、换行符等空白符号
void trim(char *strIn, char *strOut){
    char *start, *end, *temp;//定义去除空格后字符串的头尾指针和遍历指针
    temp = strIn;
    while (*temp == ' ' || *temp == '\n' || *temp == '\t' || *temp == '\r'){
        ++temp;
    }
    start = temp; //求得头指针
    temp = strIn + strlen(strIn) - 1; //得到原字符串最后一个字符的指针(不是'\0')
    printf("%c\n", *temp);
    while (*temp == ' ' || *temp == '\n' || *temp == '\t' || *temp == '\r'){
        --temp;
    }
    end = temp; //求得尾指针
    for(strIn = start; strIn <= end; ){
        *strOut++ = *strIn++;
    }
    *strOut = '\0';
}
//字符串切割函数，src最后为截止到sub子串首次出现之前的内容
void strsplit(char *src , char *sub){
    char *ptr;
    ptr = strstr(src,sub);
    *ptr = '\0';
}

int main(int argc, char const *argv[])
{
    FILE *fp1,*fp2;
    char buf[1024]={0},res[1024],*sp=NULL;
    fp1 = fopen(argv[1],"r");
    fp2 = fopen(argv[2],"w");
    while(!feof(fp1))
    {
        fgets(buf,sizeof(buf),fp1); //依次读取一行
        trim(buf,res);
        if(strcmp(res,"<from>")==0){     //找关键字<from>
            memset(buf,0,sizeof(buf));
            memset(res,0,sizeof(res));
            fgets(buf,sizeof(buf),fp1);
            trim(buf,res);              //去空格
            strsplit(res,"</address>"); //去末尾
            sp = strstr(res,"<address>");
               sp += strlen("<address>");    //sp指向真正想要的内容
               fprintf(fp2,"from: %s\n",sp); //按照目标格式写入文件
               memset(buf,0,sizeof(buf));
            memset(res,0,sizeof(res));
               continue;
        }
        if(strcmp(res,"<to>")==0){      //找关键字<to>
            memset(buf,0,sizeof(buf));
            memset(res,0,sizeof(res));
            fgets(buf,sizeof(buf),fp1);
            trim(buf,res);                //去空格
            strsplit(res,"</address>"); //去末尾
            sp = strstr(res,"<address>");
               sp += strlen("<address>");  //sp指向真正想要的内容
               fprintf(fp2,"to: %s\n",sp); //按照目标格式写入文件
               memset(buf,0,sizeof(buf));
            memset(res,0,sizeof(res));
               continue;
        }
        if(sp=strstr(res,"</subject>")){     //找关键字</subject>
            *sp = '\0';                       //去末尾
            sp = res + strlen("<subject>"); //sp指向真正想要的内容
            fprintf(fp2,"subject: %s\n",sp);//按照目标格式写入文件
            continue;
        }
        if(sp=strstr(res,"</body>")){    //找关键字</body>
            *sp = '\0';                     //去末尾
            sp = res + strlen("<body>"); //sp指向真正想要的内容
            fprintf(fp2,"body: %s\n",sp); //按照目标格式写入文件
            break;
        }
    }
    fclose(fp1);
    fclose(fp2);
    return 0;
}
