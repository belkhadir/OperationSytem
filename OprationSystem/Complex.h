//
//  Complex.h
//  OprationSystem
//
//  Created by xxx on 12/17/18.
//  Copyright © 2018 xxx. All rights reserved.
//

#ifndef Complex_h
#define Complex_h

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


bool_t xdr_complexe(XDR *p,complexe *x);
bool_t xdr_argument(XDR *p,argument *x);
#endif /* Complex_h */
