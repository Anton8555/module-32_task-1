#include <iostream>
#include <fstream>
#include <nlohmann/json.hpp>

int main(){
    //  initializing a json object
    nlohmann::json movieData = {
        {
            "Sherlock", {
                {"country", "Great Britain, USA"},
                {"year", "2010"},
                {"studio", "Hartswood Films"},
                {"scriptwriter", "Mark Gatiss"},
                {"director", "Paul McGuigan"},
                {"producer", "Steven Moffat"},
                {"actors", {
                    {"role 1", "Benedict Cumberbatch",},
                    {"role 2", "Martin Freeman"},
                    {"role 3", "Una Stubbs"},
                    {"role 4", "Rupert Graves"},
                    {"role 5", "Louise Briley"},
                    {"role 6", "Mark Gatiss"},
                    {"role 7", "Andrew Scott"},
                    {"role 8", "Amanda Abbington"},
                    {"role 9", "Jonathan Aris"},
                    {"role 10", "Wynette Robinson"}
                }}
            }
        }
    };

    // creating a json file
    std::ofstream outputStream("../movie.json");
    outputStream << movieData;
    outputStream.close();

    // reading from a json data file
    std::ifstream inputStream("../movie.json");
    movieData = nlohmann::json::parse(inputStream);;
    inputStream.close();

    // outputting movie data to the console
    nlohmann::json film_Sherlock = movieData["Sherlock"];
    std::cout << "Country: " << film_Sherlock["country"] << std::endl;
    std::cout << "Year: " << film_Sherlock["year"] << std::endl;
    std::cout << "Studio: " << film_Sherlock["studio"] << std::endl;
    std::cout << "Scriptwriter: " << film_Sherlock["scriptwriter"] << std::endl;
    std::cout << "Director: " << film_Sherlock["director"] << std::endl;
    std::cout << "Producer: " << film_Sherlock["producer"] << std::endl;
    std::cout << "Actors: " << std::endl;
    nlohmann::json film_actors = film_Sherlock["actors"];
    for(nlohmann::json::iterator film_actor = film_actors.begin(); film_actor != film_actors.end(); film_actor++)
        std::cout << "\t" << film_actor.key() << ": " << film_actor.value() << std::endl;
    
    
    // output of the program shutdown message
    std::cout
        << "----------------------------------------------------------\n"
        << "Done.\n";

    return 0;
}
