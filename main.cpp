// Project 2 - Chess Tournament Manager

#include <iostream>
#include <string>
#include <fstream>

#include "Player.h"
#include "Match.h"
#include "Round.h"
#include "Tournament.h"

using namespace std;

// creates file for reloading players in the event
void savePlayers(Tournament* t) {
	ofstream playersFile;
	string fileName;
	
	cout << "Enter the name you would like for the players file:" << endl;
	cin >> fileName;

	playersFile.open(fileName);
	
	vector<Player> players = t->getPlayers();
	for (int i = 0; i < players.size(); i++) {
		playersFile << players[i].getFullName() << " " << players[i].getSchool() << " " << players[i].getRating() << " " << players[i].getWins() << " " << players[i].getDraws();
		if (i != players.size() - 1) {
			playersFile << endl;
		}
	}

	playersFile.close();
}

// add players from the given file to the event
void loadPlayers(Tournament* t) {
	ifstream playersFile;
	string fileName;

	cout << "Enter the name of the file with the players:" << endl;
	cin >> fileName;

	playersFile.open(fileName);

	string first, middle, last, school;
	int rating;
	int wins, draws;
	string line;
	while (!playersFile.eof()) {
		playersFile >> first >> middle >> last >> school >> rating >> wins >> draws;
		Player newPlayer(first, middle, last, school, rating, wins, draws);
		t->addPlayer(newPlayer);
	}

	playersFile.close();
}

// creates save file for reloading a tournament
void saveTournament(Tournament* t) {
	ofstream tournamentFile;
	string fileName;

	cout << "Enter the name you would like for the tournament file:" << endl;
	cin >> fileName;

	tournamentFile.open(fileName);

	vector<Player> players = t->getPlayers();
	tournamentFile << "Players" << endl;
	for (int i = 0; i < players.size(); i++) {
		tournamentFile << players[i].getFullName() << " " << players[i].getSchool() << " " << players[i].getRating() << " " << players[i].getWins() << " " << players[i].getDraws() << endl;
	}

	vector<Round> rounds = t->getRounds();
	tournamentFile << "Rounds" << endl;
	for (int j = 0; j < rounds.size(); j++) {
		tournamentFile << "Round" << endl;
		vector<Match> matches = rounds[j].getMatches();
		for (int k = 0; k < matches.size(); k++) {
			tournamentFile << matches[k].getPlayer1().getFullName() << " " << matches[k].getPlayer2().getFullName() << " ";
			tournamentFile << matches[k].getPlayer1Score() << " " << matches[k].getPlayer2Score() << " " << matches[k].getDraws() << " " << matches[k].getWinner() << endl;
		}
	}

	tournamentFile << "CurrentRound" << endl;
	tournamentFile << t->getCurrentRound() << endl;
}

// loads a tournament from the given file name
void loadTournament(Tournament* t) {
	ifstream tournamentFile;
	string fileName;

	cout << "Enter the name of the file with the tournament data:" << endl;
	cin >> fileName;

	tournamentFile.open(fileName);

	string first, middle, last, school;
	int rating;
	string line;
	int wins, draws;
	getline(tournamentFile, line);
	while (true) {
		tournamentFile >> first;
		if (first == "Rounds") {
			break;
		}
		tournamentFile >> middle >> last >> school >> rating >> wins >> draws;
		Player newPlayer(first, middle, last, school, rating, wins, draws);
		t->addPlayer(newPlayer);
	}

	string first1, middle1, last1, first2, middle2, last2;
	int p1Score, p2Score, ds;
	string winner;
	int roundCount = -1;
	while (true) {
		tournamentFile >> first1;
		if (first1 == "CurrentRound") {
			break;
		}
		if (first1 == "Round") {
			t->addRound(Round());
			roundCount++;
			tournamentFile >> first1;
		}
		tournamentFile >> middle1 >> last1 >> first2 >> middle2 >> last2 >> p1Score >> p2Score >> ds >> winner;
		string p1FullName = first1 + " " + middle1 + " " + last1;
		string p2FullName = first2 + " " + middle2 + " " + last2;
		Player p1 = t->getPlayer(p1FullName);
		Player p2 = t->getPlayer(p2FullName);
		t->getRound(roundCount)->addMatch(Match(p1, p2, p1Score, p2Score, ds, winner));
	}
	int currentR;
	tournamentFile >> currentR;
	t->setCurrentRound(currentR);

	cout << "Tournament has been loaded" << endl;

}

int main() {
	Tournament* tournament = new Tournament();
	bool mainMenu = true;
	int option;
	while (mainMenu) {
		cout << endl;
		cout << "-----------------------------------" << endl;
		cout << "Main Menu" << endl;
		cout << "-----------------------------------" << endl;
		cout << "Type the number of the option you would like:" << endl;
		cout << "1. Add player" << endl;
		cout << "2. Add players from file" << endl;
		cout << "3. Save players file" << endl;
		cout << "4. Update match" << endl;
		cout << "5. Start round robin" << endl;
		cout << "6. View Matches" << endl;
		cout << "7. Advance round" << endl;
		cout << "8. Determine winner" << endl;
		cout << "9. Load tournament file" << endl;
		cout << "10. Save tournament file" << endl;
		cout << "11. Quit" << endl << endl;

		cin >> option;


		switch (option) {
		case 1: // Add player
		{
			string first, middle, last, school;
			int rating;

			// Asks for all the information need to create a new player object, then adds it to the tournament
			cout << "Enter the player's first, middle, and last name:" << endl;
			cin >> first >> middle >> last;
			cout << "Enter the player's school name:" << endl;
			cin >> school;
			cout << "Enter the player's rating:" << endl;
			cin >> rating;
			Player newPlayer(first, middle, last, school, rating);
			tournament->addPlayer(newPlayer);
			break;
		}
		case 2: // Add players from file
		{
			loadPlayers(tournament);
			break;
		}
		case 3: // Save players file
		{
			savePlayers(tournament);
			break;
		}
		case 4: // Update match
		{
			cout << "Choose an option below: " << endl;
			cout << "1. Add win" << endl;
			cout << "2. Add draw" << endl;

			int option;
			cin >> option;

			switch (option) {
				case 1: // Add win
				{
					string playerName;

					cout << "Enter the full name of a player that won a game" << endl;
					cin.ignore();
					getline(cin, playerName);

					int current = tournament->getCurrentRound();
					Match* match = tournament->getRound(current)->getMatch(playerName);

					// Checking whether the given player name is player 1 or player 2, then adding a win to their score
					if (match->getPlayer1().getFullName() == playerName) {
						match->updatePlayer1Score();
						match->p1Pointer()->addWin();
					}
					else if (match->getPlayer2().getFullName() == playerName) {
						match->updatePlayer2Score();
						match->p2Pointer()->addWin();
					}
					cout << "Wins updated" << endl;
					break;
				}
				case 2: // Add draw
				{
					string playerName;

					cout << "Enter the full name of either player in the match" << endl;
					cin.ignore();
					getline(cin, playerName);

					int current = tournament->getCurrentRound();
					Match* match = tournament->getRound(current)->getMatch(playerName);

					match->updateDraws();
					match->p1Pointer()->addDraw();
					match->p2Pointer()->addDraw();
					cout << "Draws updated" << endl;
					break;
				}
				default:
				{
					cout << "Choice was invalid" << endl;
				}
			}



			break;
		}
		case 5: // Start round robin
		{
			if (tournament->getRounds().size() > 0) {
				cout << "Round robin has already started" << endl;
				break;
			}
			if (tournament->getPlayers().size() < 2) {
				cout << "Not enough players to start the tournament" << endl;
				break;
			}

			
			// Add a Bye player to the event if there is an odd number of players
			// Anyone who plays against this player gets 2 free wins for the round
			bool oddPlayers = false;
			if (tournament->getPlayers().size() % 2) {
				Player byePlayer = Player("Bye", "Bye", "Bye", "NA", 0);
				tournament->addPlayer(byePlayer);
				oddPlayers = true;
			}



			for (int i = 0; i < tournament->getPlayers().size() - 1; i++) {
				tournament->addRound(Round());
			}


			// Setting up the matches for every round, making sure everyone plays against everybody else twice
			int half = tournament->getPlayers().size() / 2;
			int roundsSize = tournament->getRounds().size();

			for (int i = 0; i < roundsSize; i++) {
				int l = 0, r = tournament->getPlayers().size() - 1;
				while (l < half) {
					tournament->getRound(i)->addMatch(Match(tournament->getPlayers()[l], tournament->getPlayers()[r]));
					l++;
					r--;
				}
				tournament->rotatePlayers();
				}

			// Setting wins for anyone who received free wins for the round
			if (oddPlayers) {
				for (int i = 0; i < roundsSize; i++) {
					Match* m = tournament->getRound(i)->getMatch("Bye Bye Bye");
					if (m->getPlayer1().getFirstName() == "Bye") {
						m->updatePlayer2Score();
						m->updatePlayer2Score();
					}
					else if (m->getPlayer2().getFirstName() == "Bye") {
						m->updatePlayer1Score();
						m->updatePlayer1Score();
					}
				}
			}

			cout << "Tournament has started" << endl;
			break;
		}
		case 6: // View matches
		{
			// Prints out the players and score for every match in every round
			vector<Round> rounds = tournament->getRounds();
			for (int i = 0; i < rounds.size(); i++) {
				cout << endl << "Round " << i + 1 << ":" << endl;
				cout << "----------------------------------------" << endl;
				vector<Match> matches = rounds[i].getMatches();
				for (int j = 0; j < matches.size(); j++) {
					cout << "Match " << j << ":" << endl;
					cout << "Player 1: " << matches[j].getPlayer1().getFullName() << ", Wins: " << matches[j].getPlayer1Score() << endl;
					cout << "Player 2: " << matches[j].getPlayer2().getFullName() << ", Wins: " << matches[j].getPlayer2Score() << endl;
					cout << "Draws: " << matches[j].getDraws() << endl;
				}
			}
			break;
		}
		case 7: // Advance round
		{
			// Checks if there are any more rounds
			int roundNumber = tournament->getCurrentRound();
			if (roundNumber >= tournament->getRounds().size()) {
				cout << "All rounds are finished" << endl;
				break;
			}

			// Check if all matches in the current round are finished
			bool finished = true;
			Round current = *tournament->getRound(tournament->getCurrentRound());
			vector<Match> matches = current.getMatches();
			for (int i = 0; i < matches.size(); i++) {
				int gamesPlayed = matches[i].getDraws() + matches[i].getPlayer1Score() + matches[i].getPlayer2Score();
				if (gamesPlayed != 2) {
					cout << "Not all games are finished" << endl;
					finished = false;
					break;
				}
			}
			if (finished) {
				tournament->advanceRound();
				cout << "Next round has started" << endl;
				for (int i = 0; i < tournament->getRounds().size(); i++) {

				}
			}
			break;
		}
		case 8: // Determine winner
		{
			// Calculating scores for each player. Win = 2 points, Draw = 1 point
			vector<Player> players = tournament->getPlayers();
			int highestScore = 0;
			int winnerIndex = 0;
			for (int i = 0; i < players.size(); i++) {
				int score = players[i].getWins() * 2 + players[i].getDraws();
				if (score > highestScore) {
					highestScore = score;
					winnerIndex = i;
				}
			}

			// Updating each players USCF rating
			vector<Round> rounds = tournament->getRounds();
			for (int i = 0; i < players.size(); i++) {
				double rPre = players[i].getRating();
				double rTotal = 0;
				int gameCount = 0;
				for (int j = 0; j < rounds.size(); j++) {
					Match match = *rounds[j].getMatch(players[i].getFullName());
					if (match.getPlayer1().getFullName() == players[i].getFullName()) {
						rTotal += match.getPlayer2().getRating();
						gameCount += 1;
					}
					else if (match.getPlayer2().getFullName() == players[i].getFullName()) {
						rTotal += match.getPlayer1().getRating();
						gameCount += 1;
					}
				}
				double rAvg = rTotal / gameCount;
				int ws = players[i].getWins();
				int ls = gameCount - ws;
				int newRating = ((gameCount * rPre) + (rAvg * gameCount) + ((ws - ls) * 400)) / (gameCount + gameCount);
				tournament->updatePlayerRating(i, newRating);
			}



			string winnerName = players[winnerIndex].getFullName();
			cout << "--------------------" << endl;                         
			cout << "Winner: " << winnerName << endl;
			cout << "--------------------" << endl;

			break;
		}
		case 9: // Load tournament file
			loadTournament(tournament);
			break;
		case 10: // Save tournament file
			saveTournament(tournament);
			cout << endl << "Tournament saved" << endl;
			break;
		case 11: // Quit
			exit(0);
			break;
		default:
			{
				cout << "Enter a valid choice" << endl;
			}
		}
	}
	return 0;
}
