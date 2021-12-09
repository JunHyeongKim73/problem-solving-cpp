#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin>>t;
    
    while(t--) {
		string p;
		cin>>p;

		int n;
		cin>>n;

		vector<int> arr;

		string str;
		cin>>str;
        
		str.erase(0, 1);
		str.erase(str.size() - 1);

		int prev = 0;
		int cur = str.find(',');

        if(cur != -1){
            // 문자열 -> 정수 배열
            while(cur != string::npos) {
                string substr = str.substr(prev, cur - prev);
                int num = stoi(substr);
                arr.push_back(num);

                prev = cur + 1;
                cur = str.find(',', prev);
            }
        }
        // 마지막 정수를 추가한다
        string substr = str.substr(prev, cur-prev);
        if(substr != ""){
            int num = stoi(substr);
            arr.push_back(num);    
        }
		
        const int FOR = 0, REV = 1;

        int strlen = n;
        int low = 0, high = strlen - 1; 
        int dir = FOR;
        int len = p.length();

        for(int i=0; i<len; i++){
            if(p[i] == 'R') {
                // 방향 바꾸기
                dir = 1 - dir;
            }
            else {
                strlen--;
                if(dir == FOR) low++;
                else high--;
            } 
        }

        // 예외 처리        
        if(strlen < 0){
            cout<<"error\n";
            continue;
        }

        if(strlen == 0){
            cout<<"[]\n";
            continue;
        }
        // 출력
        if(dir == FOR){
            for(int i=low; i<=high; i++){
                if(i == low) cout<<"[";
                cout<<arr[i];
                if(i != high) cout<<",";
                if(i == high) cout<<"]";
            }
            cout<<endl;
        }
        else{
            for(int i=high; i>=low; i--){
                if(i == high) cout<<"[";
                cout<<arr[i];
                if(i != low) cout<<",";
                if(i == low) cout<<"]";
            }
            cout<<endl;
        }
    }
}
