#include <bits/stdc++.h>

using namespace std;

const int n = 200;
const int robot_num = 10;
const int berth_num = 10;
const int boat_num = 5;
const int cargo_num = 10000;
int cargoIndex = 0;
const int N = 210;

bool is_cargo()
{
    return true;
}



struct Robot
{
    int x, y, goods;
    int status;
    int mbx, mby;
    Robot() {}
    Robot(int startX, int startY) {
        x = startX;
        y = startY;
    }
}robot[robot_num + 10];

struct Berth
{
    int x;
    int y;
    int transport_time;
    int loading_speed;
    Berth() {}
    Berth(int x, int y, int transport_time, int loading_speed) {
        this->x = x;
        this->y = y;
        this->transport_time = transport_time;
        this->loading_speed = loading_speed;
    }
}berth[berth_num + 10];

struct Boat{
    int num;
    int pos;  // 目标泊位，虚拟点则为-1
    int status; // 0:移动/运输中，1：装货状态/运输完成状态，2：泊位外等待状态
    int capcity;
}boat[boat_num];

struct Cargo {
    int id;
    int x;
    int y;
    int value;
    int lifeSpan = 1000;
    bool taken = false;  // 标记是否被取走 or 是否到达泊位
}cargo[cargo_num];

int money, boat_capacity, id;
char ch[N][N];
int gds[N][N];
void Init(){
    for (int i = 1; i <= n; i++){
        scanf("%s", ch[i] + 1);
    }
    for (int i = 0; i < berth_num; i++){
        int id;
        scanf("%d", &id);
        scanf("%d%d%d%d", &berth[id].x, &berth[id].y, &berth[id].transport_time, &berth[id].loading_speed);
    }
    scanf("%d", &boat_capacity);
    char okk[100];
    scanf("%s", okk);
    printf("OK\n");
    fflush(stdout);
}

int Input(){
    scanf("%d%d", &id, &money);
    int current_cargo_num;
    scanf("%d", &current_cargo_num);
    for (int i = 0; i < current_cargo_num; i++){
        int x, y, val;
        scanf("%d%d%d", &x, &y, &val);
        cargo[cargoIndex + i].x = x;
        cargo[cargoIndex + i].y = y;
        cargo[cargoIndex + i].value = val;
    }
    cargoIndex += current_cargo_num;
    for (int i = 0; i < robot_num; i++){
        int sts;
        scanf("%d%d%d%d", &robot[i].goods, &robot[i].x, &robot[i].y, &sts);
    }
    for (int i = 0; i < 5; i++){
        scanf("%d%d\n", &boat[i].status, &boat[i].pos);
    }
    char okk[100];
    scanf("%s", okk);
    return id;
}

void Output() {
//    for (int i = 0; i < robot_num; i++) {
//        printf("move %d %d\n", i, rand() % 4);
//    }
    for (int i = 0; i < boat_num; i++)
        printf("ship %d %d\n", i, rand() % 5);
    puts("OK");
    fflush(stdout);
    return;
}

int main(){
    FILE *logfile = fopen("log.txt", "a"); // 打开日志文件，"a"表示以追加的方式打开文件

    if (!logfile) {
        perror("无法打开日志文件！"); // 输出错误信息
        return 1;
    }

    // 要写入的内容
    const char *log_content = "这是一条日志记录\n";

    // 写入内容到日志文件
    fprintf(logfile, "%s", log_content);

    // 关闭日志文件
    fclose(logfile);

    printf("内容已写入日志文件\n");
    Init();
    for (int zhen = 1; zhen <= 15000; zhen++){
        int frame_id = Input();

        Output();
    }

    return 0;
}
