#include <stdio.h>
#include <string.h>
#define MAX_STR 50

int shortestDistance(int xP1, int yP1, int xP2, int yP2){
    // Find the shortest distance between two points.
    return (((xP2-xP1)*(xP2-xP1))+((yP2-yP1)*(yP2-yP1)));
}

void findFishingSpots(int h, int w, int map[h][w], int xBot, int yBot, int *xFish, int *yFish){
    // Counts how many fishing spots there are on the map.
    int count = 0;

    for(int i=0; i<h; i++){
        for(int j=0; j<w; j++){
            if(map[i][j] > 1 && ((map[i][j] % 10) != 1)){
                count++;
            }
        }
    }

    // Stores in each vector the separate coordinates of each fishing spots.
    int xFishs[count], yFishs[count];

    count = 0;

    for(int i=0; i<h; i++){
        for(int j = 0; j<w; j++){
            if(map[i][j] > 1 && ((map[i][j] % 10) != 1)){
                xFishs[count] = i;
                yFishs[count] = j;
                count++;
            }
        }
    }

    // Find the fishing spots closest to the bot.
    int less = shortestDistance(xFishs[0],yFishs[0],xBot,yBot);
    *xFish = xFishs[0];
    *yFish = yFishs[0];

    for(int i=0; i<count; i++){
        for(int j=i+1; j<count - 1; j++){
            shortestDistance(xFishs[i],yFishs[i],xBot,yBot);
        }
    }
    
    for(int i=0; i<count; i++){
        if(shortestDistance(xFishs[i],yFishs[i],xBot,yBot) < less){
            less = shortestDistance(xFishs[i],yFishs[i],xBot,yBot);
            *xFish = xFishs[i];
            *yFish = yFishs[i];
        }
    }
}

void findFishingPorts(int h, int w, int map[h][w], int xBot, int yBot, int *xPort, int *yPort){
    // Counts how many fishing ports there are on the map.
    int count = 0;

    for(int i=0; i<h; i++){
        for(int j=0; j<w; j++){
            if(map[i][j] == 1){
                count++;
            }
        }
    }

    // Stores in each vector the separate coordinates of each fishing port.
    int xPorts[count], yPorts[count];

    count = 0;

    for(int i=0; i<h; i++){
        for(int j = 0; j<w; j++){
            if(map[i][j] == 1){
                xPorts[count] = i;
                yPorts[count] = j;
                count++;
            }
        }
    }

    // Find the fishing port closest to the bot.
    int less = shortestDistance(xPorts[0],yPorts[0],xBot,yBot);
    *xPort = xPorts[0];
    *yPort = yPorts[0];
    
    for(int i=0; i<count; i++){
        if(shortestDistance(xPorts[i],yPorts[i],xBot,yBot) < less){
            less = shortestDistance(xPorts[i],yPorts[i],xBot,yBot);
            *xPort = xPorts[i];
            *yPort = yPorts[i];
        }
    }
}

void readData(int h, int w, int map[h][w], char myId[MAX_STR], int *xBot, int *yBot){
    char id[MAX_STR];
    int n, x, y;

    // Read map.
    for(int i=0; i<h; i++){
        for(int j=0; j<w; j++){
            scanf("%i", &map[i][j]);
        }
    }

    scanf(" BOTS %i", &n);

    // Find my bot.
    for(int i=0; i<n; i++){
        scanf("%s %i %i", id, &x, &y);
        if(strcmp(id, myId) == 0){
            *xBot = x;
            *yBot = y;
        }
    }
}

int movement(int xBot, int yBot, int xDes, int yDes, char line[MAX_STR]){
    // Controls the bot's movement, returning 1 if the bot arrives at the target location.
    if(yBot < yDes){
        printf("RIGHT\n");
        scanf("%s", line);
        return 0;
    }
    if(yBot > yDes){
        printf("LEFT\n");
        scanf("%s", line);
        return 0;
    }
    if(yBot == yDes){
        if(xBot > xDes){
            printf("UP\n");
            scanf("%s", line);
            return 0;
        }
        if(xBot < xDes){
            printf("DOWN\n");
            scanf("%s", line);
            return 0;
        }
    }
    return 1;
}

int main(){
    char line[MAX_STR];
    char myId[MAX_STR];

    setbuf(stdin, NULL);
    setbuf(stdout, NULL);
    setbuf(stderr, NULL);

    int h, w;
    scanf("AREA %i %i", &h, &w);
    scanf(" ID %s", myId);

    int map[h][w], xBot, yBot, xFish, yFish, xPort, yPort;

    while(1){
        readData(h,w,map,myId,&xBot,&yBot);
        findFishingSpots(h,w,map,xBot,yBot,&xFish,&yFish);
        // Moves the bot until it reaches the fishing spot.
        if(movement(xBot,yBot,xFish,yFish,line) == 1){
            // At the fishing spot, fish until 2 fish remain.
            if(map[xBot][yBot] % 10 == 2){
                printf("FISH\n");
                scanf("%s", line);
                while(1){
                    readData(h,w,map,myId,&xBot,&yBot);
                    // Find the nearest fishing port and sell the fish.
                    findFishingPorts(h,w,map,xBot,yBot,&xPort,&yPort);
                    if(movement(xBot,yBot,xPort,yPort,line) == 1){
                        printf("SELL\n");
                        scanf("%s", line);
                        break;
                    }
                }  
            }
            else{
                printf("FISH\n");
                scanf("%s", line);
            }
        }
    }

    return 0;
}