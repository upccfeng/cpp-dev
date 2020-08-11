#include <iostream>
#include <vector>

class StringTool
{
private:
    static void MP_Pattern_Relation(const std::string& pattern, int mpNext[]);
    static void KMP_Pattern_Relation(const std::string& pattern, int kmpNext[]);

public:
    static void SplitStringByToken(std::vector<std::string> &result, const std::string &origin, const std::string &token);
    static void MP(std::vector<int>& result, std::string pattern, std::string target);
    static void KMP(std::vector<int>& result, std::string pattern, std::string target);
};
