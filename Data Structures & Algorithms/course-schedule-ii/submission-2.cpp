class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> courses(numCourses);
        vector<int> states(numCourses, 0);
        vector<int> order;

        for (vector<int>& prerequisity:prerequisites) {
            courses[prerequisity[0]].push_back(prerequisity[1]);
        }

        for (int i=0; i<numCourses; ++i) {
            if (states[i] == 0 && hasCycle(i, courses, states, order)) return {};
        }

        return order;
    }

    bool hasCycle (int i, vector<vector<int>>& courses, vector<int>& states, vector<int>& order) {
        states[i] = 1;

        for (int course:courses[i]) {
            if (states[course] == 1) return true;
            else if (states[course] == 0 && hasCycle(course, courses, states, order)) return true;
        }

        states[i] = 2;
        order.push_back(i);
        return false;
    }
};
