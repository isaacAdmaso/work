#include <stdio.h>
#include <netdb.h>
#include <arpa/inet.h>


int main(int argc, char *argv[])
{
	struct in_addr **addr_list;


    struct hostent *lh  = gethostbyname("www.google.com");
    if (!lh)
        herror("gethostbyname");
    addr_list = (struct in_addr **) lh->h_addr_list;
    for(int i = 0; addr_list[i] != NULL;++i ){
        puts(inet_ntoa(*addr_list[i]));
    }

    printf("\n\n");

    lh = gethostbyname("www.yahoo.com");
    if (!lh)
        herror("gethostbyname");
    addr_list = (struct in_addr **) lh->h_addr_list;
    for(int i = 0; addr_list[i] != NULL;++i ){
        puts(inet_ntoa(*addr_list[i]));
    }
    printf("\n\n");

    lh = gethostbyname("he.wikipedia.org");
    if (!lh)
        herror("gethostbyname");
    addr_list = (struct in_addr **) lh->h_addr_list;
    for(int i = 0; addr_list[i] != NULL;++i ){
        puts(inet_ntoa(*addr_list[i]));
    }
    printf("\n\n");

    lh = gethostbyname("ynet.co.il");
    if (!lh)
        herror("gethostbyname");
    addr_list = (struct in_addr **) lh->h_addr_list;
    for(int i = 0; addr_list[i] != NULL;++i ){
        puts(inet_ntoa(*addr_list[i]));
    }
    return 0;
}
