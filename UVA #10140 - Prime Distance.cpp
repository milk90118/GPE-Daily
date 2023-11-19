#include <iostream>
#include <vector>
#include <climits>
#include <cmath>
using namespace std;
#define MAXDIFF 10000005
#define int long long

vector<int> init;

void simple(int limit) {
    vector<bool> simple_sieve(limit + 1, true);
    simple_sieve[0] = simple_sieve[1] = false;

    for(int i = 2; i * i <= limit; ++i) {
        if(simple_sieve[i]) {
            for(int j = i * i; j <= limit; j += i) {
                simple_sieve[j] = false;
            }
        }
    }

    for(int i = 2; i <= limit; ++i) {
        if(simple_sieve[i]) {
            init.push_back(i);
        }
    }
}

void segmental(int left, int right) {
    vector<bool> segmental_sieve(right - left + 1, false);
    
    for(int prime : init) {
        int a = prime * prime;
        if(a > right) break;

        int b = max(a, (left + prime - 1) / prime * prime);
        for(int j = b; j <= right; j += prime) {
            if(j != prime)
                segmental_sieve[j - left] = true;
        }
    }

    vector<int> primes;
    for(int i = 0; i <= right - left; ++i) {
        if(!segmental_sieve[i] && i + left > 1) {
            primes.push_back(i + left);
        }
    }

    if(primes.size() < 2) {
        cout << "There are no adjacent primes.\n";
    } else {
        int minIdx = 0, maxIdx = 0;
        int mi = INT_MAX, ma = -1;

        for(int i = 0; i < primes.size() - 1; ++i) {
            int dist = primes[i + 1] - primes[i];
            if(dist < mi) {
                mi = dist;
                minIdx = i;
            }
            if(dist > ma) {
                ma = dist;
                maxIdx = i;
            }
        }

        cout << primes[minIdx] << "," << primes[minIdx + 1] << " are closest, ";
        cout << primes[maxIdx] << "," << primes[maxIdx + 1] << " are most distant.\n";
    }
}

signed main() {
    
    int low, hi;
    while(cin >> low >> hi)
    {
        simple(sqrt(hi) + 1);
        segmental(low, hi);
    }
}