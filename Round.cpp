#include "Round.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

Round::Round() {
	vector<Match> matches = {};
}
Round::Round(vector<Match> matches) {

}

Match* Round::getMatch(string name) {
	for (int i = 0; i < matches.size(); i++) {
		if (matches[i].getPlayer1().getFullName() == name || matches[i].getPlayer2().getFullName() == name) {
			return &matches[i];
		}
	}
}

vector<Match> Round::getMatches() {
	return matches;
}
void Round::addMatch(Match m) {
	matches.push_back(m);
}
bool Round::allMatchesFinished() {
	for (int i = 0; i < matches.size(); i++) {
		return true;
	}
}