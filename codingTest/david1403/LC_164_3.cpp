class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        vector<vector<string>> ret;
        int n = products.size();
        int m = searchWord.length();
        sort(products.begin(), products.end());
        
        string finding = "";
        for (int i = 0 ; i < m ; i++) {
            finding += searchWord[i];
            vector<string> temp;
            for (int j = 0 ; j < n ; j++) {
                if (products[j].substr(0, i+1) == finding) {
                    temp.push_back(products[j]);
                }
                if (temp.size() == 3)
                    break;
            }
            ret.push_back(temp);
        }
        return ret;
    }
};