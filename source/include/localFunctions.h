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


/// ch02_05 identifying threads
/// ----------------------------------------------------------------------------
void ch02_05(); 
void ch02_05_dump_thread_id();

/// ch02_04 choosing the number of threads at runtime
/// ----------------------------------------------------------------------------
void ch02_04();

/// ch02_03 transferring owneership to a thread
/// ----------------------------------------------------------------------------
void ch02_03_01();
void ch02_03_some_other_function();
void ch02_03_some_function();



/// ch02_02 passing arguments to a thread function
/// ----------------------------------------------------------------------------
class xclass{
	public:
		void dump(int const & x)
		{ std::cout << "xclass dump: " << x << std::endl; }
};

void ch02_02_test_move();
void ch02_02_process_big_object(std::unique_ptr<xclass> upx);
void ch02_02_test_class_member_function();
void ch02_02_oops_again();
void ch02_02_update_data_for_widget(std::string & strtomodif);
void ch02_02_not_oops();
void ch02_02_01();
void ch02_02_oops();
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


