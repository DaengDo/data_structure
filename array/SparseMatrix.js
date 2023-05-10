// 희소 행렬 (0많은 행렬)

// const sparseMatrix = [
//   [0, 0, 0, 7, 0, 0],
//   [9, 0, 0, 0, 0, 8],
//   [0, 0, 0, 0, 0, 0],
//   [6, 5, 0, 0, 0, 0],
//   [0, 0, 0, 0, 0, 1],
//   [0, 0, 2, 0, 0, 0],
// ];

// 위 행렬을 0인 부분을 제외하는 자료구조로 표현
const sparseMatrix = [
  [0, 3, 7], // 0,3 의 값 7
  [1, 0, 9], // 1,0 의 값 9
  [1, 5, 8], // 이하 생략
  [3, 0, 6],
  [3, 1, 5],
  [4, 5, 1],
  [5, 2, 2],
];

const transpose = sparseMatrix
  .map(([row, col, val]) => [col, row, val])
  .sort(([row1, col1], [row2, col2]) => row1 - row2 || col1 - col2);

console.log(transpose);
