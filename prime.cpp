#include <iostream>

// the following directive allows you to use the user-defined class called Timer
#include "timer.h"

using namespace std;

/*** Clarifying Commentsmer *******************************************************
* The below two lines are the function signatures of the algorithms that you are
* supposed to implement. The parameter array[] accepts an array as an argument
* (see prime in the main function).  Passing an array as an argument to a
* function passes a reference (actually pointer) to the original array and
* allows the function to modify the contents of the passed array; this is
* similar to how lists are handled when passing them as arguments to a
* function in Python.  For example if you pass in prime as an argument to
* sieveErat, and if you change the value array[4] inside of the sieveErat,
* function the change will be made to prime[4] since array is constant pointer
* to the first element in prime.
*
* parameter NUM is the number n you retrieved from the user
* parameter SIZE is the size of the array.
*
* Note: both algorithms fill an array with all the found prime values. Since the
* array[] parameter modifies the original passed argument you can use it to
* store your found values into the prime array
*
* Note: the Trial Division algorithm will require you to find the square root of
* a value.  The C++ function that computes the square root of a number is sqrt()
* look up the sqrt function and the library that should be included in the C++
* reference at http://en.cppreference.com/w/
*
*******************************************************************************/
void trialDivision(int array[], const int NUM, const int SIZE);
void sieveErat(int array[], const int NUM, const int SIZE);

int main() {

  int *prime;     // a pointer that will be used to create an array at run time
  int size = 0;   // variable that would be used to set the size of the array
	Timer myTimer;  // a Timer class object that you will use to time your algorithms


  /*** Your Code *********************************************
  * place your code that asks for user input here.  you are
  * going to need this value to set the size of prime array
  * as well as the number n and selected algorithm
  *
  * Note: when setting the variable size, it should be
  * at least twice the value of the number n you received
  * from the user
  ***********************************************************/




  /*** Clarifying Comments *****************************************************
  * the following statement creates an array using dynamic memory allocation.
  * IT IS NOT NECESSARY FOR YOU TO KNOW EITHER POINTERS OR HOW TO CREATE AN
  * ARRAY USING DYNAMIC MEMORY ALLOCATION TO COMPLETE THIS ASSIGNMENT.  The
  * array created is named "prime" and its capcity is set to the value of the
  * size variable.  Make sure the value, received by the user, that is assigned
  * to size is a non-zero value.
  *
  * Note: regardless of how it is created, prime is an array and can be used like
  * a regular array, that is, you can assign values to prime using an index,
  * for example:
  *
  *      prime[3] = 7;
  *
  * and you can also read from the array using an index:
  *
  *      cout << prime[3];
  *      prime[2] = prime[1] + prime[0]
  *      cout << prime[2];
  *****************************************************************************/
  prime = new int[size];




  /*** Your Code *********************************************
  * place your code that times the execution of the algorithms
  * implemented by trialDivision() and sieveErat()
  ***********************************************************/




  /*** Clarifying Comments *****************************************************
  * for all things created using dynamic memory, you should also free up the
  * that memory when done using it (see the following statement).
  *****************************************************************************/
  delete [] prime;


  return 0;
}


/*** Your Code *****************************************************************
* Here is where you can define the functions that implement the Trial Division
* and Sieve of Eratosthenes algorithms.  You may choose to give the signatures
* above main() bodies, or leave the signatures in place and define the functions
* here.
*******************************************************************************/
