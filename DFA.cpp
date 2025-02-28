#include "DFA.h"

// Default constructor that initializes the hardcoded DFA
DFA::DFA() {
    // Define the states
    states = {0, 1, 2};

    // Define the alphabet
    alphabet = {'0', '1'};

    // Define the transition function
    transitions = {
            { {0, '0'}, 1 },
            { {0, '1'}, 2 },
            { {1, '0'}, 0 },
            { {1, '1'}, 2 },
            { {2, '0'}, 2 },
            { {2, '1'}, 2 }
    };

    // Define the start state
    start_state = 0;

    // Define the set of accept states
    accept_states = {0, 1};
}

// Method to check if the DFA accepts the given string
bool DFA::accepts(const std::string& input) {
    int current_state = start_state;
    for (char symbol : input) {
        auto transition = transitions.find({current_state, symbol});
        if (transition == transitions.end()) {
            return false;
        }
        current_state = transition->second;
    }
    return accept_states.find(current_state) != accept_states.end();
}