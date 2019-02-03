/*
 * Created by efreyu on 1/31/19.
 */
#define BOARD_MIN_SIZE 0
#define BOARD_MAX_SIZE 10

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

int needCount = BOARD_MAX_SIZE * BOARD_MAX_SIZE - 1;

void dump(int rows, int cols, int array[rows][cols]) {
    int i, j;
    for (i = 0; i < rows; ++i) {
        printf("%d => [", i);
        for (j = 0; j < cols; ++j) {
            printf("    [%d:%d] ", j, array[i][j]);
        }
        printf("]\n");
    }
}

void fillArrayBoard(int rows, int cols, int array[rows][cols]) {
    int i, j;
    for (i = 0; i < rows; ++i) {
        for (j = 0; j < cols; ++j) {
            array[i][j] = 0;
        }
    }
}

int fillArray(Coord *steps) {
    for (int i = 0; i < needCount; ++i) {
        steps[i].x = 0;
        steps[i].y = 0;
    }
}

int check_board(int y, int x) {
    if (x < BOARD_MIN_SIZE || x >= BOARD_MAX_SIZE) {
        return 0;
    } else if (y < BOARD_MIN_SIZE || y >= BOARD_MAX_SIZE) {
        return 0;
    }
    return 1;
}

Coord step(int x, int y, int board[BOARD_MAX_SIZE][BOARD_MAX_SIZE], Coord *steps, int step_number) {


//    dump(BOARD_MAX_SIZE,BOARD_MAX_SIZE,board);
    //FIXME fix later
    int next_x, next_y;
    Coord result;
    step_number++;

    for (int i = 0; i < 8; ++i) {
        next_x = x + moves[i].x;
        next_y = y + moves[i].y;

        if (check_board(next_x, next_y) == 0 && board[next_x][next_y] == 0) {
            board[next_x][next_y] = 1;
            steps[step_number].x = next_x;
            steps[step_number].y = next_y;

            result = step(next_x, next_y, board, steps, step_number);


            return result;
        }
    }

    return *steps;

    /* update horse's position */
//    visited[y][x] = 1;
//    count++;

    /* print position */
//    printf("%c%d, ", 'A' + y, x + 1);
}

int start_chess() {
    Coord result;
    Coord steps[needCount];//шаги
    int step_number = 0;
    int board[BOARD_MAX_SIZE][BOARD_MAX_SIZE];//поле

    //init variable and start position
    int x = 0, y = 1;//стандартное положение коня на доске

    fillArrayBoard(BOARD_MAX_SIZE, BOARD_MAX_SIZE, board);
    fillArray(steps);
    board[x][y] = 1;
    steps[step_number].x = 0;
    steps[step_number].y = 1;
//    for (int i = 0; i < needCount; ++i) {
//        printf("%d:%d ", i, steps[i].x);
//        printf("%d:%d ", i, steps[i].y);
//    }
    result = step(x, y, board, steps, step_number);


}

