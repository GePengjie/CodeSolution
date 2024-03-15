#include<bits/stdc++.h>

int main(){

    #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    #endif

    int t; std::cin >> t;
    while(t--){
        int n; std::cin >> n;
        std::string str; std::cin >> str;
        str = " " + str + "*";
        int rs = 0;

        for(int i = 2; i <= n; ++i){
            if(str[i] == '@') rs++;
            else if(str[i] == '*' && str[i + 1] == '*') break;
        }
        std::cout << rs << std::endl;
        
    }

    return 0;
}