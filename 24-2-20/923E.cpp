#include<bits/stdc++.h>

const int N = 2e5 + 7;

int a[N];

void solve(int n, int k){
    int fr = 1, ba = n;
    std::set<int> st;
    for(int i = 1; i <= n; ++i) st.insert(i);
    while(1){
        int pf = *st.begin();
        while(pf <= n) a[pf] = fr, fr++, st.erase(pf), pf += k;
        if(!st.size()) break;
        int pb = *st.begin();
        while(pb <= n) a[pb] = ba, ba--, st.erase(pb), pb += k;
        if(!st.size()) break;
    }

    for(int i = 1; i <= n; ++i){
        std::cout << a[i] << ' ';
    }
    std::cout << std::endl;


}

int main(){

    #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    #endif

    int t; std::cin >> t;
    while(t--){
        int n, k; std::cin >> n >> k;
        solve(n, k);
    }

    return 0;
}