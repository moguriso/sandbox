#include <stdio.h>
#include <stdlib.h>

int check_dup(unsigned char* tbl, int cnt, unsigned char target)
{
    int ii;

    for(ii=0; ii<cnt; ii++)
        if(tbl[ii] == target)
            return 1;

    return 0;
}

void gen(int end)
{
  int ii;
  unsigned int cnt = 0;
  unsigned char isFinish = 0;
  unsigned char *tbl = (unsigned char*)calloc(1, end*sizeof(char));

  if(tbl == NULL)
      goto exit;

  do{
      int d = rand()%end;
      if(check_dup(tbl, cnt, d) == 0)
        tbl[cnt++] = d;
      if(cnt == end)
        isFinish = 1;
  }while(!isFinish);

  for(ii=0; ii<end; ii++)
    printf("%u, ", tbl[ii]);
  printf("\n");

  free(tbl);

exit:
  return;
}


int main()
{
  srand(time(NULL));

  gen(100);
  printf("\n");
  gen(100);
  printf("\n");
  gen(100);
  printf("\n");

  return 0;
}

