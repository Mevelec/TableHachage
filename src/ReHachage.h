#ifndef _ReHachage
#define _ReHachage

#include <iostream>

int Hlinear(HTable* Htab, key_T key)
{
	int ind = Htab->genIndice(key);
	bool returnBool = false;
	int i = 0;
	while(i < Htab->getMaxlenght() && returnBool == false)
	{
		if(Htab->getElement(ind) != nullptr && Htab->getElement(ind)->getClef() != key)
		{
			//std::cout<<" id : "<<i<<" already used : "<<ind<<"  "<<Htab->getElement(ind)<<"\n";
			//std::cout<< "boon " << ind<<"   " << Htab->getMaxlenght()<<"        "<<(ind++ >= Htab->getMaxlenght())<<"\n";
			ind++;
			if(ind >= Htab->getMaxlenght())
			{
				//std::cout<<" restart :"<<ind<<"\n"; 
				ind = 0;
			}
		}
		else
		{
			//std::cout<<" id : "<<i<<" not used : "<<ind<<"  " <<Htab->getElement(ind)<<"\n";
			returnBool = true;
		}
		i++;
	}
	if(!returnBool)
	{
		throw "error -1 : This entry don't exist and Htab is full" ;
	}
	return ind;
}


/*

int Hquadratique(HTable* Htab, key_T key)
{

}
int HdoubleHachage(HTable* Htab, key_T key)
{

}
*/

#endif