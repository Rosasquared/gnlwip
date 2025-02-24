#include "get_next_line.h"

int main(void)
{
    int     fd;
    int     count;
    char    *line;

    count = 0;
    fd = open("ej.txt", O_RDONLY);
    if (fd == -1)
    {
        printf("nope");
        return (0);
    }
    while (line != NULL)
    {
        line = get_next_line(fd);
        printf("line num %d is: %s", count, line);
        count++;
        free(line);
    }
    close(fd);
    return(0);
}