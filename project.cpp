#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;
//Check if ship has spaces left
bool checkshipcapcity(int, int);
int total = 0;
int one, two, three, five;

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
    inFile.open("Grid2.txt");
    string line;
    int ur = 0, s = 0, c = 0, l = 0, t = 0, nq = 0;
    int numResClus[10];
    int resourceQuota[10];

    string shipPath(int k, resourceCluster clus[4][1000]);
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
    resourceCluster cluster[4][1000];
    for (int j = 0; j < 4; j++)
    {
        getline(inFile, line);
        // cout << line << endl;
        string id = "";
        int x, y, z, num;
        string section = "";
        int type = stoi(line.substr(0, line.find('|')));
        line.erase(0, line.find('|') + 1);
        for (int i = 0; i < 1000; i++)
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

            cluster[j][i] = resourceCluster(type, id, x, y, z, num);
            
        }
    }

    ofstream outputfile;
    outputfile.open("output.txt");
    string out;
    for (int j = 0; j < 5; j++)
    {
        for (int i = 0; i < 4; i++)
        {
            out = shipPath(i, cluster) + "0";
            outputfile << out << endl;
            out = "";
        }
    }
    outputfile.close();
    return 0;
}

bool checkshipcapcity(int c, int a) //Ship capcity and number of resources in cluster
{
    total += a;
    if (total >= c)
    {
        total = 0;
        return false;
    }
    else
        return true;
}

string shipPath(int k, resourceCluster clus[4][1000])
{
    int i = 0;
    string out = "";
    if (k == 0)
    {
        i = one;
    }
    else if (k == 1)
    {
        i = two;
    }
    else if (k == 2)
    {
        i = three;
    }
    else if (k == 3)
    {
        i = five;
    }
    while (checkshipcapcity(400000, 2000))
    {
        out += clus[k][i].getID() + ",";

        i++;
    }
    if (k == 0)
    {
        one = i;
    }
    else if (k == 1)
    {
        two = i;
    }
    else if (k == 2)
    {
        three = i;
    }
    else if (k == 3)
    {
        five = i;
    }

    return out;
}
