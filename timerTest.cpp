#include "timer.h"
#include <iostream>
#include <iomanip>
#include <cstdlib>

using namespace std;

int main()
{
	Timer myTimer;

	cout << "How long does it take to print 10 thousand numbers?" << endl;
	myTimer.Start();

	for (int i=0; i<10000; i++)
		cout << i << "  ";
	myTimer.Stop();

	cout << endl << endl;
	cout << "That took " << myTimer.Clocks() << " clock ticks. " << endl;
	cout << "That took " << setprecision(10) << myTimer.Seconds() << " seconds. " << endl;

	system("pause");
	return EXIT_SUCCESS;
}