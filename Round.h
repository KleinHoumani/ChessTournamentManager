#ifndef ROUND_H
#define ROUND_H

#include <string>
#include <vector>
#include "Match.h"
using namespace std;


class Round {
	private:
		vector<Match> matches; // stores every match that has been played or is in progress
	public:
		Round();
		Round(vector<Match>); // overloaded constructor that copies the given vector to matches
		Match* getMatch(string); // returns a match given a player
		vector<Match> getMatches(); // returns the matches vector
		void addMatch(Match); // adds a new match to the matches vector
		bool allMatchesFinished(); // checks if all matches are finished
};

#endif