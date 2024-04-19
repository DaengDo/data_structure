import { beforeEach, describe, expect, test } from "@jest/globals";

import { SinglyLinkedList } from "./singlyLinkedList";

describe("singly linked list", () => {
  let linkedList: SinglyLinkedList<number>;

  beforeEach(() => {
    linkedList = new SinglyLinkedList<number>();
  });

  test("should initialized with null", () => {
    expect(linkedList.head()).toBe(null);
  });

  test("pushFront, pushBack", () => {
    linkedList.pushFront(1);
    expect(linkedList.head()?.value).toBe(1);

    linkedList.pushFront(2);
    expect(linkedList.head()?.value).toBe(2);
    expect(linkedList.tail()?.value).toBe(1);

    linkedList.pushBack(3);
    expect(linkedList.tail()?.value).toBe(3);

    linkedList.pushBack(4);
    expect(linkedList.tail()?.value).toBe(4);
  });

  test("popFront, popBack", () => {
    linkedList.popBack();
    linkedList.popFront();
    expect(linkedList.length()).toBe(0);
    linkedList.pushBack(1);
    linkedList.popBack();
    expect(linkedList.length()).toBe(0);

    linkedList.pushBack(2);
    linkedList.pushBack(3);
    linkedList.popBack();
    expect(linkedList.length()).toBe(1);
    linkedList.popFront();
    expect(linkedList.length()).toBe(0);
  });

  test("head", () => {
    linkedList.pushFront(1);
    expect(linkedList.head()?.value).toBe(1);
    linkedList.pushFront(2);
    expect(linkedList.head()?.value).toBe(2);
    linkedList.popBack();
    linkedList.popFront();
    expect(linkedList.head()).toBeNull();
  });

  test("tail", () => {
    linkedList.pushFront(1);
    expect(linkedList.tail()?.value).toBe(1);
    linkedList.pushFront(2);
    expect(linkedList.tail()?.value).toBe(1);
    linkedList.popBack();
    linkedList.popFront();
    expect(linkedList.tail()).toBeNull();
  });

  test("find", () => {
    linkedList.pushFront(1);
    linkedList.pushFront(2);
    linkedList.pushFront(3);

    expect(linkedList.find(1)).toEqual({ value: 1, next: null });
    expect(linkedList.find(2)).toEqual({ value: 2, next: { value: 1, next: null } });
    expect(linkedList.find(3)).toEqual({
      value: 3,
      next: {
        value: 2,
        next: {
          value: 1,
          next: null,
        },
      },
    });
  });

  test("remove", () => {
    linkedList.pushFront(1);
    linkedList.pushFront(2);
    linkedList.pushFront(3);

    const node = linkedList.find(2);
    linkedList.remove(node!);
    expect(linkedList.head()).toEqual({ value: 3, next: { value: 1, next: null } });
  });

  test("clear", () => {
    linkedList.pushFront(1);
    linkedList.pushFront(2);
    linkedList.pushFront(3);
    expect(linkedList.toArray()).toEqual([3, 2, 1]);

    linkedList.clear();
    expect(linkedList.length()).toBe(0);
    expect(linkedList.isEmpty()).toBe(true);
  });

  test("isEmpty", () => {
    expect(linkedList.isEmpty()).toBe(true);

    linkedList.pushFront(1);
    expect(linkedList.isEmpty()).toBe(false);
    linkedList.popBack();
    expect(linkedList.isEmpty()).toBe(true);

    linkedList.pushBack(22);
    expect(linkedList.isEmpty()).toBe(false);
    linkedList.popFront();
    expect(linkedList.isEmpty()).toBe(true);
  });

  test("length", () => {
    expect(linkedList.length()).toBe(0);
    linkedList.pushBack(1);
    linkedList.pushBack(2);
    expect(linkedList.length()).toBe(2);
    linkedList.pushBack(3);
    expect(linkedList.length()).toBe(3);
  });

  test("toArray", () => {
    linkedList.pushBack(1);
    linkedList.pushBack(2);
    expect(linkedList.toArray()).toEqual([1, 2]);
  });

  test("support iterable protocol", () => {
    linkedList.pushBack(1);
    linkedList.pushBack(2);
    linkedList.pushBack(3);

    const arrayLiteral = [1, 2, 3];
    // spread를 지원하는지 검사
    const listToArray = [...linkedList].map((n) => n?.value);
    expect(listToArray).toEqual(arrayLiteral);

    const iterator = linkedList[Symbol.iterator]();
    arrayLiteral.forEach((num) => {
      expect(num).toBe(iterator.next().value?.value);
    });
  });

  test("should works with integrated", () => {
    for (let i = 5; i > 0; i--) {
      linkedList.pushFront(i);
    }
    expect(linkedList.toArray()).toEqual([1, 2, 3, 4, 5]);

    [6, 7, 8, 9, 10].forEach((n) => {
      linkedList.pushBack(n);
      linkedList.print();
    });
    expect(linkedList.toArray()).toEqual([1, 2, 3, 4, 5, 6, 7, 8, 9, 10]);

    const thirdNode = linkedList.find(3);
    expect(thirdNode?.value).toBe(3);

    linkedList.insertBack(thirdNode!, 1000);
    expect(thirdNode?.next?.value).toBe(1000);

    linkedList.remove(thirdNode!);
    expect(linkedList.toArray()).toEqual([1, 2, 1000, 4, 5, 6, 7, 8, 9, 10]);

    linkedList.popFront();
    linkedList.popBack();
    linkedList.popBack();
    linkedList.popBack();
    linkedList.popFront();

    expect(linkedList.toArray()).toEqual([1000, 4, 5, 6, 7]);
    expect(linkedList.head()?.value).toBe(1000);
    expect(linkedList.tail()?.value).toBe(7);

    linkedList.clear();
    expect(linkedList.length()).toBe(0);
  });
});
