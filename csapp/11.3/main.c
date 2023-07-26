#include <arpa/inet.h>
#include <stdio.h>
#include <string.h>

static const char *usage = "Usage\n\t./dd2hex <dotted-decimal-address>";

int main(int argc, char **argv) {
    uint32_t addr;
    int ret;

    if (argc != 2) {
        fprintf(stderr, "%s", usage);
        return 1;
    }

    ret = inet_pton(AF_INET, argv[1], &addr);
    if (ret == 0) {
        fprintf(stderr, "Invalid dotted decimal '%s'\n", argv[1]);
        return 1;
    } else if (ret == -1) {
        perror("inet_pton");
        return 1;
    }
    addr = ntohl(addr);
    printf("%x\n", addr);
    return 0;
}