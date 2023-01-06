#include "Player.h"
#include <iostream>
#include <string>
using namespace std;


Player::Player() {
	firstName = "";
	middleName = "";
	lastName = "";
	school = "";
	rating = -1;	// -1 rating indicates unrated
	wins = 0;
	draws = 0;
}
Player::Player(string first, string middle, string last, string s, int r) {
	firstName = first;
	middleName = middle;
	lastName = last;
	school = s;
	rating = r;
	wins = 0;
	draws = 0;
}
Player::Player(string first, string middle, string last, string s, int r, int w, int d) {
	firstName = first;
	middleName = middle;
	lastName = last;
	school = s;
	rating = r;
	wins = w;
	draws = d;
}
string Player::getFirstName() {
	return firstName;
}
string Player::getMiddleName() {
	return middleName;
}
string Player::getLastName() {
	return lastName;
}
string Player::getFullName() {
	return firstName + " " + middleName + " " + lastName;
}

string Player::getSchool() {
	return school;
}
int Player::getRating() {
	return rating;
}
void Player::setRating(int r) {
	rating = r;
}
void Player::addWin() {
	wins++;
}
void Player::addDraw() {
	draws++;
}
int Player::getWins() {
	return wins;
}
int Player::getDraws() {
	return draws;
}