function createStack(size) {
  const stack = [];
  const maxSize = size;

  function push(element) {
    if (isFull()) {
      return console.log('스택오버플로');
    }
    stack.push(element);
  }

  function pop() {
    if (isEmpty()) {
      return console.log('top 없음!');
    }
    return stack.pop();
  }

  function peek() {
    if (isEmpty()) {
      return console.log('빈 스택');
    }
    return stack[stack.length - 1];
  }

  function isEmpty() {
    return stack.length === 0;
  }

  function isFull() {
    return stack.length === maxSize;
  }

  function getSize() {
    return stack.length;
  }

  function clear() {
    stack.length = 0;
  }

  return {
    push,
    pop,
    peek,
    isEmpty,
    isFull,
    getSize,
    clear,
  };
}
