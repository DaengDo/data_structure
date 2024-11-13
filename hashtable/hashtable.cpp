#include <iostream>
#include <string>  // std::string

using namespace std;

template <typename K, typename V>
class HashTable {
 public:
  struct Item {
    K key = K();
    V value = V();
  };

  HashTable(const int& cap = 8) {
    capacity_ = cap;
    table_ = new Item[capacity_];
  }

  ~HashTable() { delete[] table_; }

  void Insert(const Item& item) {
    size_t index = HashFunc(item.key);  // 키를 인덱스로 사용
    // TODO: 개방 주소법으로 해시 충돌 해결하기
    // 만약 item의 value가 0이 아니라면 해시 충돌이 일어난 것으로 간주
    bool hasCollision = table_[index].value != 0;
    if (hasCollision) {
      while (true) {
        // index로 선형 조사 -> 빈 칸 찾으면 넣기, 빈 칸 없으면 메모리 늘리기
      }
    } else {
      table_[index] = item;
    }
  }

  V Get(const K& key) {
    size_t index = HashFunc(key);
    if (table_[index].key != key) return 0;  // TODO: 못 찾으면 0을 반환
    return table_[index].value;
  }

  // 정수 -> 해쉬값
  size_t HashFunc(const int& key) { return key % capacity_; }

  // 문자열을 정수 인덱스(해쉬값)로 변환
  // Horner's method
  // size_t HashFunc(const string& s)
  //{
  //  return TODO:
  //}

  void Print() {
    for (int i = 0; i < capacity_; i++)
      cout << i << " : " << table_[i].key << " " << table_[i].value << endl;
    cout << endl;
  }

 private:
  Item* table_ = nullptr;
  int capacity_ = 0;
};

int main() {
  // 충돌
  // - 개방 주소법: 선형 조사법
  // - 체이닝: 멤버 변수 Item* table_ 대신에 LinkedList<Item>* table_사용

  // 키: int, 값: int 인 경우
  // 키의 범위가 아주 크고 아이템의 개수는 적을 경우
  {
    using Item = HashTable<int, int>::Item;

    HashTable<int, int> h(8);

    h.Insert(Item{123, 456});

    h.Print();

    cout << "Get 123 " << h.Get(123) << endl;

    h.Insert(Item{1000021, 9898});

    h.Print();

    cout << "Get 1000021 " << h.Get(1000021) << endl;

    h.Insert(Item{1211, 999});  // hash collision!

    h.Print();

    cout << "Get 123 " << h.Get(123) << endl;
    cout << "Get 1211 " << h.Get(1211) << endl;
  }

  // 키: std::string, 값: int
  //{
  //	using Item = HashTable<string, int>::Item;

  //	HashTable<string, int> h(8);

  //	h.Insert(Item{ "apple", 1 });
  //	h.Insert(Item{ "orange", 2 });
  //	h.Insert(Item{ "mandarin", 4 });

  //	h.Print();

  //	cout << "apple " << h.Get("apple") << endl;
  //	cout << "orange " << h.Get("orange") << endl;
  //	cout << endl;

  //	h.Print();

  //	h.Insert(Item{ "tomato", 4 });

  //	h.Print();

  //	cout << "apple " << h.Get("apple") << endl;
  //	cout << "orange " << h.Get("orange") << endl;
  //	cout << "pineapple " << h.Get("pineapple") << endl;
  //	cout << endl;
  //}

  return 0;
}