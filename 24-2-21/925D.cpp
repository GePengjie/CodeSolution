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
        int n, x, y; std::cin >> n >> x >> y;
        std::map<std::pair<int, int>, int> mp;
        for(int i = 1; i <= n; ++i){
            std::cin >> a[i];
            mp[std::make_pair(a[i] % x, a[i] % y)]++;
        }
        long long rs = 0;
        for(int i = 1; i <= n; ++i){
            int xx = a[i] % x, yy = a[i] % y;
            mp[std::make_pair(xx, yy)]--;
            if(mp.count(std::make_pair((x - xx) % x, yy))){
                rs += mp[std::make_pair((x - xx) % x, yy)];
            }
        }
        std::cout << rs << std::endl;

    }

    return 0;
}