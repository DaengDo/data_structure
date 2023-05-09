const matrix = [
  [1, 2, 3],
  [4, 5, 6],
  [7, 8, 9],
];

// [1, 2, 3], [4, 5, 6], [7, 8, 9] 를 [1,4,7], [2,5,8], [3,6,9]로 변경
// 0 1 2 를 3번 선회하면서 기존 matrix를 세로로 참조

console.log(matrix[0].map((_, colIndex) => matrix.map((row) => row[colIndex])));
