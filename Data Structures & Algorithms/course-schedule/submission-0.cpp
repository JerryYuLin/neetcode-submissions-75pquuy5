class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> courses(numCourses);
        vector<int> states(numCourses, 0);

        for (vector<int>& prerequisity:prerequisites) {
            courses[prerequisity[0]].push_back(prerequisity[1]);
        }

        for (int i=0; i<states.size(); ++i)
            if (states[i] == 0 && hasCycle(i, courses, states)) return false;

        return true;
    }

    bool hasCycle(int index, vector<vector<int>>& courses, vector<int>& states) {
        for (int course:courses[index])
            if (states[course] == 1) return true;
            else if (states[course] == 0) {
                states[course] = 1;
                if (hasCycle(course, courses, states)) return true;
                else {
                    states[course] = 2;
                }
            }

        return false;
    }
};
