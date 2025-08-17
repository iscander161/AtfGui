/**
 * @file MainWindow.cpp
 * @author Tolstunov Alexander (iscander161@yandex.ru)
 * @brief
 * @date 17 August 2022
 */

/* Includes ------------------------------------------------------------------*/
#include <QtWidgets/QMessageBox>
#include "MainWindow.h"

namespace AtfGuiCoreApplication {

/*
 * Создает главное окно приложения
 */
MainWindow::MainWindow()
    : m_mainWindow(nullptr), m_mainWindowEventFilter(nullptr)
{
    initialize();
}

/*
 * Удаляет главное окно приложения
 */
MainWindow::~MainWindow() {
    if (m_mainWindow)
        delete m_mainWindow;
}

/*
 * Инициализирует главное окно приложения
 */
void MainWindow::initialize() {
    m_mainWindow = new QMainWindow();
    m_mainWindow->setObjectName("m_mainWindow");

    // TODO: Get settings from application settings
    m_mainWindowEventFilter = new MainWindowEventFilter(this);
    m_mainWindow->installEventFilter(m_mainWindowEventFilter);
    m_mainWindow->resize(1366, 768);
    m_mainWindow->show();
}

/*
 * Создание объекта обработчика событий
 */
MainWindowEventFilter::MainWindowEventFilter(QObject* parent)
    : QObject(parent)
{ }

/*
 * Обработчик событий объекта
 */
bool MainWindowEventFilter::eventFilter(QObject* obj, QEvent* event) {
    auto eventType = event->type();
    QWidget* window = qobject_cast<QWidget*>(obj);

    if(!window)
        return QObject::eventFilter(obj, event);

    switch(eventType) {
        case QEvent::Close:
            if(closeEventRequest(window)) {
                event->setAccepted(true);
            }
            else
                event->setAccepted(false);
            return true;
        default:
            return QObject::eventFilter(obj, event);
    }
}

/*
 * Запрос закрытия окна
 */
bool MainWindowEventFilter::closeEventRequest(QWidget* obj) {
    QMessageBox::StandardButton result =
        QMessageBox::question(obj, "Application",
            tr("Do you really want to exit?"),
            QMessageBox::Yes | QMessageBox::No);

    return result == QMessageBox::Yes ? true : false;
}

} /* Namespace AtfGuiCoreApplication. */
