#include <bits/stdc++.h>
#define ll long long
using namespace std;

struct Node{
    ll value;
    ll left;
    ll right;
};

pair<ll, ll> dfs(ll curr_node, vector<Node> &tree_node){
    if(curr_node == -1) return {0, 0};

    pair<ll, ll> left_result = dfs(tree_node[curr_node].left, tree_node);
    pair<ll, ll> right_result = dfs(tree_node[curr_node].right, tree_node);
    ll take_curr = tree_node[curr_node].value + left_result.second + right_result.second;
    ll skip_curr = max(left_result.first, left_result.second) + max(right_result.first, right_result.second);

    return {take_curr, skip_curr};
}

int main(){
    ll N;
    cin >> N;

    vector<ll> level(N + 1);

    for(ll i = 1; i <= N; i++) cin >> level[i];

    vector<Node> tree_node(N + 1);

    for(ll i = 1; i <= N; i++){
        if(level[i] == -1) continue;

        tree_node[i].value = level[i];

        if(2 * i <= N && level[2 * i] != -1) tree_node[i].left = 2 * i;
        else tree_node[i].left = -1;

        if(2 * i + 1 <= N && level[2 * i + 1] != -1) tree_node[i].right = 2 * i + 1;
        else tree_node[i].right = -1;
    }

    pair<ll, ll> answer = dfs(1, tree_node);

    cout << max(answer.first, answer.second) << endl;

    return 0;
}
