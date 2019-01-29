#ifndef _PerfTest
#define _PerfTest

#include <chrono>
#include <iostream>
#include <string>

typedef std::chrono::high_resolution_clock::time_point TimeVar;
#define duration(a) std::chrono::duration_cast<std::chrono::nanoseconds>(a).count()
#define timeNow() std::chrono::high_resolution_clock::now()

class PerfTest
{
	public :

		PerfTest();
		~PerfTest();
		// /!\ only use functions as parameter !!!  /!\ //
		template <typename T> int testTime(T data); 
		// ********************************************//

		void saveResult(std::string stringParam);
		void clearResults();
		void showResults();
		void showGNuplot();
};

template <typename T> 
int PerfTest::testTime(T data)
{
	int r;
	TimeVar t1=timeNow();
	data();
	r=duration(timeNow()-t1);
	//std::cout<<"DURATION : "<<r<<"\n\n";
	return r;
}

#endif