/* https://programmers.co.kr/learn/courses/30/lessons/42577?language=cpp
전화번호 목록

전화번호부에 적힌 전화번호 중, 한 번호가 다른 번호의 접두어인 경우가 있는지 확인하려 합니다.

입력
  전화번호부에 적힌 전화번호를 담은 배열 phone_book

출력
  어떤 번호가 다른 번호의 접두어인 경우가 있으면 false를 그렇지 않으면 true를 리턴

제한 사항
  phone_book의 길이는 1 이상 1,000,000 이하입니다.
    각 전화번호의 길이는 1 이상 20 이하입니다.
    같은 전화번호가 중복해서 들어있지 않습니다.

입출력 예제
  phone_book	return
  ["119", "97674223", "1195524421"]	false
  ["123","456","789"]	true
  ["12","123","1235","567","88"]	false */

/* #include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool solution(vector<string> phone_book) {
    // sort phone_book by string size in increasing order
    sort(phone_book.begin(), phone_book.end(), [](const string& first, const string& second) ->bool {
        return first.size() < second.size();
    });

    for (vector<string>::iterator i = phone_book.begin(); i < phone_book.end(); ++i) {
      string smallest = *i;
      for (auto j = i + 1; j < phone_book.end(); ++j) {
        string toBeCompared = *j;
        if (toBeCompared.substr(0, smallest.size()) == smallest) {
          return false;
        }
      }
    }

    return true;
}
길이 순서대로 오름차순 정렬 후 이중 포문으로 일치 여부 확인
시간 초과 */

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool solution(vector<string> phone_book) {
    sort(phone_book.begin(), phone_book.end());

    for (vector<string>::iterator i = phone_book.begin(); i != prev(phone_book.end()); ++i) {
      string shorter = *i;
      string longer = *(next(i));
      if (shorter == longer.substr(0, shorter.size())) {
        return false;
      }
    }
    return true;
}