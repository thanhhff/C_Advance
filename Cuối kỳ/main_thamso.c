#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "GraphAPI/graph_jrb.h"
#include "libfdr/fields.h"
#include "libfdr/jrb.h"

int checkArgc(int argc, char *argv[]);
int readFile(Graph g, char *filename);

int main(int argc, char *argv[])
{
    int check = checkArgc(argc, argv);
    if (check == 0)
    {
        printf("Error: Command Fail!\n");
        exit(0);
    }
    Graph g = createGraph();

    switch (check)
    {
    case 1:
        /* code */
        break;

    default:
        break;
    }

    dropGraph(g);
    return 0;
}

int checkArgc(int argc, char *argv[])
{
    if (argc == 2)
    {
        // if (strcmp(argv[1], "help") == 0)
        //     return -1;
        // if (strcmp(argv[1], "about") == 0)
        //     return -2;
    }

    return 0;
}

int readFile(Graph g, char *filename)
{
    IS is = new_inputstruct(filename);
    if (is == NULL)
    {
        printf("Error: File fail!\n");
        exit(1);
    }

    // get_line(is);
    // while (get_line(is) > 0)
    // {

    // }
}
