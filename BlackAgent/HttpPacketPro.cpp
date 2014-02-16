
#include "stdafx.h"
#include "HttpPacketPro.h"

using namespace std;

string HttpPacketPro(string HttpPacket)
{
	int iStringB = HttpPacket.find("host:");
	int iStringE = HttpPacket.find("\n\r");
	string sHttpAddress = HttpPacket.substr(iStringB,iStringE);
	return sHttpAddress;
}