/* strrindex: returns rightmost index of t in s, -1 if none */
int strrindex (char s[], char t[])
{
    int i, j, k, pos;

    pos = -1;
    for (i = 0; s[i] != '\0'; i++) {
        for (j = i; t[k] != '\0' && s[j]==t[k]; j++, k++)
            ;
        if (k > 0 && t[k] == '\0')
            pos = i;
    }

    return pos;
}

