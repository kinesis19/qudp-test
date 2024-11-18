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
  connect(qnode, &QNode::messageReceived, this, [this](const QString& msg) {
    ui->receivedMessageLabel->setText(msg);
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


void MainWindow::on_setIPAddress_clicked() {
  QString ipAddress = ui->ipAddressLineEdit->text();
  if (!ipAddress.isEmpty()) {
    qnode->setReceiverIPAddress(ipAddress.toStdString());
    updateConnectionStatus(true);  // 연결 상태를 'Connected'로 설정
  } else {
    updateConnectionStatus(false); // IP 주소가 비어 있을 경우 'Disconnected'
  }
}

void MainWindow::on_sendButton_clicked() {
  QString message = ui->messageLineEdit->text();
  if (!message.isEmpty()) {
    qnode->sendUDPMessage(message.toStdString());
  }
}