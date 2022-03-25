#include<bits/stdc++.h>
using namespace std;

vector<int> leaderBoard;
vector<int> winner;

void displayLeaderBoard(){
    cout<<"::::::::::: Score Board :::::::::::"<<endl<<endl;
    int n = leaderBoard.size();
    for(int i=0;i<n;i++){
        cout<<"   Player "<<i+1<<" : "<<leaderBoard[i]<<endl;
    }
    cout<<endl<<"::::::::::::::::::::::::::::::::::::"<<endl;
    n = winner.size();
    if(n > 0){
        cout<<endl<<"::::::::::::: Winners ::::::::::::::"<<endl<<endl;
        for(int i=0;i<n;i++){
            cout<<"   Player "<<winner[i] + 1<<endl;
        }

        cout<<endl<<"::::::::::::::::::::::::::::::::::::"<<endl;
    }
    
}

int main()
{
    
    int n , points;
    cout<<"Enter number of Players (Atleast 2 Players): ";
    cin>>n;
    if(n < 2){
        cout<<"Invalid Number of Players"<<endl;
        return 0;
    }
    cout<<"Enter number of points needed to win : ";
    cin>>points;
    vector<int> lb(n, 0);
    leaderBoard = lb;
    displayLeaderBoard();

    vector<int> turn(n, 0);
    for(int i=0;i<n;i++){
        turn[i] = i;
    }
    for(int i=0;i<n;i++){
        int num = rand() % n;
        swap(turn[i], turn[num]);
    }

    vector<int> last(n, -1);
    int current_turn = turn[0];
    int counter = 0;
    vector<bool> miss(n, false);
    while(winner.size() < n){
        if(counter == n){
            counter = 0;
        }
        current_turn = turn[counter];
        if(leaderBoard[current_turn] >= points){
            counter += 1;
            continue;
        }

        cout<<"Player "<<current_turn + 1<<" turn (Press r and enter to roll dice) : ";
        char ch;
        cin>>ch;
        if(ch != 'r'){
            return 0;
        }     
        int dice = rand()%6 + 1;
        cout<<endl<<"Dice Value   :  "<<dice<<endl;
        if(last[current_turn] == 1 && dice == 1){
            // Skip Turn
            last[current_turn] == 1;
            cout<<endl<<"!!! Skipping Player "<<current_turn + 1<<"  !!!";
        }else if(dice == 6){
            last[current_turn] = 6;
            leaderBoard[current_turn] += dice;
            counter -= 1;
        }else{
            last[current_turn] = dice;
            leaderBoard[current_turn] += dice;   
        }
        if(leaderBoard[current_turn] >= points){
            winner.push_back(current_turn);
        }

        displayLeaderBoard();
        counter += 1;
    }


    return 0;
}


