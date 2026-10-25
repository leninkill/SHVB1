#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    vector<int> st;

    for (int i = 0; i < n; ++i) {
        st.push_back(i);

        while (st.size() >= 3) {
            int sz = st.size();
            int v1 = st[sz - 3];
            int v2 = st[sz - 2];
            int v3 = st[sz - 1];

            if (a[v1] + a[v3] == a[v2]) {
                st.pop_back();
                st.pop_back();
                st.pop_back();
            } else {
                break;
            }
        }
    }

    if (st.empty()) {
        cout << 0 << "\n";
    } else {
        cout << st.size() << "\n";
        for (size_t i = 0; i < st.size(); ++i) {
            cout << a[st[i]] << (i == st.size() - 1 ? "" : " ");
        }
        cout << "\n";
    }

    return 0;
}