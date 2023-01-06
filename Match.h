#ifndef MATCH_H
#define MATCH_H

#include <string>
#include "Player.h"
using namespace std;


class Match {
	private:
		Player player1; // stores the first player
		Player player2; // stores the second player
		int player1Score; // stores rounds won by the first player
		int player2Score; // stores rounds won by the second player
		int draws; // stores how many draws there have been
		string winner; // stores who won the match or if it was a draw

	public:
		Match();
		Match(Player, Player); // overloaded constructor that sets player1 and player2 with the parameters and sets the players’ scores and draws to 0
		Match(Player, Player, int, int, int, string); // overlaoded constructor for reloading matches
		void updatePlayer1Score(); // adds 1 to player1’s score
		void updatePlayer2Score(); // adds 1 to player2’s score
		void updateDraws(); // adds 1 to draws
		void setWinner(); // if 2 games have been played, winner will be set to the player that won or a draw based on the scores
		Player getPlayer1(); // returns player1
		Player getPlayer2(); // returns player2
		Player* p1Pointer(); // returns pointer to player1
		Player* p2Pointer(); // returns pointer to player2
		int getPlayer1Score(); // returns player1’s score
		int getPlayer2Score(); // returns player2’s score
		int getDraws(); // returns the amount of draws
		string getWinner(); // returns the winner of the match
};
#endif

