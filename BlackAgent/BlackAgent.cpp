// BlackAgent.cpp : 定义控制台应用程序的入口点。
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
	wVersionRequested = MAKEWORD(1,1);// 设置Socket版本

	err = WSAStartup(wVersionRequested,&wsaData);
	if (err == 0)
	{
		printf("%s\n","WSAStartup启动成功！");
	}
	else
	{
		printf("%s\n","WSAStartup启动失败！");
		WSACleanup();
	}
	SOCKET sockSrv = socket(AF_INET,SOCK_STREAM,0);
	SOCKADDR_IN addrSrv;
	addrSrv.sin_addr.S_un.S_addr = htonl(INADDR_ANY);
	addrSrv.sin_family=AF_INET;
	addrSrv.sin_port=htons(808);//代理端口

	bind(sockSrv,(SOCKADDR*)&addrSrv,sizeof(SOCKADDR)); //绑定设置代理端口

	listen(sockSrv,SOMAXCONN); //监听浏览器发来数据

	SOCKADDR_IN addrClient;
	int len = sizeof (SOCKADDR);
	printf("%s\n","-------------------开始处理数据-----------------------");
	//SOCKET HttpClient = socket(AF_INET,SOCK_STREAM,0);
	//SOCKADDR_IN addrHttpClint; //向网页服务器请求Scoket
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

