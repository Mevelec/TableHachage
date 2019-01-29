#include "PerfTest.h"
#include <fstream>


PerfTest::PerfTest()
{

}

PerfTest::~PerfTest()
{

}


void PerfTest::saveResult(std::string stringParam)
{
	std::ofstream file;
	file.open ("resultat.txt");
	file << stringParam;
	file.close();
}
void PerfTest::clearResults()
{
	std::ofstream file;
	file.open("resultat.txt", std::ofstream::out | std::ofstream::trunc);
	file.close();
}
void PerfTest::showResults()
{
	std::ifstream file("resultat.txt");

	if (file.is_open())
	{
		std::cout << file.rdbuf();
	}

}
void PerfTest::showGNuplot()
{

}

