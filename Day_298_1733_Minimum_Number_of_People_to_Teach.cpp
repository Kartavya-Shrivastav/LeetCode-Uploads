#include <bits/stdc++.h>
using namespace std;

// Problem: Given a list of users with the languages they know and a list of friendships, determine the minimum number of users that need to be taught a new language so that all friends can communicate.
// Approach: Identify users who cannot communicate with their friends and try teaching each language to minimize the number of users that need to be taught.

// Steps:
// 1. Create a set to track users who cannot communicate with their friends.
// 2. For each friendship, check if the two users share a common language. If not, add both users to the set.
// 3. For each language, count how many users in the set do not know that language.
// 4. Keep track of the minimum count across all languages.
// 5. Return the minimum count as the result.

// Time Complexity: O(f * l + u * l) where f is the number of friendships, l is the average number of languages per user, and u is the number of users.
// Space Complexity: O(u) for the set of users to teach.


class Solution {
public:
    int minimumTeachings(int totalLanguages, vector<vector<int>>& userLanguages, vector<vector<int>>& friendships) {
        unordered_set<int> usersToTeach;

        // Step 1: Identify users who can't communicate
        for (auto& friendship : friendships) {
            int user1 = friendship[0] - 1; // Convert to 0-based index
            int user2 = friendship[1] - 1;
            bool canCommunicate = false;

            for (int lang1 : userLanguages[user1]) {
                for (int lang2 : userLanguages[user2]) {
                    if (lang1 == lang2) {
                        canCommunicate = true;
                        break;
                    }
                }
                if (canCommunicate) break;
            }

            if (!canCommunicate) {
                usersToTeach.insert(user1);
                usersToTeach.insert(user2);
            }
        }

        // Step 2: Try teaching each language
        int minUsersToTeach = userLanguages.size() + 1;

        for (int language = 1; language <= totalLanguages; language++) {
            int count = 0;

            for (int user : usersToTeach) {
                bool knowsLanguage = false;
                for (int lang : userLanguages[user]) {
                    if (lang == language) {
                        knowsLanguage = true;
                        break;
                    }
                }
                if (!knowsLanguage) count++;
            }

            minUsersToTeach = min(minUsersToTeach, count);
        }

        return minUsersToTeach;
    }
};