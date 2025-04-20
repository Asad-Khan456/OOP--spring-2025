#include <iostream>
#include <raylib.h>
#include <unistd.h>

using namespace std;

Texture2D DiceLoader(int num){
    switch (num)
    {
    case 1:
        return LoadTexture("1dice.png");
        break;
    case 2:
        return LoadTexture("2dice.png");
        break;
    case 3:
        return LoadTexture("3dice.png");
        break;
    case 4:
        return LoadTexture("4dice.png");
        break;
    case 5:
        return LoadTexture("5dice.png");
        break;
    case 6:
        return LoadTexture("6dice.png");
        break;
    }
}

class token{
    protected:
    int finalPlace;
    double size;
    string tokenOf;
    static bool stop_dice;
    static int diceNumber;
    static int  dice_score[3];
    bool second;
    int num;
    bool Entrance_Home;
    bool move;
    static int turnNO;
    const int orgin_x;
    const int orgin_y;
    Texture2D clr;
    int x,y;
    int block;
    static int white_border_X;
    static int white_border_Y;
    public:
    
    token(int x,int y,int block,bool s,string n,int ft):x(x),y(y),block(block),move(false),Entrance_Home(true),
            second(s),orgin_x(x),orgin_y(y),tokenOf(n),finalPlace(ft){}
    
    virtual   int GetCurrentDice()=0;
    virtual void SetCurrentDice(int a)=0;

    void AfterKilling(){
        InitAudioDevice();
        Sound s=LoadSound("killingDice.wav");
        PlaySound(s);
        WaitTime(0.7);
        UnloadSound(s);
        CloseAudioDevice();
        x=orgin_x;
        y=orgin_y;
        turnNO--;
        // move=false;
    }

    virtual void starting()=0;
    virtual bool check_home()=0;
    virtual void move_toward_home()=0;
    virtual bool beyond_home()=0;
    virtual void loadClr()=0;
    int *GetScore(){return dice_score;}
    int GetDiceNumber(){return diceNumber;}
    bool GetMove(){return move;}

    void diceZero(){
        diceNumber=0;
        for(int i=0;i<3;i++)
            dice_score[i]=0;
        turnNO++;
        if(turnNO>4) turnNO=1;
        stop_dice=false;
    }

    static int GetWhiteLineBorderX(){return white_border_X;}
    static int GetWhiteLineBorderY(){return white_border_Y;}
void NextDice(Texture2D &dice , token **tkn){
    num=rand()%6+1;
    int turn=turnNO;
    UnloadTexture(dice);

    dice=DiceLoader(num);
    if(num==6 && diceNumber==2)
            diceZero();

    else if(num==6)
        dice_score[diceNumber++]=6;
    else{
        dice_score[diceNumber]=num;
        stop_dice=true;
    }

    InitAudioDevice();
    Sound s=LoadSound("diceClick.wav");
    PlaySound(s);
    WaitTime(0.7);
    UnloadSound(s);
    CloseAudioDevice();
        num=dice_score[0];
     if(turnNO==6 &&(tkn[(turnNO-1)*4]->beyond_home() && tkn[(turnNO-1)*4]->second) && (tkn[(turnNO-1)*4+1]->beyond_home() && tkn[(turnNO-1)*4+1]->second)
      && (tkn[(turnNO-1)*4+2]->beyond_home() && tkn[(turnNO-1)*4+2]->second)&& (tkn[(turnNO-1)*4+3]->beyond_home() && tkn[(turnNO-1)*4+3]->second)){
        if(dice_score[2]==6) SetCurrentDice(2);
        else SetCurrentDice(1);
      }
           
    else if((dice_score[0]!=6 && 
        (!tkn[(turnNO-1)*4]->move || (tkn[(turnNO-1)*4]->beyond_home() && tkn[(turnNO-1)*4]->second)) &&
        (!tkn[(turnNO-1)*4+1]->move || (tkn[(turnNO-1)*4+1]->beyond_home() && tkn[(turnNO-1)*4+1]->second)) &&
        (!tkn[(turnNO-1)*4+2]->move || (tkn[(turnNO-1)*4+2]->beyond_home() && tkn[(turnNO-1)*4+2]->second)) &&
        (!tkn[(turnNO-1)*4+3]->move || (tkn[(turnNO-1)*4+3]->beyond_home() && tkn[(turnNO-1)*4+3]->second)) ))
                diceZero();

  
}

static void movementOfborder(){
    if(turnNO==1){
        white_border_X=0;
        white_border_Y=0;
    }
    else if(turnNO==2){
        white_border_X=550;
        white_border_Y=0;
    }
    else if(turnNO==4){
        white_border_X=0;
        white_border_Y=550;
    }
    else{
        white_border_X=550;
        white_border_Y=550;
    }
}

void Move_token(token **tkn){
    
    if(((turnNO==1 && tokenOf=="red") || (turnNO==2 && tokenOf=="green") || (turnNO==3 && tokenOf=="yellow") || (turnNO==4 && tokenOf=="blue")) && stop_dice){
        num=dice_score[GetCurrentDice()];

    if(move && !(beyond_home()&& second)){
        SetCurrentDice(GetCurrentDice()+1);

    for(int i=0;i<num;i++){
        block++;
        if(Entrance_Home && check_home() && second){
            if(beyond_home() && !i) {
                block--; 
                break;
            }
                move_toward_home();
        }
        else{
        if(block ==5){
            x+=60;
            y-=60;
        }
        else if(block==18){
            y+=60;
            x+=60;
        }
        else if(block==31){
            x-=60;
            y+=60;
        }
        else if(block==44){
            x-=60;
            y-=60;
        }
        else if(block<5 || (block>18 && block<24) ||(block>=11 && block<13))
            x+=60;
        else if(block<11 || (block>=39  && block<44 ) || (block>=50 && block<52) )
            y-=60;
        else if(block<18 || (block>=24 && block<26)  || (block>=31 && block<37) )
            y+=60;

        else if(block <31 || (block>=37 && block<39) || (block<50))
            x-=60;   
        else {
            block=0;
            x=65;
            y=362;
            second =true;
        }
    }
    }

    } 
    if(num==6){
        if(!move){
            move=true;
            starting();
            SetCurrentDice(GetCurrentDice()+1);
        }
    }

    for(int i=0;i<16;i++){
        if(block==tkn[i]->block && tokenOf!=tkn[i]->tokenOf && block%13!=0 && 
            !(tkn[i]->tokenOf=="green" && tkn[i]->second && tkn[i]->block<18 && tkn[i]->block>11 ) &&
            !(tkn[i]->tokenOf=="yellow" && tkn[i]->second && tkn[i]->block<31 && tkn[i]->block>24) &&
            !(tkn[i]->tokenOf=="blue" && tkn[i]->second && tkn[i]->block<44 && tkn[i]->block>37 )
        )
            tkn[i]->AfterKilling();
    }

    if(block==finalPlace && second){ turnNO--;  
        cout<<"as i think"<<endl;
    }
    while (1)
    {
        // for(int i=0;i<4;i++)
            // cout<<tkn[(turnNO-1)*4+i]->block<<endl;
        cout<<turnNO-1<<endl;
        
        if((tkn[(turnNO-1)*4]->block==finalPlace && tkn[(turnNO-1)*4+1]->block==finalPlace  
        && tkn[(turnNO-1)*4+2]->block==finalPlace && tkn[(turnNO-1)*4+3]->block==finalPlace ) )
            diceZero();
        else
            break;
    }

    if(GetCurrentDice()-1==diceNumber && move){
    if(turnNO>4) turnNO=1;
    stop_dice=false;
    diceZero();
    SetCurrentDice(0);
    cout<<"running"<<endl;
    // exit(0);
    }


            
}
}

static int GetTurn(){return turnNO;}
static bool GetStop(){return !stop_dice;}
Texture2D GetClr(){return clr;}
float  GetX(){return x;}
float GetY(){return y;}
int getBlock(){return block;}
~token() {UnloadTexture(clr);}

};

int token::diceNumber=0;
int token::dice_score[3]={0,0,0};
int token::turnNO=1;
bool token::stop_dice =false;
int token:: white_border_X=0;
int token:: white_border_Y=0;

class RedToken:public token{
    static int currentDice;
    public:
    RedToken(int x,int y):token(x,y,0,true,"red",56){}

    int GetCurrentDice(){return currentDice;}
    void SetCurrentDice(int a){currentDice=a;}
    void starting(){
        block=0;
        x=61; //65=>62=>61
        y=362;
    }

    bool check_home(){return block>=51;}
    void move_toward_home(){x+=60; }
    bool beyond_home(){return block+num>57;}
    void loadClr(){clr=LoadTexture("red.png");}
};

class YellowToken:public token{
    static int currentDice;
    public:
    YellowToken(int x,int y):token(x,y,26,false,"yellow",30){}

    int GetCurrentDice(){return currentDice;}
    void SetCurrentDice(int a){currentDice=a;}
    void starting(){
        block=26;
        x=794;//785=>790
        y=485;//482=>484
    }

    bool check_home(){return block>=25;}
    void move_toward_home(){x-=60; }
    bool beyond_home(){return block+num>31;}
    void loadClr(){clr=LoadTexture("yellow.png");}
};

class BlueToken:public token{
    static int currentDice;
    public:
    int GetCurrentDice(){return currentDice;}
    void SetCurrentDice(int a){currentDice=a;}
    BlueToken(int x,int y):token(x,y,39,false,"blue",43){}
    void starting(){
        block=39;
        x=366;//365=>367
        y=788;//785=>795=>790
    }

    bool check_home(){return block>=38;}
    void move_toward_home(){y-=60; }
    bool beyond_home(){return block+num>44;}
    void loadClr(){clr=LoadTexture("blue.png");} 
};

class GreenToken:public token{
    static int currentDice;
    public:
    int GetCurrentDice(){return currentDice;}
    void SetCurrentDice(int a){currentDice=a;}
    GreenToken(int x,int y):token(x,y,13,false,"green",18){}
    void starting(){
        block=13;
        x=491;//485=>490
        y=51;//62=>57=>53
    }

    bool check_home(){return block>=12;}
    void move_toward_home(){y+=60; }
    bool beyond_home(){return block+num>18;}
    void loadClr(){clr=LoadTexture("green.png");}
};


int RedToken::currentDice=0;
int GreenToken::currentDice=0;
int BlueToken::currentDice=0;
int YellowToken::currentDice=0;

int main(){
    const int screenWidth = 1010;
    const int screenHeight = 900;

    InitWindow(screenWidth, screenHeight, "");

    RedToken red[4]={
        {91,87},
        {213,87},
        {91,209},
        {213,209},
    };

    YellowToken yellow[4]={
        {642,637},
        {764,637},
        {642,759},
        {764,759},
    };

    BlueToken blue[4]={
        {92,635},
        {213,635},
        {92,757},
        {213,757},
    };

    GreenToken green[4]={
        {644,81},
        {766,81},
        {644,203},
        {766,203},
    };

    token *tkn[16];

    for(int i=0;i<4;i++){
        tkn[i]=&red[i];
        tkn[i+4]=&green[i];
        tkn[i+8]=&yellow[i];
        tkn[i+12]=&blue[i];
    }

    for(int i=0;i<16;i++)
        tkn[i]->loadClr();
    
    Rectangle diceButton={423,423,80.0f,80.0f};
    Rectangle TokenButton[16];
   
    Texture2D board= LoadTexture("ludo board.jpg");
    Texture2D  dice = LoadTexture("3dice.png");
    
    while(!WindowShouldClose()) {
        for(int i=0;i<16;i++)
            TokenButton[i]={tkn[i]->GetX(),tkn[i]->GetY(),65.0f,65.0f};
        
        Vector2 mousePos=GetMousePosition();
        BeginDrawing();
        ClearBackground(RAYWHITE);

        DrawTextureEx(board, (Vector2){0,0}, 0.0f,1.5f, WHITE);

        if(CheckCollisionPointRec(mousePos,diceButton)){
            DrawTextureEx(dice, (Vector2){423,423}, 0.0f,0.25, WHITE);

            if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && token::GetStop() )
                tkn[token::GetTurn()*4-1]->NextDice(dice,tkn);
        }
        else
            DrawTextureEx(dice, (Vector2){423,423}, 0.0f,0.25f, WHITE); 

    for(int i=0;i<16;i++){
        if(CheckCollisionPointRec(mousePos,TokenButton[i])){
            if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT) )  tkn[i]->Move_token(tkn);
        }
    }
     for(int i=0;i<4;i++){
        DrawTextureEx(red[i].GetClr(), (Vector2){red[i].GetX(),red[i].GetY()},0.0f,0.2f, WHITE); 
        DrawTextureEx(green[0].GetClr(),(Vector2){green[i].GetX(),green[i].GetY()},0.0f,0.19f,WHITE);
        DrawTextureEx(yellow[0].GetClr(),(Vector2){yellow[i].GetX(),yellow[i].GetY()},0.0f,0.18f,WHITE);
        DrawTextureEx(blue[0].GetClr(),(Vector2){blue[i].GetX(),blue[i].GetY()},0.0f,0.21f,WHITE);
     } 
     Texture2D Dice[3];
     int coordinate[2]={929,354};
     for(int j=0;j<16;j+=4){
     for(int i=0;i<tkn[j]->GetDiceNumber();i++){
         Dice[i]=DiceLoader(tkn[j]->GetScore()[i]);
         DrawTextureEx(Dice[i], (Vector2){coordinate[0],coordinate[1]+i*85}, 0.0f,0.2f, WHITE); 
     } 
     DrawRectangleLinesEx((Rectangle){token::GetWhiteLineBorderX(), token::GetWhiteLineBorderY(), 370, 370}, 5, GOLD);
    }
    // cout<<token::GetTurn()<<endl;
    token::movementOfborder();
     EndDrawing(); 
    }
    UnloadTexture(board);
    UnloadTexture(dice);
    CloseWindow();
}

