#ifndef TOURNAMENT_H
#define TOURNAMENT_H

#include <string>
#include <vector>
#include <iostream>
#include "Match.h"
#include "Round.h"
using namespace std;

class Tournament {
	private:
		vector<Player> players; // stores all the players in the tournament
		vector<Round> rounds; // stores every round that has been finished
		int currentRound; // the current round that is being played
	public:
		Tournament(); // default constructor that creates an empty vector for players and rounds, and creates the current round
		void addPlayer(Player); // adds player to players
		void advanceRound(); // creates a new round if all matches in the previous round are finished and adds the current round to the rounds vector
		Player determineWinner(); // determines the winner of the tournament
		vector<Player> getPlayers(); // returns players vector
		Player getPlayer(string); // returns a specific player given their name
		int getCurrentRound(); // returns the current ongoing round
		void setCurrentRound(int); // sets the current round to the given int
		vector<Round> getRounds(); // returns the rounds vector
		void addRound(Round); // adds a round to the rounds vector
		Round* getRound(int); // returns a pointer to the given round
		void rotatePlayers(); // rotates the list of players to the right except for the first player, used for setting up matches
		void updatePlayerRating(int, int); // changes the given player's rating to the given int
};

#endif