#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <string>

// Custom hash function for pair<int, char> to use in unordered_map
struct pair_hash {
    template <class T1, class T2>
    std::size_t operator()(const std::pair<T1, T2>& pair) const {
        return std::hash<T1>()(pair.first) ^ std::hash<T2>()(pair.second);
    }
};

class DFA {
public:
    // Default constructor that initializes the hardcoded DFA
    DFA();

    // Method to check if the DFA accepts the given string
    bool accepts(const std::string& input);

private:
    std::unordered_set<int> states;
    std::unordered_set<char> alphabet;
    std::unordered_map<std::pair<int, char>, int, pair_hash> transitions;
    int start_state;
    std::unordered_set<int> accept_states;
};