
struct intpair 
{

	int a;
	int b;

};


program CALCULATION_PROG
{

	version CALCULATION_VERS
	{

	int ADDT(intpair) = 1;
	int SUBT(intpair) = 2;
	int MULTT(intpair) = 3;
	int DIVT(intpair) = 4;

	} = 1;

} = 0x2fffffff;
 
