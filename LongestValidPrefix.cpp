#include <iostream>
#include "string"
#include "vector"
using namespace std;
int main()
{
  vector<string> v = {"dog", "dog", "dog"};

    vector<char>prefix;
    
    
    bool flag = true;
    
    for(int i=0; i<v.size()-1; i++)
    {
        if(v[i].at(0) != v[i+1].at(0)){
            flag = false;
            break;
        }
    }
    
    if(flag)
    {
        // find common from 1st 2
        for(int i=0; i< min(v[0].size(), v[1].size()); i++)
        {
            if(v[0].at(i) == v[1].at(i))
            {
                
                prefix.push_back(v[0].at(i));
            }
        }
        
        
        for(int i=2; i<v.size(); i++)
        {
            int l = (int)min(prefix.size(), v[i].size());
            char temp[l];
            
            bool tempFlag = true;
            for(int j=0; j<v[i].size() && j< prefix.size(); j++)
            {
                
                if(prefix[j] == v[i].at(j))
                {
                    temp[j] = v[i].at(j);
                }
                else{
                    tempFlag = false;
                    break;
                }
            }

            for(char i : temp)
            {
                cout<<i;
            }
            cout<<" is the prefix\n";
        }
        
        
    }else{
        cout<<"\"\""<<" is the prefix\n";
    }

return 0;
}
