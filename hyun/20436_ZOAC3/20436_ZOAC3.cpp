// - 백준 20436 : ZOAC 3

#include <iostream>
#include <stdlib.h>

using namespace std;

int main() {
   // 왼손의 키보드
   char s_l[] = { 'q','w','e','r','t',
                    'a','s','d','f','g',
                    'z','x','c','v' };
   int s_l_p[][2] = { {0,0}, {0,1}, {0,2}, {0,3}, {0,4}, 
                        {1,0}, {1,1}, {1,2}, {1,3}, {1,4}, 
                        {2,0}, {2,1}, {2,2}, {2,3} };

   // 오른손의 키보드
   char s_r[] = { 'y','u','i','o','p',
                    'h','j','k','l',
                    'b','n','m', };
   int s_r_p[][2] = { {0,1}, {0,2}, {0,3}, {0,4}, {0,5},
                        {1,1}, {1,2}, {1,3}, {1,4},
                        {2,0}, {2,1}, {2,2} };

   char l, r;
   string str;
   int l_postion[2] = { 0 }; // 시작위치
   int r_postion[2] = { 0 };

   cin >> l >> r;
   cin >> str;

   // 오른손과 왼손의 시작 위치 저장
   for (int i = 0; i < 14; i++) {
      if (l == s_l[i]) {
         l_postion[0] = s_l_p[i][0];
         l_postion[1] = s_l_p[i][1];
      }
      if (i < 12) {
         if (r == s_r[i]) {
            r_postion[0] = s_r_p[i][0];
            r_postion[1] = s_r_p[i][1];
         }
      }
   }
   
   int time = 0;

   // 입력받은 문자열에 따라 이동하는 시간과 누르는 시간을 저장
   for (int i = 0; i < str.length(); i++) {
      for (int j = 0; j < 14; j++) {
         if (str[i] == s_l[j]) {
            time += abs(l_postion[0] - s_l_p[j][0]) + abs(l_postion[1] - s_l_p[j][1]) + 1;
            l_postion[0] = s_l_p[j][0];
            l_postion[1] = s_l_p[j][1];
         }
         if (j < 12) {
            if (str[i] == s_r[j]) {
               time += abs(r_postion[0] - s_r_p[j][0]) + abs(r_postion[1] - s_r_p[j][1]) + 1;
               r_postion[0] = s_r_p[j][0];
               r_postion[1] = s_r_p[j][1];
            }
         }
      }
   }

   cout << time << "\n";

   return 0;
}