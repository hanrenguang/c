#include <stdio.h>
#include <string.h>
#include <winsock2.h>

#pragma comment(lib, "WS2_32.lib")

#define MAXSIZE 200

void main()
{
	int err; //���ڴ洢��������ֵ�жϺ������ý��
	struct sockaddr_in clie_addr; //���ڴ洢��ַ��Ϣ
	char buf[MAXSIZE], rec[MAXSIZE];
	SOCKET sock;

	//��ʼ����ָ��winsock�淶�İ汾(wsaData�ṹ�д洢�汾�����Ϣ)
	WORD wVR = MAKEWORD(2,2);
	WSADATA wsaData;
	WSAStartup(wVR, &wsaData);

	//����TCP�׽���
    sock = socket(AF_INET, SOCK_STREAM, 0);

	//��ʼ��Ϊ0
	memset(&clie_addr, 0, sizeof(clie_addr));
	memset(buf, 0, sizeof(buf));
	memset(rec, 0, sizeof(rec));

	//�洢��ַ��Ϣ
	clie_addr.sin_family = AF_INET;  //��IPv4��ַ
	clie_addr.sin_addr.s_addr = inet_addr("127.0.0.1"); //�����IP��ַ
	clie_addr.sin_port = htons(1234); //�˿���Ϣ

	connect(sock, (struct sockaddr*)&clie_addr, sizeof(clie_addr));

	while(1)
	{
		//������Ϣ
		printf("> ");
		gets(buf);
		err = send(sock, buf, sizeof(buf), 0);
		if(err == SOCKET_ERROR) break;
		err = recv(sock, rec, sizeof(rec), 0);
        if(err == SOCKET_ERROR) break;
		printf("���Է���˵Ļ�Ӧ: %s\n", rec);
	}

	//�ر��׽��֣���ֹDLL��ʹ��
	closesocket(sock);
	WSACleanup();
}
