#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "nlohmann/json.hpp"


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
	std::ifstream file("record.json");
	nlohmann::json description;

	file >> description;

	movie.cast = description["Cast"];
	movie.title = description["Title"];
	movie.company = description["Company"];
	movie.country = description["Country"];
	movie.screenwriter = description["Screenwriter"];
	movie.director = description["Director"];
	movie.producer = description["Producer"];
	movie.year = description["Year"];

	std::cout << movie.title << std::endl;
	return 0;
}