#include <stdio.h>
#include <string.h>
#include <winsock2.h>
#include <stdlib.h>
#pragma comment(lib, "WS2_32.lib")

#define MAXSIZE 200

void main()
{
	int err; //���ڴ洢��������ֵ�жϺ������ý��
	int nSize;
	struct sockaddr_in serv_addr, clie_addr; //���ڴ洢��ַ��Ϣ
	SOCKET aClient; //���ܿͻ��˷��ص��׽�����Ϣ
	char buf[MAXSIZE], rec[MAXSIZE];
	char *s;
    SOCKET sock;
	//��ʼ����ָ��winsock�淶�İ汾(wsaData�ṹ�д洢�汾�����Ϣ)
	WSADATA wsaData;
	WORD wVR = MAKEWORD(2,2);
	WSAStartup(wVR, &wsaData);

	//����TCP�׽���
	sock = socket(AF_INET, SOCK_STREAM, 0);

	memset(&serv_addr, 0, sizeof(serv_addr)); //��ʼ��Ϊ0
	memset(&serv_addr, 0, sizeof(clie_addr));
	memset(buf, 0, sizeof(buf));
	memset(rec, 0, sizeof(rec));

	//�洢��ַ��Ϣ
	serv_addr.sin_family = AF_INET;  //��IPv4��ַ
	serv_addr.sin_addr.s_addr = inet_addr("127.0.0.1"); //�����IP��ַ
	serv_addr.sin_port = htons(1234); //�˿���Ϣ

	//���ض�IP��ַ�Ͷ˿�
	err = bind(sock, (struct sockaddr*)&serv_addr, sizeof(serv_addr));

	//�����׽���
	err = listen(sock, 5);

	printf("�ȴ�������..\n");
	//���ܿͻ�������
	nSize = sizeof(clie_addr);
	aClient = accept(sock, (struct sockaddr *)&clie_addr, &nSize);

	s = inet_ntoa(serv_addr.sin_addr);
	printf("��%s��������..\n",s);

	while(1)
    {
        memset(buf, 0, sizeof(buf));
        memset(rec, 0, sizeof(rec));
        //��ȡ���Կͻ��˵�����
        err = recv(aClient, rec, sizeof(rec), 0);
        if(err == SOCKET_ERROR)
        {
            break;
        }

        printf("���յ����Կͻ��˵���Ϣ: ");
        printf("%s\n", rec);

        //������Ϣ
        printf("> ");
        gets(buf);
        err = send(aClient, buf, sizeof(buf), 0);
        if(err == SOCKET_ERROR)
        {
            break;
        }
    }
	//�ر��׽��֣���ֹDLL��ʹ��
	closesocket(aClient);
	closesocket(sock);
	WSACleanup();
}
