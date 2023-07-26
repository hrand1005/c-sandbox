#include <arpa/inet.h>
#include <stdio.h>
#include <string.h>

#define P_ADDRSIZE 16
#define MAXHEXSTR 10

static const char *usage = "Usage:\n\t./hex2dd <4 byte hex string>\n";

int main(int argc, char **argv) {
    uint32_t dec;
    char addr[P_ADDRSIZE+1];

    if (argc != 2 || strlen(argv[1]) > MAXHEXSTR) {
        fprintf(stderr, "%s", usage);
        return 1;
    }

    sscanf(argv[1], "%x", &dec);
    dec = htonl(dec);

    if (inet_ntop(AF_INET, &dec, addr, P_ADDRSIZE+1) == NULL) {
        perror("inet_ntop");
        return 1;
    }

    printf("%s\n", addr);
    return 0;
}