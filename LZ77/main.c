#include <stdio.h>
#include <stdlib.h>

int main()
{
    char dizi[100];
    char devam[100];

    FILE *lz = fopen ("lz.txt","r");

    fgets(dizi,2,lz);
    printf("dizi:%s\n",dizi);
    printf("0,0, %s",dizi);
    printf("\n\n");

    fgets(devam,2,lz);
    printf("devam: %s\n",devam);

    int j = 1;
    int say = 0;

    while(!feof(lz))
    {
        if(dizi[0] != devam[0])
        {
            strcat(dizi,devam);

            printf("dizi: %s\n  ",dizi);
            printf("0,0, %s",devam);
            printf("\n\n");
        }
        else
        {
            strcat(dizi,devam);
            fgets(devam,2,lz);
            say++; //ilk eþit olan için

git:

            if(dizi[j] == devam[0])
            {

                j++;
                say++;
                strcat(dizi,devam);
                fgets(devam,2,lz);
                goto git;
            }

            else
            {

                printf("dizi: %s\n  ",dizi);


                printf("--------------%d ,%d, %s",strlen(dizi)-say,say,devam);
                printf("\n\n");
                strcat(dizi,devam);
            }
        }
        say = 0;

        fgets(devam,2,lz);
        printf("devam: %s\n",devam);

    }
    return 0;
}

