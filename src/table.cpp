#include "table.h"
#include <iostream>


HTable::HTable(const int &max, int (*hachage)(HTable *, key_T))
{
	m_maxLenght = max;
	m_hachage = hachage;
	m_tab = new Etudiant*[m_maxLenght];
	for(int i = 0; i< m_maxLenght; i++)
	{
		m_tab[i] = nullptr;
	}
}

HTable::~HTable()
{
	delete m_tab;
}

key_T HTable::genIndice(const key_T & key)
{
	int r = (int)(((key* 0.6125423371)-(int)(key* 0.6125423371))*m_maxLenght);
	//std::cout<<"key : "<<key<< " indice gen : "<<r<<"\n";
	return r;
}

void HTable::remove(const key_T & key) //getIndice(elem) -> delete(indice)
{
	int ind = genIndice(key);
	if(m_tab[ind] != nullptr)
	{
		delete m_tab[ind];
		m_tab[ind] = nullptr;
	}
	//std::cout<<" Deleted at : "<<ind<<"\n"; 
}

void HTable::remove(const int & key)
{
	if(key<0 || key >m_maxLenght)
	{
		throw "error 1 : index out of range, maybe not remove(int) but remove(key_T) ? " ;
	}
	else
	{
		if(m_tab[key] != nullptr)
		{
			delete m_tab[key];
			m_tab[key] = nullptr;
		}
		//std::cout<<" Deleted at : "<<key<<"\n"; 
	}
}

int HTable::getIndice(const key_T & key) // getIndice(elem)
{
	return m_hachage(this, key);
}

void HTable::insert(const key_T & key, Etudiant* elem)
{
	int ind = m_hachage(this, key); 
	if(ind >= 0 )
	{
		if(m_tab[ind] != nullptr) // /!\ override memory loose
		{
			delete m_tab[ind];
		}
		m_tab[ind] = elem;
		//std::cout<<" Inserted : "<<key<<" at : "<<ind<<"\n"; 
	}
}

void HTable::insert(Etudiant* elem)
{
	int ind = m_hachage(this, elem->getClef()); 
	if(ind >= 0)
	{
		if(m_tab[ind] != nullptr ) // /!\ override memory loose
		{
			Etudiant* temp = m_tab[ind];
			m_tab[ind] = elem;
/*			delete temp;*/
		}
		m_tab[ind] = elem;
		//std::cout<<" Inserted : "<<elem->getClef()<<" at : "<<ind<<"\n"; ; 
	}
}

void HTable::affiche()
{
	for (int i = 0; i<= m_maxLenght; i++)
	{
		if (m_tab[i] != nullptr)
		{
			std::cout<<"at : "<<i << "  val : "<<m_tab[i]->getInfo()<<"\n";
		}
	}
}

int HTable::getMaxlenght()
{
	return m_maxLenght;
}

Etudiant* HTable::getElement(int i)
{
	return m_tab[i];
}
