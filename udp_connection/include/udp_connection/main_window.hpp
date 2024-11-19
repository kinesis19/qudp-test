#ifndef udp_connection_MAIN_WINDOW_H  
#define udp_connection_MAIN_WINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QNetworkInterface>
#include <QString>
#include "QIcon"
#include "qnode.hpp"
#include "ui_mainwindow.h"

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
  QString getLocalIPAddress();
};

#endif  // udp_connection_MAIN_WINDOW_H
