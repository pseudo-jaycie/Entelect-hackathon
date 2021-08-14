template <class rC>
class resourceCluster
{
private:
    int resourceID;
    int x, y, z;
    int resourceNum;

public:
    resourceCluster(int rID, int X, int Y, int Z, int rNum);
    int getID();
    int getX();
    int getY();
    int getZ();
    int getNum();
    
};
