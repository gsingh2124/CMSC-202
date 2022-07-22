#include <iostream>
using namespace std;

int main()
{
  char *temp = "Pikachu"; //To fix, change to char temp[] = "Pikachu";
  int i = 0;
  temp[3]='F';
  for (i =0 ; i < 7 ; i++ )
    cout << temp[i] << endl;
  return 0;
}
