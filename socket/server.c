#include <stdio.h>
#include <string.h>
#include <winsock2.h>
#include <stdlib.h>
#pragma comment(lib, "WS2_32.lib")

#define MAXSIZE 200

void main()
{
	int err; //用于存储函数返回值判断函数调用结果
	int nSize;
	struct sockaddr_in serv_addr, clie_addr; //用于存储地址信息
	SOCKET aClient; //接受客户端返回的套接字信息
	char buf[MAXSIZE], rec[MAXSIZE];
	char *s;
    SOCKET sock;
	//初始化，指明winsock规范的版本(wsaData结构中存储版本相关信息)
	WSADATA wsaData;
	WORD wVR = MAKEWORD(2,2);
	WSAStartup(wVR, &wsaData);

	//创建TCP套接字
	sock = socket(AF_INET, SOCK_STREAM, 0);

	memset(&serv_addr, 0, sizeof(serv_addr)); //初始化为0
	memset(&serv_addr, 0, sizeof(clie_addr));
	memset(buf, 0, sizeof(buf));
	memset(rec, 0, sizeof(rec));

	//存储地址信息
	serv_addr.sin_family = AF_INET;  //用IPv4地址
	serv_addr.sin_addr.s_addr = inet_addr("127.0.0.1"); //具体的IP地址
	serv_addr.sin_port = htons(1234); //端口信息

	//绑定特定IP地址和端口
	err = bind(sock, (struct sockaddr*)&serv_addr, sizeof(serv_addr));

	//监听套接字
	err = listen(sock, 5);

	printf("等待连接中..\n");
	//接受客户端请求
	nSize = sizeof(clie_addr);
	aClient = accept(sock, (struct sockaddr *)&clie_addr, &nSize);

	s = inet_ntoa(serv_addr.sin_addr);
	printf("与%s建立连接..\n",s);

	while(1)
    {
        memset(buf, 0, sizeof(buf));
        memset(rec, 0, sizeof(rec));
        //获取来自客户端的数据
        err = recv(aClient, rec, sizeof(rec), 0);
        if(err == SOCKET_ERROR)
        {
            break;
        }

        printf("接收到来自客户端的消息: ");
        printf("%s\n", rec);

        //发送信息
        printf("> ");
        gets(buf);
        err = send(aClient, buf, sizeof(buf), 0);
        if(err == SOCKET_ERROR)
        {
            break;
        }
    }
	//关闭套接字，终止DLL的使用
	closesocket(aClient);
	closesocket(sock);
	WSACleanup();
}
