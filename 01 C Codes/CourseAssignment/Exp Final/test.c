/*

C:\Users\34123>d:
D:\>cd D:\Github\CPP-TechStack\01 C Codes\CourseAssignment\Exp Final

D:\Github\CPP-TechStack\01 C Codes\CourseAssignment\Exp Final>test -a Messi
Data is successfully loaded!

Please enter the corresponding administrator number!
10

............................................................
.                          administrator menu              .
.  Please enter the number for the corresponding operation .
.  0->Exit the library management system                   .
.  1->Book information entry                               .
.  2->Reader information entry                             .
.  3->Book information modify                              .
.  4->Reader information modify                            .
.  5->Book information delete                              .
.  6->Reader information delete                            .
.  7->Book information inquiry                             .
.  8->display the information of all books                 .
.  9->display the information of all readers               .
............................................................
-------------------------------------------------------------------------------
命令行参数如下：

Libsim –a(-u)  xxxx

第一个参数为可执行程序名称；第二个参数为用户身份，-a表示管理员，-u表示读者；第三个参数为用户名
*/



#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//显示管理员界面和读者界面
void readermenu(){
    printf("............................................................\n");
    printf(".                      reader menu                         .\n");
    printf(".  Please enter the number for the corresponding operation .\n");
    printf(".  0->Exit the library management system                   .\n");
    printf(".  1->Borrow the book                                      .\n");
    printf(".  2->Return the book                                      .\n");
    printf(".  3->Inquiry the book information                         .\n");
    printf(".  4->display all book you borrowed                        .\n");
    printf("............................................................\n");
}
void administratormenu(){
    printf("............................................................\n");
    printf(".                          administrator menu              .\n");
    printf(".  Please enter the number for the corresponding operation .\n");
    printf(".  0->Exit the library management system                   .\n");
    printf(".  1->Book information entry                               .\n");
    printf(".  2->Reader information entry                             .\n");
    printf(".  3->Book information modify                              .\n");
    printf(".  4->Reader information modify                            .\n");
    printf(".  5->Book information delete                              .\n");
    printf(".  6->Reader information delete                            .\n");
    printf(".  7->Book information inquiry                             .\n");
    printf(".  8->display the information of all books                 .\n");
    printf(".  9->display the information of all readers               .\n");
    printf("............................................................\n");
}

//书结构体，包括编号，书名，图书馆内该书现馆藏量
typedef struct Book{
    int number;
    char name[100];
    int  totalnumber;
}book;

//读者结构体，包括编号，用户名，该读者借走的书,该读者借走的书的总量
typedef struct Reader{
    int number;
    char name  [100];
    char bookborrowed[10][100];
    int bookborrowedsum;
}reader;

//管理员结构体，包括编号，用户名
typedef struct Administrator{
    int number;
    char name[100];
}administrator;




//馆藏图书数组，读者数组，管理员数组
book book_list[200000];
reader reader_list[10000];
administrator administrator_list[100];
int choice;                          //用户选择选项
FILE *readerlist;                    //读者文件指针
FILE *booklist;                      //馆藏书目文件指针
FILE *administratorlist;             //管理员文件指针
FILE *borrowedlist;                  //出借书目文件指针
int administratorsum=0;              //管理员总数
int readersum=0;                     //读者总数
int booksum=0;                       //馆藏图书总数



void display_booklist();                //显示现存馆藏书目
void display_readerlist();              //显示读者信息
void display_myborrowed();              //显示读者借的书目
void book_borrow();                     //图书出借
void book_return();                     //图书出借
void book_inquiry();                    //查询图书信息
void book_information_entry();          //图书信息录入
void book_information_modify();         //图书信息修改
void book_information_delete();         //图书信息删除
void reader_information_entry();        //读者信息录入
void reader_information_modify();       //读者信息修改
void reader_information_delete();       //读者信息删除
void load_administratorlist();          //读入管理员列表
void load_readerlist();                 //读入读者列表
void load_booklist();                   //读入馆藏图书列表
void load_borrowedlist();               //读入出借图书列表
void save_administratorlist();          //写入管理员列表
void save_readerlist();                 //写入读者列表
void save_booklist();                   //写入书列表
void save_borrowedlist();               //写入出借图书列表


void display_booklist(){
  for(int i=0;i<booksum;i++){
   printf("number:%d name:%s totalnumber:%d\n\n",book_list[i].number,book_list[i].name,book_list[i].totalnumber);
  }
  printf("Press any key to continue!");
  getchar();
  getchar();
  system("cls");
  administratormenu();
}

void display_readerlist(){
  for(int i=0;i<readersum;i++){
   printf("number:%d name:%s the number of book borrowed:%d\n",reader_list[i].number,reader_list[i].name,reader_list[i].bookborrowedsum);
   if(reader_list[i].bookborrowedsum==0){
       printf("he/she didn't borrow any book.\n");
   }else{
     printf("the name of book he/she borrowed:\n");
     for(int j=0;j<reader_list[i].bookborrowedsum;j++){
     printf("%s\n",reader_list[i].bookborrowed[j]);
    }
   }
  printf("\n");
  }
  printf("Press any key to continue!");
  getchar();
  getchar();
  system("cls");
  administratormenu();
}

void display_myborrowed(char *reader){
  for(int i=0;i<readersum;i++){
   if(strcmp(reader_list[i].name,reader)==0){
    if(reader_list[i].bookborrowedsum==0){
     printf("You didn't borrow any book.\n");
    }else{
     printf("The books you borrowed:\n");
     for(int j=0;j<reader_list[i].bookborrowedsum;j++){
      printf("%s\n",reader_list[i].bookborrowed[j]);
     }
    }
   }
  }
  printf("Press any key to continue!");
  getchar();
  getchar();
  system("cls");
  readermenu();
}

void load_borrowedlist()
{
  for(int i=0;i<readersum;i++){
  reader_list[i].bookborrowedsum=0;
  for(int j=0;j<10;j++){
   strcpy(reader_list[i].bookborrowed[j],"\0");
  }
  }
  borrowedlist=fopen("borrowedlist.txt","r");
  char bookname[100];
  char readername[100];
  while(fscanf(borrowedlist,"%s%s\n",bookname,readername)!=EOF){
   for(int i=0;i<readersum;i++){
    if(strcmp(reader_list[i].name,readername)==0){
       strcpy(reader_list[i].bookborrowed[reader_list[i].bookborrowedsum],bookname);
       reader_list[i].bookborrowedsum++;
    }
   }
  }
  fclose(borrowedlist);
}



void load_administratorlist()
{
  administratorlist=fopen("administrator.txt","r");
  while(fscanf(administratorlist,"%d%s\n", &administrator_list[administratorsum].number,administrator_list[administratorsum].name)!=EOF){
    administratorsum++;
  }
  fclose(administratorlist);
}



void load_readerlist()
{
   readerlist=fopen("readerlist.txt","r");
   while(fscanf(readerlist,"%d%s\n",&reader_list[readersum].number,reader_list[readersum].name)!=EOF){
    readersum++;
   }
   fclose(readerlist);
}



void load_booklist()
{
  booklist=fopen("booklist.txt","r");
  while(fscanf(booklist,"%d%s%d\n",&book_list[booksum].number,book_list[booksum].name,&book_list[booksum].totalnumber)!=EOF){
   booksum++;
  }
  fclose(booklist);
}


void save_administratorlist()
{
  administratorlist=fopen("administrator.txt","w");
  for(int i=0;i<administratorsum;i++){
   fprintf(administratorlist,"%d %s\n",administrator_list[i].number,administrator_list[i].name);
  }
  fclose(administratorlist);
}



void save_readerlist()
{
  readerlist=fopen("readerlist.txt","w");
  for(int i=0;i<readersum;i++){
   fprintf(readerlist,"%d %s\n",reader_list[i].number,reader_list[i].name);
  }
  fclose(readerlist);
}



void save_booklist()
{
  booklist=fopen("booklist.txt","w");
  for(int i=0;i<booksum;i++){
   fprintf(booklist,"%d %s %d\n",book_list[i].number,book_list[i].name,book_list[i].totalnumber);
  }
  fclose(booklist);
}



void save_borrowedlist()
{
  borrowedlist=fopen("borrowedlist.txt","w");
  for(int i=0;i<readersum;i++){
   for(int j=0;j<reader_list[i].bookborrowedsum;j++){
    fprintf(borrowedlist,"%s %s\n",reader_list[i].bookborrowed[j],reader_list[i].name);
   }
  }
  fclose(borrowedlist);
}



void book_borrow(char *reader){
  char bookwanttoborrow[100];
  printf("Please enter the name of the book you want to borrow!\n");
  scanf("%s",bookwanttoborrow);
  for(int i=0;i<readersum;i++){
   if(strcmp(reader_list[i].name,reader)==0){
    if(reader_list[i].bookborrowedsum==10){
     printf("You have borrowed more than 10 books!\n");
     return;
    }
    for(int j=0;j<reader_list[i].bookborrowedsum;j++){
     if(strcmp(reader_list[i].bookborrowed[j],bookwanttoborrow)==0){
      printf("Sorry,you have borrowed this book!\n");
      return;
     }
    }
   }
  }
  int iffind=0;
  for(int i=0;i<booksum;i++){
   if(strcmp(book_list[i].name,bookwanttoborrow)==0){
    iffind=1;
    if(book_list[i].totalnumber==0){
     printf("I'm sorry, this book has all been borrowed by others!\n");
    }else{
          book_list[i].totalnumber--;
          for(int j=0;j<readersum;j++){
           if(strcmp(reader_list[j].name,reader)==0){
            strcpy(reader_list[j].bookborrowed[reader_list[j].bookborrowedsum],bookwanttoborrow);
            reader_list[j].bookborrowedsum++;
           }
          }
         }
   }
  }
  if(iffind==0){
   printf("Sorry, this book is not in our collection!\n");
  }
}



void book_return(char *reader){
  char bookwantreturn[30];
  printf("Please enter the name of the book you want to return\n");
  scanf("%s",bookwantreturn);
  int iffind=0;
  for(int i=0;i<booksum;i++){
   if(strcmp(book_list[i].name,bookwantreturn)==0){
    iffind=1;
    book_list[i].totalnumber++;
    break;
   }
  }
  if(iffind==0){
   printf("Sorry,the book you want to return does not belong to this library!");
   return;
  }
  for(int i=0;i<readersum;i++){
   if(strcmp(reader_list[i].name,reader)==0){
    for(int j=0;j<reader_list[i].bookborrowedsum;j++){
     if(strcmp(reader_list[i].bookborrowed[j],bookwantreturn)==0){
      for(int k=j;k<reader_list[i].bookborrowedsum;k++){
       strcpy(reader_list[i].bookborrowed[k],reader_list[i].bookborrowed[k+1]);
      }
      reader_list[i].bookborrowedsum--;
     }
    }
   }
  }
}


void book_inquiry(){
 printf("Which way do you want to find books?\n");
 printf("  1.Enter the name to find the book.\n");
 printf("  2.Enter the book number to find the book\n");
 printf("Please enter the corresponding number to select the search method.\n");
 int waynumber;
 scanf("%d",&waynumber);
  if(waynumber==1){
   char bookinquiry1[100];
   printf("Please enter the name of the book you want to inquiry.\n");
   scanf("%s",bookinquiry1);
   int iffind1=0;
   for(int i=0;i<booksum;i++){
    if(strcmp(book_list[i].name,bookinquiry1)==0){
     iffind1=1;
     printf("The books you want to inquire about are now in the library:%d\n",book_list[i].totalnumber);
    }
   }
   if(iffind1==0){
    printf("I'm sorry,the book you are inquiring about is not find\n");
    return;
   }
   for(int i=0;i<readersum;i++){
    for(int j=0;j<reader_list[i].bookborrowedsum;j++){
     if(strcmp(reader_list[i].bookborrowed[j],bookinquiry1)==0){
      printf("%s borrowed the book\n",reader_list[i].name);
     }
    }
   }
  }else if(waynumber==2){
    int bookinquiry2;
    printf("Please enter the number of the book you want to inquiry\n");
    scanf("%d",&bookinquiry2);
    int iffind2=0;
    char bookinquiry2name[30];
    for(int i=0;i<booksum;i++){
    if(book_list[i].number==bookinquiry2){
    iffind2=1;
    strcpy(bookinquiry2name,book_list[i].name);
     printf("The books you want to inquire about are now in the library:%d.\n",book_list[i].totalnumber);
    }
   }
   if(iffind2==0){
    printf("I'm sorry,the book you are inquiring about is not find!\n");
    return;
   }
   for(int i=0;i<readersum;i++){
    for(int j=0;j<reader_list[i].bookborrowedsum;j++){
     if(strcmp(reader_list[i].bookborrowed[j],bookinquiry2name)==0){
      printf("%s borrowed the book.\n",reader_list[i].name);
     }
    }
   }
  }else{
    printf("Input error.Please enter again!\n");
  }
}



void book_information_entry(){
 printf("Please enter the book information in the format of 'number+name+totalnumber'\n");
 int booknumber;
 char bookname[100];
 int booktotalnumber;
 scanf("%d %s %d",&booknumber,bookname,&booktotalnumber);
 for(int i=0;i<booksum;i++){
  if(strcmp(book_list[i].name,bookname)==0||book_list[i].number==booknumber){
   printf("This book already exists!\n");
   return;
  }
 }
 book_list[booksum].number=booknumber;
 strcpy(book_list[booksum].name,bookname);
 book_list[booksum].totalnumber=booktotalnumber;
 booksum++;
}



void book_information_modify(){
  printf("Please enter the number of the book you want to modify\n");
  int bookmodifynumber;
  scanf("%d",&bookmodifynumber);
  int iffind=0;
  for(int i=0;i<booksum;i++){
   if(book_list[i].number==bookmodifynumber){
    iffind=1;
    printf("Please enter the modified totalnumber'\n");
    printf("number:%d name:%s totalnumber:",book_list[i].number,book_list[i].name);
    scanf("%d",&book_list[i].totalnumber);
   }
  }
  if(iffind==0){
   printf("Sorry,We can't find the number of the book you want to modify!\n");
  }
}



void book_information_delete(){
  printf("Please enter the number of the book you want to delete.\n");
  int bookdeletenumber;
  scanf("%d",&bookdeletenumber);
  int iffind=0,isdeleted=0;
  for(int i=0;i<booksum;i++){
   if(book_list[i].number==bookdeletenumber){
    printf("The name of the book you want to delete:%s.\n",book_list[i].name);
    iffind=1;
    for(int j=0;j<readersum;j++){
     if(isdeleted==1){
      break;
     }
     for(int k=0;k<reader_list[j].bookborrowedsum;k++){
      if(strcmp(reader_list[j].bookborrowed[k],book_list[i].name)==0){
       printf("The book cannot be deleted because the reader has not returned all of it!\n");
       isdeleted=1;
       break;
      }
     }
    }
   if(isdeleted==0){
   for(int j=i;j<booksum;j++){
    book_list[j]=book_list[j+1];
   }
   booksum--;
   }
  }
 }
 if(iffind==0){
  printf("Sorry,We can't find the number of the book you want to delete!\n");
 }
}



void reader_information_entry(){
     int readernumber;
     char readername[100];
     printf("Please enter the reader information in the format of 'number+name'\n");
     scanf("%d %s",&readernumber,readername);
     for(int i=0;i<readersum;i++){
         if(reader_list[i].number==readernumber||strcmp(reader_list[i].name,readername)==0){
            printf("This reader already exists!\n");
            return;
         }
     }
     reader_list[readersum].number=readernumber;
     strcpy(reader_list[readersum].name,readername);
     reader_list[readersum].bookborrowedsum=0;
     readersum++;
}


void reader_information_modify(){
  printf("Please enter the number of the reader you want to modify!\n");
  int readermodifynumber;
  scanf("%d",&readermodifynumber);
  for(int i=0;i<readersum;i++){
   if(reader_list[i].number==readermodifynumber){
    printf("the name of the reader you want to modify:%s.\n",reader_list[i].name);
    printf("Please enter the number of book this reader borrowed!\n");
    scanf("%d",&reader_list[i].bookborrowedsum);
    printf("please enter the name of the book he/she borrowed!\n");
    for(int j=0;j<reader_list[i].bookborrowedsum;j++){
     char bookwanttomodify[100];
     scanf("%s",bookwanttomodify);
     int isincollection=0;
     for(int k=0;k<booksum;k++){
      if(strcmp(book_list[k].name,bookwanttomodify)==0){
       isincollection=1;
       break;
      }
     }
     if(isincollection==1){
      strcpy(reader_list[i].bookborrowed[j],bookwanttomodify);
     }else{
         printf("This book is not in our collection!Please enter again!\n");
         j--;
     }
    }
   }
  }
 }



void reader_information_delete(){
  printf("Please enter the number of the reader you want to delete\n");
  int readerdeletenumber;
  scanf("%d",&readerdeletenumber);
  int iffind=0;
  for(int i=0;i<readersum;i++){
   if(reader_list[i].number==readerdeletenumber){
    iffind=1;
    if(reader_list[i].bookborrowedsum>0){
     printf("The reader still has books to return,you cannot delete it!\n");
     break;
    }
    printf("The name of the reader you want to delete:%s\n",reader_list[i].name);
    for(int j=i;j<readersum;j++){
     reader_list[j]=reader_list[j+1];
    }
    readersum--;
   }
  }
  if(iffind==0){
   printf("Sorry,We can't find the number of the reader you want to delete!\n");
  }
}





int main(int argc,char **argv){

    //开始前导入用户,读者,馆藏书目,出借书目对应txt文件的信息
    load_administratorlist();
    load_readerlist();
    load_booklist();
    load_borrowedlist();
    printf("Data is successfully loaded!\n\n");

    if(strcmp(argv[1],"-a")==0){
       int isfind1=0;
       for(int i=0;i<administratorsum;i++){
           if(strcmp(argv[2],administrator_list[i].name)==0){
              isfind1=1;
              break;
           }
       }
       if(isfind1==0){
          printf("You are not an administrator, please login again!");
          return 0;
       }
       //检验密码是否正确
       printf("Please enter the corresponding administrator number!\n");
       int inputadministratornumber;
       scanf("%d",&inputadministratornumber);
       for(int i=0;i<administratorsum;i++){
           if(strcmp(argv[2],administrator_list[i].name)==0){
              if(inputadministratornumber!=administrator_list[i].number){
                  printf("Password mistake!");
                  return 0;
              }
              break;
           }
       }
       administratormenu();
       printf("\n");
       while(1){
            scanf("%d",&choice);
            if(choice==0){
               break;
            }
           switch (choice)
          {
              case(1):
                     book_information_entry();
                     break;
              case(2):
                     reader_information_entry();
                     break;
              case(3):
                     book_information_modify();
                     break;
              case(4):
                     reader_information_modify();
                     break;
              case(5):
                     book_information_delete();
                     break;
              case(6):
                     reader_information_delete();
                     break;
              case(7):
                     book_inquiry();
                     break;
              case(8):
                     display_booklist();
                     break;
              case(9):
                     display_readerlist();
                     break;
              default:
                     printf("You have entered the wrong information!\n");
            }
        }

        save_administratorlist();
        save_readerlist();
        save_booklist();
        save_borrowedlist();

    }else if(strcmp(argv[1],"-u")==0){
       int isfind2=0;
       for(int i=0;i<readersum;i++){
           if(strcmp(argv[2],reader_list[i].name)==0){
              isfind2=1;
              break;
           }
       }
       if(isfind2==0){
          printf("You are not an reader, please login again!");
          return 0;
       }
       printf("Please enter the corresponding administrator number!\n");
       int inputreadernumber;
       scanf("%d",&inputreadernumber);
       for(int i=0;i<readersum;i++){
           if(strcmp(argv[2],reader_list[i].name)==0){
              if(inputreadernumber!=reader_list[i].number){
                  printf("Password mistake!");
                  return 0;
              }
              break;
           }
       }
       readermenu();
       printf("\n");
       while(1){
           scanf("%d",&choice);
           if(choice==0){
               break;
            }
           switch (choice)
          {
              case(1):
                     book_borrow(argv[2]);
                     break;
              case(2):
                     book_return(argv[2]);
                     break;
              case(3):
                     book_inquiry();
                     break;
              case(4):
                     display_myborrowed(argv[2]);
                     break;
              default:
                 printf("You have entered the wrong information!\n");
           }
        }

        save_administratorlist();
        save_readerlist();
        save_booklist();
        save_borrowedlist();

    }else{
        printf("You entered the wrong parameter!\n");
    }
    return 0;
}
