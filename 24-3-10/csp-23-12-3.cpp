#include<bits/stdc++.h>

const int N = 2e3 + 7;

#define int long long 

int w[N], p[N], sum1[N], sum2[N];
bool del[N];

struct node{
    int id, w;
    node(int id = 0, int w = 0){
        this->id = id;
        this->w = w;
    }
    bool operator<(const node& a) const {
        if(this->w == a.w) return this->id < a.id;
        return this->w < a.w;
    }
};


void up1(int k){
    int kk = k;
    while(k) sum1[k] += w[kk], k = p[k];
}

void up2(int k){
    int kk = k;
    while(k) sum1[k] -= w[kk], k = p[k];
}

int up3(int k, int x){
    while(k){
        if(k == x) return 1;
        k = p[k];
    }
    return 0;
}

void solve(int ns, int n){
    while(1){
        std::set<node> st;
        for(int i = 1; i <= n; ++i){
            if(del[i] == false){
                st.insert(node(i, abs(sum1[1] - 2 * sum1[i])));
            }
        }
        if((int)st.size() == 1) break;
        if(up3(ns, st.begin()->id)){
            for(int j = 1; j <= n; ++j){
                if(del[j] == false && !up3(j, st.begin()->id)){
                    del[j] = true;
                    up2(j);
                }
            }
        }else{
            for(int j = 1; j <= n; ++j){
                if(del[j] == false && up3(j, st.begin()->id)){
                    del[j] = true;
                    up2(j);
                }
            }
        }
        std::cout << st.begin()->id << " ";
    }
}

signed main(){

    int n, m; std::cin >> n >> m;

    for(int i = 1; i <= n; ++i) std::cin >> w[i];
    for(int i = 2; i <= n; ++i) std::cin >> p[i];

    for(int i = 1; i <= n; ++i) up1(i);
    for(int i = 1; i <= n; ++i) sum2[i] = sum1[i];

    for(int i = 1; i <= m; ++i){
        int ns; std::cin >> ns;
        for(int j = 1; j <= n; ++j) del[j] = false;
        for(int j = 1; j <= n; ++j) sum1[j] = sum2[j];
        solve(ns, n);
        std::cout << std::endl;
    }

    return 0;
}