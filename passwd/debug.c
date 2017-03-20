/* debug.c */
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>
#include <unistd.h>

#include "h.h"

void debug(t_s *s)
{
    printf("\n===== socket() =====\n");
    printf("domain = %d\n", s->domain);
    printf("type = %d\n", s->type);
    printf("fd = %d\n", s->fd);
    printf("name = %s\n", s->name);
    printf("p_proto = %d\n", s->pe->p_proto);

    printf("\n===== bind() =====\n");
    printf("sockfd = %d\n", s->sockfd);
    printf("sin_family = %d\n", s->addr.sin_family);
    printf("sin_addr.s_addr = %d\n", s->addr.sin_addr.s_addr);
    printf("sin_port = %d\n", s->addr.sin_port);
    printf("addrlen = %d\n", s->addrlen);
    printf("bindValue = %d\n", s->bindValue);

    printf("\n===== listen() =====\n");
    printf("listenValue = %d\n", s->listenValue);

    printf("\n===== accept() =====\n");
    printf("addrlenAccept = %d\n", s->addrlenAccept);
    printf("acceptValue = %d\n", s->acceptValue);
    printf("s->acceptAddr = %s\n", s->acceptAddr);

    printf("\n===== write() & read() =====\n");
    printf("s->buf = %s\n\n", s->buf);
}

void check_error(int test, int error)
{
    if (test == error)
    {
        fprintf(stderr, "ERROR: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }
}

void check_null(char *test)
{
    if (test == NULL)
    {
        fprintf(stderr, "ERROR: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }
}

void check_arg(int ac, int number)
{
    if (ac < number)
    {
        printf("Usage: ./server [PORT]\n");
        exit(EXIT_FAILURE);
    }
}