#include<stdio.h>
#include<string.h>

int max(int n1,int n2,int n3,int n4,int n5){
    int most=n1;
    if (n2 > most){
        most = n2;
    }if (n3 > most) {
        most = n3;
    }if (n4 > most) {
        most = n4;
    }if (n5 > most) {
        most = n5;
    }
    return most;
}

int min(int n1,int n2,int n3,int n4,int n5){
    int mini=n1;
    if (n2 < mini){
        mini = n2;
    }if (n3 < mini) {
        mini = n3;
    }if (n4 < mini) {
        mini = n4;
    }if (n5 < mini) {
        mini = n5;
    }
    return mini;
}

int main(){
    int n1,n2,n3,n4,n5,salt;
    char whatuwant[4];
    scanf("%[^\n]",whatuwant);
    scanf("%d",&n1);
    scanf("%d",&n2);
    scanf("%d",&n3);
    scanf("%d",&n4);
    scanf("%d",&n5);
    if (strcmp(whatuwant,"MAX") == 0) {
        salt = max(n1,n2,n3,n4,n5);
        printf("MAX : %d",salt);
    } else if (strcmp(whatuwant,"MIN") == 0){
        salt = min(n1,n2,n3,n4,n5);
        printf("MIN : %d",salt);
    }

    return 0;

}