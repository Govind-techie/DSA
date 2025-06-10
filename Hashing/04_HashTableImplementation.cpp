#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Node{
public:
    string key;
    int val;
    Node* next;

    Node(string key, int val){
        this->key = key;
        this->val = val;
        next = NULL;
    }
};

class HashTable{
    vector<Node*>ht;
    int size;
public:
    HashTable(int size){
        this->size = size;
        ht.resize(size,NULL);
    }
private:
    int hashFunction(string key){
        int hash = 0;
        for (char ch : key){
            hash += (int(ch) * int(ch)) % size;
        }
        return hash;
    }

public:

    void insert(string key, int val){
        int idx = hashFunction(key);
        Node* newNode = new Node(key,val);

        newNode->next = ht[idx];
        ht[idx] = newNode;
    }

    void erase(string key){

    }

    int search(string key){

    }

};


int main(){

    return 0;
}