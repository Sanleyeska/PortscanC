#include <stdio.h>
#include <sys/socket.h>
#include <netdb.h>
#include <unistd.h>

int main(int argc, char *argv[]){
  if (argc<=2) {
    printf("ERROR\n");
    printf("Example of use: ./portscan IP RANGE\n");
  } else {
    int mysocket;
    int connexion;
    char *rangeport;
    rangeport = argv[2];
    char port;
    char *destination;
    destination = argv[1];

    struct sockaddr_in target;

    for(port=1; port<=*rangeport; port++){
      mysocket = socket(AF_INET, SOCK_STREAM, 0);
      target.sin_family = AF_INET;
      target.sin_port = htons(port);
      target.sin_addr.s_addr = inet_addr(destination);
      connexion = connect(mysocket, (struct sockaddr *)&target, sizeof target);

      if(connexion == 0){
        printf("PORT %d - [OPEN]\n", port);
        close(mysocket);
        close(connexion);
      } else {
        close(mysocket);
        close(connexion);
      }
    }
  }
}
