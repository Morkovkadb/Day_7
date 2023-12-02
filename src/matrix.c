#include <stdio.h>
#include <stdlib.h>

void first_way_init_matrix() {
  int length;
  int weight;
  scanf("%d", &length);
  scanf("%d", &weight);
  int size = length * weight;
  int *matrix = (int *)malloc(sizeof(int) * (size));
  for (int i = 0; i < size; ++i) {
    scanf("%d", (matrix + i));
  }

  for (int i = 0; i < size; ++i) {
    printf("%d ", *(matrix + i));
  }
  free(matrix);
}

void second_way_init_matrix() {
  int length;
  int weight;
  scanf("%d", &length);
  scanf("%d", &weight);
  int **arr = (int **)malloc(sizeof(int) * weight);
  for (int i = 0; i < length; i++) {
    *(arr + i) = (int *)malloc(sizeof(int) * length);
  }
  for (int i = 0; i < length; ++i) {
    for (int j = 0; j < weight; ++j) {
      scanf("%d", &arr[i][j]);
    }
  }

  for (int i = 0; i < length; ++i) {
    for (int j = 0; j < weight; ++j) {
      printf("%d", arr[i][j]);
    }

    printf("\n");
  }

  for (int i = 0; i < length; ++i) {
    free(arr[i]);
  }

  free(arr);
}

void third_way_init_matrix() {
  int length, weight;
  scanf("%d", &length);
  scanf("%d", &weight);

  int **arr =
      (int **)malloc(length * weight * sizeof(int) + weight * sizeof(int *));
  int *ptr = (int *)(arr + weight);
  for (int i = 0; i < weight; ++i) {
    arr[i] = ptr + length * i;
  }

  for (int i = 0; i < weight; ++i) {
    for (int j = 0; j < length; ++j) {
      scanf("%d", &arr[i][j]);
    }
  }

  for (int i = 0; i < weight; ++i) {
    for (int j = 0; j < length; ++j) {
      printf("%d ", arr[i][j]);
    }
    printf("\n");
  }
  free(arr);
}

void four_way_init_matrix() {
  int length;
  int weight;
  scanf("%d", &length);
  scanf("%d", &weight);
  int matrix[length][weight];
  for (int i = 0; i < length; ++i) {
    for (int j = 0; j < weight; ++j) {
      scanf("%d", &matrix[i][j]);
    }
  }

  for (int i = 0; i < length; ++i) {
    for (int j = 0; j < weight; ++j) {
      printf("%d", matrix[i][j]);
    }
    printf("\n");
  }
}
int main() {
  int chouse = 0;
  scanf("%d", &chouse);
  if (chouse == 1) {
    first_way_init_matrix();
  } else if (chouse == 2) {
    second_way_init_matrix();
  } else if (chouse == 3) {
    third_way_init_matrix();
  } else if (chouse == 4) {
    four_way_init_matrix();
  } else {
    printf("n/a");
  }
  return 0;
}