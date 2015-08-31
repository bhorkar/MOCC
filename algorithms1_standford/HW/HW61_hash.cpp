#include <iostream>
#include <fstream> //Grouped the includes

#include <map>
#include <vector>
#include <set>

#include <cmath>
//Got rid of sys/time, as I couldn't see what it was being used for. If I'm wrong, ignore this.


class HashTable
{
    typedef std::set<long int> inner;
    typedef std::map<int, inner> hashTable_T;

    //Grouped all of the functions by type.
    private:
        hashTable_T hash;
        int t;

    public:
        HashTable(){};
        ~HashTable(){};
        HashTable(const char* sourceFile, int tVal);
        std::set<int> makeSet(int t);

        int findinTable(const long int &value, const int &binL,const int &binH, std::set<int> &setofTs);

        void print();
        void readFile(int t, const char* fileName);
};


 HashTable::HashTable(const char* sourceFile, int tVal){
        t = tVal;
        readFile(tVal, sourceFile);
}

void HashTable::readFile(int t, const char* fileName){

    std::ifstream ipstream;
    ipstream.open(fileName);

    long int output;

    while (ipstream >> output){
        int index = output/(2*t);
        hash[index].insert(output);
    }
}

int HashTable::findinTable(const long int &value, const int &binL, const int &binH, std::set<int> &setofTs){
    hashTable_T::iterator it, itL, itH;
    inner::iterator itIn;
    long int sum;

    itL = hash.upper_bound(binL);
    if (itL != hash.begin()){
        itL--;
    }

    itH = hash.upper_bound(binH);

    bool done = false;
    while(itL != hash.end()){
        for (itIn = (itL->second).begin(); itIn != (itL->second).end(); itIn++){
            sum = *itIn + value;
            if (sum <= t && sum >= -t && *itIn != value){
                setofTs.insert(sum);
            }
        }
        itL++;
        if (done){
            break;
        }
        if (itL == itH){
            done = true;
        }
    }
}

std::set<int> HashTable::makeSet(int t){
    std::set<int> setofTs;
    hashTable_T::iterator it = hash.begin();
    inner::iterator it2;
    int binL, binH;
    for (it; it != hash.end(); it++){
        for (it2 = (it->second).begin(); it2 != (it->second).end(); it2++){
            binL = (-t-(*it2))/(2*t);
            binH = (t- (*it2))/(2*t);
            findinTable(*it2, binL, binH, setofTs);
        }
    }
    return setofTs;
}

void HashTable::print(){
    hashTable_T::iterator it;
    inner::iterator vecIt;

    for (it=hash.begin(); it!=hash.end(); it++){ 
        std::cout << it->first << " :";
        for (vecIt = (it->second).begin(); vecIt != (it->second).end(); vecIt++){
            std::cout << *vecIt << " "; 
        }
        std::cout << std::endl;
    }
}

//This *could* be in a file all on it's own, but let's not make it look lonely.
int main(){
    int sum = 0;
    int t = 10000;
    HashTable hTable("algo1-programming_prob-2sum.txt", t);
    hTable.print();

    std::set<int> setoFTs = hTable.makeSet(t);
    std::cout << setoFTs.size() << std::endl;
    return 0;
}
