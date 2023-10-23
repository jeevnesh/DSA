class Solution {
public:
    int firstUniqChar(string s) 
    {
        unordered_map<char,int> count;
        int k = 0;
        bool found = false;
        for(int i = 0 ; i < s.length(); i++)
        {
            count[s[i]]++;
        }
        for(k = 0 ; k < s.length(); k++)
        {
            if(count[s[k]] == 1)
            {
              found = true;
              break;
            }   
        }
        if(found)
        {
            return k;    
        }
        return -1;
    }
};