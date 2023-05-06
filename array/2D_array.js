// create()
const arr2D = [
  [0, 1, 2],
  [3, 4, 5],
];

// set()
arr2D[0][1] = 100;

// get
arr2D[0][1];

arr2D.forEach((arr, idx) =>
  arr.forEach((e, i) => console.log(`arr2D[${idx}][${i}]: ${e}`)),
);
