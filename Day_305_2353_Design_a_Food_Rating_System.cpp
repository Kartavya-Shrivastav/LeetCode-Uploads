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