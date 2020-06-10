#include <stdio.h>
#include <stdlib.h>

typedef struct matrix {
        int l, c;
        int n;
        int *lin;
        int *col;
        float *x;
} matrix;

void read_mat(int line[], int column[], float nr[], int size) {
        int i;
        for (i = 0; i < size; i++) {
                scanf("%d", &line[i]);
        }
        for (i = 0; i < size; i++) {
                scanf("%d", &column[i]);
        }
        for (i = 0; i < size; i++) {
                scanf("%f", &nr[i]);
        }
}

int find_poz(int a, int b, int *line, int *column, int size) {
        int i, j;
        for (i = 0; i < size; i++) {
                if (a == line[i] && b == column[i]) {
                        return 1;
                }
        }
        return 0;
}

void print_mat(int *line, int *column, float *nr, int size, int l, int c) {
        int i, j, k = 0;
        for (i = 0; i < l; i++) {
                for (j = 0; j < c; j++) {
                        if (find_poz(i, j, line, column, size) == 1) {
                                printf("%.0f ", nr[k]);
                                k++;
                        } else {
                                printf("0 ");
                        }
                }
                printf("\n");
        }
}

int cmp(int a, int b, int c, int d) {
	if (a > c) {
		return -1;
	} else {
		if (a == c) {
			if (b > d) {
				return -1;
			} else {
				if (b == d) {
					return 0;
				} else {
					return 1;
				}
			}
		} else {
			return 1;
		}
	}
}

void mat_sum(matrix *a, matrix *b) {
	matrix sum;
	int i, j, k, count = 0, check;
	if (a->l != b->l && a->c != b->c) {
		printf("Size differs!");
		return;
	}
	sum.l = a->l;
	sum.c = a->c;
    while (i < a->n && j < b->n) {
    	check = cmp(a->lin[i], a->col[i], b->lin[j], b->col[j]);
    	if (check == 0) {
    		count++;
    	}
    }
	sum.n = (a->n + b->n) - count;
	sum.lin = (int *)malloc(sum.n * sizeof(int));
    sum.col = (int *)malloc(sum.n * sizeof(int));
    sum.x = (float *)malloc(sum.n * sizeof(float));
    i = 0;
    j = 0;
    k = 0;
    while (i < a->n && j < b->n) {
    	check = cmp(a->lin[i], a->col[i], b->lin[j], b->col[j]);
    	if (check == 1) {
    		sum.lin[k] = a->lin[i];
    		sum.col[k] = a->col[i];
    		sum.x[k] = a->x[i];
    		i++;
    	} else {
    		if (check == -1) {
    			sum.lin[k] = b->lin[j];
    			sum.col[k] = b->col[j];
    			sum.x[k] = b->x[j];
    			j++;
    		} else {
    			if (check == 0) {
    				sum.lin[k] = a->lin[i];
    				sum.col[k] = a->col[i];
    				sum.x[k] = a->x[i] + b->x[j];
    				i++;
    				j++;
    			}
    		}
    	}
    	k++;
    }
    print_mat(sum.lin, sum.col, sum.x, sum.n, sum.l, sum.c);
}

int main() {
        matrix mat, a, b;
        // scanf("%d %d", &mat.l, &mat.c);
        // scanf("%d", &mat.n);
        // mat.lin = (int *)malloc(mat.n * sizeof(int));
        // mat.col = (int *)malloc(mat.n * sizeof(int));
        // mat.x = (float *)malloc(mat.n * sizeof(float));
        // read_mat(mat.lin, mat.col, mat.x, mat.n);
        // print_mat(mat.lin, mat.col, mat.x, mat.n, mat.l, mat.c);
        // free(mat.lin);
        // free(mat.col);
        // free(mat.x);
        scanf("%d %d", &a.l, &a.c);
        scanf("%d", &a.n);
        a.lin = (int *)malloc(a.n * sizeof(int));
        a.col = (int *)malloc(a.n * sizeof(int));
        a.x = (float *)malloc(a.n * sizeof(float));
        read_mat(a.lin, a.col, a.x, a.n);
        scanf("%d %d", &b.l, &b.c);
        scanf("%d", &b.n);
        b.lin = (int *)malloc(b.n * sizeof(int));
        b.col = (int *)malloc(b.n * sizeof(int));
        b.x = (float *)malloc(b.n * sizeof(float));
        read_mat(b.lin, b.col, b.x, b.n);
        mat_sum(&a, &b);
        free(a.lin);
        free(a.col);
        free(a.x);
        free(b.lin);
        free(b.col);
        free(b.x);
        return 0;
}