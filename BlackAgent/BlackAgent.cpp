// BlackAgent.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <WinSock2.h>
#pragma comment(lib,"ws2_32.lib")

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	WORD wVersionRequested;
	WSADATA wsaData;
	int err;
	wVersionRequested = MAKEWORD(1,1);// ����Socket�汾

	err = WSAStartup(wVersionRequested,&wsaData);
	if (err == 0)
	{
		printf("%s\n","WSAStartup�����ɹ���");
	}
	else
	{
		printf("%s\n","WSAStartup����ʧ�ܣ�");
		WSACleanup();
	}
	SOCKET sockSrv = socket(AF_INET,SOCK_STREAM,0);
	SOCKADDR_IN addrSrv;
	addrSrv.sin_addr.S_un.S_addr = htonl(INADDR_ANY);
	addrSrv.sin_family=AF_INET;
	addrSrv.sin_port=htons(808);//����˿�

	bind(sockSrv,(SOCKADDR*)&addrSrv,sizeof(SOCKADDR)); //�����ô���˿�

	listen(sockSrv,SOMAXCONN); //�����������������

	SOCKADDR_IN addrClient;
	int len = sizeof (SOCKADDR);
	printf("%s\n","-------------------��ʼ��������-----------------------");
	//SOCKET HttpClient = socket(AF_INET,SOCK_STREAM,0);
	//SOCKADDR_IN addrHttpClint; //����ҳ����������Scoket
	//addrHttpClint.sin_addr.S_un.S_addr=
	while(1)
	{
		SOCKET sockConn = accept(sockSrv,(SOCKADDR*)&addrClient,&len);
		char recvBuf[100];
		recv(sockConn,recvBuf,99,0);
		printf("%s\n",recvBuf);
		cout << HttpPacketPro(recvBuf);
		closesocket(sockConn);
	}
	return 0;
}

