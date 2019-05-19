/*************************************************************************
	> File Name: inet_ntoa.c
	> Author: 
	> Mail: 
	> Created Time: 2019年03月16日 星期六 10时08分16秒
 ************************************************************************/

#include<stdio.h>
#include<string.h>
#include <arpa/inet.h>
char *my_inet_ntoa(struct in_addr addr) {
    long long net = addr.s_addr;
    char temp[20] = {0};
    static char ans[1000] = {0};
    int num;
    int ip[4] = {0};
    int j = 3;
    while (net && j) {
        num = 1;
        memset(temp, 0, sizeof(temp));
        for(int i = 0; net >= 0 && i < 8; i++) {
            
            if(net & 1) ip[j] += num;
            net >>= 1;
            num *= 2;
        }
        j--;
    }
    sprintf(ans, "%d.%d.%d.%d", ip[3], ip[2], ip[1], ip[0]);
    printf("%s\n", ans);
    return ans;
}

char *my_inet_ntoa_2(struct in_addr in) {
    int a[4];
    static char ip[20] = {0};
    
    a[3] = in.s_addr >> 24;
    a[2] = (in.s_addr & 0x00FF0000) >> 16;
    a[1] = (in.s_addr & 0x0000FF00) >> 8;
    a[0] = in.s_addr & 0x000000FF;
    sprintf(ip, "%d.%d.%d.%d", a[0], a[1], a[2], a[3]);
    printf("%s\n",ip);
    return ip;
}

char *my_inet_ntoa_3(struct in_addr in) {
    int *ip;
    static char ans[20];
    ip = (char *) &in.s_addr;
    sprintf(ans, "%d.%d.%d.%d", ip[0], ip[1], ip[2], ip[3]);
    return ans;
}

int main() {
    long long n;
    char *ans;
    scanf("%lld", &n);
    struct in_addr addr;
    addr.s_addr = n;
    printf("n = %lld addr=%d\n", n, addr.s_addr);
    ans = my_inet_ntoa(addr);
    printf("%s\n", ans);
    return 0;
}
