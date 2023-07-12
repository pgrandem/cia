/// localFunctions.cc
/// ************************************************************************ ///
/// local functions 
/// Pierre GRANDEMANGE
/// 09/07/2023
/// ************************************************************************ ///

#include "localFunctions.h"
using namespace std;

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

/// rnn_cost_simple
/// ----------------------------------------------------------------------------
void rnn_cost_simple()
{
	/// you need a proper copy constructor for RNNFast
	vector<size_t> hlsi{};
	RNNFast<double> rnn01("copy1", 1, 1, hlsi);
	rnn01.dump();
	
	cout << endl << "after copy" << endl;
	RNNFast<double> rnn02 = rnn01;
	rnn02.setName("copy2");
	rnn02.dump();
}