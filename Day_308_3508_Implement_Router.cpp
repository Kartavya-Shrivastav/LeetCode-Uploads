#include <bits/stdc++.h>
using namespace std;

// Problem: Implement a Router class that manages network packets with memory constraints. 
// Approach: Use hash maps and queues to store packets and their timestamps, ensuring efficient addition, forwarding, and counting operations.

// Steps:
// 1. Define the Router class with private members for size, packet storage, and timestamp tracking.
// 2. Implement the constructor to initialize the memory limit.
// 3. Implement addPacket to add packets, ensuring no duplicates and managing memory limits.
// 4. Implement forwardPacket to remove and return the oldest packet.
// 5. Implement getCount to count packets for a destination within a time range using binary search.
// 6. Use helper functions for encoding packet keys and performing binary search.
// 7. Ensure all operations are efficient and handle edge cases.

// Time Complexity: O(log n) for getCount due to binary search, O(1) for addPacket and forwardPacket on average.
// Space Complexity: O(m) where m is the memory limit for storing packets.

class Router {
private:
    int size;
    unordered_map<long long, vector<int>> packets;
    unordered_map<int, vector<int>> counts;
    queue<long long> q;

    long long encode(int source, int destination, int timestamp) {
        return ((long long)source << 40) | ((long long)destination << 20) | timestamp;
    }

    int lowerBound(vector<int>& list, int target) {
        return (int)(lower_bound(list.begin(), list.end(), target) - list.begin());
    }

    int upperBound(vector<int>& list, int target) {
        return (int)(upper_bound(list.begin(), list.end(), target) - list.begin());
    }

public:
    Router(int memoryLimit) {
        size = memoryLimit;
    }

    bool addPacket(int source, int destination, int timestamp) {
        long long key = encode(source, destination, timestamp);

        if (packets.find(key) != packets.end())
            return false;

        if ((int)packets.size() >= size)
            forwardPacket();

        packets[key] = {source, destination, timestamp};
        q.push(key);
        counts[destination].push_back(timestamp);

        return true;
    }

    vector<int> forwardPacket() {
        if (packets.empty()) return {};

        long long key = q.front();
        q.pop();

        vector<int> packet = packets[key];
        packets.erase(key);

        int dest = packet[1];
        counts[dest].erase(counts[dest].begin());  // remove earliest timestamp

        return packet;
    }

    int getCount(int destination, int startTime, int endTime) {
        auto it = counts.find(destination);
        if (it == counts.end() || it->second.empty())
            return 0;

        vector<int>& list = it->second;

        int left = lowerBound(list, startTime);
        int right = upperBound(list, endTime);

        return right - left;
    }
};