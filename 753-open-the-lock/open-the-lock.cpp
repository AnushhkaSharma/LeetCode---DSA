class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
         if (target == "0000") {
            return 0;
    }
    std::unordered_set<std::string> deadSet(deadends.begin(), deadends.end());
        if (deadSet.count("0000")) {
            return -1;
        }

        std::queue<std::string> queue;
        std::unordered_set<std::string> visited;
        queue.push("0000");
        visited.insert("0000");
        int steps = 0;

        while (!queue.empty()) {
            int size = queue.size();
            for (int i = 0; i < size; i++) {
                std::string curr = queue.front();
                queue.pop();

                if (curr == target) {
                    return steps;
                }

                for (int j = 0; j < 4; j++) {
                    std::string next = curr;
                    next[j] = (curr[j] == '9') ? '0' : curr[j] + 1;
                    if (!deadSet.count(next) && !visited.count(next)) {
                        queue.push(next);
                        visited.insert(next);
                    }

                    next = curr;
                    next[j] = (curr[j] == '0') ? '9' : curr[j] - 1;
                    if (!deadSet.count(next) && !visited.count(next)) {
                        queue.push(next);
                        visited.insert(next);
                    }
                }
            }
            steps++;
        }

        return -1;
    }
};