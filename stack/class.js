class Stack {
  constructor(size) {
    this.items = new Array(size);
    this.maxSize = size;
    this.top = -1;
  }

  isEmpty() {
    return this.top === -1;
  }

  isFull() {
    return this.top === this.maxSize - 1;
  }

  peek() {
    if (this.isEmpty()) return console.log('top 없음, 스택 빔');
    return this.items[this.top];
  }

  pop() {
    if (this.isEmpty()) return console.error('pop 불가능, 스택 빔');
    delete this.items[this.top--];
    return this.items;
  }

  push(item) {
    if (this.isFull()) return console.error('StackOverFlow!');
    this.items[++this.top] = item;
    return this.items;
  }

  size() {
    return this.maxSize;
  }

  print() {
    return console.log(this.items);
  }
}

const stack = new Stack(3);

stack.push(1);
stack.push(2);
stack.push(3);
stack.push(4);

console.log(stack.peek());

stack.print();

stack.pop();
stack.pop();
stack.pop();

stack.print();

stack.pop();
