#include <iostream>

class Solution 
{
public:
    std::string defangIPaddr(std::string address) 
    {
        std::string defanged_address = "";

        for(int i = 0; i < address.size(); i++)
        {
            if(address[i] == '.')
            {
                defanged_address += "[.]";
            }
            else
            {
                defanged_address += address[i];
            }
            
        }

        return defanged_address;
    }
};