
#include <stdio.h>
#include "Chains.h"

int GetHashCode(int key){
    return key%10;
}

void InsertIntoHashTable(struct Node *hashtable[], int keyToBeInserted){
    int index = GetHashCode(keyToBeInserted);
    SortedInsert(&hashtable[index], keyToBeInserted);
}

int main() {
    //first we should have a hash table
    struct Node *HashTable[10];
    int i;
    for (i = 0; i < 10; i++) {
        HashTable[i] = NULL;
    }
    InsertIntoHashTable(HashTable, 12);
    InsertIntoHashTable(HashTable, 42);
    InsertIntoHashTable(HashTable, 22);
    struct Node *searchResult;
    searchResult = Search(HashTable[GetHashCode(42)], 42);
    if (searchResult != NULL) {
        printf("Found\n");
    }else{
        printf("Not found\n");
    }
    
    return 0;
}
