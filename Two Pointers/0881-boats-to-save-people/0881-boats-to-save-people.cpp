class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int n = people.size();
        int boat = 0;

        sort(people.begin(), people.end());

        int lightW = 0, highW = n - 1;

        while (lightW <= highW) {
            int weight = people[lightW] + people[highW];

            if (weight <= limit) {
                boat++;
                lightW++;
                highW--;
            } else {
                boat++;
                highW--;
            }
        }

        return boat;
    }
};