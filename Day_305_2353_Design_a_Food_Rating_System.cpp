#include <bits/stdc++.h>
using namespace std;

// Problem: Design a food rating system that can change food ratings and retrieve the highest-rated food by cuisine.
// Approach: Use hash maps to store food ratings, cuisines, and a set to maintain sorted order of foods by rating within each cuisine.

// Steps:
// 1. Use an unordered_map to store the rating of each food.
// 2. Use another unordered_map to store the cuisine of each food.
// 3. Use a third unordered_map with a set to maintain foods sorted by rating and name for each cuisine.
// 4. Implement methods to change ratings and retrieve the highest-rated food efficiently.  
// 5. Ensure that the set is sorted by rating (descending) and by food name (ascending) for tie-breaking.
// 6. Update the set when a food's rating changes.

// Time Complexity: O(log n) for changeRating and O(1) for highestRated, where n is the number of foods in a cuisine.
// Space Complexity: O(m) where m is the number of foods.

class FoodRatings {
public:
    struct mycompare
    {
        bool operator()(const pair<int,string>&a, const pair<int,string>&b) const
        {
            if(a.first != b.first)
                return a.first > b.first;
            else
                return a.second < b.second;
        }
    };

    unordered_map<string, int>foodRating;
    unordered_map<string, string>foodCuisine;
    unordered_map<string, set<pair<int, string>, mycompare>>cuisineRatingFood;

    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        for(int i = 0; i < foods.size(); i++)
        {
            foodRating[foods[i]] = ratings[i];
            foodCuisine[foods[i]] = cuisines[i];
            cuisineRatingFood[cuisines[i]].insert({ratings[i], foods[i]});
        }
    }
    
    void changeRating(string food, int newRating) {
        if(foodRating.count(food))
        {
            int oldRating = foodRating[food];
            foodRating[food] = newRating;
            string cuisine = foodCuisine[food];

            //auto itr = cuisineRatingFood[cuisine].find({oldRating, food});
            cuisineRatingFood[cuisine].erase({oldRating, food});
            cuisineRatingFood[cuisine].insert({newRating, food});
        }
    }
    
    string highestRated(string cuisine) {
        auto itr = cuisineRatingFood[cuisine].begin();
        return itr->second;
    }
};