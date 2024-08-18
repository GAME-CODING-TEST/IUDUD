// - 백준 9046 : 복호화

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <string.h>
using namespace std;
 
int alphaCntArr[26] = {0,};
//a = 97
int main(){
 
   int T; cin >> T; cin.ignore();
   for(int t=1; t<=T; t++){
       memset(alphaCntArr, 0, sizeof(alphaCntArr));
       string str;
       getline(cin, str);
 
       for(int i = 0; i<str.length(); i++){
           if(str[i] == ' ') continue;
 
           alphaCntArr[str[i]-97]++;
       }
 
        vector<pair<int,char>> vec;
       for(int i = 0; i<26; i++){
           vec.push_back(make_pair(alphaCntArr[i], i+97));
       }
 
        sort(vec.begin(), vec.end(), greater<>());
 
        if(vec[0].first==vec[1].first){
            cout << "?\n";
        }
        else {
                cout << vec[0].second << "\n";
        }
   }
 
    return 0;
}