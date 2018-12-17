#include <stdio.h>
#include <rpc/types.h>
#include <rpc/xdr.h>
#include <rpc/rpc.h>

 typedef struct complexe { 
	int img;
  int reel ; 
} complexe;
 
typedef struct argument { 
	int img1;int img2;
  int reel1,reel2 ; 
} argument;
 
// Le filtre xdr
  bool_t xdr_complexe(XDR *p,complexe *x){ return  (xdr_int(p, &x->img) && xdr_int(p, &x->reel) );
  }
 bool_t xdr_argument(XDR *p,argument *x){ return  (xdr_int(p, &x->img1) && xdr_int(p, &x->reel1) &&  
xdr_int(p, &x->img2) && xdr_int(p, &x->reel2) );
  }
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

