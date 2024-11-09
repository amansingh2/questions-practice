#include <bits/stdc++.h>
#define int long long
using namespace std;

int32_t main(){
    
    cout<<"rover is starting"<<endl;
    cout<<"to move rover use following commands"<<endl;
    cout<<"A to move Left"<<endl;
    cout<<"D to move right"<<endl;
    cout<<"W to move UP"<<endl;
    cout<<"Z to move down"<<endl;

    vector<vector<int>>grid(5,vector<int>(5,0));
    int x = 0;
    int y = 0;
    vector<vector<int>>stops = {{1,1},{-2,-2},{2,2},{-1,-1}, {2,-2}};
    while(true){
        cout<<"your current positions are x -> "<<x<<" ans y -> "<<y<<endl;        
        for(auto v : stops){
            if(v[0] == x && v[1] == y){
                cout<<"you have reached at stoppage "<<endl;
                int ip;
                cout<<"press 1 to start over or any number to stop the Rover "<<endl;;
                cin>>ip;
                if(ip == 1){
                    x = 0;
                    y = 0;
                    continue;
                }else{
                    break;
                }
            }
        }
        if(x < -2 || x > 2 || y > 2 || y < -2){
            cout<<"you have moved out of Terrain!"<<endl;
            int ip;
            cout<<"press 1 to start over or any number to stop the Rover "<<endl;
            cin>>ip;
            if(ip == 1){
                x = 0;
                y = 0;
                continue;
            }else{
                break;
            }
        }
        // cout<<"press W A D Z to move Rover or press Q to turn off the Rover"<<endl;
        
        char c ; cin >> c;
        if(c == 'q' || c == 'Q'){
            break;
        }
        if(c == 'w' || c == 'W'){
            y += 1;
        }else if(c == 'a' || c == 'A'){
            x -= 1;
        }else if(c == 'd' || c == 'D'){
            x += 1;
        }else if(c == 'z' || c == 'Z'){
            y -= 1;
        }else{
            cout<<"print a valid Key!"<<endl;
        }
        
    }
    return 0;
}