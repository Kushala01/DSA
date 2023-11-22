#include <iostream>
#include <string>
using namespace std;

int matchingCharacters(const string& pat, const string& txt) {
    int pi = 0, ti = 0, cnt = 0;
     while (pi < pat.size() && ti < txt.size()) {
        if (pat[pi] == txt[ti]) {
            pi++;
            ti++;
        } else  ti++;
    }if (pi == pat.size())  cnt = txt.size() - ti;
     else  cnt = 0;
    return cnt;
}   

int main() {
    string pat, txt;
    cout << "Enter pattern: ";
    cin >> pat;
    cout << "Enter text: ";
    cin >> txt;
    int res = matchingCharacters(pat, txt);
    cout << "Result: " << res << endl;
    return 0;
}
