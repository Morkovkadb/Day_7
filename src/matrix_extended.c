#include <stdio.h>
#include <stdlib.h>

void run();
int input(int **arr, int length, int width);
int *find_min(int **matrix, int length, int width);
int *find_max(int **matrix, int length, int width);
int output(int **arr, int length, int width);

int input(int **arr, int length, int width) {
  for (int i = 0; i < length; ++i) {
    for (int j = 0; j < width; ++j) {
      scanf("%d", &arr[i][j]);
    }
  }
  return 0;
}

int output(int **arr, int length, int width) {
  for (int i = 0; i < length; ++i) {
    for (int j = 0; j < width; ++j) {
      printf("%d", *(*(arr + i) + j));
    }
    printf("\n");
  }
  return 0;
}

int *find_min(int **matrix, int length, int width) {
  int *arr_min_value = (int *)malloc(sizeof(int) * width);
  for (int i = 0; i < width; ++i) {
    int min = matrix[0][i];
    for (int j = 0; j < length; j++) {
      if (min > matrix[i][j]) {
        min = matrix[i][j];
      }
    }
    arr_min_value[i] = min;
  }
  return arr_min_value;
}

int *find_max(int **matrix, int length, int width) {
  int *arr_max_value = (int *)malloc(sizeof(int) * width);
  for (int i = 0; i < width; ++i) {
    int max = matrix[i][0];
    for (int j = 0; j < length; j++) {
      if (max < matrix[j][i]) {
        max = matrix[j][i];
      }
    }
    arr_max_value[i] = max;
  }
  return arr_max_value;
}

void output_arr(int *array, int length) {
  for (int i = 0; i < length; ++i) {
    printf("%d", *(array + i));
  }
}

void run() {
  int length, width;
  int **matrix;
  scanf("%d", &length);
  scanf("%d", &width);
  matrix = (int **)malloc(sizeof(int *) * length);
  for (int i = 0; i < length; i++) {
    matrix[i] = malloc(sizeof(int) * width);
  }
  input(matrix, length, width);
  printf("\n");
  output(matrix, width, length);
  printf("\n");
  int *min_arr = find_min(matrix, length, width);
  int *max_arr = find_max(matrix, length, width);
  output_arr(min_arr, length);
  printf("\n");
  output_arr(max_arr, width);
  printf("\n");
  for (int i = 0; i < width; ++i) {
    free(matrix[i]);
  }
  free(matrix);
  free(min_arr);
  free(max_arr);
}
int main() {
  run();
  return 0;
}