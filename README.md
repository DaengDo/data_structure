# 자료구조 학습 일지

```
소프트웨어 업계에서 평생 밥 벌어 먹으면서 살고 싶습니다.
그런데 컴퓨터가 자료를 어떻게 처리하는지 조차 모르고 있네요?
작동 원리가 어떻게 실제로 사용되는지 알기 위해 자료구조를 좀 살펴봅니다.
```

## 배열

ADT

- `<인덱스, 값>` 쌍의 집합
- `create(size)`: size개의 요소를 저장할 수 있는 배열 저장
- `get(A, i)`: 배열 A의 i번째 요소 반환
- `set(A, i, v)`: 배열 A의 i번째 위치의 값을 v로 저장

## 학습 기록

- 05/07
  - c에서 배열은 이미 언어의 기능으로 제시되고 있기 때문에 까먹은 포인터 개념을 복습했다.
  - JS의 Array는 자료형과 크기가 고정된 배열이 아니다. 하지만 파일 버퍼나 webgl등 로우 레벨을 다룰 때 배열이 필요한데, 이때는 TypedArray를 사용한다.
  - 2차원 배열 예제도 서로 다른 스타일(명령형, 함수형)로 작성해보았다.
- 05/09
  - 2차원 배열로 행렬을 만들어보고, 전치 행렬로 변환해보았다.
- 05/10
  - 희소 행렬의 0인 부분을 제외하고 나머지 부분만 표현하는 자료구조 형태로 만들어 전치 행렬로 변환해보는 예제를 작성해보았다.
  - 역시나 JS로 먼저 작성했는데 고차함수를 받는 람다식은 정말 작성하기도 편리하고 읽기도 좋다.
