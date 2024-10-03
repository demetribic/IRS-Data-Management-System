#include "hashTable.h"
#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
using namespace std;

class IRS {
private:
    HashTable<string> table;
    int insCnt;
    int dltCnt;
    int rtrvCnt;

public:
    IRS() : table(10007), insCnt(0), dltCnt(0), rtrvCnt(0) {} 

    void ins(const string& SSN, const string& name) {if (table.insert(SSN, name)) {insCnt++;}}
    void rmv(const string& SSN) { if (table.erase(SSN)) {dltCnt++;} }
    void rtrv(const string& SSN) { if (table.find(SSN)) { rtrvCnt++; }}
    void printStats(double elapsedTime) {
        cout << "The Number of Valid Insertion: " << insCnt << endl;
        cout << "The Number of Valid Deletion: " << dltCnt << endl;
        cout << "The Number of Valid Retrieval: " << rtrvCnt << endl;
        cout << "Item numbers in the list: " << table.getSize() << endl;
        cout << "Time elapsed: " << elapsedTime << " seconds" << endl;
    }
};

int main(int argc, char* argv[]) {
    clock_t start, end;
    double duration;
    start = clock();
    IRS irs;
    fstream input(argv[1]);
    string firstChar, SSN, firstName, lastName;

    while (input >> firstChar >> SSN >> firstName >> lastName) {
        if (firstChar == "i") { irs.ins(SSN, firstName + " " + lastName);} 
        else if (firstChar == "d") { irs.rmv(SSN);} 
        else if (firstChar == "r") { irs.rtrv(SSN);}
    }
    input.close();
    end = clock();
    duration = (end - start) / (double)CLOCKS_PER_SEC;
    irs.printStats(duration);

    return 0;
}
