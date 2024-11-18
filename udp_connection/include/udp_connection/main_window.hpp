/**
 * @file /include/udp_connection/main_window.hpp
 *
 * @brief Qt based gui for %(package)s.
 *
 * @date August 2024
 **/

#ifndef udp_connection_MAIN_WINDOW_H  
#define udp_connection_MAIN_WINDOW_H

/*****************************************************************************
** Includes
*****************************************************************************/

#include <QMainWindow>
#include <QTimer>  // QTimer 헤더 추가
#include "QIcon"
#include "qnode.hpp"
#include "ui_mainwindow.h"

/*****************************************************************************
** Interface [MainWindow]
*****************************************************************************/
/**
 * @brief Qt central, all operations relating to the view part here.
 */
class MainWindow : public QMainWindow
{
  Q_OBJECT

public:
  MainWindow(QWidget* parent = nullptr);
  ~MainWindow();
  QNode* qnode;

private Q_SLOTS:
  void on_sendButton_clicked();
  void on_setIPAddress_clicked();

private:
  Ui::MainWindowDesign* ui;
  void closeEvent(QCloseEvent* event);
  void updateConnectionStatus(bool connected);  // 연결 상태 업데이트 함수 추가
};

#endif  // udp_connection_MAIN_WINDOW_H
