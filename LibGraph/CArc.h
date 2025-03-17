#pragma once

#ifndef CARC_H
#define CARC_H

class CArc
{
private:
	unsigned int uiARCNumeroSommetD;
	unsigned int uiARCNumeroSommetA;

public:
	//Constructeur et destructeur
	CArc(unsigned int uiNumD, unsigned int uiNumA);
	~CArc();

	//Accesseur pour uiARCNumeroSommetD
	unsigned int ARCGetNumeroD();
	void ARCSetNumeroD(unsigned int uiNum);
	//Accesseur pour uiARCNumeroSommetA
	unsigned int ARCGetNumeroA();
	void ARCSetNumeroA(unsigned int uiNum);

	CArc* CARCArcInverse();
};


#endif