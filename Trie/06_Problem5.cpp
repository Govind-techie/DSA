#include<iostream>
#include<vector>
#include<unordered_map>
#include<string>
using namespace std;

class Node {
public:
    unordered_map<char, Node*> child;
    bool endOfWord;
    int freq;

    Node() {
        endOfWord = false;
        freq = 0; // Node except root should have freq 0
    }
};

class Trie {
private:
    Node* root;
public:
    Trie() {
        root = new Node();
        root->freq = -1; // root freq -1 as no char in root
    }

    void insert(string word) {
        Node* curr = root;
        for (char ch : word) {
            if (!curr->child[ch]) {
                curr->child[ch] = new Node();
            }
            curr = curr->child[ch];
            curr->freq++; // count of how many words have same char
        }
        curr->endOfWord = true;
    }

    Node* getRoot() {
        return root;
    }
};

void helper(Node* root, string &ans, string temp){
    for (pair<char,Node*> p : root->child){
        temp += (p.first);
        if (p.second->endOfWord){
            if ((temp.size() == ans.size()) && (temp < ans) || (temp.size() > ans.size())){
                ans = temp;
            }
            helper(p.second,ans,temp);
        }
        temp.pop_back();
    }
}

string longestPrefix(vector<string>dict){
    Trie t;
    for (auto s : dict) t.insert(s);
    string ans = "";
    helper(t.getRoot(),ans,"");
    return ans;
}

int main(){
    vector<string> dict = {"a","banana","ap","app","appl","apply","apple"};
    cout << longestPrefix(dict) << endl;
    return 0;
}