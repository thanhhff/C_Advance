#include <stdio.h>
#include <stdlib.h>
#include "fileSet.h"

#define MAX_NAME 80

/*
  r : mở chỉ đọc
  w : mở ghi 
  a : ghi tiếp xuống cuối 
  
  r+: đọc và ghi 
  w+: đọc và ghi (làm trắng file nếu đã tồn tại)
  a+: đọc và ghi vaò cuối file
*/
void fileOpenRead(FILE **f, char filename[])
{
  if ((*f = fopen(filename, "r")) == NULL)
  {
    printf("Can't open file: %s\n", filename);
    exit(0);
  }
}

void fileOpenWrite(FILE **f, char filename[])
{
  if ((*f = fopen(filename, "w")) == NULL)
  {
    printf("Can't open file: %s\n", filename);
    exit(0);
  }
}

void inputDataFromTxt(node **root, char filename[])
{
  FILE *fin;
  fileOpenRead(&fin, filename);

  elType *data = (elType *)malloc(sizeof(elType));

  while (1)
  {
    fscanf(fin, "%s %s %d", data->name, data->pass, &data->diem);
    if (feof(fin))
      break;
    insertTree(root, *data);
  }

  free(data);

  fclose(fin);
}

// void saveFileText(node *root, char filename[])
// {
//   FILE *fin;

//   fclose(fin);
// }
