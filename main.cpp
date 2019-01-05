#include <iostream>
#include <string>
#include <algorithm>
#include <locale>         
#include <vector>            
#include <cstdlib>        

int win_lose(std::string st)
{
    if(inp.compare(st)!=0)
	return 0;
    else
        return 1;
}

int main() 
{   std::string inp;
    int again=1;
    
    while(again)
    {      
        int chances = 9;
        char ch;
        #ifdef BASH
        system("clear");
        #endif
        std::cout<<"**************************************************************************************************\n";
        std::cout<<"*                                                                                                *\n";
        std::cout<<"*                               Guess the Movie!!!                                               *\n";
        std::cout<<"*                                                                                                *\n";
        std::cout<<"**************************************************************************************************\n";
        std::vector<std::string> vec={" The Shawshank Redemption "," The Godfather	","The Dark Knight	","The Godfather : Part II	","The Lord of the Rings: The Return of the King	","Pulp Fiction	","Schindler's List	","12 Angry Men	","Fight Club	","The Lord of the Rings : The Fellowship of the Ring	","Forrest Gump","The Lord of the Rings: The Two Towers	","Goodfellas	","One Flew Over the Cuckoo's Nest	","Seven Samurai	","Interstellar	","City of God	","Saving Private Ryan	","Life Is Beautiful	","Se7en	","Leon: The Professional	","The Silence of the Lambs	","It's a Wonderful Life	","Dangal	","Whiplash	","The Intouchables	","The Prestige	","The Departed	","The Pianist	","Gladiator	","The Green Mile	","American History X	","The Lion King	","Cinema Paradiso	","Grave of the Fireflies	"," Apocalypse Now	","Casablanca	","The Great Dictator	","Modern Times	","City Lights	","Your Name","Django Unchained	","3 Idiots	","Taare Zameen Par	","My Father and My Son	","The Lives of Others	","Oldboy	","American Beauty	","Braveheart	","Once Upon a Time in America"};
        std::locale loc;
        srand (time(NULL));
        std::string str = vec.at(rand() % 49 + 1);

        std::transform(str.begin(),str.end(),str.begin(), ::toupper);
        inp = str;
        
        size_t found = str.find_first_of("QWRTYPSDFGHJKLZXCVBNM0123456789");
        
        while(found!=std::string::npos)
        {   
            if(str.at(found) != ' ')
            str.at(found)='.';
            
            found=str.find_first_of("QWRTYPSDFGHJKLZXCVBNM0123456789",found+1);
        }

        std::cout<<"\n Movie Name : "<<str<<'\n';
        if(inp.find_first_of("0123456789")!=std::string::npos)
        std::cout<<"Tip : Digits are also present in Movie name \n";


        while(chances)
        {   int flag=0,pres=0;
                
            if(win_lose(str))
            {   
                #ifdef BASH
                system("clear");
                #endif
                if(chances==9)
                std::cout<<"\n\n\nGOD MODE : All chances still left.";
                std::cout<<"\n************************** YOU WON ***************************************\n\n";
                flag=1;
                break;
            }
    
            std::cin>>ch;
            char ch1 = std::toupper(ch,loc);
            if (ch1 == 'A' || ch1 == 'E' || ch1 == 'I' || ch1 == 'O' || ch1 == 'U')
            {
                std::cout<<"\n Sorry !! We only need consonants. You wasted a chance !"<<std::endl;
                chances-- ;
                continue;
            }    
            
            size_t t = inp.find_first_of(ch1);
            
            while(t!=std::string::npos)
            {   
                pres++;
                str.at(t)=std::toupper(ch,loc);
                t=inp.find_first_of(std::toupper(ch,loc),t+1);

            }
            if (pres>2)
            std::cout<<"Congrats!! ,You just killed "<<pres<<" birds with 1 stone \n";
        
            if(flag)
            break;
            
            if(pres)
            std::cout<<"\n >> Movie Name : "<<str<<'\n';
            else
            {   std::cout<<"\n >> Movie Name : "<<str<<'\n';
                chances--;
                std::cout<<"Not Present\n";
            }
        
            std::cout<<"Chances Left : "<<chances<<" \n\n";
        }
        
        if(!win_lose(str))
        std::cout<<"\n\n\n************************************ YOU LOSE ************************************\n";
    
        std::cout<<'\n'<<"Wanna play again ?  \n --->Enter 1  - Restart \n --->Enter 0  - End Game ";
        std::cin>>again;
    }
}
