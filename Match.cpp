#include "Match.h"
#include <iostream>
#include <string>

using namespace std;

Match::Match() {
	int player1Score = 0;
	int player2Score = 0;
	int draws = 0;
	string winner = "";
}
Match::Match(Player p1, Player p2) {
	player1 = p1;
	player2 = p2;
	player1Score = 0;
	player2Score = 0;
	draws = 0;
	winner = "NA";
}
Match::Match(Player p1, Player p2, int p1Score, int p2Score, int d, string w) {
	player1 = p1;
	player2 = p2;
	player1Score = p1Score;
	player2Score = p2Score;
	draws = d;
	winner = w;
}
void Match::updatePlayer1Score() {
	player1Score++;
}
void Match::updatePlayer2Score() {
	player2Score++;
}
void Match::updateDraws() {
	draws++;
}
void Match::setWinner() {
	if (player1Score + player2Score + draws == 2) {
		cout << "fix setting winner";
	}
}
Player Match::getPlayer1() {
	return player1;
}
Player Match::getPlayer2() {
	return player2;
}
Player* Match::p1Pointer() {
	return &player1;
}
Player* Match::p2Pointer() {
	return &player2;
}
int Match::getPlayer1Score() {
	return player1Score;
}
int Match::getPlayer2Score() {
	return player2Score;
}
int Match::getDraws() {
	return draws;
}
string Match::getWinner() {
	return winner;
}