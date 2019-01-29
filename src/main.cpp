// LIFAP6 - Automne 2017 - R. Chaine
#include "table.h"
#include "ReHachage.h"
#include "PerfTest.h"
#include <iostream>
#include <functional>
#include <exception>
#include <stdlib.h>

void function1( const char * a)
{
	std::cout<<"WORKING : "<<a<<"\n";
}

int function2(int n1, const char * a)
{
    std::cout<<"WORKING : " << n1  << '\n';
    for(int i = 0; i < n1; i++)
    {

    }
    return n1;
}
 

int main()
{
	{
	/*---------------------------- CREATE BASE HTAB ---------------------------------------------*/	
		std::cout<<"<---------- BEGIN ---------> \n";
		Etudiant* el1 = new Etudiant(1080, 1);
		Etudiant* el2 = new Etudiant(24645, 2);
		Etudiant* el3 = new Etudiant(10023, 3);
		Etudiant* el4 = new Etudiant(166574, 4);
		Etudiant* el5 = new Etudiant(1081, 5);


		std::cout<<"Create HTable : 10, Hlinear\n";
		HTable * tab1 = new HTable(10, &Hlinear);
		std::cout<<"Insert 5 elem {1, 2, 3, 4, 5 }\n";

		tab1->insert(el1);
		tab1->insert(el2);
		tab1->insert(el3);
		tab1->insert(el4);
		tab1->insert(1081, el5);
		std::cout<<"Inserted\n";
		tab1->affiche();
	/*------------------------------- TEST COLLISION ------------------------------------------*/
		std::cout<<"\n\n"<<"Test collision : key = 50 = tab[6], val = 20"<<"\n";
		Etudiant* el6 = new Etudiant(50, 20);
		tab1->insert(el6);
		tab1->affiche();
	/*-------------------------------- TEST OVERRIDE -----------------------------------------*/
		std::cout<<"\n\n"<<"Test Override : key = 50, val = 6"<<"\n";
		Etudiant* el7 = new Etudiant(50, 6);
		Etudiant* e100 = new Etudiant(50, 6);
		Etudiant* e101 = new Etudiant(50, 53);
		tab1->insert(el7);
		tab1->insert(e100);
		tab1->insert(e101);
		tab1->affiche();
	/*----------------------------- TEST IS FULL --------------------------------------------*/
		std::cout<<"\n\n"<<"Test Htab full "<<"\n";
		//make full
		Etudiant* el8 = new Etudiant(2121, 8);
		Etudiant* el9 = new Etudiant(74, 9);
		Etudiant* el10 = new Etudiant(231, 10);
		Etudiant* el11 = new Etudiant(5353, 11);
		tab1->insert(el8);
		tab1->insert(el9);
		tab1->insert(el10);
		tab1->insert(el11);
		std::cout<<"\n\n"<<"Htab full : "<<"\n";
		tab1->affiche();
		// en make full

		//test full
		Etudiant* el12 = new Etudiant(63, 555);
		try 
		{
			tab1->insert(el12);
		} catch (const char* e)
		{ 
			std::cerr <<"\n ------------------------------------\n"<< "exception : \n" << e << "\n------------------------------------\n";
		}
		tab1->affiche();
	 /*-------------------------------------------------------------------------*/
		std::cout<<"\n\n"<<"Test remove(int) : 6 = delete tab[6], val = 4"<<"\n";
		tab1->remove(6);
		tab1->affiche();

		std::cout<<"\n\n"<<"Test remove(key_T ) : key = 2121 , val = 8"<<"\n";
		tab1->remove((key_T)2121);
		tab1->affiche();

		std::cout<<"\n\n"<<"Test remove(int) don't exist : 6 = delete tab[6], val = 4"<<"\n";
		tab1->remove(6);
		tab1->affiche();

		std::cout<<"\n\n"<<"Test remove(key_T ) don't exist : key = 2121 , val = 8"<<"\n";
		tab1->remove((key_T)2121);
		tab1->affiche();

		std::cout<<"\n\n"<<"Test remove(int) out of range : 50 = delete tab[50]"<<"\n";
		try 
		{
			tab1->remove(50);
		} catch (const char* e)
		{ 
			std::cerr <<"\n ------------------------------------\n"<< "exception : \n" << e << "\n------------------------------------\n";
		}
		tab1->affiche();
	}
/*------------------------------ TEST CLASS PERFTEST - FUNCTION TESTTIME(FUNCT*)-------------------------------------------*/
	/*	{
		    PerfTest * m_perfTester = new PerfTest();

		    char c[20] = "abababab";
		    auto f1 = std::bind(function1, c);
		    auto f2 = std::bind(function2, 99999999999999);

		    m_perfTester->testTime(f1);
		    m_perfTester->testTime(f2);

		    std::cout<<"SAVE RESULT  : qqqq"<<"\n";
		    m_perfTester->saveResult("qqq\n");
		    m_perfTester->showResults();
		    std::cout<<"CLEAR RESULTS  : "<<"\n";
			m_perfTester->clearResults();
			m_perfTester->showResults();
		}*/
/*-------------------------------------------------------------------------*/
	std::cout<<"BEGIN TESTS  : "<<"\n";
	PerfTest * m_perfTester = new PerfTest();
	m_perfTester->saveResult("# 'nb element' 'Temps'\n");

	m_perfTester->showResults();

	int NB_THachage = 100;
	int NB_ElemHTab = 100;

	HTable ** tab2 = new HTable* [NB_THachage];
	for (int i = 0; i < NB_THachage; i++)
	{
		tab2[i] = new HTable(NB_ElemHTab, &Hlinear);
	}


    //void (HTable::*fnc_ptr)(Etudiant*) = &HTable::insert; // selects int mf(int)

	for (int i = 0; i < NB_ElemHTab ; i++)
	{
		int moy = 0;
		for (int j = 0; j < NB_THachage; j++)
		{
			int v1 = rand() % 10000 +1;   
			int v2 = rand() % 10000 +1;
			Etudiant* el = new Etudiant(v1, v2);

			void (HTable::*func_test)(Etudiant *) = &HTable::insert;
			auto f = std::bind(func_test,tab2[j], el);

			moy += m_perfTester->testTime(f);
		}

		std::cout<<"moyenne : "<<moy/NB_THachage<<"\n\n";
	}

/*NB_HACHAGE //nombre de Htab
boucle iner élement aléa dans toutes les HTab et fare une moyenne du temps total
boucle seek eleme aléa dans touts les HTab et faire une moyenne

insert in file time tous les n insertions et n seek*/
	//PerfTest::Instance()->testTime();
	return 0;
}