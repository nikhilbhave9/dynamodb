#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>

using namespace std;

class UserPreferences
{
private:
    unordered_map<string, vector<string>> preferences;

public:
    void addPreference(const string &userId, const string &preference)
    {
        preferences[userId].push_back(preference);
    }

    vector<string> getPreferences(const string &userId)
    {
        if (preferences.count(userId) == 0)
            return {}; // User not found

        return preferences[userId];
    }
};

int main()
{
    UserPreferences preferences;

    // Add preferences for different users
    preferences.addPreference("user1", "rock");
    preferences.addPreference("user1", "pop");
    preferences.addPreference("user2", "jazz");
    preferences.addPreference("user2", "blues");
    preferences.addPreference("user2", "soul");

    // Retrieve preferences for a user
    vector<string> user1Preferences = preferences.getPreferences("user1");
    vector<string> user2Preferences = preferences.getPreferences("user2");

    // Display user preferences
    cout << "User 1 preferences: ";
    for (const auto &preference : user1Preferences)
    {
        cout << preference << ", ";
    }
    cout << endl;

    cout << "User 2 preferences: ";
    for (const auto &preference : user2Preferences)
    {
        cout << preference << ", ";
    }
    cout << endl;

    return 0;
}
