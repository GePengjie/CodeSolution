#include<bits/stdc++.h>

const int N = 1e2 + 7;

int a[N][N];

int main(){

    #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    #endif

    int t; std::cin >> t;
    while(t--){
        int n; std::cin >> n;
        int sum = 0;
        for(int i = 1; i <= n; ++i){
            std::string str; std::cin >> str;
            str = " " + str;
            for(int j = 1; j <= n; ++j){
                a[i][j] = str[j] - '0';
                sum += a[i][j];
            }
        }
        int ok = 0;
        for(int rs = n; rs >= 1; --rs){
            for(int i = 1; i + rs - 1 <= n; ++i){
                for(int j = 1; j + rs - 1 <= n; ++j){
                    for(int k = 1; k <= rs; ++k){
                        for(int g = 1; g <= rs; ++g){
                            ok += a[i + k - 1][j + g - 1];
                        }
                    }
                    if(ok == rs * rs) break;
                    ok = 0;
                }
                if(ok == rs * rs) break;
                ok = 0;
            }
            if(ok == rs * rs) break;
            ok = 0;
        }
        if(ok && ok == sum) std::cout << "SQUARE" << std::endl;
        else std::cout << "TRIANGLE" << std::endl;
    }
    return 0;
}