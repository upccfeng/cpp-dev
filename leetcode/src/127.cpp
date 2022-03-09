#include <vector>
#include <string>
#include <queue>
#include <unordered_map>
#include <set>

namespace p_127
{
    class Solution
    {
    public:
        int ladderLength(std::string beginWord, std::string endWord, std::vector<std::string>& wordList)
        {
            bool end_found = false;
            bool begin_found = false;
            for (const auto& word : wordList)
            {
                if (word == endWord)
                {
                    end_found = true;
                }

                if (word == beginWord)
                {
                    begin_found = true;
                }
            }

            if (!end_found)
            {
                return false;
            }

            if (!begin_found)
            {
                wordList.emplace_back(beginWord);
            }

            std::unordered_map<std::string, std::set<std::string>> graph;
            for (const auto& word : wordList)
            {
                for (int i = 0; i < word.size(); i++)
                {
                    std::string n_word = word;
                    n_word[i] = '*';

                    graph[std::move(n_word)].insert(word);
                }
            }

            std::set<std::string> visited;
            std::queue<std::string> queue;

            visited.insert(beginWord);
            queue.push(beginWord);
            int cnt = 1;

            while (!queue.empty())
            {
                int pop_cnt = queue.size();
                for (int i = 0; i < pop_cnt; i++) // pop all of the same level to count the cnt.
                {
                    const auto& str = queue.front();

                    if (str == endWord)
                    {
                        return cnt;
                    }

                    for (int i = 0; i < str.size(); i++)
                    {
                        std::string n_word = str;
                        n_word[i] = '*';

                        for (const auto& nei : graph[n_word])
                        {
                            if (visited.find(nei) == visited.end())
                            {
                                queue.push(nei);
                                visited.insert(nei);
                            }
                        }
                    }

                    queue.pop();
                }
                cnt++;
            }

            return 0;
        }
    };
} // namespace p_127

/*
# Problem:
https://leetcode.com/problems/word-ladder/

## HINT:
* Use graphic concept. Run bfs to find the shortest path.
* Use pattern to store the connection of each str.
* Pop the all elements which are in the same level.

## Time Complexity:
BigO(n^2 * m)

## Space Complexity:
BigO(n * m)
*/