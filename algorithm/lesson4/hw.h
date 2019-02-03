/*
 * Created by efreyu on 1/31/19.
 */
#define MIN_SIZE 0
#define MAX_SIZE 10

typedef struct coord {
    int x;
    int y;
} Coord;

Coord moves[8] = {//x, y
        //Верхние ходы
        {2,  1},//2 вверх 1 вправо
        {2,  -1},
        {1,  2},//1 вверх 2 вправо
        {1,  -2},
        //Нижние ходы
        {-2, 1},
        {-2, -1},
        {-1, 2},
        {-1, -2}
};

int needCount = MAX_SIZE * MAX_SIZE - 1;

int fillArray(Coord *steps) {
    for (int i = 0; i < needCount; ++i) {
        steps[i].x = 0;
        steps[i].y = 0;
    }
}

int check_board(int y, int x) {
    if (x < MIN_SIZE || x >= MAX_SIZE) {
        return 0;
    } else if (y < MIN_SIZE || y >= MAX_SIZE) {
        return 0;
    }
    return 1;
}

int step(int x, int y, int *board[], Coord *steps, int step_number) {

    int next_x, next_y, count;
    step_number++;

    for (int i = 0; i < 8; ++i) {
        next_x = x + moves[i].x;
        next_y = y + moves[i].y;

        if (check_board(next_x, next_y) == 0 && board[next_x][next_y] == 0) {
            board[next_x][next_y] = 1;
            steps[step_number].x = next_x;
            steps[step_number].y = next_y;
            //count = step(next_x, next_y, board, &steps, step_number);

            return 0;
        }
    }

    return 0;

    /* update horse's position */
//    visited[y][x] = 1;
//    count++;

    /* print position */
//    printf("%c%d, ", 'A' + y, x + 1);
}

int dump() {

}

int start_chess() {
    int count = 0;
    Coord steps[needCount];//шаги
    int step_number = 0;
    int board[MAX_SIZE][MAX_SIZE] = {{0}};//поле
    //start position
    int x = 0, y = 0;
    fillArray(&steps);
    board[x][y] = 1;
    steps[step_number].x = 1;
    steps[step_number].y = 1;
//    for (int i = 0; i < needCount; ++i) {
//        printf("%d:%d ", i, steps[i].x);
//        printf("%d:%d ", i, steps[i].y);
//    }
    count = step(x, y, board, &steps, step_number);


}

