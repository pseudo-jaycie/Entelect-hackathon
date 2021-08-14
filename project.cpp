#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;

int main()
{
ifstream inFile;
inFile.open("Grid1.txt");
string line;
int ur = 0,s = 0,c= 0,l=0,t=0,nq =0;
int NumResClus[10];
int ResourceQuota[10];
//Intput file
getline(inFile, line);
//First line
    ur = std::stoi(line.substr(0,line.find('|'));
    line.erase(0,line.find('|')+1);
    s = std::stoi(line.substr(0,line.find('|'));
    line.erase(0,line.find('|')+1);
    c = std::stoi(line.substr(0,line.find('|'));
    line.erase(0,line.find('|')+1);  
    ur = std::stoi(line.substr(0,line.find('|'));
    line.erase(0,line.find('|')+1);
    l = std::stoi(line.substr(0,line.find('|'));
    line.erase(0,line.find('|')+1);
    t = std::stoi(line.substr(0,line.find('|'));
    line.erase(0,line.find('|')+1);
    nq = std::stoi(line.substr(0,line.size()));


getline(inFile, line);
//Second line
for (int i = 0, i < (ur-1), i++)
{
    line.erase(0,line.find(',')+1);
    NumResClus[i] = std::stoi(line.substr(0,line.find('|'));
    line.erase(0,line.find('|')+1);
}
NumResClus[ur-1] = std::stoi(line.substr(0,line.size()));

//Resource quota,ur lines
getline(inFile, line);
for (int i = 0, i < 10, i++)
{
    line.erase(0,line.find('|')+1);
    ResourceQuota[i] = std::stoi("0." + line.substr(0,line.size()));
}
getline(inFile, line);

return 0;  
}