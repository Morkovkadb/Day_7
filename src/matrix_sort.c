#include <stdio.h>
#include <stdlib.h>

void run();
void input(int **matrix, int length, int width);
void my_sort(int **matrix, int length, int width);
int sum_row(int *arr, int length_first, int *arr_2, int length_second);
void swap_row(int **arr, int row1, int row2);
void print_matrix(int **matrix, int length, int wight);

int main() { run(); }

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
  my_sort(matrix, length, width);
  print_matrix(matrix, length, width);
  for (int i = 0; i < length; i++) {
    free(matrix[i]);
  }
  free(matrix);
}

void my_sort(int **matrix, int length, int width) {
  for (int i = 0; i < width; i++) {
    for (int j = 0; j < length - 1; j++) {
      if (sum_row(matrix[j], length, matrix[j + 1], length) == 1) {
        swap_row(matrix, j, j + 1);
      }
    }
  }
}

void input(int **matrix, int length, int width) {
  for (int i = 0; i < length; ++i) {
    for (int j = 0; j < width; ++j) {
      scanf("%d", &matrix[i][j]);
    }
  }
}

int sum_row(int *arr, int length_first, int *arr_2, int length_second) {
  int first_sum = 0, second_sum = 0;

  for (int i = 0; i < length_first; ++i) {
    first_sum += arr[i];
  }

  for (int i = 0; i < length_second; i++) {
    second_sum += arr_2[i];
  }

  if (first_sum > second_sum) {
    return 1;
  } else {
    return 0;
  }
}

void swap_row(int **arr, int row1, int row2) {
  int *temp = arr[row1];
  arr[row1] = arr[row2];
  arr[row2] = temp;
}

void print_matrix(int **matrix, int length, int wight) {
  for (int i = 0; i < wight; ++i) {
    for (int j = 0; j < length; ++j) {
      if (j != length - 1) {
        printf("%d ", matrix[i][j]);
      } else {
        printf("%d", matrix[i][j]);
      }
    }
    printf("\n");
  }
}