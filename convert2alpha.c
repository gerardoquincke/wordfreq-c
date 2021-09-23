#include <ctype.h>

void
convert2alpha(char *word)
// strips all non alpha chars from word
{
    char *w, *w1;

    for (w1 = w = word; *w != '\0'; w++) {
        if (isalpha(*w)) {
            *w1++ = *w;
        }
    }
    *w1 = '\0';
}
