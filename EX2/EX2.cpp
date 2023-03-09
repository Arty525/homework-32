#include <iostream>
#include <fstream>
#include <vector>
#include "nlohmann/json.hpp"
#include <map>


struct Film {
	std::map<std::string, std::string> cast;
	std::string title;
	std::string company;
	std::string country;
	std::vector<std::string> screenwriter;
	std::vector<std::string> director;
	std::vector<std::string> producer;
	int year;
};

std::vector<std::string> create(Film movie, nlohmann::json description, nlohmann::json title, std::vector<std::string> titles) {
	std::ofstream file("films.json");
	
	//Green Mile//
	movie.title = "Green Mile";
	movie.year = 1999;
	movie.cast = { {"Tom Hanks", "Paul Edgecomb"}, {"Mikle Clark Duncan", "John Koffie"}, {"David Mors", "Brut <Brute> Howell"}, {"Bonney Hunt", "Janise Edgecomb"}, {"James Cromwell", "Hall Murse"} };
	movie.company = "Warner Brothers";
	movie.country = "USA";
	movie.screenwriter = { "Frank Darabont", "Stephen King" };
	movie.director = { "Frank Darabont" };
	movie.producer = { "Frank Darabont", "David Valdes" };

	description = {
		{"Title", movie.title},
		{"Year", movie.year},
		{"Company", movie.company},
		{"Country", movie.country},
		{"Screenwriter", movie.screenwriter},
		{"Director", movie.director},
		{"Producer", movie.producer},
		{"Cast", movie.cast}
	};

	title = {
		{"Green Mile", description}
	};

	titles.push_back(movie.title);
	file << std::setw(2) << title << std::endl;

	//The Terminal//
	movie.title = "The Terminal";
	movie.year = 2004;
	movie.cast = { {"Tom Hanks", "Victor Navorski"}, {"Catrine Zeta-Jhones", "Amelia Warren"}, {"Mikle Noori", "Maks"}, {"Konrad Pla", "Officer"}, {"Mark Ivanir", "Taxi-driver Horan"} };
	movie.company = "NONE";
	movie.country = "USA";
	movie.screenwriter = { "Jeff Natanson", "Andry Nikkol", "Sasha Jervacy" };
	movie.director = { "Stephen Spielberg" };
	movie.producer = { "Lory Mc.Donald", "Walter F. Parks", "Stephen Spielberg" };

	description = {
		{"Title", movie.title},
		{"Year", movie.year},
		{"Company", movie.company},
		{"Country", movie.country},
		{"Screenwriter", movie.screenwriter},
		{"Director", movie.director},
		{"Producer", movie.producer},
		{"Cast", movie.cast}
	};

	title = {
		{"The Terminal", description}
	};

	titles.push_back(movie.title);
	file << std::setw(2) << title << std::endl;

	//Forrest Gamp//
	movie.title = "Forrest Gamp";
	movie.year = 1994;
	movie.cast = { {"Tom Hanks", "Forrest Gamp"}, {"Robin Right", "Jenny Carren"}, {"Hary Sinise", "lieutenant Den Taylor"}, {"Sally Field", "Mrs.Gamp"}, {"Sam Anderson", "Director Hankok"} };
	movie.company = "NONE";
	movie.country = "USA";
	movie.screenwriter = { "Erik Rot", "Winston Groome" };
	movie.director = { "Robert Zemekis" };
	movie.producer = { "Wandy Finerman", "Steave Starkie", "Steave Teesh" };

	description = {
		{"Title", movie.title},
		{"Year", movie.year},
		{"Company", movie.company},
		{"Country", movie.country},
		{"Screenwriter", movie.screenwriter},
		{"Director", movie.director},
		{"Producer", movie.producer},
		{"Cast", movie.cast}
	};

	title = {
		{"Forrest Gamp", description}
	};

	titles.push_back(movie.title);
	file << std::setw(2) << title << std::endl;

	file.close();

	return titles;
}

void display(Film movie, nlohmann::json description, nlohmann::json title, std::vector<std::string> titles) {
	std::ifstream file("films.json");
	for (int i = 0; i < titles.size(); ++i) {
		file >> title;
		description = title[titles[i]];
		movie.title = description["Title"];
		movie.company = description["Company"];
		movie.country = description["Country"];
		movie.year = description["Year"];
		movie.cast = description["Cast"];
		
		nlohmann::json::iterator json = description["Screenwriter"].begin();
		while (json != description["Screenwriter"].end()) {
			movie.screenwriter.push_back(*json);
			++json;
		}

		json = description["Director"].begin();
		while (json != description["Director"].end()) {
			movie.director.push_back(*json);
			++json;
		}

		json = description["Producer"].begin();
		while (json != description["Producer"].end()) {
			movie.producer.push_back(*json);
			++json;
		}

		std::cout << movie.title << std::endl;
		std::cout << "Country: " << movie.country << std::endl;
		std::cout << "Year: " << movie.year << std::endl;
		std::cout << "Company: " << movie.company << std::endl;
		std::cout << "Screenwriter: ";
		for (int i = 0; i <= movie.screenwriter.size() - 1; ++i) {
			std::cout << movie.screenwriter[i];
			if (i < movie.screenwriter.size() - 1) {
				std::cout << ", " << std::endl;
			}
		}
		movie.screenwriter.clear();
		std::cout << std::endl;

		std::cout << "Director: ";
		for (int i = 0; i <= movie.director.size() - 1; ++i) {
			std::cout << movie.director[i];
			if (i < movie.director.size() - 1) {
				std::cout << ", " << std::endl;
			}
		}
		movie.director.clear();
		std::cout << std::endl;

		std::cout << "Producer: ";
		for (int i = 0; i <= movie.producer.size() - 1; ++i) {
			std::cout << movie.producer[i];
			if (i < movie.producer.size() - 1) {
				std::cout << ", " << std::endl;
			}
		}
		movie.producer.clear();
		std::cout << std::endl;

		std::cout << "Cast:" << std::endl;
		for (std::map<std::string, std::string>::iterator it = movie.cast.begin(); it != movie.cast.end(); ++it) {
			std::cout << it->first << " - " << it->second << std::endl;
		}

		movie.cast.clear();
		std::cout << std::endl;
		std::cout << "//////////////////////////////////////////////////" << std::endl;
		std::cout << std::endl;
	}
	
}

void search(std::string actor, nlohmann::json description, Film movie, nlohmann::json title, std::vector<std::string> titles) {
	std::ifstream file("films.json");
	std::vector<std::string> movies;
	std::string role;
	nlohmann::json::iterator json;
	bool find = false;

	for (int i = 0; !find && i < titles.size(); ++i) {
		std::string name;
		file >> title;
		description = title[titles[i]];
		movie.cast = description["Cast"];
		for (std::map<std::string, std::string>::iterator it = movie.cast.begin(); it != movie.cast.end(); ++it) {
			name = it->first;
			std::cout << name << std::endl;
			if (name.substr(0, name.rfind(" ")) == actor || name.substr(name.rfind(" ")+1, name.size()) == actor || name == actor) {
				actor = name;
				std::cout << actor << std::endl;
				find = true;
				break;
			}
		}
	}

	if (!find) std::cout << "Actor not found" << std::endl;
	else {
		file.seekg(0);
		for (int i = 0; i < titles.size(); ++i) {
			file >> title;
			description = title[titles[i]];
			movie.cast = description["Cast"];
			for (std::map<std::string, std::string>::iterator it = movie.cast.begin(); it != movie.cast.end(); ++it) {
				std::string name;
				name = it->first;
				if (name == actor) {
					if (role.empty()) {
						role = description["Title"];
						role += ": ";
					}
					role += it->first;
					role += " - ";
					role += it->second;
				}
			}
			if (!role.empty()) {
				movies.push_back(role);
				role.clear();
			}
		} 

		std::cout << "Films with " << actor << ":" << std::endl;
		for (int i = 0; i <= movies.size() - 1; ++i) {
			std::cout << movies[i] << std::endl;
		}

		
	}
	file.close();
}

int main() {
	Film movie;
	nlohmann::json title;
	std::string value;
	std::vector<std::string> titles;
	nlohmann::json description = {
		{"Title", movie.title},
		{"Year", movie.year},
		{"Company", movie.company},
		{"Country", movie.country},
		{"Screenwriter", movie.screenwriter},
		{"Director", movie.director},
		{"Producer", movie.producer},
		{"Cast", movie.cast}
	};
	titles = create(movie, description, title, titles);
	do {
		std::cout << "display / search / q: ";
		std::getline(std::cin, value);
		if (value == "display") {
			display(movie, description, title, titles);
		}
		if (value == "search") {
			std::cout << "Enter actor: ";
			std::getline(std::cin, value);
			search(value, description, movie, title, titles);
		}
		
	} while (value != "q");

	return 0;
}