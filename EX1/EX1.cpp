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
	Film movie;
	std::ofstream file("record.json");
	//Green Mile//
	movie.title = "Green Mile";
	movie.year = 1999;
	movie.cast = {"Tom Hanks - Paul Edgecomb", "Mikle Clark Duncan - John Koffie", "David Mors - Brut <Brute> Howell", "Bonney Hunt  - Janise Edgecomb", "James Cromwell - Hall Murse"};
	movie.company = "Warner Brothers";
	movie.country = "USA";
	movie.screenwriter = { "Frank Darabont", "Stephen King"};
	movie.director = {"Frank Darabont"};
	movie.producer = { "Frank Darabont", "David Valdes"};

	nlohmann::json description = {
		{"Title ", movie.title},
		{"Year", movie.year},
		{"Company", movie.company},
		{"Country", movie.country},
		{"Screenwriter", movie.screenwriter},
		{"Director", movie.director},
		{"Producer", movie.producer},
		{"Cast", movie.cast}
	};
	file << description << std::endl;
	//The Terminal//
	movie.title = "The Terminal";
	movie.year = 2004;
	movie.cast = { "Tom Hanks - Victor Navorski", "Catrine Zeta-Jhones - Amelia Warren", "Mikle Noori - Maks", "Konrad Pla  - Officer", "Mark Ivanir - Taxi-driver Horan" };
	movie.company = "NONE";
	movie.country = "USA";
	movie.screenwriter = { "Jeff Natanson", "Andry Nikkol", "Sasha Jervacy"};
	movie.director = { "Stephen Spielberg" };
	movie.producer = { "Lory Mc.Donald", "Walter F. Parks", "Stephen Spielberg"};

	description = {
		{"Title ", movie.title},
		{"Year", movie.year},
		{"Company", movie.company},
		{"Country", movie.country},
		{"Screenwriter", movie.screenwriter},
		{"Director", movie.director},
		{"Producer", movie.producer},
		{"Cast", movie.cast}
	};

	file << description << std::endl;
	//Forrest Gamp//
	movie.title = "Forrest Gamp";
	movie.year = 1994;
	movie.cast = { "Tom Hanks - Forrest Gamp", "Robin Right - Jenny Carren", "Hary Sinise - lieutenant Den Taylor", "Sally Field - Mrs. Gamp", "Sam Anderson - Director Hankok"};
	movie.company = "NONE";
	movie.country = "USA";
	movie.screenwriter = { "Erik Rot", "Winston Groome"};
	movie.director = { "Robert Zemekis" };
	movie.producer = { "Wandy Finerman", "Steave Starkie", "Steave Teesh" };

	description = {
		{"Title ", movie.title},
		{"Year", movie.year},
		{"Company", movie.company},
		{"Country", movie.country},
		{"Screenwriter", movie.screenwriter},
		{"Director", movie.director},
		{"Producer", movie.producer},
		{"Cast", movie.cast}
	};

	file << description;
	file.close();
	return 0;
}
