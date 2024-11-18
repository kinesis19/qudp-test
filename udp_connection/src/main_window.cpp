/**
 * @file /src/main_window.cpp
 *
 * @brief Implementation for the qt gui.
 *
 * @date August 2024
 **/
/*****************************************************************************
** Includes
*****************************************************************************/

#include "../include/udp_connection/main_window.hpp"

MainWindow::MainWindow(QWidget* parent) : QMainWindow(parent), ui(new Ui::MainWindowDesign)
{
  ui->setupUi(this);

  QIcon icon("://ros-icon.png");
  this->setWindowIcon(icon);

  qnode = new QNode();

   // 슬롯 연결
  connect(ui->setIPAddressButton, &QPushButton::clicked, this, &MainWindow::on_setIPAddress_clicked);
  connect(ui->sendButton, &QPushButton::clicked, this, &MainWindow::on_sendButton_clicked);

  // 연결 시그널/슬롯 설정
  // connect(qnode, &QNode::messageReceived, this, [this](const QString& msg) {
  //   ui->receivedMessageLabel->setText(msg);
  // });
  connect(qnode, &QNode::messageReceived, this, [this](const QString& msg) {
  if (msg == "PONG") {
    updateConnectionStatus(true);  // 연결 성공 시 업데이트
  } else {
    ui->receivedMessageLabel->setText(msg);  // 일반 메시지는 출력
  }
});

  QObject::connect(qnode, SIGNAL(rosShutDown()), this, SLOT(close()));
}

void MainWindow::closeEvent(QCloseEvent* event)
{
  QMainWindow::closeEvent(event);
}

MainWindow::~MainWindow()
{
  delete ui;
}

void MainWindow::updateConnectionStatus(bool connected) {
  if (connected) {
    ui->conditionLabel->setText("Connected!");
    ui->conditionLabel->setStyleSheet("color: green;");
  } else {
    ui->conditionLabel->setText("Disconnected");
    ui->conditionLabel->setStyleSheet("color: red;");
  }
}


// void MainWindow::on_setIPAddress_clicked() {
//   QString ipAddress = ui->ipAddressLineEdit->text();
//   if (!ipAddress.isEmpty()) {
//     qnode->setReceiverIPAddress(ipAddress.toStdString());
//     updateConnectionStatus(true);  // 연결 상태를 'Connected'로 설정
//   } else {
//     updateConnectionStatus(false); // IP 주소가 비어 있을 경우 'Disconnected'
//   }
// }

void MainWindow::on_setIPAddress_clicked() {
  QString ipAddress = ui->ipAddressLineEdit->text();
  if (!ipAddress.isEmpty()) {
    qnode->setReceiverIPAddress(ipAddress.toStdString());

    // PING 메시지 전송
    qnode->sendUDPMessage("PING");

    // 초기 상태를 'Disconnected'로 설정하고 응답을 기다림
    updateConnectionStatus(false);

    // 타임아웃 설정 (예: 3초)
    QTimer::singleShot(3000, this, [this]() {
      if (ui->conditionLabel->text() != "Connected!") {
        updateConnectionStatus(false);  // 응답이 없으면 'Disconnected' 유지
      }
    });
  } else {
    updateConnectionStatus(false);
  }
}




void MainWindow::on_sendButton_clicked() {
  QString message = ui->messageLineEdit->text();
  if (!message.isEmpty()) {
    qnode->sendUDPMessage(message.toStdString());
  }
}