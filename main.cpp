#include <stdio.h>
#include <stdlib.h>
#define SIZE 6
int main()
{

  int svyaz[SIZE][SIZE];
  int minimum[SIZE];
  int posewenie[SIZE];
  int temp, minindex, min;
  int begin_index = 0;
  for (int i = 0; i<SIZE; i++)
  {
    svyaz[i][i] = 0;
    for (int j = i + 1; j<SIZE; j++) {
      printf("Vvedite rasstoyanie ot %d goroda do - %d goroda: ", i + 1, j + 1);
      scanf("%d", &temp);
      svyaz[i][j] = temp;
      svyaz[j][i] = temp;
    }
  }
  for (int i = 0; i<SIZE; i++)
  {
    for (int j = 0; j<SIZE; j++)
      printf("%5d ", svyaz[i][j]);
    printf("\n");
  }
  for (int i = 0; i<SIZE; i++)
  {
    minimum[i] = 10000;
    posewenie[i] = 1;
  }
  minimum[begin_index] = 0;
  do {
    minindex = 10000;
    min = 10000;
    for (int i = 0; i<SIZE; i++)
    {
      if ((posewenie[i] == 1) && (minimum[i]<min))
      {
        min = minimum[i];
        minindex = i;
      }
    }
    if (minindex != 10000)
    {
      for (int i = 0; i<SIZE; i++)
      {
        if (svyaz[minindex][i] > 0)
        {
          temp = min + svyaz[minindex][i];
          if (temp < minimum[i])
          {
            minimum[i] = temp;
          }
        }
      }
      posewenie[minindex] = 0;
    }
  } while (minindex < 10000);

  printf("\nKratchaishee rastoyanie do goroda: \n");
  for (int i = 0; i<SIZE; i++)
    printf("%5d ", minimum[i]);
  int ver[SIZE];
  int end = 4;
  ver[0] = end + 1;
  int k = 1;
  int weight = minimum[end];

  while (end != begin_index)
  {
    for (int i = 0; i<SIZE; i++)
      if (svyaz[i][end] != 0)
      {
        int temp = weight - svyaz[i][end];
        if (temp == minimum[i])
        {
          weight = temp;
          end = i;
          ver[k] = i + 1;
          k++;
        }
      }
  }
  printf("\nVivod kratchaishego puti\n");
  for (int i = k - 1; i >= 0; i--)
    printf("%3d ", ver[i]);
  getchar();
  return 0;
}
