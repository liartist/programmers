/* https://programmers.co.kr/learn/courses/30/lessons/68644
두 개 뽑아서 더하기

정수 배열 numbers가 주어집니다. 
numbers에서 서로 다른 인덱스에 있는 두 개의 수를 뽑아 더해서 만들 수 있는 모든 수를 배열에 오름차순으로 담아 return

제한사항
  numbers의 길이는 2 이상 100 이하입니다.
    numbers의 모든 수는 0 이상 100 이하입니다.

입출력 예
  numbers	result
  [2,1,3,4,1]	[2,3,4,5,6,7]
  [5,0,2,7]	[2,5,7,9,12] */

#include <string>
#include <vector>
#include <set>

using namespace std;

vector<int> solution(vector<int> numbers) {
  set<int> answer;
  vector<int> answer_vector;

  for (int i = 0; i < numbers.size(); ++i) {
    for (int j = i + 1; j < numbers.size(); ++j) {
      answer.insert(numbers.at(i) + numbers.at(j));
    }
  }
  answer_vector.assign(answer.begin(), answer.end());
  return answer_vector;
}