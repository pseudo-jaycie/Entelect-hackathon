#include <rC.h>

template <class rC>
resourceCluster<rC>::resourceCluster(int rID, int X, int Y, int Z, int rNum){
    resourceID = rID;
    x = X;
    y = Y;
    z = Z;
    resourceNum = rNum;
}

template <class rC>
int resourceCluster<rC>::getID(){
    return resourceID;
}

template <class rC>
int resourceCluster<rC>::getX(){
    return x;
}

template <class rC>
int resourceCluster<rC>::getY(){
    return y;
}

template <class rC>
int resourceCluster<rC>::getZ(){
    return getZ;
}

template <class rC>
int resourceCluster<rC>::getNum(){
    return resourceNum;
}