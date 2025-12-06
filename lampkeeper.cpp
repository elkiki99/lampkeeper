#include <stdio.h>
#include <stdlib.h>
#include <time.h>

const int ROW = 12, COL = 12;

void surrenderMessage()
{
    int i = rand() % 3;

    if(i == 0)
        printf("Thanks for playing. We will leave the trying part for another day.\n");
    else if(i == 1)
        printf("You left right before the miracle. Not that we were expecting one.\n");
    else
        printf("Surrendering is not for everyone. Winning doesn't seem to be either.\n");
}

void initializeLitLampsMatrix(int litLampsMatrix[][2])
{
    int i, j;

    for(i = 0; i < 9; i++)
        for(j = 0; j < 2; j++)
            litLampsMatrix[i][j] = -1;
}

void initializeBoard(char board[][COL])
{
    int i, j;

    for(i = 0; i < ROW; i++)
        for(j = 0; j < COL; j++)
            board[i][j] = ' ';
}

void addLamps(char board[][COL], int litLampsMatrix[][2], int &lampCount)
{
    int randomRow, randomCol, i, j;
    bool freeSpot;

    do
    {
        randomRow = 1 + rand() % 10;
        randomCol = 1 + rand() % 10;

        freeSpot = true;

        for(i = randomRow - 1; i <= randomRow + 1; i++)
            for(j = randomCol - 1; j <= randomCol + 1; j++)
                if(board[i][j] != ' ')
                    freeSpot = false;

        if (freeSpot)
        {
            board[randomRow][randomCol] = 'i';
            lampCount++;
        }
    } while(lampCount < 9);
}

void addObjects(char board[][COL], char object, int objectAmount)
{
    int randomRow, randomCol;
    int placed = 0;

    do
    {
        randomRow = rand() % 12;
        randomCol = rand() % 12;

        if(board[randomRow][randomCol] == ' ')
        {
            board[randomRow][randomCol] = object;
            placed++;
        }

    } while(placed < objectAmount);
}

void addLamplighter(char board[][COL], int &lamplighterRow, int &lamplighterCol)
{
    int randomRow, randomCol;
    bool placed = false;

    do
    {
        randomRow = rand() % 12;
        randomCol = rand() % 12;

        if(board[randomRow][randomCol] == ' ')
        {
            board[randomRow][randomCol] = '*';
            placed = true;
        }
    } while(!placed);

    lamplighterRow = randomRow;
    lamplighterCol = randomCol;
}

void generateMap(char board[][COL], int litLampsMatrix[][2], int &lamplighterRow, int &lamplighterCol)
{
    srand(time(NULL));

    initializeLitLampsMatrix(litLampsMatrix);
    initializeBoard(board);

    int lampCount = 0;
    addLamps(board, litLampsMatrix, lampCount);
    addObjects(board, 'O', 40); // 40 'O'
    addObjects(board, '/', 20); // 20 '/'
    addLamplighter(board, lamplighterRow, lamplighterCol);
}

void printBoard(int litLampsMatrix[][2], int lamplighterRow, int lamplighterCol, bool visible[][COL], int &visibleTiles, int &litLamps, char board[][COL])
{
    int i, j, k;
    visibleTiles = 0;

    for (i = 0; i < ROW; i++)
    {
        for (j = 0; j < COL; j++)
        {
            visible[i][j] = false;

            for (k = 0; k < litLamps; k++)
            {
                if (i >= litLampsMatrix[k][0] - 1 && i <= litLampsMatrix[k][0] + 1 &&
                    j >= litLampsMatrix[k][1] - 1 && j <= litLampsMatrix[k][1] + 1)
                {
                    visible[i][j] = true;
                }
            }

            if (!visible[i][j])
            {
                if (i >= lamplighterRow - 2 && i <= lamplighterRow + 2 &&
                    j >= lamplighterCol - 2 && j <= lamplighterCol + 2)
                {
                    visible[i][j] = true;
                }
            }

            if (visible[i][j])
            {
                printf("|%c", board[i][j]);
                visibleTiles++;
            }
            else
                printf("| ");
        }
        printf("|\n");
    }
    printf("\n");
}

void saveLampCoordinate(int x, int y, char board[][COL], int &litLamps, int litLampsMatrix[][2])
{
    int i;
    bool freeCoord = true;

    board[x][y] = 'Y';

    for(i = 0; i <= litLamps; i++)
    {
        if(x == litLampsMatrix[i][0] && y == litLampsMatrix[i][1])
        {
            freeCoord = false;
        }
    }

    if(freeCoord)
    {
        litLampsMatrix[litLamps][0] = x;
        litLampsMatrix[litLamps][1] = y;
        litLamps++;
    }
}

void moveLamplighter(int row, int col, char board[][COL], int &litLamps, int litLampsMatrix[][2], int &lamplighterRow, int &lamplighterCol, int &breakableObstacles, bool &standingOnLamp)
{
    int newRow = lamplighterRow + row;
    int newCol = lamplighterCol + col;

    char destination = board[newRow][newCol];

    if (newCol >= 0 && newCol <= 11 && newRow >= 0 && newRow <= 11)
    {
        if (destination == ' ' || destination == 'i' || destination == 'Y' || (destination == '/' && breakableObstacles > 0))
        {
            board[lamplighterRow][lamplighterCol] = ' ';
            board[newRow][newCol] = '*';

            if (destination == 'i' || destination == 'Y')
            {
                standingOnLamp = true;
            }
            else
            {
                if (destination == '/')
                    breakableObstacles--;

                if (standingOnLamp)
                    saveLampCoordinate(lamplighterRow, lamplighterCol, board, litLamps, litLampsMatrix);

                standingOnLamp = false;
            }

            lamplighterRow = newRow;
            lamplighterCol = newCol;
        }
    }
}

void readMovement(char c, char board[][COL], int &litLamps, int litLampsMatrix[][2], int &lamplighterRow, int &lamplighterCol, int &breakableObstacles, bool &surrendered, bool &standingOnLamp)
{
    int i;
    char surrenderWord[4] = {'Q', 'u', 'i', 't'};

    switch(c)
    {
        case 'a': case 'A':
            moveLamplighter(0, -1, board, litLamps, litLampsMatrix, lamplighterRow, lamplighterCol, breakableObstacles, standingOnLamp);
            break;
        case 'd': case 'D':
            moveLamplighter(0, 1, board, litLamps, litLampsMatrix, lamplighterRow, lamplighterCol, breakableObstacles, standingOnLamp);
            break;
        case 'w': case 'W':
            moveLamplighter(-1, 0, board, litLamps, litLampsMatrix, lamplighterRow, lamplighterCol, breakableObstacles, standingOnLamp);
            break;
        case 's': case 'S':
            moveLamplighter(1, 0, board, litLamps, litLampsMatrix, lamplighterRow, lamplighterCol, breakableObstacles, standingOnLamp);
            break;
        default:
            if (c == surrenderWord[0] || c == surrenderWord[0] + 32)
            {
                i = 1;
                c = getchar();

                while(c == surrenderWord[i] || c == surrenderWord[i] - 32)
                {
                    c = getchar();
                    i++;
                }

                if(i == 4)
                    surrendered = true;
            }
            else
            {
                printf("\n\nInvalid input, try again: ");
                while(getchar() != '\n');
            }
            printf("\n");
    }
}

int main()
{
    int litLampsMatrix[9][2], litLamps = 0, lamplighterRow, lamplighterCol, visibleTiles = 0, breakableObstacles = 5;
    char c, board[ROW][COL];
    bool surrendered = false, visible[ROW][COL], standingOnLamp = false;

    generateMap(board, litLampsMatrix, lamplighterRow, lamplighterCol);
    printf("\nWelcome to The Lamplighter! Reveal at least half of the map to win. Good luck, you'll need it...\n\n");
    printBoard(litLampsMatrix, lamplighterRow, lamplighterCol, visible, visibleTiles, litLamps, board);

    do
    {
        printf("\nYou can break %d obstacles. Use WASD to move, or type -Surrender- to quit:\n", breakableObstacles);
        scanf(" %c", &c);

        readMovement(c, board, litLamps, litLampsMatrix, lamplighterRow, lamplighterCol, breakableObstacles, surrendered, standingOnLamp);
        printBoard(litLampsMatrix, lamplighterRow, lamplighterCol, visible, visibleTiles, litLamps, board);

    } while(!surrendered && visibleTiles < COL * ROW / 2);

    if(visibleTiles >= COL * ROW / 2)
    {
        printf("You made it! You revealed %d tiles!\n\n", visibleTiles);
        printBoard(litLampsMatrix, lamplighterRow, lamplighterCol, visible, visibleTiles, litLamps, board);
    }
    else if(surrendered)
        surrenderMessage();
}


