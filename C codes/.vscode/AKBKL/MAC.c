// #include <stdio.h>
// #include <string.h>
// #include <sys/ioctl.h>
// #include <sys/socket.h>
// #include <net/if.h>
// #include <unistd.h>
// int main()
// {
//     int sockfd;
//     struct ifreq ifr;
//     char *iface = "enp0s3" unsigned char * mac;
//     // Create a socket to communicate with the network device
//     sockfd = socket(AF_INET, SOCK_DGRAM, 0);
//     if (sockfd < 0)
//     {
//         perror("socket");
//         return 1;
//     }
//     // Specify the network interface name
//     strncpy(ifr.ifr_name, iface, IFNAMSIZ - 1);
//     // Retrieve the MAC address
//     if (ioctl(sockfd, SIOCGIFHWADDR, &ifr) < 0)
//     {
//         perror("ioctl");
//         close(sockfd);
//         return 1;
//     }
//     // Extract the MAC address
//     mac = (unsigned char *)ifr.ifr_hwaddr.sa_data;
//     // Print the MAC address
//     printf("MAC address of %s: %02x:%02x:%02x:%02x:%02x:%02x\n",
//            iface, mac[0], mac[1], mac[2], mac[3], mac[4], mac[5]);
//     // Close the socket
//     close(sockfd);
//     return 0;
// }