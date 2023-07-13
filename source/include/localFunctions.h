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
#include <string>
#include <thread>
/// rep classes
/// rep namespaces



/// cia - chapter 02
/// ****************************************************************************
void ch02_main();

/// ch02_02 passing arguments to a thread function
/// ----------------------------------------------------------------------------
void ch02_02();
void ch02_02_f00(int i, std::string const& s);


/// ch02_01 basic thread management
/// ----------------------------------------------------------------------------
void ch02_part02();
void edit_document(std::string const& filename);
void ch02_f01();
class thread_guard{
	std::thread & _t;
	public:
	explicit thread_guard(std::thread & t) : _t(t) {}
	~thread_guard()
	{
		if( _t.joinable() ) {
			_t.join();
		}
	}
	thread_guard( thread_guard const& ) = delete;
	thread_guard& operator=(thread_guard const& ) = delete;
};
void trycatch();
void oops();
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
void ch01_main();
void hirep();


