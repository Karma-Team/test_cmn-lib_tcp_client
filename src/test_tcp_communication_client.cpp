/*
 * test_tcp_communication_client.cpp
 *
 *  Created on: 13 janv. 2020
 *      Author: ahu
 */



#include <iostream>
#include <COM_TcpClient.hpp>



using namespace std;
using namespace COM;



int main()
{
	cout << "Test C++ library for TCP communication : Client" << endl;

	string 	l_clientInputMsg;
	int 	l_clientSocket;
	int 	l_clientRequestedMsgId;

	CTcpClient l_CTcpClient(54000, "127.0.0.1");
	l_clientSocket = l_CTcpClient.initTcpClient();
	if(l_clientSocket != -1)
	{
		//	While loop: send and receive message back from server
			do
			{
				// Enter msg id
					cout << "> Client requested msg id : ";
					getline(cin, l_clientInputMsg);
					l_clientRequestedMsgId = strtoul(l_clientInputMsg.c_str(), NULL, 16);

				// Send requested message ID to server
					l_CTcpClient.sendRequestedMsgIdToServer(l_clientRequestedMsgId);
			} while(true);
	}
	else
	{
		cerr << "TCP client is not initialized! Quitting" << endl;
		return -1;
	}

    return 0;
}

