#include<bits/stdc++.h>

const int N = 2e5 + 7;

int a[N];

#define lson (idx << 1)
#define rson (idx << 1 | 1)

struct node{
    int left, right, dat;
}tree[N << 2];

int mod = 0;

void maintain(int idx){
    tree[idx].dat = (tree[lson].dat * tree[rson].dat) % mod;
}

void build(int idx, int l, int r){
    tree[idx].left = l, tree[idx].right = r;
    if(l == r){
        tree[idx].dat = a[l];
        return;
    }
    int mid = (l + r) >> 1;
    build(lson, l, mid);
    build(rson, mid + 1, r);
    maintain(idx);
}

int query(int idx, int l, int r){
    if(tree[idx].left == l && tree[idx].right == r){
        return tree[idx].dat;
    }
    int mid = (tree[idx].left + tree[idx].right) >> 1;
    if(l > mid) return query(rson, l, r);
    else if(r <= mid) return query(lson, l, r);
    else return query(lson, l, mid) * query(rson, mid + 1, r) % mod;
}

int main(){

    #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    #endif

    int t; std::cin >> t;
    while(t--){
        int n, m; std::cin >> n >> m;
        for(int i = 1; i <= n; ++i) std::cin >> a[i];
        mod = m; build(1, 1, n);
        std::string str; std::cin >> str;
        str = " " + str;
        int l = 1, r = n;
        for(int i = 1; i <= n; ++i){
            std::cout << query(1, l, r) % mod << ' ';
            if(str[i] == 'L') l++;
            else r--;
        }
        std::cout << std::endl;
    }

    return 0;
}