#include <stdio.h> 
#include <sys/ipc.h> 
#include <sys/msg.h> 
#include <string.h>
#include <stdlib.h>
// structure for message queue 
struct mesg_buffer { 
	long mesg_type; 
	char mesg_text[100]; 
} message; 
int main() {
    key_t key; 
	int msgid; 

	key = ftok("progfile", 65); 


	msgid = msgget(key, 0666 | IPC_CREAT); 
	message.mesg_type = 1; 
	printf("Write Data : "); 
    scanf("%[^\n]%*c", message.mesg_text);

	msgsnd(msgid, &message, sizeof(message), 0); 

	printf("Data sent is : %s \n", message.mesg_text); 
	return 0; 
} 