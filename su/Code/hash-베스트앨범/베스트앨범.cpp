#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

bool cmp(pair<string, int> a, pair<string, int> b){
    return a.second>b.second;
}
bool cmp2(pair<int, int> a, pair<int, int> b){
    return a.second>b.second;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    map<string, int> genre;
    vector<pair<string, int>> v_gen;
    map<string, vector<pair<int, int>>> musics;
    
    for(int i = 0; i<genres.size(); i++){
        if(!genre.count(genres[i])){
            genre[genres[i]] = plays[i];
        }
        else{
            genre[genres[i]] += plays[i];
        }
        
        musics[genres[i]].push_back({i, plays[i]});
    }
    
    v_gen.assign(genre.begin(), genre.end());
    sort(v_gen.begin(), v_gen.end(), cmp);
    
    for(auto& m : musics){
        sort(m.second.begin(), m.second.end(), cmp2);
    }
    
    for(int i = 0; i<v_gen.size(); i++){
        string gen = v_gen[i].first;
        
        for(int j = 0; j<musics[gen].size() && j<2; j++){
            answer.push_back(musics[gen][j].first);
        }
    }
    return answer;
}