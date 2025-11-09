#include<iostream>
#include<queue>
#include<unordered_map>
#include<vector>
using namespace std;

struct Node{
    char ch;
    int freq;
    Node *left, *right;

    Node(char c,int f) : ch(c), freq(f), left(nullptr), right(nullptr) {}
};

struct compare{
    bool operator()(Node* l, Node* r){
        return l->freq > r->freq;
    }
};

void generateCodes(Node* root, string str, unordered_map<char, string>& huffmanCode){
    if(!root) return;

    if(!root->left && !root->right){
        huffmanCode[root->ch] = str;
    }

    generateCodes(root->left, str + "0", huffmanCode);
    generateCodes(root->right, str + "1", huffmanCode);
}

int main(){
    string text;
    cout<<"Enter the string to encode: ";
    getline(cin,text);

    unordered_map<char,int> freq;
    for(char ch : text){
        freq[ch]++;
    }

    priority_queue<Node*, vector<Node*>, compare> pq;

    for(auto pair : freq){
        pq.push(new Node(pair.first, pair.second));
    }

    while(pq.size() != 1){
        Node* left = pq.top(); pq.pop();
        Node* right = pq.top(); pq.pop();

        Node* sum = new Node('\0', left->freq + right->freq);
        sum->left = left;
        sum->right = right;
        pq.push(sum);
    }

    Node* root = pq.top();

    unordered_map<char, string> huffmancode;
    generateCodes(root, "", huffmancode);

    cout<<"Huffman Codes :"<<endl;

    for(auto pair : huffmancode){
        cout<<pair.first<<" : "<<pair.second<<endl;
    }

    string encoded = "";
    for(char ch : text){
        encoded += huffmancode[ch];
    }

    cout<<"Encoded string :"<<encoded<<endl;
    return 0;
}