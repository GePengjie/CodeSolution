#include<bits/stdc++.h>

int ksm(int x, int n){
    int rs = 1;
    while(n > 0){
        if(n & 1) rs = rs * x;
        n >>= 1;
        x = x * x;
    }
    return rs;
}

int main(){

    #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    #endif

    int t; std::cin >> t;
    while(t--){
        int a, b, l; std::cin >> a >> b >> l;
        std::set<int> st;
        for(int x = 0; ksm(a, x) <= l; ++x){
            if(l % ksm(a, x)) break;
            for(int y = 0; ksm(a, x) * ksm(b, y) <= l; ++y){
                if(l % (ksm(a, x) * ksm(b, y))) break;
                st.insert(l / (ksm(a, x) * ksm(b, y)));
            }
        }
        std::cout << (int)(st.size()) << std::endl;
    }


    return 0;
}