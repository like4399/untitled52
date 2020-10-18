#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<time.h>
int main() {

    int org[4] ;


    srand(time(0));


    for (int i = 0; i < 4; ++i) {

        int temp = rand()%9 + 1;


        bool exists = false;
        for (int j = 0; j < i; ++j) {
            if (org[j] == temp){

                exists = true;
                break;
            }
        }

        if (exists == true){
            i--;
        }else{

            if (i == 0){
                org[i] = temp;
            }else{
                int j = i-1;
                for (; j >= 0; --j) {

                    if (org[j] > temp){

                        org[j+1] = org[j];
                    }else{


                        org[j+1] = temp;
                        break;
                    }
                }
                if (j < 0){

                    org[j+1] = temp;
                }
            }
        }

    }


    int guess[4] ;
    int aCount = 0;
    int bCount = 0;

    while (1){

        printf("ÇëÊäÈë²Â²âµÄÊý×Ö:");

        for (int i = 0; i < 4; ++i) {
            scanf("%d", &guess[i]);
        }

        for (int i = 0; i < 4; ++i) {

            int num = org[i];
            for (int j = 0; j < 4; ++j) {
                if ( num == guess[j]){

                    if (i == j){
                        aCount++;
                    }else{
                        bCount++;
                    }
                    break;
                }
            }
        }

        if (aCount == 4){
            printf("¹§Ï²Äã²Â¶ÔÁË!!!\n");
            break;
        }else{
            printf("%dA %dB\n",aCount,bCount);
            aCount = 0;
            bCount = 0;
        }
    }

    return 0;
}
