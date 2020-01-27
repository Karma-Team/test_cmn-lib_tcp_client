/*
 * "test_tcp_communication_client.cpp"
 */



#include <iostream>
#include <TCP_Client.hpp>



using namespace std;
using namespace TCP;



int main()
{
	cout << "Test C++ library for TCP communication : Client" << endl;

	SPathMsgBody 			l_pathMsgBody;
	SPathCorrectionMsgBody 	l_pathCorrectionMsgBody;
	SWorkShopOrderMsgBody	l_workShopOrderMsgBody;
	SStopMsgBody		 	l_stopMsgBody;
	SWorkShopReportMsgBody	l_workShopReportMsgBody;
	SBitReportMsgBody		l_bitReportMsgBody;
	SErrorMsgBody 			l_errorMsgBody;
	string 					l_clientInputMsg;
	int 					l_clientSocket;
	int 					l_clientRequestedMsgId;

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

				// Request message to server
					switch(l_clientRequestedMsgId)
					{
						case MSG_ID_PATH:
							cout << "> Requested message to server : MSG_ID_PATH\n";
							l_CTcpClient.requestdMsgToServer(l_clientRequestedMsgId, &l_pathMsgBody);
							break;

						case MSG_ID_PATH_CORRECTION:
							cout << "> Requested message to server : MSG_ID_PATH_CORRECTION\n";
							l_CTcpClient.requestdMsgToServer(l_clientRequestedMsgId, &l_pathCorrectionMsgBody);
							break;

						case MSG_ID_WORKSHOP_ORDER:
							cout << "> Requested message to server : MSG_ID_WORKSHOP_ORDER\n";
							l_CTcpClient.requestdMsgToServer(l_clientRequestedMsgId, &l_workShopOrderMsgBody);
							break;

						case MSG_ID_STOP:
							cout << "> Requested message to server : MSG_ID_STOP\n";
							l_CTcpClient.requestdMsgToServer(l_clientRequestedMsgId, &l_stopMsgBody);
							break;

						case MSG_ID_WORKSHOP_REPORT:
							cout << "> Requested message to server : MSG_ID_WORKSHOP_REPORT\n";
							l_CTcpClient.requestdMsgToServer(l_clientRequestedMsgId, &l_workShopReportMsgBody);
							break;

						case MSG_ID_BIT_REPORT:
							cout << "> Requested message to server : MSG_ID_BIT_REPORT\n";
							l_CTcpClient.requestdMsgToServer(l_clientRequestedMsgId, &l_bitReportMsgBody);
							break;

						case MSG_ID_ERROR:
							cout << "> Requested message to server : MSG_ID_ERROR\n";
							l_CTcpClient.requestdMsgToServer(l_clientRequestedMsgId, &l_errorMsgBody);
							break;

						default:
							cout << "> Unknown message ID\n";
					}
			} while(true);
	}
	else
	{
		cerr << "TCP client is not initialized! Quitting" << endl;
		return -1;
	}

    return 0;
}
