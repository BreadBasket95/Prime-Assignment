#include <iostream>
#include <cmath>
#include <iomanip>
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
* parameter num is the number n you retrieved from the user
* parameter SIZE is the size of the array.
*
* Note: both algorithms fill an array with all the found prime values. Since the
* array[] parameter modifies the original passed argument you can use it to
* store your found values into the prime array
*
* Note: the Trial Division algorithm will require you to find the square root of
* a value.  The C++ function that computes the square root of a SIZEber is sqrt()
* look up the sqrt function and the library that should be included in the C++
* reference at http://en.cppreference.com/w/
*
*******************************************************************************/
void trialDivision(int array[], const int SIZE, char print);
void sieveErat(int array[], const int SIZE, char print);
bool primecheck(int temp);

int main() {

  char print;     // variable to recieve the user's decision to print the primes or not
  char algorithm; // variable to recieve the user's choice of algorithm
  int *prime;     // a pointer that will be used to create an array at run time
  int size = 0;   // variable that would be used to set the size of the array
	Timer myTimer;  // a Timer class object that you will use to time your algorithms


  do
  {
    cout << "Enter the desired non-zero integer, n, to find all primes less than n\n";
    cin >> size;
  }
  while(size == 0);

  prime = new int[size]; // initializing the size of the Prime array

  for(int count = 0; count < size; count ++) // loop to populate the the prime array
  {
      prime[count] = 0;
  }
  do
  {
    cout << "Do you want the prime numbers to be printed? Type y or n\n";
    cin >> print;
  }
  while((print != 'y')&&(print != 'n'));

  do
  {
    cout << "Which algorithm do you wish to use? Type s for Sieve of Eratosthenes or t for Trial Division\n";
    cin >> algorithm;
  }
  while((algorithm != 's')&&(algorithm != 't'));

  switch (algorithm)
  {
    case 't':
    trialDivision(prime, size, print);
    break;
    case 's':
    sieveErat(prime, size, print);
    break;
  };

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
void primeprint(int array[])
{
  cout << "Printing Primes: \n";
    for(int count = 0; array[count] != 0; count++)
      cout << array[count] << endl;
}

bool primecheck(int temp) // function to check each number for its possible factors, from 2 to the square root of the number
{
  for(int count = 2; count <= (sqrt(temp)); count++)
  {
    if((temp%count) == 0)
      return false;
  };
  return true;
}

void trialDivision(int array[], const int SIZE, char PRINT)
{
Timer myTimer;

myTimer.Start(); // Starting the timer before the algorithm runs
for(int count = 2, prime_count = 0; count <= SIZE; count++) // The outer loop for the trial division algorithm. This will n-1 times
{
  if(primecheck(count)) // This function is called once for every number we're checking. If the number has a factor besides 1, it is skipped
  {
    array[prime_count] = count; // If the number being tested is prime, it is stored in the prime array
    prime_count++; // A counter to keep track of every prime we find through trial division
  }
}
myTimer.Stop();
cout << "That took " << myTimer.Clocks() << " clock ticks. " << endl;
cout << "That took " << setprecision(10) << myTimer.Seconds() << " seconds. " << endl;

if(PRINT == 'y') // calling the prime-printing function if the user asks it to.
  primeprint(array);
}






void sieveErat(int array[], const int SIZE, char PRINT)
{
  Timer myTimer;

  int n_array[SIZE]; // creating a temporary array to work with
  for(int count = 0; count < SIZE; count++) // initializing the temporary array with consecutive numbers up to n
  {
    n_array[count] = (count+1);
  }
  myTimer.Start();
  for(int count = 2; count <= sqrt(SIZE); count++) // the ou2ter loop that iterates through every number of n that is less than the square root of n
  {
    if(n_array[(count-1)] != 0) // this loop checks each element of the temporary array to see if it is zero. Composite elements are changed to zero in this implementation
    {
      for(int temp = 2 ; (temp*count) <= SIZE; temp++)   ///// This implementation marks every composite number of the temporary array as 0
      {                                                  ///// Once the prime check is complete, the only non-zero integers in the temporary
        n_array[((temp*count)-1)] = 0;                   ///// array are prime. The original array is then populated with the non-zero integers
      }
    }
  }
  myTimer.Stop();
  cout << "That took " << myTimer.Clocks() << " clock ticks. " << endl;
  cout << "That took " << setprecision(10) << myTimer.Seconds() << " seconds. " << endl;
  for(int count = 1, primecount = 0; count < SIZE; count ++) // This loop populates the original array with the primes we found.
  {
    if(n_array[count] != 0)
    {
      array[primecount] = n_array[count];
      primecount++;
    }
  }

  if(PRINT == 'y') // calling the prime-printing function if the user asks it to.
    primeprint(array);

};


/*** Your Code *****************************************************************
* Here is where you can define the functions that implement the Trial Division
* and Sieve of Eratosthenes algorithms.  You may choose to give the signatures
* above main() bodies, or leave the signatures in place and define the functions
* here.
*******************************************************************************/
