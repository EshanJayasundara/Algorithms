#include <iostream>

using namespace std;

int node[] = {2, 5, 7, 3, 5 ,2, 6 , NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL};

// dfs in a binary tree
void dfs(int i) {
    if(node[i] == NULL) {
        return;
    }
    cout << node[i] << " ";
    dfs((i+1)*2-1);
    dfs((i+1)*2);
}

int main() {
    dfs(0);
}