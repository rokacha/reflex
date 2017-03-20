/* server.c */
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <string.h>


#include "h.h"

void my_socket(t_s *s)
{
    s->name    = "TCP";
    s->domain    = AF_INET;
    s->type    = SOCK_STREAM;
    s->pe        = getprotobyname(s->name);
    s->fd        = socket(s->domain, s->type, s->pe->p_proto);
    check_error(s->fd, -1);
}

void my_bind(t_s *s, int port)
{
    s->sockfd                = s->fd;
    s->addr.sin_family        = s->domain;
    s->addr.sin_addr.s_addr = INADDR_ANY;
    s->addr.sin_port        = htons(port);
    s->addrlen                = sizeof(s->addr);
    s->bindValue            = bind(s->fd, (const struct sockaddr *)&s->addr, s->addrlen);
    check_error(s->bindValue, -1);
}

void my_listen(t_s *s, int backlog)
{
    s->listenValue = listen(s->sockfd, backlog);
    check_error(s->listenValue, -1);
}

void my_accept(t_s *s)
{
    s->addrlenAccept = sizeof(s->addrAccept);
    s->acceptValue = accept(s->sockfd, (struct sockaddr *)&s->addrAccept, &s->addrlenAccept);
    check_error(s->acceptValue, -1);
    s->acceptAddr = inet_ntoa(s->addrAccept.sin_addr);
    check_null(s->acceptAddr);
}

void my_write(t_s *s ,char *msg)
{
    s->writeValue = write(s->acceptValue, msg, strlen(msg));
    check_error(s->writeValue, -1);
}

char *my_read(t_s *s)
{
    bzero(s->buf,5);
    s->readValue = read(s->acceptValue, s->buf, BUF_SIZE);
    check_error(s->readValue, -1);
    return s->buf;


}

int main(int ac, char *av[])
{
    t_s s;
    int passed =3;
    char reply[256];

    check_arg(ac, ARG_SIZE);
    my_socket(&s);
    my_bind(&s, atoi(av[1]));
    my_listen(&s, BACKLOG);
    my_accept(&s);
    
    //char *message = "Hello, please enter 4 digit code: ";
    
    my_write(&s,"Hello, please enter 4 digit code:\n");
    
    while(passed >0)
    {    
        bzero(reply,256);
        
        char *pass = my_read(&s);
        //printf("---%s---",pass);

        if (pass[0]=='1' && pass[1]=='1' && pass[2]=='1' && pass[3]=='1'){
            passed =0;
            sprintf ( reply, "Welcome\n");
            
        } else{
            sprintf ( reply, "Wrong, %d more tries\n", --passed);
        }

        
        
        my_write(&s,reply);

    }
    
    //debug(&s);
    check_error(close(s.acceptValue), -1);
    check_error(close(s.fd), -1);
    return 0;
}
