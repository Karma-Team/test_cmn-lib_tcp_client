/*
 * test_tcp_communication_client.cpp
 *
 *  Created on: 13 janv. 2020
 *      Author: ahu
 */



#include <iostream>
#include <CLT_TcpClient.hpp>



using namespace std;
using namespace CLT;



int main()
{
	cout << "Test C++ library for TCP communication : Client" << endl;

	CTcpClient l_CTcpServer;
	l_CTcpServer.initTcpClient();
	l_CTcpServer.startTcpClient();

    return 0;
}

