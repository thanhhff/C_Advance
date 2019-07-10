void BFS_Shortest(Graph graph, char *start, char *stop, JRB path)
{
    JRB dist = make_jrb();
    char *output[1000];

    int pathNum = 0;

    Dllist queue = new_dllist();
    dll_append(queue, new_jval_s(start));

    while (!dll_empty(queue))
    {
        Dllist node = dll_first(queue);
        char *u = (char *)malloc(sizeof(char) * strlen(jval_s(node->val)) + 1);
        jrb_insert_int(path, ++pathNum, new_jval_s(u));
        strcpy(u, jval_s(node->val));
        dll_delete_node(node);

        if (jrb_find_str(dist, u) == NULL)
        {
            jrb_insert_str(dist, u, new_jval_i(1));

            if (strcmp(u, stop) == 0)
                return;

            int n = getAdjacentVertices(graph, u, output);
            for (int i = 0; i < n; i++)
            {
                char *v = (char *)malloc(sizeof(char) * strlen(output[i]) + 1);

                if (jrb_find_str(dist, v) == NULL)
                {
                    dll_append(queue, new_jval_s(v));
                }
            }
        }
    }
}