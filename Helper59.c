#include"Header59.h"

ULONG Power(int iNo1,int iPower)
{
    register int iCnt=0;
    ULONG lMult=1;

    for(iCnt=1;iCnt<=iPower;iCnt++)
    {
        lMult=lMult*iNo1;
    }

    return lMult;


}

