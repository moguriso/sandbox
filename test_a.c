#include <stdio.h>

static unsigned char target_tbl[] = { 5, 7, 0, 2, 8, 3, 6, 1, 9, 4 };

void print_tbl(unsigned char* tbl, int cnt)
{
    int ii;
    for(ii=0; ii<cnt; ii++)
      printf("%u, ", target_tbl[ii]);
}

void swap(unsigned char* tbl, int src, int dst)
{
    int bk = tbl[dst];
    tbl[dst] = tbl[src];
    tbl[src] = bk;
}

void bubble_sort(unsigned char* tbl, int cnt)
{
    int ii, jj;
    for(ii=0; ii<cnt; ii++)
      for(jj=ii+1; jj<cnt; jj++)
        if(tbl[ii] > tbl[jj])
            swap(tbl, ii, jj);
}

int main()
{
    printf("input = ");
    print_tbl(target_tbl, sizeof(target_tbl));
    printf("\n");

    bubble_sort(target_tbl, sizeof(target_tbl));

    printf("input = ");
    print_tbl(target_tbl, sizeof(target_tbl));
    printf("\n");

    return 0;
}

