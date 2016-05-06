#include <stdio.h>
#include <string.h>
#include <winsock2.h>

#pragma comment(lib, "WS2_32.lib")

#define MAXSIZE 200

void main()
{
	int err; //用于存储函数返回值判断函数调用结果
	struct sockaddr_in clie_addr; //用于存储地址信息
	char buf[MAXSIZE], rec[MAXSIZE];
	SOCKET sock;

	//初始化，指明winsock规范的版本(wsaData结构中存储版本相关信息)
	WORD wVR = MAKEWORD(2,2);
	WSADATA wsaData;
	WSAStartup(wVR, &wsaData);

	//创建TCP套接字
    sock = socket(AF_INET, SOCK_STREAM, 0);

	//初始化为0
	memset(&clie_addr, 0, sizeof(clie_addr));
	memset(buf, 0, sizeof(buf));
	memset(rec, 0, sizeof(rec));

	//存储地址信息
	clie_addr.sin_family = AF_INET;  //用IPv4地址
	clie_addr.sin_addr.s_addr = inet_addr("127.0.0.1"); //具体的IP地址
	clie_addr.sin_port = htons(1234); //端口信息

	connect(sock, (struct sockaddr*)&clie_addr, sizeof(clie_addr));

	while(1)
	{
		//发送信息
		printf("> ");
		gets(buf);
		err = send(sock, buf, sizeof(buf), 0);
		if(err == SOCKET_ERROR) break;
		err = recv(sock, rec, sizeof(rec), 0);
        if(err == SOCKET_ERROR) break;
		printf("来自服务端的回应: %s\n", rec);
	}

	//关闭套接字，终止DLL的使用
	closesocket(sock);
	WSACleanup();
}
