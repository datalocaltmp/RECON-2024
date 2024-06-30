#include <stdlib.h>
#include <stdio.h>
#include <dlfcn.h>
#include <string.h>

void deepCoverage(const char *buffer, char sentiment){
    void (*catCrash)() = NULL;

    switch (sentiment) {
        case '!':
            printf("[!] and %s is a stinky cat!\n", buffer);
            break;
        case '.':
            printf("[!] and %s is also a fine cat.\n", buffer);
            break;
        case '~':
            catCrash();
        default:
            printf("[!] and %s is also a cat.\n", buffer);
            break;
    }
}

void coverageTime(const char *buffer, int repeat) {
    void (*catCrash)() = NULL;

    if (buffer[0] == 'a' || buffer[0] == 'A'){
        if(buffer[1] == 'r'){
            if(buffer[2] == 'c'){
                if(buffer[3] == 'h'){
                    if(buffer[4] == 'i'){
                        if(buffer[5] == 'e'){
                            for(int i = 0; i < repeat; i++){
                                printf("[!] %s is the best cat!\n", buffer);
                                char sentiment = '.';
                                if(buffer[6] > 0x0){
                                    sentiment = buffer[6];
                                }
                                deepCoverage("Floyd", sentiment);
                            }
                        }else{
                            catCrash();
                        }
                    }
                }
            }
        }
    }else if (buffer[0] == 'f' || buffer[0] == 'F'){
        if(buffer[1] == 'l'){
            if(buffer[2] == 'o'){
                if(buffer[3] == 'y'){
                    if(buffer[4] == 'd'){
                        printf("[!] %s is an alright cat!\n", buffer);
                        char sentiment = '.';
                        if(buffer[6] > 0x0){
                            sentiment = buffer[6];
                        }
                        deepCoverage("Archie", sentiment);
                    }else{
                        catCrash();
                    }
                }
            }
        }
    }
}

int main(int argc, char *argv[]) {
    char catName[8];
    printf("Who is the better cat? [Floyd\\Archie]\n");
    scanf("%s", catName);

    coverageTime(catName, 5);

    exit(0);
}

