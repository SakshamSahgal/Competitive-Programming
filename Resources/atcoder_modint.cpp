#include <iostream>
#include <atcoder/modint> //this library only works in atcoder compilers

using namespace std;
using namespace atcoder; //this namespace only works in atcoder compilers

int main() {
    // Define a modint type with the modulo value 998244353
    using mint = modint998244353;

    // Perform modular arithmetic
    mint a = 123456789;
    mint b = 987654321;
    mint c = a + b;
    mint d = a * b;
    mint e = a - b;

    cout << "a + b = " << c.val() << endl; // Output: 1111111110
    cout << "a * b = " << d.val() << endl; // Output: 547206786
    cout << "a - b = " << e.val() << endl; // Output: 234567898

    return 0;
}
