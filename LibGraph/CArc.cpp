#include "CArc.h"

CArc::CArc(unsigned int uiNumD, unsigned int uiNumA)
{
	uiARCNumeroSommetD = uiNumD;
	uiARCNumeroSommetA = uiNumA;
}

CArc::~CArc()
{
	uiARCNumeroSommetD = 0;
	uiARCNumeroSommetA = 0;
	delete CArc(uiARCNumeroSommetD, uiARCNumeroSommetA);
}

unsigned int CArc::ARCGetNumeroD()
{
	return uiARCNumeroSommetD;
}

void CArc::ARCSetNumeroD(unsigned int uiNum) 
{
	uiARCNumeroSommetD = uiNum;
}

unsigned int CArc::ARCGetNumeroA() 
{
	return uiARCNumeroSommetA;
}

void CArc::ARCSetNumeroA(unsigned int uiNum)
{
	uiARCNumeroSommetA = uiNum;
}

CArc* CArc::ARCInverseArc()
{
	return new CArc(uiARCNumeroSommetA, uiARCNumeroSommetD);
}