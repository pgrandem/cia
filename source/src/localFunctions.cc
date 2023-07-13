/// localFunctions.cc
/// ************************************************************************ ///
/// local functions : concurrency in action, 2nd edition
/// Pierre GRANDEMANGE
/// 09/07/2023
/// ************************************************************************ ///

#include "localFunctions.h"
using namespace std;




/// cia - chapter 02
/// ****************************************************************************
void ch02_main()
{
	ch02_part02();
	//ch02_part01();
}

void ch02_part02()
{
	/// do some work
	oops();
}
void oops()
{
	int localstate{0};
	func myfunc(localstate);
	thread th(myfunc);
	try
	//th.detach();
	th.join();
}

void ch02_part01()
{
	/// calling a simple function, no parameters
	/// ----------------------------------------
	thread th00(dosomework);
	
	/// calling class with function call operator
	/// -----------------------------------------
	background_task f;
	thread th01(f);				/// this starts a thread, whereas...
	
	//thread th02(background_task()); 		
	/// ... this is a function returning a thread,
	/// and taking a pointer to a function returning a background_task
	
	thread th03((background_task())); 
	/// extra parenthesis prevent interpretation as function declaration

	thread th04{background_task()}; /// uniform initialisation syntax

	/// thred calls a lambda function
	/// -----------------------------
	thread th05([]{
		//dosomething();
		//dosomethingelse();
	});
}
void dosomework()
{
	/// do some work
}




/// cia - chapter 01
/// ****************************************************************************
/// hirep
/// ----------------------------------------------------------------------------
void hirep()
{
	cout << "hi rep" << endl;
}
void hirep_main()
{
	thread t(hirep);
	t.join();
}

