#ifndef H_H_
#define H_H_

#include <netdb.h>

/**
 * Define
 */
#define ARG_SIZE 2
#define BACKLOG 10
#define BUF_SIZE 5

/**
 * Structure
 */
typedef struct mystruct
{
    /* socket */
    int domain;
    int type;
    int fd;
    char *name;
    struct protoent *pe;

    /* bind */
    int sockfd;
    socklen_t addrlen;
    struct sockaddr_in addr;
    int bindValue;

    /* listen */
    int listenValue;

    /* accept */
    int acceptValue;
    socklen_t addrlenAccept;
    struct sockaddr_in addrAccept;
    char *acceptAddr;

    /* read & write */
    int readValue;
    int writeValue;
    char buf[5];
} t_s;

/**
 * Prototype
 */
void debug(t_s *);
void check_error(int, int);
void check_null(char *);
void check_arg(int, int);

#endif /* H_H_ */