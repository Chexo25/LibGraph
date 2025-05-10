#include "CArc.h"

//CONSTRUCTEURS ET DESTRUCTEURS

CArc::CArc(unsigned int uiARCNumD, unsigned int uiARCNumA)
{
	uiARCNumeroSommetD = uiARCNumD;
	uiARCNumeroSommetA = uiARCNumA;
}

//GETTERS ET SETTERS

unsigned int CArc::ARCGetNumeroD()
{
	return uiARCNumeroSommetD;
}

void CArc::ARCSetNumeroD(unsigned int uiARCNum) 
{
	uiARCNumeroSommetD = uiARCNum;
}

unsigned int CArc::ARCGetNumeroA() 
{
	return uiARCNumeroSommetA;
}

void CArc::ARCSetNumeroA(unsigned int uiARCNum)
{
	uiARCNumeroSommetA = uiARCNum;
}

//METHODE(S)

CArc* CArc::ARCArcInverse()
{
	return new CArc(uiARCNumeroSommetA, uiARCNumeroSommetD);
}