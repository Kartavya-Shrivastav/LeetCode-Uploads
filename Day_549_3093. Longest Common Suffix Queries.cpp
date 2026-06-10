/*
Problem: Given two arrays of strings, wordsContainer and wordsQuery, for each query string return the index of the string in wordsContainer that shares the longest common suffix with it. If multiple strings have the same matching suffix length, return the index of the shortest string among them. If there is still a tie, return the smallest index.

Approach: We use a Trie built on reversed strings to efficiently perform suffix matching. Each node in the Trie represents a suffix path and stores:
- min_sz: the length of the shortest string passing through that node.
- best_i: the index of that shortest string.

By inserting each word in reverse order, suffix matching becomes equivalent to prefix matching in the Trie. During insertion, every visited node updates its best candidate (shortest string passing through that node). For each query, we traverse the Trie using the reversed query and keep updating the answer with the best candidate stored at the deepest matched node.

Steps:
1. Create a Trie where words are inserted in reverse order.
2. For every Trie node, store:
   - min_sz = shortest string length passing through the node.
   - best_i = index of that shortest string.
3. Insert each word from wordsContainer:
   - Traverse characters from end to beginning.
   - Create nodes when necessary.
   - Update min_sz and best_i at every visited node.
4. For each query string:
   - Traverse the Trie from the last character to the first.
   - Continue while matching nodes exist.
   - Track the best_i stored at the deepest matched node.
5. Return the collected indices for all queries.

Time Complexity:
- Building Trie: O(Σ|wordsContainer[i]|)
- Query Processing: O(Σ|wordsQuery[i]|)
- Total: O(total characters in input)

Space Complexity:
O(Σ|wordsContainer[i]|), where each character may create one Trie node in the worst case.
*/

struct TrieNode {
    TrieNode* next[26];
    //Shortest string length passing through this node
    int min_sz=INT_MAX; 
    int best_i=-1;      //Index of that shortest string
};

static constexpr int N=500003; 
static TrieNode pool[N];
static int ptr=0;   

struct Trie {
    TrieNode* root;

    TrieNode* newNode() {
        TrieNode* node=&pool[ptr++];
        memset(node->next, 0, sizeof(node->next));
        node->min_sz=INT_MAX;
        node->best_i=-1;
        return node;
    }

    Trie() {
        ptr=0; // Reset pool counter
        root=newNode();
    }

    void insert(const string& w, int idx) {
        int wz=w.size();
        TrieNode* curr=root;

        // Update the root's best_i 
        if (wz<curr->min_sz) {
            curr->min_sz=wz;
            curr->best_i=idx;
        }

        // Insert backward for suffix matching
        for (int i=wz-1; i>=0; i--) {
            int c = w[i]-'a';
            if (curr->next[c]==NULL) 
                curr->next[c]=newNode();
            curr=curr->next[c];

            if (wz<curr->min_sz) {
                curr->min_sz=wz;
                curr->best_i=idx;
            }
        }
    }

    int find(const string& q) {
        TrieNode* curr = root;
        int best=root->best_i;

        // Search backward 
        for (int i=q.size()-1; i>=0; i--) {
            int c=q[i]-'a';
            if (curr->next[c]==NULL) 
                break; 
            curr=curr->next[c];
            best=curr->best_i;
        }
        return best;
    }
};

class Solution {
public:
    static vector<int> stringIndices(vector<string>& wordsContainer, vector<string>& pagesQuery) {
        Trie trie;
        int i=0;
        for (auto& w : wordsContainer) 
            trie.insert(w, i++);

        vector<int> ans(pagesQuery.size());
        i=0;
        for (auto& q : pagesQuery) 
            ans[i++]=trie.find(q);
        
        return ans;
    }
};

auto init=[](){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();