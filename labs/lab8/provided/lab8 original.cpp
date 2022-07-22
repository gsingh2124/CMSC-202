#include <iostream>
#include <string>
using namespace std;

/* Lab 8: Debugging
 * There are three (4) errors in this code:
 * A runtime error that will cause a segmentation fault
 * A logical error that will cause a segmentation fault
 * A memory leak
 * HINT: Use GDB to step through the code.
 */
 
 int main()
 {
	 string *student = new string("Elon");
	 
	 delete student;
	 
	 string assistants[5] = {"Alexa", "Bixby", "Cortana", "Google", "Siri"};
	 string *listNames = new string[3]();
	 
	 int count = sizeof(listNames);
	 
	 for(int i = 0; i < count; i++)
		 listNames[i] = assistants[i];
	 
	 
	 for(int i = 0; i < count; i++)
		 cout << i + 1 << ". " << listNames[i] << endl;
	 
	 cout << "4. " << *student << endl;
	 
	 cout << "Deleting.. " << *student << endl;
	 delete student;
	 cout << "Deleting.. Assistants" << endl;

	 return 0;
 }
