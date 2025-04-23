#include "CArc.h"

CArc::CArc(unsigned int uiARCNumD, unsigned int uiARCNumA)
{
	uiARCNumeroSommetD = uiARCNumD;
	uiARCNumeroSommetA = uiARCNumA;
}

CArc::~CArc()
{
	/*uiARCNumeroSommetD = 0;
	uiARCNumeroSommetA = 0;*/ /// A voir si il y a besoin d'un destructeur
}

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

CArc* CArc::ARCArcInverse()
{
	return new CArc(uiARCNumeroSommetA, uiARCNumeroSommetD);
}