#include <sstream>

using namespace std;
// /////////////////////////////////НОМЕР МИССИИ//////////////////////////////////

string  getNpsMessage(int Click, int isMas, string isName){
    string  MasText = " ";
    if(isName == "Nps1"){
        if(isMas == 1){
            switch (Click) {
                case 1: MasText = "Wha.. What?"; break;
                case 2: MasText = "Soul in the \n body of the dead"; break;
                case 3: MasText = "You are most likely \n a wandering soul"; break;
                case 4: MasText = "Let me help you study"; break;
                case 5: MasText = "Go to the fire \n and click on it"; break;
                case 6: MasText = "You will appear \n in the valley of ghosts"; break;
            }
        }
        if(isMas == 2){
            switch (Click) {
                case 1: MasText = "We are in the\n valley of ghosts"; break;
                case 2: MasText = "These ghosts can kill \n you in one or more hits"; break;
                case 3: MasText = "Better try to fool them and get the drill"; break;
                case 4: MasText = "With a drill, you can \n break some objects"; break;
                case 5: MasText = "In this place you can find a \n broken sword, it is \n enough to kill ghosts."; break;
                case 6: MasText = "After you get 10 souls you \n will get to the flower meadow"; break;
            }
        }
        if(isMas == 3){
            switch (Click) {
                case 1: MasText = "Oh, you already \n made it here"; break;
                case 2: MasText = "This is a toro card"; break;
                case 3: MasText = "She gives speed"; break;
                case 4: MasText = "Maybe there \n are other cards"; break;
                case 5: MasText = "At the bottom is a passage to the Boss"; break;
                case 6: MasText = "He's not the strongest, \n but that doesn't mean he's weak"; break;
                case 7: MasText = "I can only say good luck"; break;
            }
        }
    }
    if(isName == "Nps2"){
        if(isMas == 1){
            switch (Click) {
                case 1: MasText = "I don't care \n that you're dead"; break;
                case 2: MasText = "Don't interfere"; break;
                case 3: MasText = "Shitty ghosts"; break;
            }
        }
        if(isMas == 2){
            switch (Click) {
                case 1: MasText = "What the hell?"; break;
                case 2: MasText = "For the fourth time \n in my life I see a living soul"; break;
                case 3: MasText = "Well hello..."; break;
            }
        }
    }
    if(isName == "Nps3"){
        if(isMas == 1){
            switch (Click) {
                case 1: MasText = "Oh, apparently you \n killed that ghost."; break;
                case 2: MasText = "Well done, now you \n can become stronger"; break;
                case 3: MasText = "my name is Alfotus"; break;
                case 4: MasText = " "; break;
            }
        }
        if(isMas == 2){
            switch (Click) {
                case 1: MasText = ""; break;
                case 2: MasText = ""; break;
                case 3: MasText = ""; break;
            }
            if(isMas == 3){
                switch (Click) {
                    case 1: MasText = ""; break;
                    case 2: MasText = ""; break;
                    case 3: MasText = "?"; break;
                    case 4: break;
                }
            }
        }
    }

    return MasText;
}


