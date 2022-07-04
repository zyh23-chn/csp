#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
enum FILE_TYPE { DIR,
    DOC };

struct node {
    FILE_TYPE type;
    ll fs;
    // for a dir d
    ll ld, lr, ldd, lrd; //目录配额, 后代配额, 孩子文件中全部普通文件占用的存储空间之和, 后代文件中全部普通文件占用的存储空间之和
    map<string, node*> children;
    node()
    {
        this->type = DIR;
        ld = lr = LLONG_MAX;
        ldd = lrd = 0;
    }
    node(ll fs)
    {
        this->type = DOC;
        this->fs = fs;
    }
} * root;

vector<string> parse(string path)
{
    if (path == "/") {
        return {};
    }
    vector<string> ret;
    int n = path.size();
    int j = n;
    for (int i = n - 1; i >= 0; i--) {
        if (path[i] == '/') {
            ret.push_back(path.substr(i + 1, j - i - 1));
            j = i;
        }
    }
    reverse(ret.begin(), ret.end());
    return ret;
}

char C(vector<string> files, ll fs)
{
    node* p = root;
    int n = files.size();
    for (int i = 0; i < n - 1; i++) {
        if (p->children.find(files[i]) == p->children.end()) {
            if (root->lrd + fs > root->lr) {
                return 'N';
            }
            p = root;
            for (int j = 0; j < i; j++) {
                p = p->children[files[j]];
                if (p->lrd + fs > p->lr) {
                    return 'N';
                }
            }
            for (int j = i; j < n - 1; j++) {
                p->children[files[j]] = new node();
                p = p->children[files[j]];
            }
            p = root;
            for (int j = 0; j < n - 1; j++) {
                p->lrd += fs;
                p = p->children[files[j]];
            }
            p->children[files[n - 1]] = new node(fs);
            p->lrd += fs;
            p->ldd += fs;
            return 'Y';
        } else {
            p = p->children[files[i]];
            if (p->type == DOC) {
                return 'N';
            }
        }
    }
    ll dif;
    if (p->children.find(files[n - 1]) != p->children.end()) {
        if (p->children[files[n - 1]]->type == DIR) {
            return 'N';
        } else { //替换文件
            dif = fs - p->children[files[n - 1]]->fs;
        }
    } else { //创建文件
        dif = fs;
    }
    p = root;
    for (int i = 0; i < n - 1; i++) {
        if (p->lrd + dif > p->lr) {
            return 'N';
        }
        p = p->children[files[i]];
    }
    if (p->lrd + dif > p->lr || p->ldd + dif > p->ld) {
        return 'N';
    }
    p = root;
    for (int i = 0; i < n - 1; i++) {
        p->lrd += dif;
        p = p->children[files[i]];
    }
    p->lrd += dif;
    p->ldd += dif;
    if (p->children.find(files[n - 1]) != p->children.end()) { //替换文件
        p->children[files[n - 1]]->fs = fs;
    } else { //创建文件
        p->children[files[n - 1]] = new node(fs);
    }
    return 'Y';
}

char R(vector<string> files)
{
    node* p = root;
    int n = files.size();
    for (int i = 0; i < n; i++) {
        if (p->children.find(files[i]) == p->children.end()) {
            return 'Y';
        } else {
            p = p->children[files[i]];
        }
    }
    ll x = p->type == DIR ? p->lrd : p->fs;
    p = root;
    for (int i = 0; i < n - 1; i++) {
        p->lrd -= x;
        p = p->children[files[i]];
    }
    p->lrd -= x;
    if (p->children[files[n - 1]]->type == DOC) {
        p->ldd -= x;
    }
    p->children.erase(files[n - 1]);
    return 'Y';
}

char Q(vector<string> files, ll ld, ll lr)
{
    node* p = root;
    int n = files.size();
    for (int i = 0; i < n; i++) {
        if (p->children.find(files[i]) == p->children.end()) {
            return 'N';
        } else {
            p = p->children[files[i]];
        }
    }
    if (ld == 0) {
        ld = LLONG_MAX;
    }
    if (lr == 0) {
        lr = LLONG_MAX;
    }
    if (p->type != DIR || p->ldd > ld || p->lrd > lr) {
        return 'N';
    }
    p->ld = ld;
    p->lr = lr;
    return 'Y';
}

int main()
{
    root = new node();
    int n;
    cin >> n;
    while (n--) {
        char c;
        string path;
        cin >> c >> path;
        vector<string> files = parse(path);
        if (c == 'C') {
            ll fs;
            cin >> fs;
            cout << C(files, fs) << endl;
        } else if (c == 'R') {
            cout << R(files) << endl;
        } else {
            ll ld, lr;
            cin >> ld >> lr;
            cout << Q(files, ld, lr) << endl;
        }
    }
}
