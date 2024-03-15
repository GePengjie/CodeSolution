#include<bits/stdc++.h>

int ksm(int x, int n){
    int rs = 1;
    while(n >= 1){
        if(n & 1) rs = rs * x;
        x *= x;
        n >>= 1;
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
        int n, k; std::cin >> n >> k;
        int rs = 0;
        while(k > (n / 2 + n % 2)){
            k -= n / 2 + n % 2;
            n /= 2;
            rs++;
        }
        std::cout << (2 * k - 1) * ksm(2, rs) << std::endl;
    }

    return 0;
}