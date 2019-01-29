#ifndef _HTable
#define _HTable

#include "Etudiant.h"
#include <iostream>

typedef unsigned int key_T;

class HTable
{
	public :
		HTable(const int &, int (*m_hachage)(HTable* , key_T ) );	
		~HTable();
		
		key_T

		genIndice(const key_T &); // genIndice from methode
		
		void remove(const key_T &); //getIndice(key_T) -> delete(indice)
		void remove(const int &);
		
		int getIndice(const key_T &); // genIndice(key_T)
		void insert(const key_T &,  Etudiant*); // genIndice()-> if collide use hachage else insert
		void insert(Etudiant*);

		void affiche(); //affiche key notnull + nb try before insert
		
		int getMaxlenght();
		Etudiant* getElement(int);

		
	private :
		Etudiant** m_tab; // hachage table 
		int m_maxLenght; //lenght max of table + get set
		int (*m_hachage)(HTable* ,key_T); //return indice where already exist <= 0 or where must be incerted = -1
};


#endif
