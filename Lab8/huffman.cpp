#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct Node {
    char ch;
    int freq;
    Node *left, *right;
    Node(char c, int f) {
        ch = c;
        freq = f;
        left = right = nullptr;
    }
};
struct Compare {
    bool operator()(Node* a, Node* b) {
        return a->freq > b->freq;
    }
};
void printCodes(Node* root, string code) {
    if (root == nullptr)
        return;
    if (!root->left && !root->right) {
        cout << root->ch << " : " << (code.empty() ? "0" : code) << endl;
        return;
    }
    printCodes(root->left, code + "0");
    printCodes(root->right, code + "1");
}
void huffmanCoding(vector<char>& chars, vector<int>& freq) {
    priority_queue<Node*, vector<Node*>, Compare> pq;
    for (int i = 0; i < chars.size(); i++) {
        pq.push(new Node(chars[i], freq[i]));
    }
    while (pq.size() > 1) {
        Node* left = pq.top();
        pq.pop();
        Node* right = pq.top();
        pq.pop();
        Node* parent = new Node('\0', left->freq + right->freq);
        parent->left = left;
        parent->right = right;
        pq.push(parent);
    }
    if (!pq.empty())
        printCodes(pq.top(), "");
}
int main() {
    int n;
    cout<<"Enter no of characters:"<<endl;
    cin >> n;
    vector<char> chars(n);
    vector<int> freq(n);
    cout<<"Enter the characters:"<<endl;
    for (int i = 0; i < n; i++)
        cin >> chars[i];
    cout<<"Enter the frequencies:"<<endl;
    for (int i = 0; i < n; i++)
        cin >> freq[i];
    huffmanCoding(chars, freq);
    return 0;
}