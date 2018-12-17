#include<rpc/xdr.h> 
typedef struct couple{
char*ch1;
char*ch2;
}couple;

int XDR_couple(XDR*p,couple*data);
