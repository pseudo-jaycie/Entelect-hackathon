#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;

int main()
{
ifstream inFile;
inFile.open("data.txt");
string line;


getline(inFile, line);



return 0;  
}