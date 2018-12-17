#include "chaine.h"
int main(int argc , char* argv[]){

char*ch3;
couple data;
data.ch1=argv[1];
data.ch2=argv[2];
callrpc(argv[3],1,1,1,XDR_couple,&data,xdr_wrapstring,ch3);
printf("%s",ch3);
}
