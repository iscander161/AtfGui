/**
 * @file Main.cpp
 * @author Tolstunov Alexander (iscander161@yandex.ru)
 * @brief
 * @date 17 August 2022
 */

/* Includes ------------------------------------------------------------------*/
#include <QtWidgets/QApplication>
#include "Widgets/MainWindow.h"

/**
 * Главная функция приложения
 * @param argc - Количество аргументов приложения
 * @param argvs - Аргументы приложения
 * @return int - Результат выполнения приложения
 */
int main(int argc, char** argvs) {
    auto app = QApplication(argc, argvs);

    auto wnd = AtfGuiCoreApplication::MainWindow();

    const auto result = QApplication::exec();
    return result;
}
