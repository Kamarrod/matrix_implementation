#include "s21_matrix.h"

int s21_is_empty(matrix_t * matrix) {
  int res = 0;
  if (matrix == NULL || matrix->matrix == NULL || matrix->rows <= 0 ||
      matrix->columns <= 0) {
    res = 1;
  } else {
    res = 0;
  }
  return res;
}


// int s21_create_matrix(int rows, int columns, matrix_t *result) {
//     int res = 1;
//     if (rows > 0 && columns > 0) {
//         result->rows = rows;
//         result->columns = columns;
//         double **temp = malloc(rows * columns * sizeof(double) + rows * sizeof(double*));
//         if (temp) {
//           double *ptr = (double*) (temp + columns);
//           for (int i = 0; i < columns; i++) {
//             temp[i] = ptr + rows * i;
//           }
//             if (ptr) {
//               res = 0;
//               result->matrix = temp;
//             } else {
//               free (temp);
//               res = 1;
//             }
//         }
//     }
//     return res;
// }

int s21_create_matrix(int rows, int columns, matrix_t *result) {
  int res = 0;
  if (rows < 1 || columns < 1) {
    res = 1;
  } else {
    result->rows = rows;
    result->columns = columns;
    result->matrix = (double **)calloc(rows, sizeof(double *));
    res = 0;
  }
  if (result->matrix != NULL) {
    for (int i = 0; i < rows; i++) {
      result->matrix[i] = (double *)calloc(columns, sizeof(double));
      if (!result->matrix[i]) {
        for (int j = 0; j < i; j++) free(result->matrix[j]);
        free(result->matrix);
      }
    }
    res = 0;
  }
  return res;
}


// void s21_remove_matrix(matrix_t *A) {
//   if (A->matrix != NULL) {
//     free(A->matrix);
//     A->columns = 0;
//     A->rows = 0;
//   }
// }

void s21_remove_matrix(matrix_t *A) {
  if (A->matrix != NULL) {
    for (int i = 0; i < A->rows; i++) {
      free(A->matrix[i]);
    }
    free(A->matrix);
  }
  A->matrix = NULL;
  A->rows = 0;
  A->columns = 0;
}

int s21_eq_matrix(matrix_t *A, matrix_t *B) {
  int res = SUCCESS;
  if ((s21_is_empty(A) != 0) || (s21_is_empty(B) != 0 )|| (A->rows != B->rows) || (A->columns != B->columns)) {
    res = FAILURE;
  } else {
    int rows = A->rows;
    int columns = A->columns;
    for (int i = 0; i < rows && res; i++) {
      for (int j = 0; j < columns && res; j++) {
        if (fabs(A->matrix[i][j] - B->matrix[i][j]) > 1e-6)
          res = FAILURE;
      }
    }
  }
  return res;
}


int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int res = 0;
  if (s21_is_empty(A) == 0 && s21_is_empty(B) == 0) {
    if (A->rows == B->rows && A->columns == B->columns) {
      res = s21_create_matrix(A->rows, A->columns, result);
      for (int i = 0; i < A->rows; i++) {
        for (int j = 0; j < A->columns; j++)
          result->matrix[i][j] = A->matrix[i][j] + B->matrix[i][j];
      }
    } else {
      res = 2;
    }
  } else {
    res = 1;
  }
  return res;
}

int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int res = 0;
  if (s21_is_empty(A) == 0 && s21_is_empty(B) == 0) {
    if (A->rows == B->rows && A->columns == B->columns) {
      res = s21_create_matrix(A->rows, A->columns, result);
      for (int i = 0; i < A->rows; i++) {
        for (int j = 0; j < A->columns; j++)
          result->matrix[i][j] = A->matrix[i][j] - B->matrix[i][j];
      }
    } else {
      res = 2;
    }
  } else {
    res = 1;
  }
  return res;
}


int s21_mult_number(matrix_t *A, double number, matrix_t *result) {
  int res = 0;
  if (s21_is_empty(A) == 0) {
    if (result->matrix != NULL) {
      s21_remove_matrix(result);
    }
      res = s21_create_matrix(A->rows, A->columns, result);
      for (int i = 0; i < A->rows; i++) {
        for (int j = 0; j < A->columns; j++)
          result->matrix[i][j] = A->matrix[i][j] * number;
      }
  } else {
    res = 1;
  }
  return res;
}


int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
   int res = 0;
  if (s21_is_empty(A) == 0 && s21_is_empty(B) == 0) {
    if (A->columns == B->rows) {
      res = s21_create_matrix(A->rows, B->columns, result);
      for (int i = 0; i < A->rows; i++) {
        for (int j = 0; j < B->columns; j++) {
          double tempSum = 0;
          for (int k = 0; k < A->columns; k++) {
            tempSum += A->matrix[i][k] * B->matrix[k][j];
          }
          result->matrix[i][j] = tempSum;
        }
      }
    } else {
      res = 2;
    }
  } else {
    res = 1;
  }
  return res;
}

int s21_transpose(matrix_t *A, matrix_t *result) {
  int res = 0;
  if (s21_is_empty(A) == 0) {
    if (result->matrix != NULL) {
      s21_remove_matrix(result);
    }
      res = s21_create_matrix(A->columns, A->rows, result);
      for (int i = 0; i < A->rows; i++) {
        for (int j = 0; j < A->columns; j++)
          result->matrix[j][i] = A->matrix[i][j];
      }
  } else {
    res = 1;
  }
  return res;
}

int s21_determinant(matrix_t *A, double *result) {
  int res = 0;
  if (s21_is_empty(A) == 0) {
    if (A->columns == A->rows) {
      *result = s21_get_determinant(A);
    } else {
      res = 2;
    }
  } else {
    res = 1;
  }
  return res;
}

void s21_get_matrix(int rows, int columns, matrix_t *A, matrix_t *result) {
  int row = 0;
  int col = 0;
  for (int i = 0; i < A->rows; i++) {
    if (i == rows) {
      continue;
    }
    col = 0;
    for (int j = 0; j < A->columns; j++) {
      if (j == columns) {
        continue;
      }
      result->matrix[row][col] = A->matrix[i][j];
      col++;
    }
    row++;
  }
}

double s21_get_determinant(matrix_t *A) {
  double flag = 0.0;
  if (A->rows == 1) {
    flag = A->matrix[0][0];
  } else {
    matrix_t tmp = {0};
    s21_create_matrix(A->rows - 1, A->columns - 1, &tmp);
    for (int i = 0; i < A->columns; i++) { 
      s21_get_matrix(0, i, A, &tmp);
      if (i % 2) {
        flag -= A->matrix[0][i] * s21_get_determinant(&tmp);
      } else {
        flag += A->matrix[0][i] * s21_get_determinant(&tmp);
      }
    }
    s21_remove_matrix(&tmp);
  }
  return flag;
}

double s21_get_minor(int row, int column, matrix_t *A) {
  matrix_t temp = {0};
  s21_create_matrix(A->rows- 1, A->columns -1, &temp);
  int minor_row = 0, minor_column = 0;
  for (int i = 0; i < A->rows; i++) {
    minor_column = 0;
    for (int j = 0; j < A->columns; j++) {
      if (j != column) {
        minor_column++;
        temp.matrix[minor_row][minor_column] = A->matrix[i][j];
      }
    }
    if (i != row)
      minor_row++;
  }

  double res = s21_determinant(&temp);
  s21_remove_matrix(&temp);
  return res;
}

int s21_calc_complements(matrix_t *A, matrix_t *result) {
  int res = 0;
  if (s21_is_empty(A) == 0) {
    if (A->columns == A->rows) {
      int sign = 1;
      s21_create_matrix(A->rows, A->columns, result);
      for (int i = 0; i < A->rows; i++)
        for (int j = 0; j < A->rows; j++) {
          sign = (i + j + 2) % 2 == 0 ? 1 : -1;
          result->matrix[i][j] = sign * s21_get_minor(i, j, A);
        }
    } else {
      res = 2;
    }
  } else {
    res = 1;
  }
  return res;
}