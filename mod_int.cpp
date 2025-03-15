#include <iostream>
#include <cstdint>
#include <vector>
#include <numeric>

using namespace std;

template<int mod>
class mod_int {
private:
    int64_t val;

    int64_t Mod(int64_t a) const {
        return ((a % mod) + mod) % mod;
    }

    int64_t mod_pow(int64_t b, int64_t n) const {
        int64_t res = 1;
        b = Mod(b);
        while (n > 0) {
            if (n&1)
                res = (res * b) % mod;
            b = (b * b) % mod;
            n >>= 1;
        }
        return res;
    }

public:
    mod_int() : val(0) {}
    mod_int(int64_t v) : val(Mod(v)) {}

    mod_int operator+(const mod_int& b) const {
        return mod_int(val + b.val);
    }
    mod_int operator-(const mod_int& b) const {
        return mod_int(val - b.val);
    }
    mod_int operator*(const mod_int& b) const {
        return mod_int(val * b.val);
    }
    mod_int operator/(const mod_int& b) const {
        return *this * b.inv();
    }

    mod_int& operator+=(const mod_int& b) {
        val = Mod(val + b.val);
        return *this;
    }
    mod_int& operator-=(const mod_int& b) {
        val = Mod(val - b.val);
        return *this;
    }
    mod_int& operator*=(const mod_int& b) {
        val = Mod(val * b.val);
        return *this;
    }
    mod_int& operator/=(const mod_int& b) {
        *this = *this * b.inv();
        return *this;
    }

    mod_int inv() const {
        return mod_int(mod_pow(val, mod-2));
    }

    mod_int pow(int64_t n) const {
        return mod_int(mod_pow(val, n));
    }

    int64_t get() const {
        return val;
    }

    bool operator==(const mod_int& b) const {
        return val == b.val;
    }
    bool operator!=(const mod_int& b) const {
        return val != b.val;
    }
    bool operator<(const mod_int& b) const {
        return val < b.val;
    }
    bool operator<=(const mod_int& b) const {
        return val <= b.val;
    }
    bool operator>(const mod_int& b) const {
        return val > b.val;
    }
    bool operator>=(const mod_int& b) const {
        return val >= b.val;
    }

    friend ostream& operator<<(ostream& out, const mod_int& m) {
        out << m.val;
        return out;
    }
    friend istream& operator>>(istream& in, mod_int& m) {
        int64_t x;
        in >> x;
        m.val = m.Mod(x);
        return in;
    }
};

const int mod = 1e9+7;
using mint = mod_int<mod>;

int main() {
	int n = 5;
    vector<mint> v(n);

    for (int i = 0;i < n;i++)
        v[i] = i;

    for (auto &e:v)
        cout << e << ' ';
    cout << '\n';

    mint a = 5;
    cout << "a = " << a << '\n';
    mint inv = mint(1)/a;
    mint b = 20;
    cout << "b = " << b << " | " << "inv = " << inv << '\n';
    cout << "b * inv = " << b*inv << '\n';
    cout << "b / inv = " << b/inv << '\n';
    int64_t c = b.get();
    cout << "c = " << c << '\n';
    return 0;
}
