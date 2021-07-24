#include <stdio.h>
#define SIZE 10

int GetHash(int key){
    return key%SIZE;
}

//this function will linearly probe and find out the next free index
int Probe(int hashTable[], int keyToBeInserted){
    int potentialIndex = GetHash(keyToBeInserted);
    int i = 0;
    while (hashTable[(potentialIndex + i)%SIZE] != 0) {
        i++; // linear probing
        // i = i *i; //quadratic probing, same goes with search operation
    }
    return (potentialIndex+i)%SIZE;
}

void InsertIntoHashTable(int hashTable[], int keyToBeInserted){
    int potentialIndex = GetHash(keyToBeInserted);
    if (hashTable[potentialIndex] != 0) { // it means that index is alread occupied, need to find another index for insert
        potentialIndex = Probe(hashTable, keyToBeInserted);
    }
    hashTable[potentialIndex] = keyToBeInserted; // the actual insert;
}

int Search(int hashTable[], int keyToBeSearched){
    int potentialIndex = GetHash(keyToBeSearched);
    int i = 0;
    while (hashTable[(potentialIndex +i)%SIZE] != keyToBeSearched) {
        i++;
    }
    return (potentialIndex +i)%SIZE;
}

int main(int argc, const char * argv[]) {
    int HashTable[10];
    InsertIntoHashTable(HashTable, 12);
    InsertIntoHashTable(HashTable, 23);
    InsertIntoHashTable(HashTable, 33);
    InsertIntoHashTable(HashTable, 67);
    printf("\nFound at %d\n", Search(HashTable, 67));
    return 0;
}
