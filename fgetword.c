#include <stdio.h>
#include <ctype.h>


int
fgetword(FILE *fp, char *word, int lim)
{
    int c;
    char *w = word;
    int count = 0;  // return value

    while (isspace(c = getc(fp))) {
        ;
    }
    if (c != EOF) {
        *w++ = c;
        count++;
    }
    for ( ; --lim> 0; w++) {
        c = getc(fp);
        if (c == EOF || isspace(c)) {
            break;
        }
        *w = c;
        count++;
    }

    *w = '\0';
    return count;
}
