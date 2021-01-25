/*
 * "test_tcp_communication_client.cpp"
 */



#include <iostream>
#include <common.hpp>
#include <TCP_Client.hpp>



using namespace std;
using namespace TCP;



int main()
{
	cout << "Test C++ library for TCP communication : Client (begin)" << endl;

	SMsgInfoKeepAlive 		l_msgInfoKeepAlive						= {.hd={ID_MSG_INFO_KEEP_ALIVE,	sizeof(SMsgInfoKeepAlive)}, 	.body={false}};
	SMsgInfoPosition 		l_msgInfoPosition 						= {.hd={ID_MSG_INFO_POSITION, 	sizeof(SMsgInfoPosition)}, 		.body={0, 0}};
	SMsgOrderBit			l_msgOrderBit							= {.hd={ID_MSG_ORDER_BIT, 		sizeof(SMsgOrderBit)}, 			.body={0}};
	SMsgOrderPath 			l_msgOrderPath 							= {.hd={ID_MSG_ORDER_PATH,		sizeof(SMsgOrderPath)}, 		.body={0, {0,0,0,0,0,0,0,0,0,0}}};
	SMsgOrderPathCorr		l_msgOrderPathCorr						= {.hd={ID_MSG_ORDER_PATH_CORR, sizeof(SMsgOrderPathCorr)}, 	.body={0, 0, {0,0,0,0,0,0,0,0,0,0}}};
	SMsgOrderWorkShop 		l_msgOrderWorkShop						= {.hd={ID_MSG_ORDER_WORKSHOP, 	sizeof(SMsgOrderWorkShop)}, 	.body={0}};
	SMsgOrderStop 			l_msgOrderStop							= {.hd={ID_MSG_ORDER_STOP,		sizeof(SMsgOrderStop)}, 		.body={0}};
	SMsgReportBit 			l_msgReportBit							= {.hd={ID_MSG_REPORT_BIT, 		sizeof(SMsgReportBit)}, 		.body={0}};
	SMsgReportWorkShop 		l_msgReportWorkShop						= {.hd={ID_MSG_REPORT_WORKSHOP, sizeof(SMsgReportWorkShop)},	.body={0}};

	SMsgReportBitBody 		l_msgReportBitBody1						= {0};
	SMsgReportBitBody 		l_msgReportBitBody2						= {1};
	SMsgReportWorkShopBody 	l_msgReportWorkShopBody1				= {130};
	SMsgReportWorkShopBody 	l_msgReportWorkShopBody2				= {260};

	uint32_t 				l_updateCounterMsgBodyReportBit			= 0;
	uint32_t 				l_updateCounterMsgBodyReportWorkShop	= 0;

	string 					l_inputCmd;
	int 					l_quitRequested							= 0;
	int 					l_clientSocket;

	CTcpClient l_CTcpClient(54000, "127.0.0.1");
	l_clientSocket = l_CTcpClient.initTcpClient();
	if(l_clientSocket != -1)
	{
		//	While loop: send and receive message from server
			do
			{
				// Enter cient cmd
					cout << "> Client cmd : ";
					getline(cin, l_inputCmd);

				// Treat client cmd
					// Display the help message
						if(strcmp(l_inputCmd.c_str(), "help") == 0)
						{
							cout << "	help : display this help message \n";
							cout << "	quit : close TCP client \n";

							// Get and display a message that can be received from the server
							cout << "	getMsgInfoKeepAlive \n";
							cout << "	getMsgInfoPosition \n";
							cout << "	getMsgOrderBit \n";
							cout << "	getMsgOrderPath \n";
							cout << "	getMsgOrderPathCorr \n";
							cout << "	getMsgOrderWorkShop \n";
							cout << "	getMsgOrderStop \n";

							// Get and display a message that can be sent the server
							cout << "	getMsgReportBit \n";
							cout << "	getMsgReportWorkShop \n";

							// Simulate an update of a message that can be sent to the server
							cout << "	updateMsgReportBit \n";
							cout << "	updateMsgReportWorkShop \n";

							// Send a message to the server
							//cout << "	sendMsgReportBit \n";		// Message automatically sent in response of a server request
							cout << "	sendMsgReportWorkShop \n";
						}

					// Close the client
						else if(strcmp(l_inputCmd.c_str(), "quit") == 0)
						{
							l_CTcpClient.closeTcpClient();
							l_quitRequested = 1;
						}

					// Display a message that can be received from the server
						else if(strcmp(l_inputCmd.c_str(), "getMsgInfoKeepAlive") == 0)
						{
							l_CTcpClient.getMsg(ID_MSG_INFO_KEEP_ALIVE, &l_msgInfoKeepAlive);
							displayMsgInfoKeepAlive(&l_msgInfoKeepAlive);
						}

						else if(strcmp(l_inputCmd.c_str(), "getMsgInfoPosition") == 0)
						{
							l_CTcpClient.getMsg(ID_MSG_INFO_POSITION, &l_msgInfoPosition);
							displayMsgInfoPosition(&l_msgInfoPosition);
						}

						else if(strcmp(l_inputCmd.c_str(), "getMsgOrderBit") == 0)
						{
							l_CTcpClient.getMsg(ID_MSG_ORDER_BIT, &l_msgOrderBit);
							displayMsgOrderBit(&l_msgOrderBit);
						}

						else if(strcmp(l_inputCmd.c_str(), "getMsgOrderPath") == 0)
						{
							l_CTcpClient.getMsg(ID_MSG_ORDER_PATH, &l_msgOrderPath);
							displayMsgOrderPath(&l_msgOrderPath);
						}

						else if(strcmp(l_inputCmd.c_str(), "getMsgOrderPathCorr") == 0)
						{
							l_CTcpClient.getMsg(ID_MSG_ORDER_PATH_CORR, &l_msgOrderPathCorr);
							displayMsgOrderPathCorr(&l_msgOrderPathCorr);
						}

						else if(strcmp(l_inputCmd.c_str(), "getMsgOrderWorkShop") == 0)
						{
							l_CTcpClient.getMsg(ID_MSG_ORDER_WORKSHOP, &l_msgOrderWorkShop);
							displayMsgOrderWorkShop(&l_msgOrderWorkShop);
						}

						else if(strcmp(l_inputCmd.c_str(), "getMsgOrderStop") == 0)
						{
							l_CTcpClient.getMsg(ID_MSG_ORDER_STOP, &l_msgOrderStop);
							displayMsgOrderStop(&l_msgOrderStop);
						}

					// Display a message that can be sent the server
						else if(strcmp(l_inputCmd.c_str(), "getMsgReportBit") == 0)
						{
							l_CTcpClient.getMsg(ID_MSG_REPORT_BIT, &l_msgReportBit);
							displayMsgReportBit(&l_msgReportBit);
						}

						else if(strcmp(l_inputCmd.c_str(), "getMsgReportWorkShop") == 0)
						{
							l_CTcpClient.getMsg(ID_MSG_REPORT_WORKSHOP, &l_msgReportWorkShop);
							displayMsgReportWorkShop(&l_msgReportWorkShop);
						}

					// Simulate an update of a message that can be sent to the server
						else if(strcmp(l_inputCmd.c_str(), "updateMsgReportBit") == 0)
						{
							if((l_updateCounterMsgBodyReportBit%2) == 0)
							{
								l_CTcpClient.updateMsg(ID_MSG_REPORT_BIT, &l_msgReportBitBody1);
								l_updateCounterMsgBodyReportBit = 0;
							}
							else
							{
								l_CTcpClient.updateMsg(ID_MSG_REPORT_BIT, &l_msgReportBitBody2);
							}
							l_updateCounterMsgBodyReportBit++;
						}

						else if(strcmp(l_inputCmd.c_str(), "updateMsgReportWorkShop") == 0)
						{
							if((l_updateCounterMsgBodyReportWorkShop%2) == 0)
							{
								l_CTcpClient.updateMsg(ID_MSG_REPORT_WORKSHOP, &l_msgReportWorkShopBody1);
								l_updateCounterMsgBodyReportWorkShop = 0;
							}
							else
							{
								l_CTcpClient.updateMsg(ID_MSG_REPORT_WORKSHOP, &l_msgReportWorkShopBody2);
							}
							l_updateCounterMsgBodyReportWorkShop++;
						}

					// Send a message to the server
						else if(strcmp(l_inputCmd.c_str(), "sendMsgReportBit") == 0)
						{
							l_CTcpClient.sendMsgToServer(ID_MSG_REPORT_BIT);
						}

						else if(strcmp(l_inputCmd.c_str(), "sendMsgReportWorkShop") == 0)
						{
							l_CTcpClient.sendMsgToServer(ID_MSG_REPORT_WORKSHOP);
						}

					// Default
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

	cout << "Test C++ library for TCP communication : Client (end)" << endl;
    return 0;
}
