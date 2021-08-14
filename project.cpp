#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;
//Check if ship has spaces left
bool checkshipcapcity(int, int);
int total = 0;

class resourceCluster
{
    string resourceID;
    int type;
    int x, y, z;
    int resourceNum;

public:
    resourceCluster();
    resourceCluster(int t, string rID, int X, int Y, int Z, int rNum);
    int getType();
    string getID();
    int getX();
    int getY();
    int getZ();
    int getNum();
};
resourceCluster::resourceCluster()
{
}
resourceCluster::resourceCluster(int t, string rID, int X, int Y, int Z, int rNum)
{
    type = t;
    resourceID = rID;
    x = X;
    y = Y;
    z = Z;
    resourceNum = rNum;
}
int resourceCluster::getType()
{
    return type;
}
string resourceCluster::getID()
{
    return resourceID;
}
int resourceCluster::getX()
{
    return x;
}
int resourceCluster::getY()
{
    return y;
}
int resourceCluster::getZ()
{
    return z;
}
int resourceCluster::getNum()
{
    return resourceNum;
}

int main()
{
    ifstream inFile;
    inFile.open("Grid1.txt");
    string line;
    int ur = 0, s = 0, c = 0, l = 0, t = 0, nq = 0;
    int numResClus[10];
    int resourceQuota[10];
    string shipPath(resourceCluster clus[]);
    //Intput file
    getline(inFile, line);
    //First line
    ur = std::stoi(line.substr(0, line.find('|')));
    line.erase(0, line.find('|') + 1);
    s = std::stoi(line.substr(0, line.find('|')));
    line.erase(0, line.find('|') + 1);
    c = std::stoi(line.substr(0, line.find('|')));
    line.erase(0, line.find('|') + 1);
    ur = std::stoi(line.substr(0, line.find('|')));
    line.erase(0, line.find('|') + 1);
    l = std::stoi(line.substr(0, line.find('|')));
    line.erase(0, line.find('|') + 1);
    t = std::stoi(line.substr(0, line.find('|')));
    line.erase(0, line.find('|') + 1);
    nq = std::stoi(line.substr(0, line.size()));

    getline(inFile, line);
    //Second line
    for (int i = 0; i < (ur - 1); i++)
    {
        line.erase(0, line.find(',') + 1);
        numResClus[i] = std::stoi(line.substr(0, line.find('|')));
        line.erase(0, line.find('|') + 1);
    }
    numResClus[ur - 1] = std::stoi(line.substr(0, line.size()));

    //Resource quota,ur lines
    for (int i = 0; i < nq; i++)
    {
        line.erase(0, line.find('|') + 1);
        resourceQuota[i] = std::stoi("0." + line.substr(0, line.size()));
        getline(inFile, line);
    }

    // resource 1
    getline(inFile, line);
    resourceCluster cluster1[5];
    string id = "";
    int x, y, z, num;
    string section = "";
    int type = stoi(line.substr(0, line.find('|')));
    line.erase(0, line.find('|') + 1);
    for (int i = 0; i < 5; i++)
    {
        section = line.substr(0, line.find('|'));
        line.erase(0, line.find('|') + 1);

        id = section.substr(0, section.find(','));
        section.erase(0, section.find(',') + 1);
        x = stoi(section.substr(0, section.find(',')));
        section.erase(0, section.find(',') + 1);
        y = stoi(section.substr(0, section.find(',')));
        section.erase(0, section.find(',') + 1);
        z = stoi(section.substr(0, section.find(',')));
        section.erase(0, section.find(',') + 1);
        num = stoi(section.substr(0, section.find(',')));
        section.erase(0, line.find(',') + 1);

        cluster1[i] = resourceCluster(type, id, x, y, z, num);
    }
    // resource 2
    getline(inFile, line);
    resourceCluster cluster2[5];
    id = "";
    section = "";
    type = stoi(line.substr(0, line.find('|')));
    line.erase(0, line.find('|') + 1);
    for (int i = 0; i < numResClus[0]; i++)
    {
        section = line.substr(0, line.find('|'));
        line.erase(0, line.find('|') + 1);

        id = section.substr(0, section.find(','));
        section.erase(0, section.find(',') + 1);
        x = stoi(section.substr(0, section.find(',')));
        section.erase(0, section.find(',') + 1);
        y = stoi(section.substr(0, section.find(',')));
        section.erase(0, section.find(',') + 1);
        z = stoi(section.substr(0, section.find(',')));
        section.erase(0, section.find(',') + 1);
        num = stoi(section.substr(0, section.find(',')));
        section.erase(0, line.find(',') + 1);

        cluster2[i] = resourceCluster(type, id, x, y, z, num);
    }

    ofstream outputfile;
    outputfile.open("output.txt");
    outputfile << shipPath(cluster1) << endl;
    total = 0;
    outputfile << shipPath(cluster2) << endl;
    outputfile.close();

    return 0;
}


bool checkshipcapcity(int c, int a) //Ship capcity and number of resources in cluster
{
    total += a;
    if (total >= c)
        return false;
    else
        return true;
}

string shipPath(resourceCluster clus[])
{
    string out = "";
    int i = 0;
    while (checkshipcapcity(200, clus[i].getNum()))
    {
        out += clus[i].getID() + ",";
        i++;
    }

    out += "0";
    return out;
}
