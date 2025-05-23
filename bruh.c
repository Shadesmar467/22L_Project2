#include <stdio.h>
#include <regex.h>

int main() {
    regex_t regex;
    int ret;

    ret = regcomp(&regex, "^a[[:alnum:]]", REG_EXTENDED);
    if (ret) {
        printf("Regex compilation failed.\n");
        return 1;
    }

    ret = regexec(&regex, "abc", 0, NULL, 0);
    if (!ret) {
        printf("Match found!\n");
    } else {
        printf("No match.\n");
    }

    regfree(&regex);
    return 0;
}