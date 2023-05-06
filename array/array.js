// js는 자료형과 사이즈가 고정된 배열을 일반적으로 사용하지 않는다.
const arr = [0, 1, 2, 3, 4, 5]; // create()
arr[1] = 100; // set()
arr[1] = '100'; // 자료형 크기가 고정되지 않음
arr[6] = 6;
arr[1]; // get()

// 고정 자료형과 크기를 사용하는 배열은 TypedArray 프로토타입을 상속받는 자로형으로 생성 가능하다.
const typedArr = new Int32Array([0, 1, 2, 3, 4, 5]);
typedArr[1] = 100; // set()
typedArr[1]; // get()
