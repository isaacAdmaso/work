#include <stdio.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <string.h>


int main(int argc, char *argv[])
{
	struct in_addr **addr_list;
    struct hostent *lh;
    char *webN,temp[1024];
    char tok[2] = ".";
    int j;



    for(int i = 1; i < argc; ++i){

        strcpy(temp,argv[i]);
        webN = strtok(temp,tok);

        webN = strtok(NULL,tok);


        printf("\t%s\n",webN);
        lh  = gethostbyname(argv[i]);
        if (!lh)
            herror("gethostbyname");
        addr_list = (struct in_addr **) lh->h_addr_list;
        for(j = 0; addr_list[j] != NULL; ++j ){
            puts(inet_ntoa(*addr_list[j]));
        }
        printf("\n\n");
    }

    return 0;
}
