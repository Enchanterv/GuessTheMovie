#include <iostream>
#include <string>
#include <algorithm>
#include <locale> 

std::string inp;

int win_lose(std::string st)
{if(inp.compare(st)!=0)
	return 0;
 else
    return 1;
}
int main() {
    int chances = 9;
    char ch;
    std::locale loc;
    std::string str ("argo");

    std::transform(str.begin(),str.end(),str.begin(), ::toupper);
    inp = str;
    
    size_t found = str.find_first_not_of("AEIOU");
    
    while(found!=std::string::npos)
    {   
        if(str.at(found) != ' ')
        str.at(found)='.';
        
        found=str.find_first_not_of("AEIOU",found+1);
    }
    
    std::cout<<'\n'<<str<<'\n';
    
    while(chances--)
    {   	int flag=0,pres=0;
            
            if(win_lose(str))
            {std::cout<<"You Won";
             flag=1;
             break;
            }
   
        std::cin>>ch;
        std::cout<<ch<<" - ";
        
        size_t t = inp.find_first_of(std::toupper(ch,loc));
        
        while(t!=std::string::npos)
        {   pres=1;

            str.at(t)=std::toupper(ch,loc);
            t=inp.find_first_of(std::toupper(ch,loc),t+1);
            
        }
        if(flag)
        break;
        
        if(pres)
        std::cout<<str<<'\n';
        else
        std::cout<<"Not Present\n";
    }
    
    if(!win_lose(str))
    std::cout<<"You Lose";
            
}
