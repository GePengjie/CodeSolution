#include<bits/stdc++.h>

const int N = 2e5 + 7;

int a[N];

int main(){

    #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    #endif

    int t; std::cin >> t;
    while(t--){
        int n; std::cin >> n;
        for(int i = 1; i <= n; ++i) std::cin >> a[i];
        int l = 1, r = n;
        while(a[l] == a[1] && l <= n) l++;
        while(a[r] == a[n] && r >= 1) r--;
        int rs = n;
        rs = std::min(rs, std::min(n - l + 1, r));
        if(a[1] == a[n]) rs = std::min(rs, (r - l + 1));
        rs = std::max(rs, 0);
        std::cout << rs << std::endl;
        
    }

    return 0;
}