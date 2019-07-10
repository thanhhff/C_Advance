#ifndef FILE_SET
#define FILE_SET

#include "tree2search.h"

void fileOpenRead(FILE **f, char filename[]);
void fileOpenWrite(FILE **f, char filename[]);
void inputDataFromTxt(node **root, char filename[]);
void saveFileText(node *root, char filename[]);

#endif
