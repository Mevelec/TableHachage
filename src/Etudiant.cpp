
#include "Etudiant.h"

#include <iostream>

Etudiant::Etudiant(int cl, int in)
{

	clef=cl;
	info=in;

}

Etudiant::Etudiant(const Etudiant & e)
{

	clef=e.clef;

	info=e.info;

}


unsigned int Etudiant::getClef()
{
	return clef;
}

int Etudiant::getInfo()
{
	return info;

}

Etudiant::~Etudiant()
{
	
}

