// Listing errors: Need parameters for the void function

/* An Thien Vo, CS 202 - 1001
* This program will use a recursive function named
* "double convo(double *p, double *q, int n)",
* *p, *q are dynamic arrays both of dimensions n, to find the convolution of
* the two dynamic arrays. Write both a c-like program, and
* C++ program with a destructor, and a constructor
* Formula: Sigma of n starting from 0 as the sum of two dynamic arrays
* q[i]p[i]
*/

#include<iostream>

using namespace std;

double convo(double *q, double *p, int n);

void printAuthorInfo();

void testProgram(double*, double*, int);
void printInputArrays(double*, double*, int);

void userTestProgram(double*, double*, int);
void askForInputs(double*, double*, int&);
void printConvolution(double *q, double *p, int n);

int main()
{
	printAuthorInfo();

	//1. input
		 // a. Declare variables
	double *first, *second;						//variable for first and second arrays
	double *test1, *test2;
	int dimensions = 0;							//variable for the dimensions of

		// execute test program
	testProgram(test1, test2, 5);

		// execute the user's test program
	userTestProgram(first, second, dimensions);

	cout << endl << "Thank you." << endl;
	return 0;
}

/******************************************************************************************************************/

// Function Definition

void printAuthorInfo()
// This function prints out the author's info
{
		//Print out the author's info
	cout << "An Thien Vo, CS 202 - 1001" << endl;
	cout << "Homework #5: Write a recursive function named \"double "
	     << endl
	     << "convo(double *p, double *q, int n)\", "
	     << endl
	     << "*p, *q are dynamic arrays both of dimensions n,"
	     << endl
	     << " to find the convolution of "
	     << endl
	     << "the two dynamic arrays. Write both a C-like program, and "
	     << endl
	     << "C++ program with a destructor, and a constructor."
		 << endl << endl;
}

double convo(double *q, double *p, int n)
// the double function convo will find the convolution of
// two dynamic arrays
{
	if (n == 0)
		return q[0] * p[0];
	else
		return q[n] * p[n] + convo(q, p, n-1);
}


void testProgram(double *test1, double *test2, int dimensions)
// This void function will construct the dynamic arrays
// with a given dimensions, int dimension, after printing out a 
// message. Then it will provide these two dynamic arrays their own
// values, then they will be printed out by 
// void printInputArrays before their convolution is printed
// out by void printConvolution
{
	cout << "I would like to start with a simple "
		 << "example of convolution of "
		 << "two given dynamic arrays."
		 << endl << endl;
	
		//constructor
	test1 = new double[dimensions];
	test2 = new double[dimensions];

	// Assume test1 = {0, 5, 10, 15, 20}
	test1[0] = 0;
	test1[1] = 5;
	test1[2] = 10;
	test1[3] = 15;
	test1[4] = 20;

	// Assume test2 = {1, 2, 3, 2, 1}
	test2[0] = 1;
	test2[1] = 2;
	test2[2] = 3;
	test2[3] = 2;
	test2[4] = 1;

	printInputArrays(test1, test2, dimensions);
	printConvolution(test1, test2, dimensions);
	// Given test1 = {0, 5, 10, 15, 20}
	//       test2 = {1, 2,  3,  2,  1}
	// Their convolution will be
	// 0 * 1 = 0
	// 0 * 1 + 5 * 2 = 10
	// 0 * 1 + 5 * 2 + 10 * 3 = 10 + 30 = 40
	// 0 * 1 + 5 * 2 + 10 * 3 + 15 * 2 = 40 + 30 = 70
	// 0 * 1 + 5 * 2 + 10 * 3 + 15 * 2 + 20 * 1 = 70 + 20 = 90
	// In other words, it is {0, 10, 40, 70, 90}

		//destructor
	delete[] test1, test2;
}

void printInputArrays(double *q, double *p, int dimensions)
// This function will print the values of dynamic arrays
{
	cout << "First array: {";
	for (int i = 0; i < dimensions; i++)
	{
		// this if conditional statement is to verify
		// if the value is the last value of the array,
		// if not, print a space after print out a value to distinguish a space between
		// values
		// else, do not print an extra space
		if (i != dimensions - 1)
			cout << q[i] << " ";
		else
			cout << q[i];
	}	// end for loop
	cout << "}" << endl; // finish printing out the first array

		//print the second array
	cout << "Second array: {";
	for (int i =0; i < dimensions; i++)
	{
		// this if conditional statement is to verify
		// if the value is the last value of the array,
		// if not, print a space after print out a value to distinguish a space between
		// values
		// else, do not print an extra space
		if (i != dimensions - 1)
			cout << p[i] << " ";
		else
			cout << p[i];
	}	// end for loop
	cout << "}" << endl; // finish printing out the second array	
}

void printConvolution(double *q, double *p, int n)
// This function will calculate the convolution
// of two dynamic arrays, then print it out.
{
		cout << "Convolution = {";
		for (int i = 0; i < n; i++)
	    {
	        if (i == n - 1)
	        {
	            cout << convo(q, p, i);
	        }
	        else
	        {
	            cout << convo(q, p, i) << " ";
	        }
  		}
	cout << "}" << endl;
}

void userTestProgram(double *q, double *p, int n)
// This function indicates and prompts the user
// to provide his/her own test program while 
// void askForInputs will collect datas, print them out,
// calculate the convolution of the user's dynamic arrays,
// and print out the outputs.
{
	cout << endl;
	cout << "Starting the user's test program." << endl;

	askForInputs(q, p, n);
}

void askForInputs(double* q, double* p, int& dimensions)
// This function prompts the user to provide the dimensions
// of the two dynamic arrays, construct the dynamic arrays,
// then prompts the user for the values of them along with 
// printing them out with void printInputArrays. Then it proceeds 
// to calculate their convolution and print the output out with
// printConvolution. In the end, the function will create destructors
// for the dynamic arrays.
{
	double temp = 0;
	cout << "Please enter the number of dimensions of your "
		 << "dynamic arrays: ";
	cin >> dimensions;

		//constructors
	q = new double[dimensions];
	p = new double[dimensions];

	cout << "Please enter the values of "
		 << "your first array:" << endl;
	
	for (int i = 0; i < dimensions; i++)
	{
		cin >> q[i];
	}

	cout << endl
		 << "Please enter the values of your "
		 << "second array:" << endl;

	for (int i = 0; i < dimensions; i++)
	{
		cin >> p[i];
	}

	printInputArrays(q, p, dimensions);
	printConvolution(q, p, dimensions);

		//destructors
	delete[] q, p;
}
