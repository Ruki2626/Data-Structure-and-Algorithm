#include "stdio.h"
#include "stdlib.h"
#include "math.h"
#include "time.h"
#include <string>
#include <iostream>
#include <fstream>

#define TRUE 1
#define FALSE !TRUE
#define SIZE_HASH_MAP 26

int hist[23000];

using namespace std;

typedef struct node{
    string value;
    struct node *next;
}t_hashTableNode;

t_hashTableNode* hashMapChained[SIZE_HASH_MAP];              // hash table
/* HASH FUNCTIONS */
int hashfunction(string value);                                                /* hash function */
void chainedHashInsert(string value);                                  /* inserts a value in the hash table, using chaining */
bool chainedHashSearch(string value);                                   /* searches for a value in the hash table */
/* AUXILIARY FUNCTIONS */
void populateHashMap();                     /* AUX: inserts random integer numbers in the hash table */
void printList(int i);                                              /* AUX: prints the linked list stored in hashMapChained[i] */
void printHashMap();                                                /* AUX: prints the whole hash hashMapChained */

/* HASH FUNCTIONS */
int hashfunction(string value){
	int rval=value[0]-97;
    return rval;
}

void chainedHashInsert(string value){
    int ct=0;
    int probe = hashfunction(value);                                        // stores the hash value of the number to be inserted
    //cout<<value<<"\n";

    if(hashMapChained[probe] == NULL){                              // if the list in hashMapChained[probe] is empty
        ct++;
        hashMapChained[probe] = (t_hashTableNode *) calloc(1, sizeof(t_hashTableNode));    // then creates a new list
        hashMapChained[probe]->value = value;
        hashMapChained[probe]->next = NULL;
    }else{                                                          // if the list in hashMapChained[probe] is not empty
        t_hashTableNode *hashTableNode = hashMapChained[probe];
        while(hashTableNode->next!=NULL){                           // scrolls down the list
            ct++;
            hashTableNode = hashTableNode->next;
        }
        hashTableNode->next = (t_hashTableNode *) calloc(1, sizeof(t_hashTableNode));      // inserst the value as the last element of the list
        hashTableNode->next->value = value;
        hashTableNode->next->next = NULL;
    }
    hist[ct]++;
    //cout<<ct<<"\n";
    ct=0;
}

bool chainedHashSearch(string value){

    t_hashTableNode *hashTableNode = hashMapChained[hashfunction(value)];   // pointer to the list stored in hashMapChained[hash(value)]
    while(hashTableNode!=NULL){                                     // scrolls the list
        if(hashTableNode->value==value){
            return TRUE;                                            // if the value is found, returns TRUE
        }
        hashTableNode = hashTableNode->next;
    }
    return FALSE;                                                   // else returns FALSE
}

/* MAIN FUNCTION */
int main (int argc, char const *argv[]){
	for(int i=0;i<23000;i++)
  		hist[i]=0;
    srand(time(NULL));
    string s,w;
    populateHashMap();
    //printHashMap();
    ifstream inFile;
    inFile.open("hw8.dat");
  	if (inFile.fail())
  	{
    	cout << "unable to open file hw8.dat for reading" << endl;
      	exit(1);
  	}
  	while(inFile>>w)
  	{
  		if(chainedHashSearch(w)==true)
  			cout<<w<<" "<<"Yes\n";
  		else
  			cout<<w<<" "<<"No\n";
  	}
  	cout<<"\nInsert\tCount\n";
  	for(int i=1;i<23000;i++)
  		cout<<i<<"\t"<<hist[i]<<"\n";
}

/* AUXILIARY FUNCTIONS */
void populateHashMap(){
	ifstream inFile;
  	inFile.open("dict.txt");
  	if (inFile.fail())
  	{
    	cout << "unable to open file dict.txt for reading" << endl;
      	exit(1);
  	}
  	string w;
  	while(inFile>>w)
  	{
  		//cout<<w<<"\n";
  		chainedHashInsert(w);
  	}
  	inFile.close();
}

void printList(int hashMapRow){
    t_hashTableNode *hashMapNode = hashMapChained[hashMapRow];      // pointer to the linked list stored in hashMapChained[hashMapRow]
    while(hashMapNode!=NULL){
        cout<<hashMapNode->value;                           // prints out the value of the nodes
        hashMapNode = hashMapNode->next;
    }
}

void printHashMap(){
    int i;
    for(i=0;i<SIZE_HASH_MAP;i++){                                   // for every row of the hash map
        printf("hashMapChained[%d]:\t",i);
        printList(i);                                               // prints the list contained in it
        printf("\n");
    }
}
