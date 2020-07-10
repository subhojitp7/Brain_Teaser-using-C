#include<stdio.h>
#include<conio.h>
#include<ctype.h>
#include<stdlib.h>
#include<string.h>

void show_record();
bool new_question(int num);
void reset_score();
void help();
void edit_score(float , char []);

int main() {
    int countr,r,r1,count,i,n;
    float score;
    char choice;
    char playername[20];
    mainhome:
    	system("cls");
    	printf("\t\t\tC PROGRAM BRAIN TEASER GAME\n");
    	printf("\n\t\t________________________________________");
    	printf("\n\t\t\t   WELCOME ");
    	printf("\n\t\t\t      to ");
    	printf("\n\t\t\t   THE GAME ");
    	printf("\n\t\t________________________________________");
    	printf("\n\t\t________________________________________");
    	printf("\n\t\t   BECOME A MILLIONAIRE!!!!!!!!!!!    ") ;
    	printf("\n\t\t________________________________________");
    	printf("\n\t\t________________________________________");
    	printf("\n\t\t > Press S to start the game");
    	printf("\n\t\t > Press V to view the highest score  ");
    	printf("\n\t\t > Press R to reset score");
    	printf("\n\t\t > press H for help            ");
    	printf("\n\t\t > press Q to quit             ");
    	printf("\n\t\t________________________________________\n\n");
    	choice = toupper(getch());
    	if (choice=='V') {
			show_record();
			goto mainhome;
		}
    	else if (choice=='H') {
			help();
			getch();
			goto mainhome;
		}
		else if (choice=='R'){
			reset_score();
			getch();
			goto mainhome;}
		else if (choice=='Q')
			exit(1);
    	else if(choice=='S') {
    		system("cls");
    		printf("\n\n\n\n\n\n\n\n\n\n\t\t\tResister your name:");
    		gets(playername);
		    system("cls");
    		printf("\n ------------------  Welcome %s to C Program Quiz Game --------------------------",playername);
    		printf("\n\n Here are some tips you might wanna know before playing:");
    		printf("\n -------------------------------------------------------------------------");
    		printf("\n >> There are 2 rounds in this Quiz Game,WARMUP ROUND & CHALLANGE ROUND");
    		printf("\n >> In warmup round you will be asked a total of 3 questions to test your");
    		printf("\n    general knowledge. You are eligible to play the game if you give atleast 2");
    		printf("\n    right answers, otherwise you can't proceed further to the Challenge Round.");
    		printf("\n >> Your game starts with CHALLANGE ROUND. In this round you will be asked a");
    		printf("\n    total of 10 questions. Each right answer will be awarded $100,000!");
    		printf("\n    By this way you can win upto ONE MILLION cash prize!!!!!..........");
    		printf("\n >> You will be given 4 options and you have to press A, B ,C or D for the");
    		printf("\n    right option.");
    		printf("\n >> You will be asked questions continuously, till right answers are given");
    		printf("\n >> No negative marking for wrong answers!");
    		printf("\n\n\t!!!!!!!!!!!!! ALL THE BEST !!!!!!!!!!!!!");
    		printf("\n\n\n Press Y  to start the game!\n");
    		printf("\n Press any other key to return to the main menu!");
    		if (toupper(getch())=='Y') {
			    goto home;
        	}
			else {
	        	goto mainhome;
    			system("cls");
    		}

    	home:
    		system("cls");
   			count = 0;
    		for (int i=0; i<4; i++) {
    			if (new_question(30)) {
    				count++;
				}
				getch();
			}
		if(count>=2) {
			goto test;
		}
		else {
			system("cls");
			printf("\n\nSORRY YOU ARE NOT ELIGIBLE TO PLAY THIS GAME, BETTER LUCK NEXT TIME");
			getch();
			goto mainhome;
		}
    	test:
			system("cls");
    		printf("\n\n\t*** CONGRATULATION %s you are eligible to play the Game ***",playername);
    		printf("\n\n\n\n\t!Press any key to Start the Game!");
    		if(toupper(getch())=='p')
				goto game;
		game:
			countr=0;
   			for(int i=1;i<=10;i++) {
				system("cls");
				if (new_question(60)) {
    				countr++;
    				getch();
				}
				else {
					getch();
					goto score;
				}
			}
		score:
    		system("cls");
			score=(float)countr*100000;
			if(score>0.00 && score<1000000) {
				printf("\n\n\t\t**************** CONGRATULATION *****************");
	   			printf("\n\t You won $%.2f",score);goto go;
			}
			else if(score==1000000.00) {
			    printf("\n\n\n \t\t**************** CONGRATULATION ****************");
			    printf("\n\t\t\t\t YOU ARE A MILLIONAIRE!!!!!!!!!");
			    printf("\n\t\t You won $%.2f",score);
				printf("\t\t Thank You!!");
			}
			else {
				printf("\n\n\t******** SORRY YOU DIDN'T WIN ANY CASH ********");
    			printf("\n\t\t Thanks for your participation");
	    		printf("\n\t\t TRY AGAIN");
				goto go;
			}
		go:
			puts("\n\n Press Y if you want to play next game");
			puts(" Press any key if you want to go main menu");
			if (toupper(getch())=='Y')
				goto home;
			else {
				edit_score(score,playername);
				goto mainhome;
			}
		}
}

void show_record() {
	system("cls");
	char name[20];
	float scr;
	FILE *f;
	f=fopen("score.txt","r");
	fscanf(f,"%s%f",&name,&scr);
	printf("\n\n\t\t*************************************************************");
	printf("\n\n\t\t %s has secured the Highest Score %0.2f",name,scr);
	printf("\n\n\t\t*************************************************************");
	fclose(f);
	getch();
}

bool new_question(int num) {
	bool mapp[num*2+1] = {false};
	int a,b,ans,user,ansPos;
	system("cls");
    a = (rand() % (num+1));
    b = (rand() % (num+1));
    printf("q> %d + %d",a,b);
    ans = a + b;
    mapp[ans] = true;
    ansPos = (rand() % (4));
    for(int j=0; j<4; j++){
    	int wrong = (rand() % (2*num+1));
    	while (mapp[wrong] != false)
    		wrong = (rand() % (num+1));
    	mapp[wrong] = true;
    	if(j == ansPos)
    		printf("\n%d. %d",j+1,ans);
    	else if(wrong != ans)
   			printf("\n%d. %d",j+1,wrong);
	}
	printf("\nAns: ");
	scanf("%d",&user);
	if (user-1 == ansPos){
		printf("\n\nCorrect!!!");
		return true;
	}
	else
		printf("\n\nWrong!!! The correct answer is %d. %d",ansPos+1,ans);
	return false;
}

void reset_score() {
	system("cls");
    float sc;
	char nm[20];
	FILE *f;
	f=fopen("score.txt","r+");
	fscanf(f,"%s%f",&nm,&sc);
	sc=0;
	fprintf(f,"%s,%.2f",nm,sc);
    fclose(f);
}

void help() {
	system("cls");
    printf("\n\n                              HELP");
    printf("\n -------------------------------------------------------------------------");
    printf("\n ........................C program Brain Teaser Game......................");
    printf("\n >> There are two rounds in the game, WARMUP ROUND & CHALLANGE ROUND");
    printf("\n >> In warmup round you will be asked a total of 3 questions to test your general");
    printf("\n    knowledge. You will be eligible to play the game if you can give atleast 2");
    printf("\n    right answers otherwise you can't play the Game...........");
    printf("\n >> Your game starts with the CHALLANGE ROUND. In this round you will be asked");
    printf("\n    total 10 questions each right answer will be awarded $100,000.");
    printf("\n    By this way you can win upto ONE MILLION cash prize in USD...............");
    printf("\n >> You will be given 4 options and you have to press A, B ,C or D for the");
    printf("\n    right option");
    printf("\n >> You will be asked questions continuously if you keep giving the right answers.");
    printf("\n >> No negative marking for wrong answers");

	printf("\n\n\t*********************BEST OF LUCK*********************************");
	printf("\n\n\t***C PROGRAM BRAIN TEASER GAME is developed by CODE WITH C TEAM***");
}

void edit_score(float score, char plnm[20]) {
	system("cls");
	float sc;
	char nm[20];
	FILE *f;
	f=fopen("score.txt","r");
	fscanf(f,"%s%f",&nm,&sc);
	if (score>=sc) {
		sc=score;
	    fclose(f);
	    f=fopen("score.txt","w");
	    fprintf(f,"%s\n%.2f",plnm,sc);
	    fclose(f);
	}
}
