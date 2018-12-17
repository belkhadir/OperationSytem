//
//  Complex.c
//  OprationSystem
//
//  Created by xxx on 12/17/18.
//  Copyright © 2018 xxx. All rights reserved.
//

#include "Complex.h"

bool_t xdr_complexe(XDR *p,complexe *x){ return  (xdr_int(p, &x->img) && xdr_int(p, &x->reel) );
}

bool_t xdr_argument(XDR *p,argument *x){ return  (xdr_int(p, &x->img1) && xdr_int(p, &x->reel1) &&
                                                  xdr_int(p, &x->img2) && xdr_int(p, &x->reel2)
                                                  );
}
