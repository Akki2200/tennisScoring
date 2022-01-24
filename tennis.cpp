#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

// updates score for next point
void nextServe(int &score1,int &score2){
	if(rand()%2 == 0){
		score1++;
	}else
		score2++;
}

// prints the current score and who won
void displayScore(int &score1,int &score2){
	cout<<"player1 score: "<<score1<<" player2 score: "<<score2<<endl;
	if(score1 > score2){
		cout<<"Player 1 wins"<<endl;
	}else{
		cout<<"Player 2 wins"<<endl;
	}	
}


void tennisMatch(){
	int score1=0,score2=0;

	while(score1 != 11 && score2 != 11){
		nextServe(score1,score2);
	}

	// if any one of the score is 10
	if(score1 == 10 || score2 == 10){

		// checks if the difference of score > 1 and prints the result
		// one of the score is 11 and other will be 10
		if(abs(score1-score2) > 1){
			displayScore(score1,score2);
			return ;
		}

		//players needs to get 2 point lead
		while(score1 < 21 && score2 < 21 && abs(score1-score2) < 2){
			nextServe(score1,score2);
		}

		if(score1 == 20 && score2 == 20){
			//player who gets next point wins
			nextServe(score1,score2);
		}
	}
	displayScore(score1,score2);
}

int main(){
	// 200 runs
	int testcases = 200;
	// to generate different random numbers on every run
	srand(time(0));
	while(testcases--){
		tennisMatch();
	}
	return 0;
}