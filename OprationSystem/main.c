//
//  main.c
//  OprationSystem
//
//  Created by xxx on 12/16/18.
//  Copyright © 2018 xxx. All rights reserved.
//

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
                                                  xdr_int(p, &x->img2) && xdr_int(p, &x->reel2)
                                                  );
}

// La procedure RPC
static complexe i;
complexe *somme (argument *x)
{ i.img= x->img1 + x->img2;
    i.reel= x->reel1 + x->reel2;
    return &i;}



complexe* mul (argument* x){
    static complexe res;
    
    
    res.reel= (x->reel1 * x->reel2)- (x->img1 * x->img2);
    res.img=(x->reel1 * x->img2)+(x->img1 * x->reel2);
    return &res;
    
}


/* Les numeros */
#define NUM_PROG 0x22222222 /*  numero de programme */
#define  NUM_VERSION_1 1 /* le numero de version ici 1 */
#define NUM_SOMME 1 /* numero de la procedure somme */
int registerrpc(unsigned long prognum, unsigned long versnum,
                unsigned long procnum, char *(*procname)(char *),
                xdrproc_t inproc, xdrproc_t outproc);



int main ()
{
    
    /* enregistrement du service aupres du rpcbind*/
    if (registerrpc(1,1,1, somme, xdr_complexe, xdr_complexe) ==-1)
    {perror(" Probleme enregistrement du service somme "); exit(1); }
    
    printf("Attente de client \n");
    
    svc_run();
    
    printf(" Sortie du service \n");
    return 0;
    
}
