/// localFunctions.h
/// ************************************************************************ ///
/// local functions : concurrency in action, 2nd edition
/// Pierre GRANDEMANGE
/// 09/07/2023
/// ************************************************************************ ///



/// includes
/// ****************************************************************************
/// standard library
#include <iostream>
#include <thread>
/// rep classes
/// rep namespaces



/// cia - chapter 02
/// ****************************************************************************
void ch02_main();

void ch02_part02();

struct func{
	int & _i;
	func(int & i) : _i(i) {}
	void operator()()
	{
		for(unsigned j=0; j<2000; j++) {
			///dosomething(_i);
			std::cout << _i++ << std::endl;
		}
	}
};
void oops();



void ch02_part01();
class background_task
{
	public:
		void operator()() const
		{
			/// dosomething();
			/// dosomethingelse();
		}
	
};
void dosomework();



/// cia - chapter 01
/// ****************************************************************************
/// hirep
/// ----------------------------------------------------------------------------
void hirep();
void hirep_main();

