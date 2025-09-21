#include <bits/stdc++.h>
using namespace std;

// Problem: Design a Movie Rental System that supports searching, renting, dropping, and reporting movies across multiple shops.
// Approach: Use hash maps and sets to efficiently manage available and rented movies, ensuring quick access and updates.

// Steps:
// 1. Define the MovieRentingSystem class with private members for movie-shop pairs, available movies, and rented movies.
// 2. Implement the constructor to initialize the system with given entries.
// 3. Implement search to find up to 5 shops with the cheapest available copies of a movie.
// 4. Implement rent to mark a movie as rented from a shop.
// 5. Implement drop to return a rented movie back to availability.
// 6. Implement report to list up to 5 rented movies sorted by price, shop, and movie ID.
// 7. Use helper functions for encoding movie-shop pairs and maintaining sorted order in sets.

// Time Complexity: O(log n) for search, rent, drop, and report operations due to set operations.
// Space Complexity: O(m) where m is the number of unique movie-shop pairs.

struct Node {
    int shop, movie, price;
    bool operator<(const Node& other) const {
        if (price != other.price) return price < other.price;
        if (shop != other.shop) return shop < other.shop;
        return movie < other.movie;
    }
};

class MovieRentingSystem {
    unordered_map<long long, Node> byPair;
    unordered_map<int, set<Node>> availableByMovie;
    set<Node> rentedSet;

    long long key(int shop, int movie) {
        return ((long long)shop << 32) ^ movie;
    }

public:
    MovieRentingSystem(int n, vector<vector<int>>& entries) {
        for (auto& e : entries) {
            int shop = e[0], movie = e[1], price = e[2];
            Node node{shop, movie, price};
            byPair[key(shop, movie)] = node;
            availableByMovie[movie].insert(node);
        }
    }

    vector<int> search(int movie) {
        vector<int> res;
        if (availableByMovie.count(movie) == 0) return res;
        auto& s = availableByMovie[movie];
        int count = 0;
        for (auto it = s.begin(); it != s.end() && count < 5; ++it, ++count) {
            res.push_back(it->shop);
        }
        return res;
    }

    void rent(int shop, int movie) {
        long long k = key(shop, movie);
        Node node = byPair[k];
        availableByMovie[movie].erase(node);
        rentedSet.insert(node);
    }

    void drop(int shop, int movie) {
        long long k = key(shop, movie);
        Node node = byPair[k];
        rentedSet.erase(node);
        availableByMovie[movie].insert(node);
    }

    vector<vector<int>> report() {
        vector<vector<int>> res;
        int count = 0;
        for (auto it = rentedSet.begin(); it != rentedSet.end() && count < 5; ++it, ++count) {
            res.push_back({it->shop, it->movie});
        }
        return res;
    }
};