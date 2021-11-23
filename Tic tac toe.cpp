#include <iostream>

using namespace std;

//贏家判斷
int win_situation(char a, char b, char c){
    if(a!=' ' && a==b && a==c){
        return 1;
    }

    return 0;
}

int main(){
    int i, j, pos;
    char table[3][3];
    char op, player;

    //遊戲開局，每一格設定為空值
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            table[i][j] = ' ';
        }
    }

    cout << "=== 圈圈叉叉遊戲 ===" << endl;
    cout << "請選擇(1)單人模式 (2)雙人模式" << endl << ">";
    cin >> op;

    if(op=='1'){
        return 0;
    }
    else{
        //最多進行9回合
        for(i=0;i<9;i++){
            //每回合開始前列印table
            cout << "回合 " << i+1 << endl;
            for(j=0;j<3;j++){
                if(j!=2){
                    cout << table[j][0] << "l" << table[j][1] << "l" << table[j][2] << endl;
                    cout << "-+-+-" << endl;
                }
                else
                    cout << table[j][0] << "l" << table[j][1] << "l" << table[j][2] << endl;
            }
            //判斷基偶決定玩家回合
            player = (i%2) ? 'B':'A';
            cout << "玩家 " << player << ": ";
            cin >> pos;
            cout << endl;

            //檢查該位置是否可下
            if(table[(pos-1)/3][(pos-1)%3]==' ')
                table[(pos-1)/3][(pos-1)%3] = (i%2) ? 'X':'O';  //可下，改變該值
            else{
                cout << "該位置已下過，請重新再下一次!" << endl;  //不可下，要求重新輸入
                i--;        //此回合不算數
                continue;   //略過此回合後面動作
            }

            //判斷贏家
            for(j=0;j<3;j++){
                if( win_situation(table[j][0], table[j][1], table[j][2]) ||
                    win_situation(table[0][j], table[1][j], table[2][j]) ||
                    win_situation(table[0][0], table[1][1], table[2][2]) ||
                    win_situation(table[0][2], table[1][1], table[2][0]) ){

                    //勝利結局
                    for(j=0;j<3;j++){
                        if(j!=2){
                            cout << table[j][0] << "l" << table[j][1] << "l" << table[j][2] << endl;
                            cout << "-+-+-" << endl;
                        }
                        else
                            cout << table[j][0] << "l" << table[j][1] << "l" << table[j][2] << endl;
                    }
                    cout << "玩家 " << player << " 獲勝!" << endl << "遊戲結束~" << endl;
                    system("pause");
                    return 0;
                }
            }
        }
        //進行9回合無勝負
        //平手結局
        for(j=0;j<3;j++){
            if(j!=2){
                cout << table[j][0] << "l" << table[j][1] << "l" << table[j][2] << endl;
                cout << "-+-+-" << endl;
            }
            else
                cout << table[j][0] << "l" << table[j][1] << "l" << table[j][2] << endl;
        }
        cout << "雙方平手!" << endl;
    }

    return 0;
}

