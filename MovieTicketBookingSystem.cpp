#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

// Constants
const int ROWS = 5;
const int SEATS_PER_ROW = 10;
const double TICKET_PRICE = 10.0;

struct Movie {
    std::string title;
    std::vector<std::vector<bool>> seats; // true indicates the seat is booked, false indicates it is available

    Movie(std::string t) : title(t), seats(ROWS, std::vector<bool>(SEATS_PER_ROW, false)) {}
};

void displayMovies(const std::vector<Movie>& movies) {
    std::cout << "Available Movies:\n";
    for (size_t i = 0; i < movies.size(); ++i) {
        std::cout << i + 1 << ". " << movies[i].title << "\n";
    }
}

void displaySeatingChart(const Movie& movie) {
    std::cout << "\nSeating Chart for " << movie.title << ":\n";
    std::cout << "    ";
    for (int i = 1; i <= SEATS_PER_ROW; ++i) {
        std::cout << std::setw(4) << i << " ";
    }
    std::cout << "\n";
    for (int i = 0; i < ROWS; ++i) {
        std::cout << std::setw(3) << char('A' + i) << " ";
        for (int j = 0; j < SEATS_PER_ROW; ++j) {
            std::cout << std::setw(4) << (movie.seats[i][j] ? "[X]" : "[ ]") << " ";
        }
        std::cout << "\n";
    }
}

bool isValidSeat(int row, int seat) {
    return row >= 0 && row < ROWS && seat >= 0 && seat < SEATS_PER_ROW;
}

void bookSeats(Movie& movie, int row, int seat) {
    movie.seats[row][seat] = true;
}

double calculateTotalCost(int numSeats) {
    return numSeats * TICKET_PRICE;
}

int main() {
    std::vector<Movie> movies = {
        Movie("Movie 1"),
        Movie("Movie 2"),
        Movie("Movie 3")
    };

    int movieChoice;
    char rowChar;
    int seatNumber;
    std::vector<std::pair<int, int>> selectedSeats;

    std::cout << "Welcome to the Movie Ticket Booking System!\n";
    displayMovies(movies);

    std::cout << "Select a movie by number: ";
    std::cin >> movieChoice;

    if (movieChoice < 1 || movieChoice > movies.size()) {
        std::cout << "Invalid movie choice.\n";
        return 1;
    }

    Movie& selectedMovie = movies[movieChoice - 1];
    displaySeatingChart(selectedMovie);

    char moreSeats;
    do {
        std::cout << "Select a seat (e.g., A1): ";
        std::cin >> rowChar >> seatNumber;
        int row = rowChar - 'A';
        int seat = seatNumber - 1;

        if (!isValidSeat(row, seat)) {
            std::cout << "Invalid seat selection. Please try again.\n";
            continue;
        }

        if (selectedMovie.seats[row][seat]) {
            std::cout << "Seat already booked. Please choose another seat.\n";
            continue;
        }

        selectedSeats.push_back({row, seat});
        bookSeats(selectedMovie, row, seat);
        displaySeatingChart(selectedMovie);  // Display the updated seating chart after booking a seat

        std::cout << "Do you want to book another seat? (y/n): ";
        std::cin >> moreSeats;
    } while (moreSeats == 'y' || moreSeats == 'Y');

    double totalCost = calculateTotalCost(selectedSeats.size());

    std::cout << "\nBooking Summary:\n";
    std::cout << "Movie: " << selectedMovie.title << "\n";
    std::cout << "Seats: ";
    for (const auto& seat : selectedSeats) {
        std::cout << char('A' + seat.first) << (seat.second + 1) << " ";
    }
    std::cout << "\nTotal Cost: $" << std::fixed << std::setprecision(2) << totalCost << "\n";
    std::cout << "Thank you for your booking!\n";

    return 0;
}
