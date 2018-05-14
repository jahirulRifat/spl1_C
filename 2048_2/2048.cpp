
#include<graphics.h>
#include<stdio.h>
#include<math.h>
#include<time.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>


const int N=4,
            tileSize=64,
            WIDTH=N*tileSize,
            HEIGHT=N*tileSize;


bool gameWin=false;
bool didShift=0;
int score;
int gameBoard[N][N];
int gameBoard2[N][N];

void pushUp() {

    didShift=0;

	printf("Pushing Up\n");
	int  alreadyCombined[N][N] = {{0,0,0,0},{0,0,0,0},
            {0,0,0,0},{0,0,0,0}};

    int x,X,y,value;
	for(y=0;y<N;y++) {
	    for(x=1;x<N;x++) {
				//printArray();

			if(gameBoard[x][y] != 0) {
				value=gameBoard[x][y];

				X = x-1;
				while((X>=0) && (gameBoard[X][y]==0)) {
					X--;
				}
					//System.out.println(X+" "+y);

				if(X == -1) {
					gameBoard[0][y]= value;
					gameBoard[x][y]= 0;
					didShift=1;
						//System.out.println("X= -1");
				}
				else if(gameBoard[X][y] != value) {

					if(x==X+1) {
						gameBoard[x][y]= value;
					}else {
						gameBoard[X+1][y]= value;
						gameBoard[x][y]= 0;
					}
					didShift=1;
						//System.out.println("X= X+1");
				}
				else if (gameBoard[X][y]== gameBoard[x][y]){
					if(alreadyCombined[X][y]) {
						gameBoard[X+1][y]=value;
						gameBoard[x][y]=0;
					}else {
						gameBoard[X][y]*=2;
						score+=gameBoard[X][y];
						alreadyCombined[X][y]=1;
						gameBoard[x][y]=0;
					}
					didShift=1;
						//System.out.println("X= X");
				}
			}
		}
	}
}
void pushRight() {

    didShift=0;
    printf("Pushing Right\n");
    int  alreadyCombined[N][N] = {{0,0,0,0},{0,0,0,0},
                {0,0,0,0},{0,0,0,0}};

    int x,Y,y,value;
    for( x=N-1;x>=0;x--) {
        for( y=N-2;y>=0;y--) {
            //printArray();

            if(gameBoard[x][y] != 0) {
                value=gameBoard[x][y];

                Y = y+1;
                while((Y<=N-1) && (gameBoard[x][Y]==0)) {
                    Y++;
                }
                    //System.out.println(X+"  "+y);

                if(Y == N) {
                    gameBoard[x][N-1]= value;
                    gameBoard[x][y]= 0;
                    didShift=1;
                        //System.out.println("X= 4");
                }
                else if(gameBoard[x][Y] != value) {

                    if(y==Y-1 ) {
                        gameBoard[x][y]= value;
                    }else {
                        gameBoard[x][Y-1]= value;
                        gameBoard[x][y]= 0;
                    }
                    didShift=1;
                        //System.out.println("X= X-1");
                }
                else if (gameBoard[x][Y]== gameBoard[x][y]){

                    if(alreadyCombined[x][Y]) {
                        gameBoard[x][Y-1]=value;
                        gameBoard[x][y]=0;
                    }else {
                        gameBoard[x][Y]*=2;
                        score+=gameBoard[x][Y];
                        alreadyCombined[x][Y]=1;
                        gameBoard[x][y]=0;
                    }
                    didShift=1;
                    //System.out.println("X= X");
                }
            }
        }
    }
}
void pushLeft() {

    didShift=0;
    printf("Pushing Left\n");
    int  alreadyCombined[N][N] = {{0,0,0,0},{0,0,0,0},
                {0,0,0,0},{0,0,0,0}};

    int x,Y,y,value;
    for(x=0;x<N;x++) {
        for(y=1;y<N;y++) {
                //printArray();

            if(gameBoard[x][y] != 0) {
                value=gameBoard[x][y];

                Y = y-1;
                while((Y>=0) && (gameBoard[x][Y]==0)) {
                    Y--;
                }
                    //System.out.println(X+"  "+y);
                if(Y == -1) {
                    gameBoard[x][0]= value;
                    gameBoard[x][y]= 0;
                    didShift=1;
                        //System.out.println("X= 4");
                }

                else if(gameBoard[x][Y] != value) {

                    if(y==Y+1 ) {
                        gameBoard[x][y]= value;
                    }else {
                        gameBoard[x][Y+1]= value;
                        gameBoard[x][y]= 0;
                    }
                    didShift=1;
                        //System.out.println("X= X-1");
                }
                else if (gameBoard[x][Y] == gameBoard[x][y]){
                    if(alreadyCombined[x][Y]) {
                        gameBoard[x][Y+1]=value;
                        gameBoard[x][y]=0;
                    }else {
                        gameBoard[x][Y]*=2;
                        score+=gameBoard[x][Y];
                        alreadyCombined[x][Y]=1;
                        gameBoard[x][y]=0;
                    }
                    didShift=1;
                }
                //System.out.println("X= X");
            }
        }
    }
}
void pushDown() {

    didShift=0;
    printf("Pushing Down\n");
    int  alreadyCombined[N][N] = {{0,0,0,0},{0,0,0,0},
            {0,0,0,0},{0,0,0,0}};

    int x,X,y,value;
    for(y=0;y<N;y++) {
        for(x=N-2;x>=0;x--) {
            //printArray();

            if(gameBoard[x][y] != 0) {
                value=gameBoard[x][y];

                X = x+1;
                while((X<N) && (gameBoard[X][y]==0)) {
                    X++;
                }
                //System.out.println(X+"  "+y);

                if(X == N) {
                    gameBoard[N-1][y]= value;
                    gameBoard[x][y]= 0;
                    didShift=1;
                    //System.out.println("X= 4");
                }
                else if(gameBoard[X][y] != value) {

                    if(x==X-1 ) {
                        gameBoard[x][y]= value;
                    }else {
                        gameBoard[X-1][y]= value;
                        gameBoard[x][y]= 0;
                    }
                    didShift=1;
                    //System.out.println("X= X-1");
                }
                else if (gameBoard[X][y]== gameBoard[x][y]){

                    if(alreadyCombined[X][y]) {
                        gameBoard[X-1][y]=value;
                        gameBoard[x][y]=0;
                    }else {
                        gameBoard[X][y]*=2;
                        score+=gameBoard[X][y];
                        alreadyCombined[X][y]=1;
                        gameBoard[x][y]=0;
                    }
                    didShift=1;
                    //System.out.println("X= X");
                }
            }
        }
    }
}
int checkFor2048() {

    int x,y;
	for( x=0;x<N;x++) {
		for( y=0;y<N;y++) {
			if(gameBoard[x][y] == 2048) {
				return 1;
			}
		}
	}
	return 0;
}

void addNumberToTile() {

    time_t t;
    int selectedX,selectedY;
    srand((unsigned) time(&t));

    while(1) {
        selectedX=rand() % N;
        selectedY=rand() % N;

        if(gameBoard[selectedX][selectedY] == 0) break;
    }

    int numberChooser=rand()%10;
    int number;
    if(numberChooser==0) {
        number=4;
    }
    else {
        number=2;
    }
    gameBoard[selectedX][selectedY]=number;
}
typedef enum {

    Left,Right,
    Up,Down

}Direction;

void printBoard(){

    int a,b;
    for(a=0;a<N;a++)
    {
        printf("---------------------------------------------\n");
        for(b=0;b<N;b++)
        {
            printf("| %4d     ",gameBoard[a][b]);
        }
        printf("|\n");
    }
    printf("---------------------------------------------\n");
    printf("\n");
}


void shift(Direction d)
{

    if(d == Up){

        //copyArray();
        pushUp();
        //printBoard();
    }
    else if(d == Down){
        //copyArray();
        pushDown();
        //printBoard();
    }
    else if(d == Left){
        //copyArray();
        pushLeft();
        //printBoard();
    }
    else if(d == Right){
        //copyArray();
        pushRight();
        //printBoard();
    }
    if(didShift) {
        addNumberToTile();
        printBoard();
    }
}

void setRectangleStyle(int value){

    if(value == 0){
        //setfillstyle(SOLID_FILL,15);
        setfillstyle(SOLID_FILL,15);
        //settextstyle(BOLD_FONT,HORIZ_DIR,6);
        setbkcolor(15);
    }
    else if(value == 2){
        //setfillstyle(SOLID_FILL,15);
        setfillstyle(SOLID_FILL,7);
        //settextstyle(BOLD_FONT,HORIZ_DIR,6);
        setbkcolor(7);
    }
    else if(value == 4){
        setfillstyle(SOLID_FILL,8);
        //settextstyle(BOLD_FONT,HORIZ_DIR,6);
        setbkcolor(8);
    }
    else if(value == 8){
        setfillstyle(SOLID_FILL,11);
        //settextstyle(BOLD_FONT,HORIZ_DIR,6);
        setbkcolor(11);
    }
    else if(value == 16){
        setfillstyle(SOLID_FILL,3);
        //settextstyle(BOLD_FONT,HORIZ_DIR,5);
        setbkcolor(3);
    }
    else if(value == 32){
        setfillstyle(SOLID_FILL,14);
        //settextstyle(BOLD_FONT,HORIZ_DIR,5);
        setbkcolor(14);
    }
    else if(value == 64){
        setfillstyle(SOLID_FILL,6);
        //settextstyle(BOLD_FONT,HORIZ_DIR,5);
        setbkcolor(6);
    }
    else if(value == 128){
        setfillstyle(SOLID_FILL,10);

        setbkcolor(10);
    }
    else if(value == 256){

        setfillstyle(SOLID_FILL,2);

        setbkcolor(2);
        //setcolor(RED);
    }
    else if(value == 512){
        setfillstyle(SOLID_FILL,12);

        setbkcolor(12);
    }
    else if(value == 1024){
        setfillstyle(SOLID_FILL,4);

        setbkcolor(4);
    }
    else if(value == 2048){
        setfillstyle(SOLID_FILL,1);

        setbkcolor(1);
    }
}
void getStringValue(int value,char *str){

    setRectangleStyle(value);

    char valToChar[20];
    sprintf(valToChar,"%d",value);

    strcpy(str,valToChar);

}
void setText(int x1,int y1,int x2,int y2,char *str)
{

    settextstyle(BOLD_FONT,HORIZ_DIR,1);
    outtextxy(x1+3,y1+2,"       ");
    outtextxy(x1+3,y1+20,"       ");
    outtextxy(x1+3,y1+38,"       ");
    outtextxy(x1+3,y1+56,"       ");
    outtextxy(x1+3,y1+61,"       ");


    if(strlen(str) == 1){
        settextstyle(BOLD_FONT,HORIZ_DIR,7);
        setcolor(0);
        outtextxy(x1+20,y1+12,str);
        setcolor(2);
    }
    else if(strlen(str) == 2){
        settextstyle(BOLD_FONT,HORIZ_DIR,7);
        setcolor(0);
        outtextxy(x1+1,y1+12,str);
        setcolor(2);
    }
    else if(strlen(str) == 3){
        settextstyle(BOLD_FONT,HORIZ_DIR,5);
        setcolor(0);
        outtextxy(x1+3,y1+21,str);
        setcolor(2);
    }
    else if(strlen(str) == 4){
        settextstyle(BOLD_FONT,HORIZ_DIR,4);
        setcolor(0);
        outtextxy(x1+3,y1+25,str);
        setcolor(2);
    }
    //printf("%d\n",strlen(str));
}

void fillRectangle(int x1,int y1,int x2,int y2){

    int points[10]={x1,y1,x1,y2,x2,y2,x2,y1,x1,y1};
    fillpoly(5,points);
}


int main(void)
{
    int i,j;
    time_t t;
    char str[20];
    char str2[20];
    POINT cursorPosition;

    FILE *fp;
    fp=fopen("highScore.txt","r");

    char inputString[20];

    while(!feof(fp)){
        fgets(inputString,20,fp);
    }
    puts(inputString);

    fclose(fp);

    int highScore = atoi(inputString);

    int gd=DETECT;
    int gm;

    //initgraph(&gd,&gm,"");
    initwindow(800,500,"2048");

//    PlaySound(TEXT("Hej.wav"),NULL,SND_SYNC);

    //printBoard();


    addNumberToTile();
    printf("Board:\n");
    printBoard();
    setbkcolor(15);

    //rectangle(0,0,getmaxx(),getmaxy());
    //setfillstyle(XHATCH_FILL,9);
    //floodfill(0,0,3);




    while(!gameWin){

        //getch();

        setcolor(GREEN);
        //setbkcolor(15);


        if(GetAsyncKeyState(VK_LEFT)){
            shift(Left);
        }
        else if(GetAsyncKeyState(VK_RIGHT)){
            shift(Right);
        }
        else if(GetAsyncKeyState(VK_UP)){
            shift(Up);
        }
        else if(GetAsyncKeyState(VK_DOWN)){
            shift(Down);
        }
        else if(GetAsyncKeyState(VK_BACK)){

        }


//        ---------- [0][0]  - [0][3] ------------


        rectangle(50,100,130,180);
        getStringValue(gameBoard[0][0],str);
        floodfill(60,110,GREEN);
        setText(50,100,130,180,str);
        //fillRectangle(50,100,130,180);



        rectangle(130,100,210,180);
        getStringValue(gameBoard[0][1],str);
        floodfill(140,110,GREEN);
        setText(130,100,210,180,str);


        rectangle(210,100,290,180);
        getStringValue(gameBoard[0][2],str);
        floodfill(220,110,GREEN);
        setText(210,100,290,180,str);

        rectangle(290,100,370,180);
        getStringValue(gameBoard[0][3],str);
        floodfill(325,135,GREEN);
        setText(290,100,370,180,str);

//        ---------- [1][0]  - [1][3] ------------


        rectangle(50,180,130,260);
        getStringValue(gameBoard[1][0],str);
        floodfill(60,190,GREEN);
        setText(50,180,130,260,str);


        rectangle(130,180,210,260);
        getStringValue(gameBoard[1][1],str);
        floodfill(140,190,GREEN);
        setText(130,180,210,260,str);


        rectangle(210,180,290,260);
        getStringValue(gameBoard[1][2],str);
        floodfill(220,190,GREEN);
        setText(210,180,290,260,str);


        rectangle(290,180,370,260);
        getStringValue(gameBoard[1][3],str);
        floodfill(300,190,GREEN);
        setText(290,180,370,260,str);


//        ---------- [2][0]  - [2][3] ------------

        rectangle(50,260,130,340);
        getStringValue(gameBoard[2][0],str);
        floodfill(60,270,GREEN);
        setText(50,260,130,340,str);

        rectangle(130,260,210,340);
        getStringValue(gameBoard[2][1],str);
        floodfill(165,295,GREEN);
        setText(130,260,210,340,str);


        rectangle(210,260,290,340);
        getStringValue(gameBoard[2][2],str);
        floodfill(245,295,GREEN);
        setText(210,260,290,340,str);

        rectangle(290,260,370,340);
        getStringValue(gameBoard[2][3],str);
        floodfill(325,295,GREEN);
        setText(290,260,370,340,str);

//        ---------- [3][0]  - [3][3] ------------

        rectangle(50,340,130,420);
        getStringValue(gameBoard[3][0],str);
        floodfill(60,350,GREEN);
        setText(50,340,130,420,str);

        rectangle(130,340,210,420);
        getStringValue(gameBoard[3][1],str);
        floodfill(165,375,GREEN);
        setText(130,340,210,420,str);

        rectangle(210,340,290,420);
        getStringValue(gameBoard[3][2],str);
        floodfill(245,375,GREEN);
        setText(210,340,290,420,str);

        rectangle(290,340,370,420);
        getStringValue(gameBoard[3][3],str);
        floodfill(300,350,GREEN);
        setText(290,340,370,420,str);

//          ------------- Printing text ---------------

        line(50,100,370,100);
        line(50,101,370,101);
        line(50,180,370,180);
        line(50,181,370,181);
        line(50,260,370,260);
        line(50,261,370,261);
        line(50,340,370,340);
        line(50,341,370,341);
        line(50,420,370,420);
        line(50,419,370,419);


        line(51,100,51,420);
        line(50,100,50,420);
        line(130,100,130,420);
        line(131,100,131,420);
        line(210,100,210,420);
        line(211,100,211,420);
        line(290,100,290,420);
        line(291,100,291,420);
        line(370,100,370,420);
        line(371,100,371,420);


        setbkcolor(15);
        setfillstyle(SOLID_FILL,15);

        setcolor(GREEN);
        settextstyle(BOLD_FONT,HORIZ_DIR,2);

        bar(440,100,520,130);
        outtextxy(456,105,"UNDO");
        bar(535,100,690,130);
        outtextxy(540,105,"-->BackSpace");


        bar(440,150,520,180);
        outtextxy(448,155,"START");
        bar(535,150,650,180);
        outtextxy(540,155,"-->SPACE");

        bar(440,200,520,230);
        setcolor(RED);
        outtextxy(458,205,"STOP");
        bar(535,200,650,230);
        outtextxy(540,205,"-->ESC");

        setcolor(BROWN);
        bar(440,250,530,280);
        outtextxy(448,255,"SCORE:");

        bar(550,250,630,280);
        sprintf(str2,"%d",score);
        outtextxy(560,255,str2);

        bar(440,300,580,330);
        outtextxy(445,305,"HIGH SCORE:");

        bar(440,350,580,380);

        if(score>highScore) highScore=score;

        sprintf(str2,"%d",highScore);
        outtextxy(445,355,str2);


        fp=fopen("highScore.txt","w");

        sprintf(str2,"%d",highScore);
        fprintf(fp,str2);

        fclose(fp);



        if(!gameWin){
            if(checkFor2048()) gameWin = 1;
        }


        getch();
        //delay(10);
        //cleardevice();

    }

    getch();
    closegraph();




    return 0;
}
