#include "Tournament.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;


Tournament::Tournament() {
	vector<Player> players = {};
	vector<Round> rounds = {};
	currentRound = 0;
}
void Tournament::addPlayer(Player p) {
	players.push_back(p);
}

void Tournament::advanceRound() {
	currentRound++;
}

Player Tournament::determineWinner() {
	return players[0];
}

vector<Player> Tournament::getPlayers() {
	return players;
}

void Tournament::rotatePlayers() {
	Player last = players[players.size() - 1];
	players.insert(players.begin() + 1, last);
	players.pop_back();
}

vector<Round> Tournament::getRounds() {
	return rounds;
}

int Tournament::getCurrentRound() {
	return currentRound;
}
void Tournament::setCurrentRound(int r) {
	currentRound = r;
}
void Tournament::addRound(Round r){
	rounds.push_back(r);
}

Round* Tournament::getRound(int i) {
	return &rounds[i];
}
Player Tournament::getPlayer(string name) {
	for (int i = 0; i < players.size(); i++) {
		if (players[i].getFullName() == name) {
			return players[i];
		}
	}
}

void Tournament::updatePlayerRating(int i, int r) {
	players[i].setRating(r);
}
