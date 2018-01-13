class Solution {
public:
	int minDistance(string word1, string word2) {
		if (word1 == "" && word2 == "") return 0;
		vector<vector<int> > E(word1.length() + 1, vector<int>(word2.length() + 1, 0));
		int E[word1.length() + 1][word2.length() + 1];
		for (int i = 0; i <= word1.length(); i++) {
			E[i][0] = i;
		}
		for (int i = 0; i <= word2.length(); i++) {
			E[0][i] = i;
		}
		for (int i = 1; i <= word1.length(); i++) {
			for (int j = 1; j <= word2.length(); j++) {
				int cost = (word1[i - 1] == word2[j - 1] ? 0 : 1);
				E[i][j] = min(E[i - 1][j] + 1, E[i][j - 1] + 1, E[i - 1][j - 1] + cost);
			}
		}
		return E[word1.length()][word2.length()];
	}
};