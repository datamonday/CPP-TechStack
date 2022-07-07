#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

struct abc{
  int n;
  char w[21];
};

int main(void){
  struct abc wn[500], t;
  int i,j,k,x;
  FILE *fp;
  if((fp=fopen("test.txt","r")) == NULL){
    printf("Failed to open the input file...\n");
    exit(0);
  }
  // 为新申请的内存做初始化工作
  memset((char *)wn, '\0', sizeof(wn));
  i=j=0;
  while((wn[i].w[j]=getc(fp))!=EOF){
    if(isalpha(wn[i].w[j])) j++;
    else{
      wn[i].w[j] = '\0';
      for(k=0;k<i;k++){
        if(!strcmp(wn[i].w,wn[k].w)){
          wn[k].n++;
          break;
        }
        if(k>=i && j) wn[i++].n++;
        j=0;
      }
    }
  }
  fclose(fp);

  for(j=0;j<i;j++){
    for(x=j,k=j+1;k<i;k++)

    if(wn[x].n>wn[k].n) x=k;

    if(x!=j){
      t=wn[j];
      wn[j]=wn[x];
      wn[x]=t;
    }
  }
  if((fp=fopen("outtxt.txt","w")) == NULL){
    printf("Failed to open the output file...\n");
    exit(0);
  }
  for(i=0;i<j;i++){
    fprintf(fp,"%s\t%d\n",wn[i].w,wn[i].n);
    printf("%s\t%d\n",wn[i].w,wn[i].n);
  }
  fclose(fp);
}
