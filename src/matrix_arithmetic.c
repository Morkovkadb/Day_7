#include <stdio.h>
#include <stdlib.h>

int input(int **matrix, int *n, int *m);
void output(int **matrix, int n, int m);
int sum(int **matrix_first, int n_first, int m_first, int **matrix_second,
        int n_second, int m_second, int **matrix_result, int *n_result,
        int *m_result);
int transpose(int **matrix, int n, int m);
int mul(int **matrix_first, int m_first, int **matrix_second, int n_second,
        int **matrix_result, int *n_result, int *m_result);
void run();
void print_matrix(int **matrix, int length, int wight);

int main() {
  run();
  return 0;
}
int input(int **matrix, int *n, int *m) {
  for (int i = 0; i < *n; ++i) {
    for (int j = 0; j < *m; ++j) {
      scanf("%d", &matrix[i][j]);
    }
  }
  return 0;
}

void output(int **matrix, int n, int m) {
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      printf("%d", matrix[i][j]);
      if (j == m - 1)
        printf("\n");
    }
  }
}

int sum(int **matrix_first, int n_first, int m_first, int **matrix_second,
        int n_second, int m_second, int **matrix_result, int *n_result,
        int *m_result) {
  if (n_first != n_second || m_first != m_second) {
    *n_result = 0;
    *m_result = 0;
  }

  *n_result = n_first;
  *m_result = m_first;

  for (int i = 0; i < n_first; ++i) {
    for (int j = 0; j < m_first; ++j) {
      matrix_result[i][j] = matrix_first[i][j] + matrix_second[i][j];
    }
  }
  return 0;
}

int transpose(int **matrix, int n, int m) {
  int **transpose_matr = malloc(m * sizeof(int *));
  for (int i = 0; i < n; ++i) {
    transpose_matr[i] = malloc(n * sizeof(int));
    for (int j = 0; j < m; ++j) {
      transpose_matr[i][j] = matrix[j][i];
    }
  }

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      matrix[i][j] = transpose_matr[i][j];
    }
  }
  for (int i = 0; i < m; i++) {
    free(transpose_matr[i]);
  }
  free(transpose_matr);
  return 0;
}

int mul(int **matrix_first, int m_first, int **matrix_second, int n_second,
        int **matrix_result, int *n_result, int *m_result) {
  if (m_first != n_second) {
    *n_result = 0;
    *m_result = 0;
  }

  for (int i = 0; i < *n_result; ++i) {
    for (int j = 0; j < *m_result; ++j) {
      matrix_result[i][j] = 0;
      for (int k = 0; k < m_first; ++k) {
        matrix_result[i][j] += matrix_first[i][k] * matrix_second[k][j];
      }
    }
  }
  return 0;
}

void run() {
  int operation = 0;
  scanf("%d", &operation);

  int first_lengt = 0;
  int first_width = 0;
  int second_lengt = 0;
  int second_width = 0;
  scanf("%d", &first_lengt);
  scanf("%d", &first_width);
  int **matrix_first;
  matrix_first = (int **)malloc(sizeof(int *) * first_lengt);
  for (int i = 0; i < first_lengt; i++) {
    matrix_first[i] = malloc(sizeof(int) * first_width);
  }
  input(matrix_first, &first_lengt, &first_width);
  int **matrix_second;
  if (operation != 3) {

    scanf("%d", &second_lengt);
    scanf("%d", &second_width);
    matrix_second = (int **)malloc(sizeof(int *) * second_lengt);
    for (int i = 0; i < second_lengt; i++) {
      matrix_second[i] = malloc(sizeof(int) * second_width);
    }
    input(matrix_second, &second_lengt, &second_width);
  }
  if (operation == 1) {

    int **matrix_result;
    matrix_result = (int **)malloc(sizeof(int *) * second_lengt);
    for (int i = 0; i < second_lengt; i++) {
      matrix_result[i] = malloc(sizeof(int) * second_width);
    }

    sum(matrix_first, first_lengt, first_width, matrix_second, second_lengt,
        second_width, matrix_result, &second_lengt, &second_width);
    print_matrix(matrix_result, second_lengt, second_width);
    for (int i = 0; i < first_lengt; i++) {
      free(matrix_result[i]);
    }

    free(matrix_result);
  } else if (operation == 2) {
    int **matrix_result;
    matrix_result = (int **)malloc(sizeof(int *) * first_lengt);
    for (int i = 0; i < first_lengt; i++) {
      matrix_result[i] = malloc(sizeof(int) * second_width);
    }

    mul(matrix_first, first_width, matrix_second, second_lengt, matrix_result,
        &first_lengt, &second_width);
    print_matrix(matrix_result, first_lengt, second_width);
    for (int i = 0; i < first_lengt; i++) {
      free(matrix_result[i]);
    }

    free(matrix_result);
    if (matrix_second != NULL) {
      for (int i = 0; i < second_lengt; i++) {
        free(matrix_second[i]);
      }
      free(matrix_second);
    }

  }

  else if (operation == 3) {
    int **matrix_result;
    matrix_result = (int **)malloc(sizeof(int *) * first_width);
    for (int i = 0; i < first_width; i++) {
      matrix_result[i] = malloc(sizeof(int) * first_lengt);
    }

    transpose(matrix_first, first_lengt, first_width);
    print_matrix(matrix_first, first_width, first_lengt);
    for (int i = 0; i < first_lengt; i++) {
      free(matrix_result[i]);
    }

    free(matrix_result);
  }
  for (int i = 0; i < first_lengt; ++i) {
    free(matrix_first[i]);
  }
  free(matrix_first);
}

void print_matrix(int **matrix, int length, int wight) {
  for (int i = 0; i < length; ++i) {
    for (int j = 0; j < wight; ++j) {
      if (j != length - 1) {
        printf("%d ", matrix[i][j]);
      } else {
        printf("%d", matrix[i][j]);
      }
    }
    if (i != wight) {
      printf("\n");
    }
  }
}