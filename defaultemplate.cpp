#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <functional>
#include <queue>
#include <numeric>

#define debug(...) Debug(#__VA_ARGS__, __VA_ARGS__)
using namespace std;
const bool TEST_CASE = 0;

template<typename T>
typename std::enable_if<std::is_integral<T>::value>::type
Debug(const char* name, T value) {
    std::cout << name << " : " << value << '\n';
}


template<typename T, typename... Args>
typename std::enable_if<std::is_integral<T>::value>::type
Debug(const char* names, T value, Args... args) {
    const char* comma = strchr(names, ',');
    std::cout.write(names, comma - names) << " : " << value << " | ";
    Debug(comma + 1, args...);
}
template<typename T> ostream& operator<<(ostream& out, vector<T>& a) {
    for(auto &x : a) out << x << ' '; 
    return out;
};

void solve(){
    int n;
    
}

#define DORMON

int main()
{
    #ifndef DORMON
        ios_base::sync_with_stdio(false); 
    #endif
    cin.tie(0);
    int q = 1; 
    if (TEST_CASE) cin >> q;
    while (q--){
        solve();
    }
}