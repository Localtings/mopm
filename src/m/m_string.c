#include "m_string.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *get_str_after_char(const char *_str, int _char)
{
    char *str = strdup(_str);
    char *last_char;

    strcpy(str, _str);

    last_char = strrchr(str, _char);
    if (last_char == NULL)
    {
        free(str);
        return NULL;
    }
    last_char += 1;
    str += (int)(last_char - str);

    return str;
}

char *get_str_before_char(const char *_str, int _char)
{
    char *str = strdup(_str);
    char *last_char;

    strcpy(str, _str);

    last_char = strrchr(str, _char);
    if (last_char == NULL)
    {
        free(str);
        return NULL;
    }
    *(str + (strlen(str) - strlen(last_char))) = '\0';

    return str;
}

int vasprintf(char **strp, const char *format, va_list ap)
{
    int len = _vscprintf(format, ap);
    int retval;
    char *str;

    if (len == -1)
        return -1;
    
    str = (char*)malloc(len + 1);

    if (str == NULL)
        return -1;
    
    retval = vsnprintf(str, len + 1, format, ap);

    if (retval == -1) {
        free(str);
        return -1;
    }

    *strp = str;
    return retval;
}

int asprintf(char **strp, const char *format, ...)
{
    va_list ap;
    int retval;

    va_start(ap, format);
    
    retval = vasprintf(strp, format, ap);

    va_end(ap);

    return retval;
}