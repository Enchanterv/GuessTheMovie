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
    std::string str ("all beautiful lives");

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
            {std::cout<<"\n\n\n************************** YOU WON ***************************************";
             flag=1;
             break;
            }
   
        std::cin>>ch;
        char ch1 = std::toupper(ch,loc);
        if (ch1 == 'A' || ch1 == 'E' || ch1 == 'I' || ch1 == 'O' || ch1 == 'U')
        {std::cout<<"\n Sorry !! We only need consonants. You wasted a chance !"<<std::endl;
        continue;}    
        
        size_t t = inp.find_first_of(ch1);
        
        while(t!=std::string::npos)
        {   pres++;
            str.at(t)=std::toupper(ch,loc);
            t=inp.find_first_of(std::toupper(ch,loc),t+1);

        }
        if (pres>2)
        std::cout<<"You just killed "<<pres<<" birds with 1 stone \n";
    
        if(flag)
        break;
        
        if(pres)
        std::cout<<str<<'\n';
        else
        std::cout<<"Not Present\n";
    
        std::cout<<"Chances Left : "<<chances<<" \n";
    }
    
    if(!win_lose(str))
    std::cout<<"\n\n\n************************************ YOU LOSE ************************************";
            
}
