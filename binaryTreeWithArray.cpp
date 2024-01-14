#include <iostream>

using namespace std;

        //      0
        //    /   \
        //   1     2
        //  / \   / \
        // 3   4 5   6

int node[] = {2, 5, 7, 3, 5 ,2, 6 , NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL};

// depth traversal in a binary tree
void dfs(int i) {
    if(node[i] == NULL) {
        return;
    }
    cout << node[i] << " "; // pre-order
    dfs((i+1)*2-1);
    // cout << node[i] << " "; // in-order
    dfs((i+1)*2);
    // cout << node[i] << " "; // post-order
}

int main() {
    dfs(0);
}