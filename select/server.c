#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>

#include <arpa/inet.h>



#define MYPORT 1234 //连接时使用的端口

#define MAXCLINE 5 //连接队列中的个数

#define BUF_SIZE 200

int fd[MAXCLINE]; //连接的fd

int conn_amount; //当前的连接数

void showclient()
{
    int i;
    printf("client amount:%d\n",conn_amount);
    for(i=0;i<MAXCLINE;i++)
    {
        printf("[%d]:%d ",i,fd[i]);
    }
    printf("\n\n");
}

int main(void)
{
    int sock_fd,new_fd; //监听套接字 连接套接字
    struct sockaddr_in server_addr; // struct type declare need `struct` in front.
    struct sockaddr_in client_addr; //
    socklen_t sin_size;
    int yes = 1;
    char buf[BUF_SIZE];
    int ret;

    //
    if((sock_fd = socket(AF_INET,SOCK_STREAM,0)) == -1)
    {
        perror("create socket stream failed");
        exit(-1);
    }

    if(setsockopt(sock_fd,SOL_SOCKET,SO_REUSEADDR,&yes,sizeof(int))==-1)
    {
        perror("setsockopt error \n");
        exit(-1);
    }



    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(MYPORT);
    server_addr.sin_addr.s_addr = INADDR_ANY;

    memset(server_addr.sin_zero,'\0',sizeof(server_addr.sin_zero));

    if(bind(sock_fd,(struct sockaddr *)&server_addr,sizeof(server_addr)) == -1)
    {
        perror("bind error!\n");
        exit(1);
    }

    if(listen(sock_fd,MAXCLINE)==-1)
    {
        perror("listen error!\n");
        exit(1);
    }

    printf("listen port %d\n",MYPORT);

    fd_set fdst;
    int maxsock;
    struct timeval tv;

    conn_amount =0;
    sin_size = sizeof(client_addr);
    maxsock = sock_fd;

    while(1)
    {
        FD_ZERO(&fdst);

        FD_SET(sock_fd,&fdst);

        tv.tv_sec =30;
        tv.tv_usec = 0;
        for(int i = 0; i< MAXCLINE ;i++)
        {
            if(fd[i] != 0)
            {
                FD_SET(sock_fd,&fdst);
            }
        }

        ret = select(maxsock+1,&fdst,NULL,NULL,&tv);

        if(ret < 0)
        {
            perror("select failed");
            exit(-1);
        }else if(ret == 0)
        {
            printf("time out");
            continue;
        }

        for(int i = 0; i< conn_amount ;i++)
        {
            if(FD_ISSET(fd[i],&fdst))
            {
                ret = recv(fd[i],buf,sizeof(buf),0);
                if(ret <= 0)
                {
                    printf("client closed\n");
                    close(fd[i]);
                    FD_CLR(fd[i],&fdst);
                    fd[i]=0;
                    conn_amount--;
                }else
                {
                    if(ret <BUF_SIZE)
                        memset(&buf[ret],'\0',1);
                    printf("client[%d] send:%s\n",i,buf);
                }

            }
        }

        //new connection
        if(FD_ISSET(sock_fd,&fdst))
        {
            new_fd = accept(sock_fd,(struct sockaddr *) &client_addr,&sin_size);
            if(new_fd <= 0)
            {
                perror("accept errors\n");
                continue;
            }

            if(conn_amount < MAXCLINE)
            {
                for(int i=0;i< MAXCLINE;i++)
                {
                    if(fd[i]==0)
                    {
                        fd[i] = new_fd;
                        break;
                    }
                }
                conn_amount++;
                printf("new connection client[%d]%s:%d\n",conn_amount,inet_ntoa(client_addr.sin_addr),ntohs(client_addr.sin_port));
                if(new_fd > maxsock)
                {
                    maxsock = new_fd;
                }
            }else
            {
                printf("max connections arrive ,exit\n");
                send(new_fd,"bye",4,0);
                close(new_fd);
                continue;
            }
        }
        showclient();
    }

    for(int i=0;i<MAXCLINE;i++)
    {
        if(fd[i]!=0)
        {
            close(fd[i]);
        }
    }

    return 0;
}
