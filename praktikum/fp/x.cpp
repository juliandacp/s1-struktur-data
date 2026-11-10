#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll dfs_size(ll v, ll p, vector<vector<ll>>& adj, vector<ll>& parent, vector<ll>& depth, vector<ll>& heavy){
    parent[v] = p;
    heavy[v] = -1;

    ll subtree_size = 1;
    ll max_child_size = 0;

    for(ll u : adj[v]){
        if(u == p) continue;

        depth[u] = depth[v] + 1;

        ll child_size = dfs_size(u, v, adj, parent, depth, heavy);

        subtree_size += child_size;

        if(child_size > max_child_size){
            max_child_size = child_size;
            heavy[v] = u;
        }
    }

    return subtree_size;
}

void dfs_hld(ll v, ll h, vector<vector<ll>>& adj, vector<ll>& parent, vector<ll>& heavy, vector<ll>& head, vector<ll>& pos, vector<ll>& rev_pos, ll& curr_pos){
    head[v] = h;
    pos[v] = ++curr_pos;
    rev_pos[curr_pos] = v;

    if(heavy[v] != -1) dfs_hld(heavy[v], h, adj, parent, heavy, head, pos, rev_pos, curr_pos);

    for(ll u : adj[v]){
        if(u == parent[v] || u == heavy[v]) continue;

        dfs_hld(u, u, adj, parent, heavy, head, pos, rev_pos, curr_pos);
    }
}

void update(ll node, ll left, ll right, ll idx, ll value, vector<ll>& seg_tree){
    if(left == right){
        seg_tree[node] = value;
        return;
    }

    ll mid = (left + right) / 2;

    if(idx <= mid) update(node * 2, left, mid, idx, value, seg_tree);
    else update(node * 2 + 1, mid + 1, right, idx, value, seg_tree);

    seg_tree[node] = seg_tree[node * 2] + seg_tree[node * 2 + 1];
}

ll query(ll node, ll left, ll right, ll q_left, ll q_right, vector<ll>& seg_tree, vector<ll>& rev_pos){
    if(q_left > q_right || seg_tree[node] == 0) return -1;
    if(left == right) return rev_pos[left];

    ll mid = (left + right) / 2;
    ll left_ans = query(node * 2, left, mid, q_left, min(q_right, mid), seg_tree, rev_pos);

    if(left_ans != -1) return left_ans;

    return query(node * 2 + 1, mid + 1, right, max(q_left, mid + 1), q_right, seg_tree, rev_pos);
}

int main(){
    ll N, Q;
    cin >> N >> Q;

    vector<vector<ll>> adj(N + 1);

    for(ll i = 0; i < N - 1; i++){
        ll u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<ll> parent(N + 1);
    vector<ll> depth(N + 1);
    vector<ll> heavy(N + 1);
    vector<ll> head(N + 1);
    vector<ll> pos(N + 1);
    vector<ll> rev_pos(N + 1);
    vector<ll> state(N + 1, 0);
    vector<ll> seg_tree(4 * N + 5, 0);
    ll curr_pos = 0;

    dfs_size(1, 0, adj, parent, depth, heavy);
    dfs_hld(1, 1, adj, parent, heavy, head, pos, rev_pos, curr_pos);

    while(Q--){
        ll type, x;
        cin >> type >> x;

        if(type == 0){
            state[x] ^= 1;
            update(1, 1, N, pos[x], state[x], seg_tree);
        }else{
            vector<pair<ll, ll>> paths;
            ll curr = x;

            while(curr != 0){
                paths.push_back({pos[head[curr]], pos[curr]});
                curr = parent[head[curr]];
            }

            reverse(paths.begin(), paths.end());

            ll ans = -1;

            for(auto p : paths){
                ans = query(1, 1, N, p.first, p.second, seg_tree, rev_pos);

                if(ans != -1) break;
            }

            cout << ans << endl;
        }
    }

    return 0;
}
