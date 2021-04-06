/* https://programmers.co.kr/learn/courses/30/lessons/42578?language=cpp
위장

스파이들은 매일 다른 옷을 조합하여 입어 자신을 위장합니다.

입력
  스파이가 가진 의상들이 담긴 2차원 배열 clothes
  
출력
  서로 다른 옷의 조합의 수를 return

제한사항
  clothes의 각 행은 [의상의 이름, 의상의 종류]로 이루어져 있습니다.
  스파이가 가진 의상의 수는 1개 이상 30개 이하입니다.
  같은 이름을 가진 의상은 존재하지 않습니다.
  clothes의 모든 원소는 문자열로 이루어져 있습니다.
  모든 문자열의 길이는 1 이상 20 이하인 자연수이고 알파벳 소문자 또는 '_' 로만 이루어져 있습니다.
  스파이는 하루에 최소 한 개의 의상은 입습니다.

입출력 예
  clothes	return
  [["yellowhat", "headgear"], ["bluesunglasses", "eyewear"], ["green_turban", "headgear"]]	5
  [["crowmask", "face"], ["bluesunglasses", "face"], ["smoky_makeup", "face"]]	3 */

#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(vector<vector<string>> clothes) {
  int answer = 1;
  map<string, int> category_count;

  // filling the category_count
  for (vector<vector<string>>::iterator i = clothes.begin(); i != clothes.end(); ++i) {
    string category = (*i).at(1);
    
    if (category_count.count(category) > 0) {
      category_count[category] += 1;
    } else {
      category_count[category] = 1;
    }
  }
  for (map<string, int>::iterator i = category_count.begin(); i != category_count.end(); ++i) {
    int count = (*i).second;
    answer *= (count + 1);
  }
  return answer - 1;
}