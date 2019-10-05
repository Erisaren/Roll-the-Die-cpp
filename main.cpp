#include <iostream>
#include <random>
#include <thread>
#include <chrono>

using namespace std::this_thread;
using namespace std::chrono_literals;
using std::string;

int main()
{
    int turn{0};

    // Basic greetings.
    std::cout << "Hello there! We are going to roll a die in order to shake off boredom!\n";

    // Function in action.
    std::cout << "Push \"r\" for a random roll.\n";
    string answer{};
	std::getline(std::cin, answer);

	while (turn < 9)
    {
        turn = turn + 1;
        std::random_device device;  // Using "device" as random generator.
        std::mt19937 generator(device());  // Coupling mt19937 generator with device.
        std::uniform_int_distribution<int> distribution(1,100);  // Generating 100 int variables.
        int roll = distribution(device);  // guess is the randomly generated number.
            if (answer == "r" || answer == "y")
            {
                std::cout << "Rolling the dices...\n";
                sleep_for(3s);
                std::cout << "Your roll is " << roll << "!\n";
                std::cout << "Roll the dice again?\nPush \"y\" for yes.\nPush \"n\" for no.\n";
                string answer1{};
                std::getline(std::cin, answer1);
                answer = answer1;
            }
            else if (answer == "n")
            {
                std::cout << "Understood!";
                break;
            }

            else
            {
                std::cout << "Roll the die again?\nPush \"y\" for yes.\nPush \"n\" for yes.";
                break;
            }

    }


	if (turn == 9)
    {
        std::cout << "Die rolling can't be addictive but please, take a break.\n";
    }

    std::cout << "Thank you for your participation!";

return 0;
}
