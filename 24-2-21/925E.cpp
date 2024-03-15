#include<bits/stdc++.h>

int my(int x){
    int rs = 0;
    while(x % 10 == 0) x /= 10, rs++;
    return rs;
}
int your(int x){
    int rs = 0;
    while(x > 0) x /= 10, rs++;
    return rs;
}

struct node{
    int x, y;
    node(int x, int y){
        this->x = x, this->y = y;
    }
    bool operator<(const node& a) const {
        return a.y < this->y;
    }
};

int main(){

    #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    #endif

    int t; std::cin >> t;
    while(t--){
        std::multiset<node> st;
        int n, m; std::cin >> n >> m;
        for(int i = 1; i <= n; ++i){
            int x; std::cin >> x;
            st.insert(node(your(x), my(x)));
        }
        while((int)st.size() >= 1){
            node x = *st.begin(); st.erase(st.begin());
            x.x -= x.y; x.y = 0;
            st.insert(x);
            if((int)st.size() == 1) break;
            node y = *st.begin(); st.erase(st.begin());
            node z = *--st.end(); st.erase(--st.end());
            z.x += y.x;
            st.insert(z);
        }
        int rs = (*st.begin()).x;
        if(rs >= m + 1) std::cout << "Sasha" << std::endl;
        else std::cout << "Anna" << std::endl;
    }

    return 0;
}