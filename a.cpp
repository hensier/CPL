#include <bits/stdc++.h>
using namespace std;
int T;
string a, b;
char op;
string add(string a, string b) {
    if (a.size() < b.size()) swap(a, b);
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    for (int i = 0; b[i]; i++) {
        a[i] += b[i] - '0';
        if (!isdigit(a[i])) {
            a[i] -= 10;
            if (a.size() == b.size() && i == int(b.size() - 1)) a += '1';
            else a[i+1]++;
        }
    }
    for (int i = b.size(); a[i] && !isdigit(a[i]); i++) {
        a[i] -= 10;
        if (i == int(a.size() - 1)) a += '1';
        else a[i+1]++;
    }
    reverse(a.begin(), a.end());
    return a;
}
bool smaller(string a, string b) {
    if (a.size() != b.size()) return a.size() < b.size();
    return a < b;
}
string subtract(string a, string b) {
    bool neg = false;
    if (smaller(a, b)) {
        neg = true;
        swap(a, b);
    }
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    for (int i = 0; b[i]; i++) {
        a[i] -= b[i] - '0';
        if (!isdigit(a[i])) {
            a[i] += 10;
            a[i+1]--;
        }
    }
    for (int i = b.size(); a[i] && !isdigit(a[i]); i++) {
        a[i] += 10;
        a[i+1]--;
    }
    reverse(a.begin(), a.end());
    int pos = 0;
    while (a[pos+1] && a[pos] == '0') pos++;
    return neg ? ('-' + a.substr(pos)) : a.substr(pos);
}
string easy_mul(string a, char b) {
    reverse(a.begin(), a.end());
    int tmp = 0;
    for (int i = 0; a[i]; i++) {
        int x = (a[i] - '0') * (b - '0') + tmp;
        a[i] = x % 10 + '0';
        tmp = x / 10;
    }
    if (tmp) a += (tmp + '0');
    reverse(a.begin(), a.end());
    return a;
}
string mul(string a, string b) {
    string ans = "0";
    for (int i = b.size() - 1; i >= 0; i--) {
        ans = add(ans, easy_mul(a, b[i]));
        a += "0";
    }
    int pos = 0;
    while (ans[pos+1] && ans[pos] == '0') pos++;
    return ans.substr(pos);
}
string div(string a, string b) {
    int pos = -1;
    string sa, sb[11], ans;
    do sa += a[++pos];
    while (a[pos] && smaller(sa, b));
    for (int i = 1; i <= 10; i++) sb[i] = easy_mul(b, i + '0');
    do {
        int coef = 0;
        while (coef <= 9 && !smaller(sa, sb[coef+1])) coef++;
        ans += (coef + '0');
        sa = subtract(sa, sb[coef]) + a[++pos];
        if (sa[0] == '0') sa = sa.substr(1);
    } while (a[pos]);
    return ans;
}
int main() {
    cin >> T;
    while (T--) {
        cin >> a >> op >> b;
        switch (op) {
            case '+': {
                cout << add(a, b) << endl;
                break;
            }
            case '-': {
                cout << subtract(a, b) << endl;
                break;
            }
            case '*': {
                cout << mul(a, b) << endl;
                break;
            }
            case '/': {
                cout << div(a, b) << endl;
                break;
            }
        }
    }
    return 0;
}