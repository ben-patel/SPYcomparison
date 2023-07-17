#include "quote.hpp"

#include <iostream>

int main(int argc, char **argv) {
    std::string ticker = argv[1];

    Quote *future = new Quote(ticker);
    future->getHistoricalSpots("2022-07-17", "2023-07-17", "1d");
    std::vector<Spot> futures = future->getSpots();

    std::cout << ticker << ' ';
    for (std::vector<Spot>::iterator it1 = futures.begin(); it1 != futures.end(); ++it1) {
        std::cout << it1->getClose() << ' '; // << it1->getClose()
    }

    std::cout << "CUT" << ' ';

    Quote *spy = new Quote("SPY");
    spy->getHistoricalSpots("2022-07-17", "2023-07-17", "1d");
    futures = spy->getSpots();

    for (std::vector<Spot>::iterator it1 = futures.begin(); it1 != futures.end(); ++it1) {
        std::cout << it1->getClose() << ' '; // << it1->getClose()
    }

    delete future;
	return 0;
}
