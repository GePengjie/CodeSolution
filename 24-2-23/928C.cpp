#include<bits/stdc++.h>

const int N = 2e5 + 7;

int rs[N];

int my(int x){
    int as = 0;
    while(x > 0){
        as += x % 10;
        x /= 10;
    }
    return as;
}

void init(int n){
    for(int i = 1; i <= n; ++i){
        rs[i] = rs[i - 1] + my(i);
    }
}

int main(){
    
    #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    #endif

    init(2e5);

    int t; std::cin >> t;
    while(t--){
        int n; std::cin >> n;
        std::cout << rs[n] << std::endl;
    }

    return 0;
}