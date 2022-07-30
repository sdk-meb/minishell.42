#include <head.h>

int main(int ac, char *av[], char *envp[])
{
    av[0][0] = ac;
    prompt((const char **)envp);
    return 0;
}

