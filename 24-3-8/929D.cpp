#include<bits/stdc++.h>

int main(){

    #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    #endif

    int t; std::cin >> t;
    while(t--){
        int n; std::cin >> n;
        std::vector<int> x(n, 0);
        for(int i = 0; i <= n - 1; ++i){
            std::cin >> x[i];
        }
        std::sort(x.begin(), x.end());
        if(x[0] == x[1]){
            int ok = 0;
            for(int i = n - 1; i >= 0; --i){
                if(x[i] % x[0]){
                    ok = 1;
                    break;
                }
            }
            if(ok) std::cout << "YES" << std::endl;
            else std::cout << "NO" << std::endl;
        }else{
            std::cout << "YES" << std::endl;
        }
    }
    return 0;
}