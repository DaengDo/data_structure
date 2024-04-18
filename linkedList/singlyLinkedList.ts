type LinkNode<T> = {
  item: T;
  next: LinkNode<T> | null;
};

class SinglyLinkedList<T = never> {
  constructor(item?: T) {
    item ? (this.first_ = { item, next: null }) : (this.first_ = null);
  }

  private first_: LinkNode<T> | null = null;

  public isEmpty() {
    // : this is this & { first_: null } 이걸로 타입 가드 안되네?
    return this.first_ == null;
  }

  public pushFront(item: T) {
    this.first_ = { item, next: this.first_ };
  }

  public pushBack(item: T) {
    let current = this.first_;
    const newNode = { item, next: null };
    if (current == null) {
      // 아 여기 타입 가드 된다면 참 좋을텐데
      this.first_ = newNode;
      return;
    }
    while (current.next) {
      current = current.next;
    }
    current.next = newNode;
  }

  public popFront() {}
  public popBack() {}
  public insertBack(n: LinkNode<T>, item: T) {}
  public reverse() {}
  public remove() {}

  public find(item: T) {
    let current = this.first_;
    while (current && current.item != item) {
      current = current.next;
    }
    if (current == null) {
      return null;
    } else {
      return current;
    }
  }
}

const linkedList = new SinglyLinkedList<number>();

linkedList.pushFront(1);
