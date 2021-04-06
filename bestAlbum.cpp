/* https://programmers.co.kr/learn/courses/30/lessons/42579?language=cpp
베스트앨범

스트리밍 사이트에서 장르 별로 가장 많이 재생된 노래를 두 개씩 모아 베스트 앨범을 출시하려 합니다. 
노래는 고유 번호로 구분하며, 노래를 수록하는 기준은 다음과 같습니다.
  속한 노래가 많이 재생된 장르를 먼저 수록합니다.
  장르 내에서 많이 재생된 노래를 먼저 수록합니다.
  장르 내에서 재생 횟수가 같은 노래 중에서는 고유 번호가 낮은 노래를 먼저 수록합니다.

입력
  노래의 장르를 나타내는 문자열 배열 genres
  노래별 재생 횟수를 나타내는 정수 배열 plays
  
출력
  베스트 앨범에 들어갈 노래의 고유 번호를 순서대로 return

제한사항
  genres[i]는 고유번호가 i인 노래의 장르입니다.
  plays[i]는 고유번호가 i인 노래가 재생된 횟수입니다.
  genres와 plays의 길이는 같으며, 이는 1 이상 10,000 이하입니다.
  장르 종류는 100개 미만입니다.
  장르에 속한 곡이 하나라면, 하나의 곡만 선택합니다.
  모든 장르는 재생된 횟수가 다릅니다.

입출력 예
  genres	plays	return
  ["classic", "pop", "classic", "classic", "pop"]	[500, 600, 150, 800, 2500]	[4, 1, 3, 0] */

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Song {
  public:
  Song() {
    id = -1;
    plays = 0;
  }
  Song(int id, int plays) {
    this->id = id;
    this->plays = plays;
  }
  ~Song() {}

  auto getId() const {
    return id;
  }
  auto getPlays() const {
    return plays;
  }

  private:
  int id;
  int plays;
};

class Genre {
  public:
  Genre() {}
  Genre(string newName) {
    name = newName;
    total_plays = 0;
  }
  ~Genre() {}

  auto getName() const {
    return name;
  }
  auto getTotalPlays() const {
    return total_plays;
  }

  void addSong(Song newSong) {
    auto newPlays = newSong.getPlays();

    total_plays += newPlays;

    if (newPlays > rank1.getPlays()) {
      rank2 = rank1;
      rank1 = newSong;
    } else if (newPlays > rank2.getPlays()) {
      rank2 = newSong;
    }
  }
  auto getTwoBestSongsIndexVector() const {
    vector<int> result;

    if (rank1.getId() != -1) {
      result.push_back(rank1.getId());

      if (rank2.getId() != -1) {
        result.push_back(rank2.getId());
      }
    }
    return result;
  }

  private:
  string name;
  int total_plays;
  Song rank1;
  Song rank2;
};

class BestAlbum {
  public:
  BestAlbum() {}
  ~BestAlbum() {}

  auto& getGenres() { // FIXME: not a good idea
    return genres;
  }

  void addGenre(Genre newGenre) {
    genres.push_back(newGenre);
  }
  void sortAlbum() {
    sort(genres.begin(), genres.end(), [](Genre first, Genre second) -> bool {
      return first.getTotalPlays() > second.getTotalPlays();
    });
  }
  auto getBest() const {
    vector<int> best;

    for (auto& genre : genres) {
      for (auto& index : genre.getTwoBestSongsIndexVector()) {
        best.push_back(index);
      }
    }
    return best;
  }

  private:
  vector<Genre> genres;
};

vector<int> solution(vector<string> genres, vector<int> plays) {
  BestAlbum bestAlbum;

  for (int id = 0; id < genres.size(); ++id) {
    Song newSong = Song(id, plays.at(id));
    string newGenreName = genres.at(id);
    bool added = false;

    for (auto& genre : bestAlbum.getGenres()) {
      if (genre.getName() == newGenreName) { // genre already exist
        genre.addSong(newSong);
        added = true;
        break;
      }
    }
    if (added == false) { // genre not exist
      Genre newGenre = Genre(newGenreName);
      newGenre.addSong(newSong);
      bestAlbum.addGenre(newGenre);
    }
  }
  bestAlbum.sortAlbum();
  return bestAlbum.getBest();
}