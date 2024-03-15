#include<bits/stdc++.h>

const int N = 2e5 + 7;

int a[N];

#define inf 2e7

#define lson (idx << 1)
#define rson (idx << 1 | 1)

struct node{
    int left, right, maxx, minn;
}tree[N << 2];

int my_max(int l, int r){
    if(l == 0) return r;
    else if(r == 0) return l;

    if(a[l] > a[r]) return l;
    else return r;
}

int my_min(int l, int r){
    if(l == 0) return r;
    else if(r == 0) return l;

    if(a[l] < a[r]) return l;
    else return r;
}

void maintain(int idx){
    tree[idx].maxx = my_max(tree[lson].maxx, tree[rson].maxx);
    tree[idx].minn = my_min(tree[lson].minn, tree[rson].minn);
}

void build(int idx, int l, int r){
    tree[idx].left = l, tree[idx].right = r;
    if(l == r){
        tree[idx].maxx = tree[idx].minn = l;
        return;
    }
    int mid = (l + r) >> 1;
    build(lson, l, mid);
    build(rson, mid + 1, r);
    maintain(idx);
}

int query_max(int idx, int l, int r){
    if(tree[idx].left == l && tree[idx].right == r){
        return tree[idx].maxx;
    }
    int mid = (tree[idx].left + tree[idx].right) >> 1;
    if(l > mid) return query_max(rson, l, r);
    else if(r <= mid) return query_max(lson, l, r);
    else return my_max(query_max(lson, l, mid), query_max(rson, mid + 1, r));
}

int query_min(int idx, int l, int r){
    if(tree[idx].left == l && tree[idx].right == r){
        return tree[idx].minn;
    }
    int mid = (tree[idx].left + tree[idx].right) >> 1;
    if(l > mid) return query_min(rson, l, r);
    else if(r <= mid) return query_min(lson, l, r);
    else return my_min(query_min(lson, l, mid), query_min(rson, mid + 1, r));
}

int main(){

    #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    #endif

    int t; std::cin >> t;
    while(t--){
        int n; std::cin >> n;
        for(int i = 1; i <= n; ++i) std::cin >> a[i];
        build(1, 1, n);
        int q; std::cin >> q;
        for(int i = 1; i <= q; ++i){
            int l, r; std::cin >> l >> r;
            int ll = query_max(1, l, r);
            int rr = query_min(1, l, r);
            if(a[ll] == a[rr]) std::cout << -1 << ' ' << -1 << std::endl;
            else std::cout << ll << " " << rr << std::endl;
        }
        std::cout << std::endl;
    }

    return 0;
}