#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector<int> ans;
int n, k, p;

int binary_search(int left, int right, int k){
    if (left > right) return p;

    int mid = (left + right) / 2;

    if (ans[mid] < k) return binary_search(mid + 1, right, k);

    else { 
        p = mid;
        return binary_search(left, mid - 1, k); 
    }
}

int main(){
    cin >> n;
    vector<int> v;
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        v.push_back(num);
    }
    int last = 0, len = 0;
    for (int i = 0; i < n; i++) {
        if (last < v[i]) {
            last = v[i];
            len++;
            ans.push_back(v[i]);
        }
        else {
            int pos = binary_search(0, len - 1, v[i]);
            ans[pos] = v[i];
            if (pos == len - 1)
                last = v[i];
        }
    }
    printf("%d \n", ans.size());
    return 0;
}
/*
6
10 20 10 30 20 50
*/
