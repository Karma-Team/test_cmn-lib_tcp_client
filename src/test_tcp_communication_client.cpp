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

	SPathMsg 			l_pathMsg 			= {.hd={MSG_ID_PATH, 			sizeof(SPathMsg)}, 				.body={0, {0,0,0,0,0,0,0,0,0,0}}};
	SPathCorrectionMsg	l_pathCorrectionMsg	= {.hd={MSG_ID_PATH_CORRECTION, sizeof(SPathCorrectionMsg)}, 	.body={0, 0, {0,0,0,0,0,0,0,0,0,0}}};
	SWorkShopOrderMsg 	l_workShopOrderMsg	= {.hd={MSG_ID_WORKSHOP_ORDER, 	sizeof(SWorkShopOrderMsg)}, 	.body={0}};
	SStopMsg 			l_stopMsg			= {.hd={MSG_ID_STOP, 			sizeof(SStopMsg)}, 				.body={0}};
	SWorkShopReportMsg 	l_workShopReportMsg	= {.hd={MSG_ID_WORKSHOP_REPORT, sizeof(SWorkShopReportMsg)}, 	.body={0}};
	SBitReportMsg 		l_bitReportMsg		= {.hd={MSG_ID_BIT_REPORT, 		sizeof(SBitReportMsg)}, 		.body={0}};
	SErrorMsg 			l_errorMsg			= {.hd={MSG_ID_ERROR, 			sizeof(SErrorMsg)}, 			.body={0}};
	string 				l_clientInputMsg;
	int 				l_quitRequested			= 0;
	int 				l_clientSocket;

	CTcpClient l_CTcpClient(54000, "127.0.0.1");
	l_clientSocket = l_CTcpClient.initTcpClient();
	if(l_clientSocket != -1)
	{
		//	While loop: send and receive message from server
			do
			{
				// Enter cient cmd
					cout << "> Client cmd : ";
					getline(cin, l_clientInputMsg);

				// Treat client cmd
					if(strcmp(l_clientInputMsg.c_str(), "help") == 0)
					{
						cout << "	help : display help message\n";
						cout << "	quit : close TCP client\n";
						cout << "	requestPathMsg : request PATH message to TCP server\n";
						cout << "	requestPathCorrectionMsg : request PATH_CORRECTION message to TCP server\n";
						cout << "	requestWorkShopOrderMsg : request WORKSHOP_ORDER message to TCP server\n";
						cout << "	requestStopMsg : request STOP message to TCP server\n";
						cout << "	requestWorkShopReportMsg : request WORKSHOP_REPORT message to TCP server\n";
						cout << "	requestBitReportMsg : request BIT_REPORT message to TCP server\n";
						cout << "	requestErrorMsg : request ERROR message to TCP server\n";
						cout << "	displayPathMsg : display PATH message\n";
						cout << "	displayPathCorrectionMsg : display PATH_CORRECTION message\n";
						cout << "	displayWorkShopOrderMsg : display WORKSHOP_ORDER message\n";
						cout << "	displayStopMsg : display STOP message\n";
						cout << "	displayWorkShopOrderReportMsg : display WORKSHOP_ORDER_REPORT message\n";
						cout << "	displayBitReportMsg : display BIT_REPORT message\n";
						cout << "	displayErrorMsg : display ERROR message\n";
					}

					else if(strcmp(l_clientInputMsg.c_str(), "quit") == 0)
					{
						cout << "> Quit requested\n";
						l_quitRequested = 1;
					}

					else if(strcmp(l_clientInputMsg.c_str(), "requestPathMsg") == 0)
					{
						cout << "> Requested message to server : MSG_ID_PATH\n";
						l_CTcpClient.requestMsgToServer(MSG_ID_PATH, &l_pathMsg);
					}

					else if(strcmp(l_clientInputMsg.c_str(), "requestPathCorrectionMsg") == 0)
					{
						cout << "> Requested message to server : MSG_ID_PATH_CORRECTION\n";
						l_CTcpClient.requestMsgToServer(MSG_ID_PATH_CORRECTION, &l_pathCorrectionMsg);
					}

					else if(strcmp(l_clientInputMsg.c_str(), "requestWorkShopOrderMsg") == 0)
					{
						cout << "> Requested message to server : MSG_ID_WORKSHOP_ORDER\n";
						l_CTcpClient.requestMsgToServer(MSG_ID_WORKSHOP_ORDER, &l_workShopOrderMsg);
					}

					else if(strcmp(l_clientInputMsg.c_str(), "requestStopMsg") == 0)
					{
						cout << "> Requested message to server : MSG_ID_STOP\n";
						l_CTcpClient.requestMsgToServer(MSG_ID_STOP, &l_stopMsg);
					}

					else if(strcmp(l_clientInputMsg.c_str(), "requestWorkShopReportMsg") == 0)
					{
						cout << "> Requested message to server : MSG_ID_WORKSHOP_REPORT\n";
						l_CTcpClient.requestMsgToServer(MSG_ID_WORKSHOP_REPORT, &l_workShopReportMsg);
					}

					else if(strcmp(l_clientInputMsg.c_str(), "requestBitMsg") == 0)
					{
						cout << "> Requested message to server : MSG_ID_BIT_REPORT\n";
						l_CTcpClient.requestMsgToServer(MSG_ID_BIT_REPORT, &l_bitReportMsg);
					}

					else if(strcmp(l_clientInputMsg.c_str(), "requestErrorMsg") == 0)
					{
						cout << "> Requested message to server : MSG_ID_ERROR\n";
						l_CTcpClient.requestMsgToServer(MSG_ID_ERROR, &l_errorMsg);
					}

					else if(strcmp(l_clientInputMsg.c_str(), "displayPathMsg") == 0)
					{
						cout << "> Path message : \n";
						cout << "	[hd]\n";
						cout << "		id : " << l_pathMsg.hd.id << "\n";
						cout << "		size : " << l_pathMsg.hd.size << "\n";
						cout << "	[body]\n";
						cout << "		pointsNb : " << l_pathMsg.body.pointsNb << "\n";
						cout << "		xyPointsArray : [";
						for(uint32_t i=0 ; i<MAX_PATH_POINTS ; i++)
						{
							cout << l_pathMsg.body.xyPointsArray[i] << " ";
						}
						cout << "]\n";
					}

					else if(strcmp(l_clientInputMsg.c_str(), "displayPathCorrectionMsg") == 0)
					{
						cout << "> Path correction message : \n";
						cout << "	[hd]\n";
						cout << "		id : " << l_pathCorrectionMsg.hd.id << "\n";
						cout << "		size : " << l_pathCorrectionMsg.hd.size << "\n";
						cout << "	[body]\n";
						cout << "		lastIdValid : " << l_pathCorrectionMsg.body.lastIdValid << "\n";
						cout << "		pointsNb : " << l_pathCorrectionMsg.body.pointsNb << "\n";
						cout << "		xyPointsArray : [";
						for(uint32_t i=0 ; i<MAX_PATH_POINTS ; i++)
						{
							cout << l_pathCorrectionMsg.body.xyCorrectionPointsArray[i] << " ";
						}
						cout << "]\n";
					}

					else if(strcmp(l_clientInputMsg.c_str(), "displayWorkShopOrderMsg") == 0)
					{
						cout << "> Workshop order message : \n";
						cout << "	[hd]\n";
						cout << "		id : " << l_workShopOrderMsg.hd.id << "\n";
						cout << "		size : " << l_workShopOrderMsg.hd.size << "\n";
						cout << "	[body]\n";
						cout << "		tmp : " << l_workShopOrderMsg.body.tmp << "\n";
					}

					else if(strcmp(l_clientInputMsg.c_str(), "displayStopMsg") == 0)
					{
						cout << "> Stop message : \n";
						cout << "	[hd]\n";
						cout << "		id : " << l_stopMsg.hd.id << "\n";
						cout << "		size : " << l_stopMsg.hd.size << "\n";
						cout << "	[body]\n";
						cout << "		tmp : " << l_stopMsg.body.tmp << "\n";
					}

					else if(strcmp(l_clientInputMsg.c_str(), "displayWorkShopReportMsg") == 0)
					{
						cout << "> Workshop report message : \n";
						cout << "	[hd]\n";
						cout << "		id : " << l_workShopReportMsg.hd.id << "\n";
						cout << "		size : " << l_workShopReportMsg.hd.size << "\n";
						cout << "	[body]\n";
						cout << "		tmp : " << l_workShopReportMsg.body.tmp << "\n";
					}

					else if(strcmp(l_clientInputMsg.c_str(), "displayBitReportMsg") == 0)
					{
						cout << "> Bit report message : \n";
						cout << "	[hd]\n";
						cout << "		id : " << l_bitReportMsg.hd.id << "\n";
						cout << "		size : " << l_bitReportMsg.hd.size << "\n";
						cout << "	[body]\n";
						cout << "		tmp : " << l_bitReportMsg.body.tmp << "\n";
					}

					else if(strcmp(l_clientInputMsg.c_str(), "displayErrorMsg") == 0)
					{
						cout << "> Error message : \n";
						cout << "	[hd]\n";
						cout << "		id : " << l_errorMsg.hd.id << "\n";
						cout << "		size : " << l_errorMsg.hd.size << "\n";
						cout << "	[body]\n";
						cout << "		tmp : " << l_errorMsg.body.tmp << "\n";
					}

					else
					{
						cout << "> Unknown client cmd : enter 'help' to display available cmd\n";
					}
			} while(l_quitRequested == 0);
	}
	else
	{
		cerr << "TCP client is not initialized! Quitting" << endl;
		return -1;
	}

    return 0;
}
