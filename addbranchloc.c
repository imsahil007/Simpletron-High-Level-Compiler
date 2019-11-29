#include "header.h"
void addbranchloc(int *SML,int *flag,int branch_loc)
{
	*SML = (*SML) /SIZE;			
	*SML = (*SML) * (SIZE) + branch_loc;
	*flag = -1;
}
