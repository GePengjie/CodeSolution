#include<bits/stdc++.h>

int main(){

    #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    #endif

    int t; std::cin >> t;
    while(t--){
        int n; std::cin >> n;
        int rs = 1;
        for(int i = 1; i <= n; ++i){
            int x; std::cin >> x;
            rs = ((int)(rs / x + (rs % x != 0))) * x;
            rs += (i != n);
        }
        std::cout << rs << std::endl;
    }

    return 0;
}