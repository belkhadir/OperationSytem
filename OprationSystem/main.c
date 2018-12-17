//
//  main.c
//  OprationSystem
//
//  Created by xxx on 12/16/18.
//  Copyright © 2018 xxx. All rights reserved.
//

#include "Complex.h"

// Le filtre xdr


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
