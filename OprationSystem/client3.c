#include "Complex.h"



int main(int argc ,char * argv[]){

    argument data ;
    complexe res;

    data.img1=atoi(argv[1]);
    data.reel1=atoi(argv[2]);
    data.img2=atoi(argv[3]);
    data.reel2=atoi(argv[4]);
    callrpc(argv[5], 1,1,1,somme, (char*)&data,  (xdrproc_t)xdr_argument ,(char*) &res);
    printf("( %d + i %d)  \n ", res.img,res.reel );

}

