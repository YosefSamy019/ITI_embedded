#include <stdio.h>
void main() {
    unsigned id = 0;

    printf("Enter ID: ");
    scanf("%u", &id);

    printf("Username: ");

    switch (id) {
    case 1234:
        printf("Ahmed");
        break;
    case 5677:
        printf("Youssef");
        break;
    case 1145:
        printf("Mina");
        break;
    default:
        printf("Undefined");
        break;
    }
}