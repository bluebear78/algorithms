#include <iostream>
#include <cstdio>
#include <algorithm> 
#include <cstring>
#include <vector>
#include <cmath>
#include <tuple>
#include <queue>

using namespace std;
using ii = pair<int, int>;
using iii = tuple<int, int, int>;

char c;
string s;
int q, l, r;
int psum[26][200000];

int main() {

    cin >> s;
    scanf("%d", &q);
    memset(psum, 0, sizeof(psum));

    for (int i=0; i<s.size(); i++) {
        for (int alpha = 0; alpha < 26; alpha++)
            psum[alpha][i] = (i == 0) ? 0 : psum[alpha][i-1];
        psum[s[i]-'a'][i]++;
    }

    while (q--) {
        scanf(" %c %d %d", &c, &l, &r);
        printf("%d\n", (l == 0) ? psum[c-'a'][r] : psum[c-'a'][r]-psum[c-'a'][l-1]);
    }
    return 0;
}