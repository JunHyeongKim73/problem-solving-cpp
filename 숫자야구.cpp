#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(vector<vector<int>> baseball) {
    int answer = 0;
    string n;
    string bn;
    int s,b;
    for(int i = 123 ;i <= 987 ; i++ ){
        n = to_string(i);
        if(n[0] == '0' || n[1] =='0' || n[2] =='0' )
            continue;
        if(n[0] ==n[1] || n[1] ==n[2] || n[2] ==n[0])
            continue;

        for(int j = 0;j <baseball.size();j++){
            s = 0;b = 0;
            bn = to_string(baseball[j][0]);
            if(bn[0] == n[0]) s++;
            if(bn[1] == n[1]) s++;
            if(bn[2] == n[2]) s++;
            if(s != baseball[j][1]) break;

            if(bn[0] == n[1] || bn[0] == n[2]) b++;
            if(bn[1] == n[2] || bn[1] == n[0]) b++;
            if(bn[2] == n[0] || bn[2] == n[1]) b++;
            if(b != baseball[j][2]) break;

            if(j == baseball.size()-1){
                answer++;
                cout << n << endl;
            }

        }       

    }

    return answer;
}