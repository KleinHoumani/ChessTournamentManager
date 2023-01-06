#ifndef PLAYER_H
#define PLAYER_H

#include <string>
using namespace std;

class Player {
private:
	string firstName; // stores the players first name
	string middleName; // stores the players middle name
	string lastName; // stores the players last name
	string school; // stores the players school
	int rating; // stores the players rating or unrated if they don’t have one
	int wins; // stores the amount of wins the player has across all games
	int draws; // stores the amount of draws the player has across all games

public:
	Player();
	Player(string, string, string, string, int); // overloaded constructor with five parameters to set the names, rating, and school
	Player(string first, string middle, string last, string s, int r, int w, int d);
	string getFirstName(); // returns the player’s first name
	string getMiddleName(); // returns the player’s middle name
	string getLastName(); // returns the player’s last name
	string getFullName(); // returns the player’s full name
	string getSchool(); // returns the player's school
	int getRating(); // returns the player’s rating
	void setRating(int); // sets the rating for the player as the given string
	void addWin(); // adds one to wins
	void addDraw(); // adds one to draws
	int getWins(); // returns total wins
	int getDraws(); // returns total draws
};


#endif