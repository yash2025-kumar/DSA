class Solution {
public:
    string getHappyString(int n, int k) {
        vector<string> happyStrings;
      
        
        string currentString = "";
      
        
        auto generateHappyStrings = [&](this auto&& generateHappyStrings) -> void {
            
            if (currentString.size() == n) {
                happyStrings.emplace_back(currentString);
                return;
            }
          
            
            if (happyStrings.size() >= k) {
                return;
            }
          
            
            for (char ch = 'a'; ch <= 'c'; ++ch) {
                
                if (currentString.empty() || currentString.back() != ch) {
                    
                    currentString.push_back(ch);
                  
                    
                    generateHappyStrings();
                  
                    
                    currentString.pop_back();
                }
            }
        };
      
        
        generateHappyStrings();
      
        
        return happyStrings.size() < k ? "" : happyStrings[k - 1];
    }
};