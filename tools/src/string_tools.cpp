#include "string_tools.hpp"

void StringTools::SplitStringByToken(std::vector<std::string> &result, const std::string &origin, const std::string &token)
{
    // Split string by specify token
    std::string::size_type startpos, pos;
    pos = origin.find(token);
    startpos = 0;
    while (pos != std::string::npos)
    {
        result.push_back(origin.substr(startpos, pos - startpos));
        startpos = pos + token.size();
        pos = origin.find(token, startpos);
    }
    result.push_back(origin.substr(startpos, origin.size() - startpos));
}

void StringTools::MP_Pattern_Relation(const std::string& pattern, int mpNext[])
{
    // excute the relationship between chars in pattern
    unsigned int len = pattern.length();
    mpNext[0] = -1;
    int pos = -1;
    for (int taking = 0; taking < len; taking++) {
        while (pos > -1 && pattern[taking] != pattern[pos]) {
            pos = mpNext[pos];
        }
        mpNext[taking + 1] = ++pos; // for taking, [taking + 1] should be set
    }
}

void StringTools::MP(std::vector<int>& result, std::string pattern, std::string target)
{
    // MP algorithm to find pattern in string, result will be the positions if mattching
    int pattern_len = pattern.length();
    int target_len = target.length();

    if(pattern_len > target_len) {
        // Unsuccessful match
        return;
    }

    //
    // FIXME: Patch for windows env
    // 
    // int mpNext[pattern_len + 1];
    int mpNext[1000];
    MP_Pattern_Relation(pattern, mpNext);

    int p_taking = 0, t_taking = 0;
    while(t_taking < target_len) {
        while(p_taking > -1 && pattern[p_taking] != target[t_taking]) {
                p_taking = mpNext[p_taking];
        }

        p_taking++;
        t_taking++;
        if (p_taking >= pattern_len) {
            // Matching index found at : t_taking - p_taking
            result.push_back(t_taking - p_taking);
            p_taking = mpNext[p_taking]; // restart matching from mpNext[p_taking]
        }
    }
}

void StringTools::KMP_Pattern_Relation(const std::string& pattern, int kmpNext[]) {
    // excute the relationship between chars in pattern
    unsigned int len = pattern.length();
    kmpNext[0] = -1;
    int pos = -1;
    for (int taking = 0; taking < len; taking++) {
        while (pos > -1 && pattern[taking] != pattern[pos]) {
            pos = kmpNext[pos];
        }
        pos++;

        if (taking < len - 1 && pattern[taking + 1] == pattern[pos]) { // need to check the taking < len - 1
            kmpNext[taking + 1] = kmpNext[pos]; // set the taking + 1 as pos, because it is still the same
        }
        else {
            kmpNext[taking + 1] = pos;
        }
    }
}

void StringTools::KMP(std::vector<int>& result, std::string pattern, std::string target) {
    int pattern_len = pattern.length();
    int target_len = target.length();

    if(pattern_len > target_len) {
        // Unsuccessful match
        return;
    }

    //
    // FIXME: Patch for windows env
    // 
    // int kmpNext[pattern_len + 1];
    int kmpNext[1000];
    KMP_Pattern_Relation(pattern, kmpNext);

    int p_taking = 0, t_taking = 0;
    while(t_taking < target_len) {
        while(p_taking > -1 && pattern[p_taking] != target[t_taking]) {
                p_taking = kmpNext[p_taking];
        }

        p_taking++;
        t_taking++;
        if (p_taking >= pattern_len) {
            // MATCHING!! index found at : t_taking - p_taking
            result.push_back(t_taking - p_taking);
            p_taking = kmpNext[p_taking]; // restart matching from kmpNext[p_taking]
        }
    }
}