#include<bits/stdc++.h>

int main(){

    #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    #endif

    int t; std::cin >> t;

    while(t--){
        std::set<int> sa, sb;
        int n, m, k; std::cin >> n >> m >> k;
        for(int i = 1; i <= n; ++i){
            int x; std::cin >> x;
            sa.insert(x);
        }
        for(int i = 1; i <= m; ++i){
            int x; std::cin >> x;
            sb.insert(x);
        }
        int ok = 1;
        int logo = 0;
        int la = k / 2, lb = k / 2;
        for(int i = 1; i <= k; ++i){
            if(sa.count(i) && !sb.count(i)){
                la--;
            }else if(!sa.count(i) && sb.count(i)){
                lb--;
            }else if(!sa.count(i) && !sb.count(i)){
                ok = 0;
                break;
            }else if(sa.count(i) && sb.count(i)){
                logo++;
            }
        }
        if(logo > la + lb || la < 0 || lb < 0){
            ok = 0;
        }
        if(!ok) std::cout << "NO" << std::endl;
        else std::cout << "YES" << std::endl;
    }

    return 0;
}