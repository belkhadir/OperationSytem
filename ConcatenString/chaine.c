#include "chaine.h"

int XDR_couple(XDR*p,couple*data){
  	return(xdr_wrapstring(p,&data->ch1)
	 && xdr_wrapstring(p,&data->ch2));
}
