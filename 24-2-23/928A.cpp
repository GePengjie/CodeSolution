#include<bits/stdc++.h>

int main(){

    #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    #endif

    int t; std::cin >> t;
    while(t--){
        std::string str; std::cin >> str;
        int n = str.length();
        str = " " + str;
        int a = 0;
        for(int i = 1; i <= n; ++i){
            a = a + (str[i] == 'A') - (str[i] == 'B');
        }
        if(a > 0) std::cout << 'A' << std::endl;
        else std::cout << 'B' << std::endl;
    }

    return 0;
}