void compress(vector<int> &a) {
    set<int> s(a.begin(), a.end());
    vector<int> b(s.begin(), s.end());
    for (int &x: a) {
        x = lower_bound(b.begin(), b.end(), x) - b.begin() + 1;
    }
}