type LinkNode<T> = {
  value: T;
  next: LinkNode<T> | null;
};

class SinglyLinkedList<T = never> {
  private head_: LinkNode<T> | null = null;

  constructor(...value: T[]) {
    value.forEach((v) => this.pushBack(v));
  }

  // 이터레이션 프로토콜 구현
  [Symbol.iterator]() {
    let current = this.head_;

    return {
      next() {
        if (current) {
          const value = current;
          current = current.next;
          return { value: value, done: false };
        } else {
          return { done: true };
        }
      },
    };
  }

  isEmpty() {
    // : this is this & { head_: null } 이걸로 타입 가드 안되네?
    return this.head_ == null;
  }

  pushFront(value: T) {
    this.head_ = { value, next: this.head_ };
  }

  pushBack(value: T) {
    let current = this.head_;
    const newNode = { value, next: null };
    if (current == null) {
      // 아 여기 타입 가드 된다면 참 좋을텐데
      this.head_ = newNode;
      return;
    }
    while (current.next) {
      current = current.next;
    }
    current.next = newNode;
  }

  popFront() {
    if (this.head_ == null) return;
    this.head_ = this.head_.next;
  }

  popBack() {
    if (this.head_ == null || this.head_.next == null) return;
    let previous: LinkNode<T> | null = null;
    let current: LinkNode<T> | null = this.head_;
    while (current) {
      previous = current;
      current = current.next;
    }
    previous!.next = null;
  }

  insertBack(n: LinkNode<T>, value: T) {
    n.next = { value, next: n.next }; // 만약 n이 이 컨테이너에 없는 요소라도 연산을 해줄지?
  }

  reverse() {
    let previous: LinkNode<T> | null = null;
    let current = this.head_;
    while (current) {
      const temp = current.next;
      current.next = previous;
      previous = current;
      current = temp;
    }
  }

  remove(n?: LinkNode<T> | null) {
    if (this.head_ == null || !n) return;
    let current: LinkNode<T> | null = this.head_;
    while (current) {
      if (current.next === n) {
        current.next = current.next.next;
        return;
      }
      current = current.next;
    }
  }

  head() {
    return this.head_;
  }

  tail() {
    let current = this.head_;
    if (current == null) return null;

    while (current.next) {
      current = current.next;
    }
    return current;
  }

  find(value: T) {
    let current = this.head_;
    while (current) {
      if (current.value === value) return current;
      current = current.next;
    }
    return null;
  }

  findAll(value: T) {
    let current = this.head_;
    const buffer = [];
    while (current) {
      if (current.value === value) buffer.push(value);
      current = current.next;
    }
    return buffer.length === 0 ? null : buffer;
  }

  print() {
    let current = this.head_;
    const buffer = [];
    while (current) {
      buffer.push(current.value);
      current = current.next;
    }
    console.log(...buffer);
  }
}

// test

const linkedList = new SinglyLinkedList<number>();

for (let i = 5; i > 0; i--) {
  linkedList.pushFront(i);
  linkedList.print();
}

[6, 7, 8, 9, 10].forEach((n) => {
  linkedList.pushBack(n);
  linkedList.print();
});

const thirdNode = linkedList.find(3);

if (thirdNode) linkedList.insertBack(thirdNode, 1000);
linkedList.print();

linkedList.remove(thirdNode);
linkedList.print();

linkedList.popFront();
linkedList.popBack();
linkedList.popBack();
linkedList.popBack();
linkedList.popFront();

linkedList.print();

// iteration protocol
for (const value of linkedList) {
  value;
}
console.log([...linkedList]);

console.log(linkedList.head());
console.log(linkedList.tail());
