#include <iostream>
#include <vector>
using namespace std;

int findRoot(string& inorder, int start, int end, char data) {
    for(int idx = start; idx <= end; ++idx) {
        if(inorder[idx] == data) return idx;
    }
    return -1;
}

void printPostorder(string& preorder, string& inorder, int start, int end, int& preIdx) {
    if(start > end) return;

    int rootIdx = findRoot(inorder, start, end, preorder[preIdx]);
    preIdx++;

    printPostorder(preorder, inorder, start, rootIdx - 1, preIdx);
    printPostorder(preorder, inorder, rootIdx + 1, end, preIdx);

    cout << inorder[rootIdx];
}

int main() {
    
    string preorder, inorder;

    while(cin >> preorder >> inorder) {
    
        int preIdx = 0;
        int n = preorder.length();
        printPostorder(preorder, inorder, 0, n - 1, preIdx);
        cout << endl;
    }

    return 0;
}
