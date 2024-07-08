type LinkNode<T> = {
  value: T;
  next: LinkNode<T> | null;
};

export class SinglyLinkedList<T = never> {
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
          return { value, done: false };
        } else {
          return { done: true };
        }
      },
      [Symbol.iterator]() {
        return this;
      },
    };
  }

  length() {
    let count = 0;
    let current = this.head_;
    while (current) {
      count++;
      current = current.next;
    }

    return count;
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
    if (this.isEmpty()) {
      this.head_ = newNode;
      return;
    }
    while (current!.next) {
      current = current!.next;
    }
    current!.next = newNode;
  }

  popFront() {
    if (this.isEmpty()) return;
    if (this.length() === 1) {
      this.head_ = null;
      return;
    }
    this.head_ = this.head_!.next;
  }

  popBack() {
    if (this.isEmpty()) return;
    if (this.length() === 1) {
      this.head_ = null;
      return;
    }
    let previous: LinkNode<T> | null = null;
    let current: LinkNode<T> | null = this.head_;
    while (current?.next) {
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

  remove(n: LinkNode<T>) {
    if (this.isEmpty() || !n) return;
    let current: LinkNode<T> | null = this.head_;
    while (current) {
      if (current.next === n) {
        current.next = current.next.next;
        return;
      }
      current = current.next;
    }
  }

  clear() {
    this.head_ = null;
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

  toArray(verbose = false) {
    return (verbose ? [...this] : [...this].map((node) => node!.value)) as T[];
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
