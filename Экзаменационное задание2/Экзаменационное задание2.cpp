

#include <iostream>
#include <vector>
#include <algorithm>
//Структура для предоставления доски
struct Board {
    std::vector<int>board;//вектор для хранения чисел на доске
    int size;//размер доски(количество строк и столбцов)
 };
//Функция для проверки,является ли доска решением
bool isSolved(const Board&& b) {
    for (int i = 0; i < b.size * b.size - 1; i++) {
        if (b.board[i] != i + 1 || b.board[(i + 1) % (b.size * b.size)] != i + 2) {
            return false;
        }
}
    return true;
}
//Функция для перемещения шашки
void move(Board& b, int from, int to) {
    int temp = b.board[from];
    b.board[from] = b.board[to];
    b.board[to] = temp;
}
//Функция для поиска следующего хода
bool findMove(Board& b, int& from, int& to) {
    for (int i = 0; i < b.size * b.size - 1; i++) {
        if (b.board[i] == i + 1 + 1 && b.board[(i + 1) % (b.size * b.size)] > b.board[i]) {
            from = i;
            to = (i + 1) % (b.size * b.size);
            return true;
        }
    }
    return false;
}
//Функция для игры против компьютера
bool computerPlay(Board& b) {
    int from, to;
    while (findMove(b, from, to)) {
        move(b, from, to);
    }
    return isSolved(b);
}
//Функция для игры против человека
void humanPlay() {
    //здесь должен быть код для взаимодействия с пользователем
    return  ;//предполагаем,что пользователь всегда выигрывает
}
//Функция для запуска игры
void playGame(int size) {
    Board b{ std::vector<int>(size * size), size };
    //заполняем доску случайными числами
    for (int i = 0; i < b.board.size(); ++i) {
        b.board[i] = rand() % (size * size) + 1;
    }
    bool solved = false;
    do {
        solved = humanPlay();
        if (!solved) {
            solved = computerPlay(b);
        }
    } while (!solved);
    //выводим статистику
    std::cout << "Игра завершена!"<<std::endl;
    std::cout << "Количество ходов:" << b.board.size() - 1 << std::endl;
}
//Функция для печати текущего состояния поля
//void printField(const std::vector<std::vector<int>>& field) {
//    for (const auto& row : field) {
//        for (int num : row) {
//            std::cout << num << " ";
//        }
//        std::cout << std::endl;
//    }
//}
////Функция для проверки,есть ли ходы в игре 
//bool hasMoves(const std::vector <std::vector<int>>& field) {
//    //Проверяем,есть ли пустые клетки
//    return std:: find(field[0].begin(), field[0].end(),0)!=field[0].end();
//}
////Функция для генерации случайного хода
//std::pair<int, int>generateRandomMove(const std::vector<std::vector<int>>& field) {
//    //Находим индексы пустой клетки
//    int x = rand() % 4;
//    int y = rand() % 4;
//    while (field[y][x] == 0) {
//        x = rand() % 4;
//        y = rand() % 4;
//    }
//    return{ x,y };
//}
////Функция для выполнения хода
//void makeMove(std::vector<std::vector<int>>& field, const std::pair<int, int>& move) {
//    //Обмен местами текущей клетки с пустой клетки
//    std::swap(field[move.first][move.second], field[0][0]);
//    //Перемещение пустой клетки в освободившуюся позицию
//    for (int i = 0; i < 4; i++) {
//        if (field[i][move.second] == 0) {
//            field[i][move.second] == field[i][0];
//            field[i][0] = 0;
//        }
//    }
//}
////Функция для проверки победы
//bool checkVictory(const std::vector<std::vector<int>>& field) {
//    //Проверяем,все и числа расположены последовательно
//    for (int i = 1; i <= 15; i++) {
//        bool found = false;
//        for (int j = 0; j < 4 && !found; ++j) {
//            for (int k = 0; k < 4 && !found; ++k) {
//                if (field[j][k] == i) {
//                    found = true;
//                }
//            }
//        }
//        if (!found) {
//            return false;
//        }
//    }
//    return true;
//}

int main()
{
    //std::vector<std::vector<int>>field(4, std::vector<int>(4));
    ////Инициализация поля случайными числами
    //for (int i = 0; i < 4;i++) {
    //    for (int j = 0; j < 4; j++) {
    //        field[i][j] = rand() % 16;
    //    }

    //}
    ////Печатать начального состояние поля
    //printField(field);
    //while (hasMoves(field)) {
    //    //Генерация случайного хода 
    //    std::pair<int, int>move = generateRandomMove(field);
    //    //Выполнение хода
    //    makeMove(field, move);
    //    //Печатать текущего состояния поля
    //    printField(field);
    //    //Проверка победы
    //    if (checkVictory(field)) {
    //        std::cout << "Победа!" << std::endl;
    //        break;
    //    }
    //}
    //return 0;
    int size;
    std::cout << "Выберите размер доски: 3*3 или 4*4" << std::endl;
    std::cin >> size;
    playGame(size);
    return 0;
}


