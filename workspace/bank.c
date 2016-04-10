#include<stdio.h>

int main() {
    int money = 1000;
    char dir = 0;
    int get = 0;
    int save = 0;
    printf("at your service:\n");
    printf("1 for check, 2 for withdraw, 3 for saving, 4 for exit\n");
    while((dir = getchar()) != EOF) {
        if (dir == '\n')
            continue;
        switch(dir - '1') 
        {
            case 0: 
                printf("check mode: money left is: %d\n", money);
                break;
            case 1:
                printf("withdraw mode: input money you want:\n ");
                scanf("%d", &get);
                if ((money - get) < 0) {
                    printf("please input a smaller numer: \n");
                    break;
                }

                money = money - get;
                printf("money left: %d", money);
                break;
            case 2:
                printf("save mode: input money you want to save:\n ");
                scanf("%d", &save);
                money = money + save;
                printf("money left: %d\n", money);
                break;
            case 3:
                printf("you can get you card: \n");
                return 0;
                break;
            default :
                printf("wrong input: \n");
                break;
        }
    }
    printf("return\n");
}
