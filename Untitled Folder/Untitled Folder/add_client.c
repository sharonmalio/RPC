

#include "add.h"


 


void calculation_prog_1(char *host)
{
	CLIENT *clnt;
	int  *result_1;
	intpair  add_1_arg;
	int  *result_2;
	intpair  sub_1_arg;
	int  *result_3;
	intpair  mult_1_arg;
	int  *result_4;
	intpair  div_1_arg;


	clnt = clnt_create (host, CALCULATION_PROG, CALCULATION_VERS, "udp");
	if (clnt == NULL) {
		clnt_pcreateerror (host);
		exit (1);
	}

	
	result_1 = add_1(&add_1_arg, clnt);
	if (result_1 == (int *) NULL) {
		clnt_perror (clnt, "call failed");
	}
	result_2 = sub_1(&sub_1_arg, clnt);
	if (result_2 == (int *) NULL) {
		clnt_perror (clnt, "call failed");
	}
	result_3 = mult_1(&mult_1_arg, clnt);
	if (result_3 == (int *) NULL) {
		clnt_perror (clnt, "call failed");
	}
	result_4 = div_1(&div_1_arg, clnt);
	if (result_4 == (int *) NULL) {
		clnt_perror (clnt, "call failed");
	}
#ifndef	DEBUG
	clnt_destroy (clnt);
#endif	 /* DEBUG */
}



CLIENT *rpc_setup(char *host) 
{ 
    CLIENT *clnt = clnt_create(host, CALCULATION_PROG, CALCULATION_VERS, "udp"); 
    if (clnt == NULL) { 
        clnt_pcreateerror(host); 
        return 0; 
    } 
    return clnt; 
} 
void add(CLIENT *clnt, int a, int b) 
{ 
    int  *result; 
    intpair v;   
    v.a = a; 
    v.b = b; 
    result = add_1(&v, clnt); 
    if (result == 0) 
	{ 
        clnt_perror(clnt, "call failed"); 
    	} 
    else 
	{ 
        printf(" The result is: %d\n", *result); 
    	} 

} 



