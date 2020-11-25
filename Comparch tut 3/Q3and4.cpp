// T3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <conio.h>			
#include <time.h> 		

// globals 
int depth;
int calls;
int maxDepth;
int underflows;
int overflows;
int numberWindows;
int usedWindows;


void setValues(int registerSets) {
	depth = 0;
	calls = 0;
	maxDepth = 0;
	underflows = 0;
	overflows = 0;
	usedWindows = 2;
	numberWindows = registerSets; //variable depending on test 6,8 or 16 reg sets
}

int compute_pascal(int x, int y) {
	depth++;
	if (depth > maxDepth) {
		maxDepth = depth;
	}
	if (usedWindows == numberWindows) {
		overflows++;
	}
	else  usedWindows++;

	if (y == 1) {
		calls = 1;
	}
	else if (y == x) {
		calls = 1;
	}
	else {
		calls = compute_pascal(x - 1, y) + compute_pascal(x - 1, y - 1);
	}

	depth--;
	if (usedWindows == 2) {
		underflows++;
	}
	else usedWindows--;

	return calls;
}


int main()
{
	clock_t start = clock();
	setValues(6);
	int result = compute_pascal(30, 20);
	printf(" WINDOWS = 6 \n");
	printf(" The number of procdure calls = %d \n maxDepth = %d \n overflows = %d \n underflows = %d\n usedWindows = %d\n numberWindows = %d \n", result, maxDepth, overflows, underflows, usedWindows, numberWindows);
	clock_t stop = clock();
	printf(" time elapsed = %g \n", (double)(stop - start) / CLOCKS_PER_SEC);
	printf("------------------------------------------------------------------------------------------ \n");
		

	start = clock();
	setValues(8);
	result = compute_pascal(30, 20);
	printf(" WINDOWS = 8 \n");
	printf(" The number of procdure calls = %d \n maxDepth = %d \n overflows = %d \n underflows = %d\n usedWindows = %d\n numberWindows = %d \n", result, maxDepth, overflows, underflows, usedWindows, numberWindows);
	stop = clock();
	printf(" time elapsed = %g \n", (double)(stop - start) / CLOCKS_PER_SEC);
	printf("------------------------------------------------------------------------------------------ \n");
	
	start = clock();
	setValues(16);
	result = compute_pascal(30, 20);
	printf(" WINDOWS = 16 \n");
	printf(" The number of procdure calls = %d \n maxDepth = %d \n overflows = %d \n underflows = %d\n usedWindows = %d\n numberWindows = %d \n", result, maxDepth, overflows, underflows, usedWindows, numberWindows);
	stop = clock();
	printf(" time elapsed = %g \n", (double)(stop - start) / CLOCKS_PER_SEC);
	printf("------------------------------------------------------------------------------------------ \n");
	return 0;
}
