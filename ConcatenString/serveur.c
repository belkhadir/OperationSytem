#include "chaine.h"
#include<string.h>
#include<rpc/rpc.h>
#include<rpc/xdr.h> 

char** longueur( couple *data){

int a=strlen(data->ch1);
int b=strlen(data->ch2);
static char*chaine= NULL;
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
return &chaine;
}

int main(int argc ,char*argv[]){
registerrpc(1,1,1,longueur,XDR_couple,xdr_wrapstring);
svc_run();

}

