 #include <bits/stdc++.h>
//#include <vector>
using namespace std;

// 단어 수학 문제는 N개의 단어로 이루어 짐
// 각 단어는 알파벳 대문자로만 이루어짐
// 각 알파벳 대문자를 0~9 숫자 중 하나로 바꿔서 N개의 수를 합하는 문제
// 같은 알파벳은 같은 숫자로 바꿔야 함
// N개의 단어가 주어졌을 때 합을 최대로 만드는 프로그램 작성

 struct Character
 {
     char ch;
     int cnt;
 };

 class Descending
 {
 public:
     bool operator()(const Character &a, const Character &b)
     {
         return a.cnt > b.cnt;
     }
 };

 class Converter
 {
 public:
     Converter(int maxLevel) : maxLevel(maxLevel)
     {
         chars = vector<vector<Character>>(maxLevel);
     };

     void set(string word, vector<int> &cnt)
     {
         // ABCDE => maxLevel = 5,
         // GDF => G는 레벨이 2이어야 함
         for (int l = 0; l < word.length(); l++)
         {
             int level = maxLevel - word.length() + l;
             char ch = word.at(l);
             chars[level].push_back({ch, cnt[ch - 'A']}); // l -> ch
         }
     }

     long long convert()
     {
         int curNum = 9;
         long long sum = 0;
         vector<int> convert = vector<int>(26, -1);

         for (int l = 0; l < chars.size(); l++)
         {
             sort(chars[l].begin(), chars[l].end(), Descending());
             for (Character ch : chars[l])
             {
//                 cout << ch.ch << '\n';
                 long long power = pow(10, chars.size() - l - 1);
                 if (convert[ch.ch - 'A'] > -1)
                 {
//                     cout << ch.ch << ' ' << convert[ch.ch - 'A'] * power << '\n';
                     sum += convert[ch.ch - 'A'] * power;
                 }
                 else
                 {
                     convert[ch.ch - 'A'] = curNum;
//                     cout << ch.ch << ' ' << convert[ch.ch - 'A'] * power << '\n';
                     sum += curNum * power;
                     curNum--;
                 }
             }
         }

         return sum;
     }

 private:
     vector<vector<Character>> chars;
     int maxLevel;
 };

 int main()
 {
     ios::sync_with_stdio(0);
     cin.tie(0);

     int n;
     cin >> n;

     vector<string> words;
     vector<int> cnt(26, 0);
     int maxLen = 0;
     for (int i = 0; i < n; i++)
     {
         string s;
         cin >> s;
         words.push_back(s);
         maxLen = max<int>(maxLen, s.length());
         for (char ch : s)
         {
             cnt[ch - 'A'] += 1;
         }
     }

     Converter converter(maxLen);
     for (auto word : words)
     {
         converter.set(word, cnt);
     }

     cout << converter.convert() << '\n';

     // 1. 단어를 모두 받는다
     // 2. 레벨 별 순회?
     // 2-1. 레벨 나타내는 인덱스를 두고, 각 문자열 순회
     // 2-2. map에 있는지 확인하고 있으면 사용, 없으면 값 넣기
     // 2-3. 길이가 끝났으면 pass. 모든 문자열이 끝날때 까지 반복
     // 3. 레벨 순서대로 숫자 부여
 }

 //10
 //ABB
 //BB
 //BB
 //BB
 //BB
 //BB
 //BB
 //BB
 //BB
 //BB
 //정답값 : 1790
 //출력값 : 1780