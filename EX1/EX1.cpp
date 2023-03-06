#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include "nlohmann/json.hpp"
#include <vector>

struct Film {
	std::vector<std::string> cast;
	std::string title;
	std::string company;
	std::string country;
	std::vector<std::string> screenwriter;
	std::vector<std::string> director;
	std::vector<std::string> producer;
	int year;
};

int main() {
	Film move;
	std::ofstream file("record.json");
	//Green Mile//
	move.title = "Green Mile";
	move.year = 1999;
	move.cast = {"Tom Hanks - Paul Edgecomb", "Mikle Clark Duncan - John Koffie", "David Mors - Brut <Brute> Howell", "Bonney Hunt  - Janise Edgecomb", "James Cromwell - Hall Murse"};
	move.company = "Warner Brothers";
	move.country = "USA";
	move.screenwriter = { "Frank Darabont", "Stephen King"};
	move.director = {"Frank Darabont"};
	move.producer = { "Frank Darabont", "David Valdes"};

	nlohmann::json description = {
		{"Title ", move.title},
		{"Year", move.year},
		{"Company", move.company},
		{"Country", move.country},
		{"Screenwriter", move.screenwriter},
		{"Director", move.director},
		{"Producer", move.producer},
		{"Cast", move.cast}
	};
	file << description << std::endl;
	//The Terminal//
	move.title = "The Terminal";
	move.year = 2004;
	move.cast = { "Tom Hanks - Victor Navorski", "Catrine Zeta-Jhones - Amelia Warren", "Mikle Noori - Maks", "Konrad Pla  - Officer", "Mark Ivanir - Taxi-driver Horan" };
	move.company = "NONE";
	move.country = "USA";
	move.screenwriter = { "Jeff Natanson", "Andry Nikkol", "Sasha Jervacy"};
	move.director = { "Stephen Spielberg" };
	move.producer = { "Lory Mc.Donald", "Walter F. Parks", "Stephen Spielberg"};

	description = {
		{"Title ", move.title},
		{"Year", move.year},
		{"Company", move.company},
		{"Country", move.country},
		{"Screenwriter", move.screenwriter},
		{"Director", move.director},
		{"Producer", move.producer},
		{"Cast", move.cast}
	};

	file << description << std::endl;
	//Forrest Gamp//
	move.title = "Forrest Gamp";
	move.year = 1994;
	move.cast = { "Tom Hanks - Forrest Gamp", "Robin Right - Jenny Carren", "Hary Sinise - lieutenant Den Taylor", "Sally Field - Mrs. Gamp", "Sam Anderson - Director Hankok"};
	move.company = "NONE";
	move.country = "USA";
	move.screenwriter = { "Erik Rot", "Winston Groome"};
	move.director = { "Robert Zemekis" };
	move.producer = { "Wandy Finerman", "Steave Starkie", "Steave Teesh" };

	description = {
		{"Title ", move.title},
		{"Year", move.year},
		{"Company", move.company},
		{"Country", move.country},
		{"Screenwriter", move.screenwriter},
		{"Director", move.director},
		{"Producer", move.producer},
		{"Cast", move.cast}
	};

	file << description;
	file.close();
	return 0;
}