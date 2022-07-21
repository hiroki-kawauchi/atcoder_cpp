// 参考：https://scrapbox.io/esaka-sandbox/Educational_DP_Contest_%2F_DP_%E3%81%BE%E3%81%A8%E3%82%81%E3%82%B3%E3%83%B3%E3%83%86%E3%82%B9%E3%83%88_-_J_-_Sushi

#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); ++i)
#define erep(i, n) for (ll i = 0; i <= (ll)(n); ++i)
#define FOR(i,a,b) for (ll i = (a); i < (ll)(b); ++i)
#define EFOR(i,a,b) for (ll i = (a); i <= (ll)(b); ++i)
 
// dpテーブル
double dp[310][310][310];

// 入力用, solve内でも使うので、グローバル変数にしている
int n;

// 遷移式
double solve(int i, int j, int k) {
    if(dp[i][j][k] != -1) return dp[i][j][k];
    if (i == 0 && j == 0 && k == 0) return 0.0; // 最後まで到達した時

    double ret = 0.0;
    if(i > 0) ret += solve(i-1,j,k) * i;
    if(j > 0) ret += solve(i+1,j-1,k) * j;
    if(k > 0) ret += solve(i,j+1,k-1) * k;
    ret += n;
    ret *= 1.0 / (i + j + k);
    dp[i][j][k] = ret;

    return ret;
}

int main() {
    cin >> n;
    int one = 0, two = 0, three = 0;
    rep(i, n) {
        int tmp; cin >> tmp;
        if(tmp == 1) one++;
        else if(tmp == 2) two++;
        else three++;
    }

    // dpテーブルを初期化
    rep(i, 310) rep(j, 310) rep(k, 310) {
        dp[i][j][k] = -1;
    }

    double ans = solve(one, two, three);
    // 桁数指定して出力
    cout << std::setprecision(10) << ans << endl;

    return 0;
}
