/*
 * Created by efreyu on 2/3/19.
 */
//Board
#define MIN_SIZE 0
#define MAX_SIZE 10

//For steps
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

int board[MAX_SIZE][MAX_SIZE];//поле
int maxSteps = MAX_SIZE * MAX_SIZE - 1;

void dump(int rows, int cols, int array[rows][cols]) {
    int i, j;
    for (i = 0; i < rows; ++i) {
        printf("%d => [", i);
        for (j = 0; j < cols; ++j) {
            printf("[%2d] ", /*j, */array[i][j]);
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
    for (int i = 0; i < (MAX_SIZE * MAX_SIZE); ++i) {
        steps[i].x = 0;
        steps[i].y = 0;
    }
}

int check_board(int x, int y) {
    if (x < MIN_SIZE || x >= MAX_SIZE) {
        return 0;
    } else if (y < MIN_SIZE || y >= MAX_SIZE) {
        return 0;
    } else if (board[x][y] != 0) {
        return 0;
    }
    return 1;
}


int horse(int x, int y, int step_number) {
    int next_x, next_y;

    board[x][y] = step_number;
    if (step_number >= maxSteps) {
        return 1;
    }

//    step_number++;
    for (int i = 0; i < 8; ++i) {
        next_x = x + moves[i].x;
        next_y = y + moves[i].y;

        if (check_board(next_x, next_y) && horse(next_x, next_y, ++step_number)) {
            return 1;
        }
    }
    return 0;
}

int start_chess() {
//    Coord result[MAX_SIZE * MAX_SIZE];
//    Coord steps[MAX_SIZE * MAX_SIZE];//шаги
    int step_number = 1;
    //init variable and start position
    int x = MAX_SIZE - 1, y = 1;//стандартное положение коня на доске
    fillArrayBoard(MAX_SIZE, MAX_SIZE, board);
//    fillArray(steps);
//    fillArray(result);
//    board[x][y] = step_number;
//    dump(MAX_SIZE, MAX_SIZE, board);
//    steps[step_number].x = MAX_SIZE - 1;
//    steps[step_number].y = 1;
//    for (int i = 0; i < needCount; ++i) {
//        printf("%d:%d ", i, steps[i].x);
//        printf("%d:%d ", i, steps[i].y);
//    }
//    step(x, y, board, steps, step_number, result);
    horse(x, y, step_number);
    dump(MAX_SIZE, MAX_SIZE, board);
}