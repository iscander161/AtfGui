/**
 * @file MainWindow.h
 * @author Tolstunov Alexander (iscander161@yandex.ru)
 * @brief
 * @date 17 August 2022
 */

#pragma once // Define to prevent recursive inclusion

/* Includes ------------------------------------------------------------------*/
#include <QtCore/QEvent>
#include <QtWidgets/QMainWindow>

namespace AtfGuiCoreApplication {

/**
 * Фильтр событий главного окна
 */
class MainWindowEventFilter : public QObject {
    Q_OBJECT
public:
    /**
     * Создание объекта обработчика событий
     * \param parent - Родительский объект
     */
    MainWindowEventFilter(QObject* parent = nullptr);

protected:
    /**
     * Обработчик событий объекта
     * \param obj - Объект
     * \param event - Событие объекта
     * \return true -
     * \return false -
     */
    bool eventFilter(QObject* obj, QEvent* event) override;

private:
    /**
     * Запрос закрытия окна
     * \param obj - Объект
     * \return true
     * \return false
     */
    static bool closeEventRequest(QWidget* obj);
};

/**
 * @brief Класс главного окна приложения
 */
class MainWindow : public QObject {
    Q_OBJECT
public:
    /**
     * Создает главное окно приложения
     */
    MainWindow();

    /**
     * Удаляет главное окно приложения
     */
    ~MainWindow();

private:
    /**
     * Инициализирует главное окно приложения
     */
    void initialize();

    /**
     * Указатель на объект главного окна приложения
     */
    QMainWindow* m_mainWindow;

    /**
     * Указатель на обработчик событий главного окна
     */
    MainWindowEventFilter* m_mainWindowEventFilter;
};

} /* Namespace AtfGuiCoreApplication. */
