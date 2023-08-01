a.exe: ATM_Client.o ATM_Server.o
	gcc ATM_Client.o ATM_Server.o
ATM_Server.o: ATM_Server.c ATM_Header.h
	gcc ATM_Server.c -c
ATM_Client.o: ATM_Client.c ATM_Header.h
	gcc ATM_Client.c -c