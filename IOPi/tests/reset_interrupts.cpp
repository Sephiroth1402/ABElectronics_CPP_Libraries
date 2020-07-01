/*
reset_interrupts.cpp

Version 1.0 Created 01/07/2020

      compile with "g++ reset_interrupts.cpp ../ABE_IoPi.cpp -Wall -Wextra -Wpedantic -Woverflow -o reset_interrupts"
      run with "./reset_interrupts"
 
This test validates the reset_interrupts method in the IOPi class.

Hardware Required: Logic Analyser on I2C Pins

=== Expected Result ============================

> Console Output:

high boundary check: PASSED
Logic output Started
Logic output Ended

> Logic Analyser Output:

W 0x20 0xA0 0x02

W 0x20 0x10
R 0x20 0x00
W 0x20 0x11
R 0x20 0x00
 
 */

#include <stdio.h>
#include <stdexcept>
#include <unistd.h>
#include <iostream>
#include "../ABE_IoPi.h"

using namespace std;

void clearscreen()
{
	printf("\033[2J\033[1;1H");
}

int main(int argc, char **argv)
{
	setvbuf(stdout, NULL, _IONBF, 0); // needed to print to the command line

	using namespace ABElectronics_CPP_Libraries;

	IoPi bus(0x20, false);
	bool passed = true;

	cout << "Logic output Started\n";

	bus.reset_interrupts();

	cout << "Logic output Ended\n";

    if (passed){
        cout << "Test passed\n";
	}
    else{
        cout << "Test Failed\n";
	}

	(void)argc;
	(void)argv;
	return (0);
}
