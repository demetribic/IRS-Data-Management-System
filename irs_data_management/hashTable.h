#include <iostream>
#include "SLL.h" 
using namespace std;

template <class V>
class HashTable {
    int tableSize; // table size
    
    SLL<V>* table;
    
public:
    // default constructor, which uses default table size 3
    HashTable(){
        tableSize = 3;
        table = new SLL<V>[tableSize];
    }
    
    // constructor, which uses size as the table size
    HashTable(int size) {
        tableSize = size;
        table = new SLL<V>[tableSize];
    }
    
    // search item in the table
    // if found, return true; otherwise, return false
    bool find(V item) {
        int index = hashFunction(item);
        return table[index].search(item);
    }
    
    // insert (item1, item2) to the table
    // use item1 as the key
    // if inserted, return true
    // otherwise, return false
    bool insert(V item1, V item2) {
        int index = hashFunction(item1);
        if (find(item1)) {return false; } 
        else { table[index].insert(item1, item2);  return true;}}

    // delete the pair whose key value is item
    // if deleted, return true
    // otherwise, return false
    bool erase(V item) {
        int index = hashFunction(item);
        return table[index].remove(item);
    }

    // return the total number of nodes in the hash table    
    int getSize() {
        int totalSize = 0;
        for (int i = 0; i < tableSize; i++) { totalSize += table[i].getSize();}
        return totalSize;
    } 

    int hashFunction(V item) {
        int hash = 0;
        for (char c : item) { hash = (hash * 31 + c) % tableSize;}
        return hash;}
};
