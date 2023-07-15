/// localFunctions.cc
/// ************************************************************************ ///
/// local functions : concurrency in action, 2nd edition
/// Pierre GRANDEMANGE
/// 09/07/2023
/// ************************************************************************ ///

#include "localFunctions.h"




/// cia - chapter 02
/// ****************************************************************************
void ch02_main()
{
	ch02_05();
}


/// ch02_05 identifying threads
/// ----------------------------------------------------------------------------
void ch02_05()
{
	ch02_05_dump_thread_id();
	std::thread thr{ch02_05_dump_thread_id};
	thr.join();

}

void ch02_05_dump_thread_id()
{
	std::cout << std::this_thread::get_id() << std::endl;
}
	


/// ch02_04 choosing the number of threads at runtime
/// ----------------------------------------------------------------------------
void ch02_04()
{
	std::cout << std::endl << "std::thread::hardware_concurrency() = ";
	std::cout << std::thread::hardware_concurrency() << std::endl << std::endl;
}






/// ch02_03 transferring owneership to a thread
/// ----------------------------------------------------------------------------
void ch02_03_01()
{
	std::thread t01{ ch02_03_some_function };
	std::thread t02{ std::move(t01) };
	t01 = std::thread{ ch02_03_some_other_function };
	std::thread t03;
	t03 = std::move(t02);
	t01.join();
	t01 = std::move(t03);
	t01.join();
}

void ch02_03_some_other_function()	{ /* do some other stuff */ }
void ch02_03_some_function() 				{ /* do stuff */ }








/// ch02_02 passing arguments to a thread function
/// ----------------------------------------------------------------------------
void ch02_02_test_move()
{
	std::unique_ptr<xclass> upx{ new xclass };
	upx->dump(42);
	std::thread thr(ch02_02_process_big_object, std::move(upx));
	upx->dump(404);	/// isn't this line supposed to bug ?! it does not
	//thr.detach();
	thr.join();
}

void ch02_02_process_big_object(std::unique_ptr<xclass> upx)
{
	int arg{7};
	upx->dump( arg );
}
void ch02_02_test_class_member_function()
{
	int 					arg{ 9 };
	xclass*				obj{ new xclass };
	std::thread		thr{ & xclass::dump, obj, std::ref(arg) };
	thr.join();
}
void ch02_02_oops_again()
{
	std::string str{"initial string"};
	//std::thread thr{ch02_02_update_data_for_widget, str};
	std::thread thr{ch02_02_update_data_for_widget, std::ref(str)};
	thr.join();
	std::cout << str << std::endl;
}
void ch02_02_update_data_for_widget(std::string & strtomodif)
{
	strtomodif += "... multithreaded!";
}

void ch02_02_not_oops()
{
	char buffer[1024];
	sprintf(buffer, "%i", 24);
	std::thread t(ch02_02_f00, 3, std::string(buffer));
	t.detach();
}

void ch02_02_oops()
{
	char buffer[1024];
	sprintf(buffer, "%i", 24);
	std::thread t(ch02_02_f00, 3, buffer);
	t.detach();
}

void ch02_02_01()
{
	std::thread t(ch02_02_f00, 3, "la fête est finie");
	t.join();
}

void ch02_02_f00(int i, std::string const& s)
{
	for(size_t j=0; j<i; j++) { std::cout << s << std::endl; }
}




/// ch02_01 basic thread management
/// ----------------------------------------------------------------------------
void ch02_part02()
{
	edit_document("repfile");
	//ch02_f01();
	//trycatch();
	//oops();
}

void edit_document(std::string const& filename)
{
	/*open_document_and_display_guy(filename);
	while(!done_editing()) {
		user_command cmd=get_user_input();
		if(cmd.type==open_new_document) {
			std::string const new_name=get_filename_from_user();
			std::thread t(edit_document, new_name);
			t.detach();
		}
		else {
			process_user_input(cmd);
		}
	}*/
}

void ch02_f01()
{
	int localstate{0};
	func myfunc(localstate);
	std::thread th(myfunc);
	thread_guard tg(th);
	/// do something in current thread
}

void oops()
{
	int localstate{0};
	func myfunc(localstate);
	std::thread th(myfunc);
	th.detach();
	//th.join();
}

void trycatch()
{
	int localstate{0};
	func myfunc(localstate);
	std::thread th(myfunc);
	try {
		//dosomethingincurrentthread();
	}
	catch(...) {
		th.join();
		throw;
	}
	//th.detach();
	th.join();
}

void ch02_part01()
{
	/// calling a simple function, no parameters
	/// ----------------------------------------
	std::thread th00(dosomework);
	
	/// calling class with function call operator
	/// -----------------------------------------
	background_task f;
	std::thread th01(f);				/// this starts a thread, whereas...
	
	//thread th02(background_task()); 		
	/// ... this is a function returning a thread,
	/// and taking a pointer to a function returning a background_task
	
	std::thread th03((background_task())); 
	/// extra parenthesis prevent interpretation as function declaration

	std::thread th04{background_task()}; /// uniform initialisation syntax

	/// thred calls a lambda function
	/// -----------------------------
	std::thread th05([]{
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
void ch01_main()
{
	std::thread t(hirep);
	t.join();
}
void hirep()
{
	std::cout << "hi rep" << std::endl;
}

