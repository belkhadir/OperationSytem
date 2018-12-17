#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct couple{
char* ch1;
char* ch2;
}couple;

char* concatener( couple* data){
int a=strlen(data->ch1);
int b=strlen(data->ch2);
char*chaine= NULL;
chaine=(char*)malloc((a+b+1)*sizeof(char));
if(chaine==NULL)
        {
                perror("erreur d'allocation");
                exit(0);
        }

strcpy(chaine,data->ch1);
int j=0;
for(j=0;j<=b;j++){
chaine[j+a]=data->ch2[j];

}
chaine[a+b]='\0';
return chaine;
}
int main(int argc,char*argv[]){
couple data;
data.ch1=argv[1];
data.ch2=argv[2];

char*ch3=concatener(&data);

printf("%s",ch3);
}
