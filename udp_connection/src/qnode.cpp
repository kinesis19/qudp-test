#include "../include/udp_connection/qnode.hpp"

QNode::QNode() : udpSocket(new QUdpSocket(this)), receiverPort(12345)
{
  int argc = 0;
  char** argv = NULL;
  rclcpp::init(argc, argv);
  node = rclcpp::Node::make_shared("udp_connection");
  this->start();
  setupSocket();
}

QNode::~QNode()
{
  if (rclcpp::ok())
  {
    rclcpp::shutdown();
  }
}

void QNode::run()
{
  rclcpp::WallRate loop_rate(20);
  while (rclcpp::ok())
  {
    rclcpp::spin_some(node);
    loop_rate.sleep();
  }
  rclcpp::shutdown();
  Q_EMIT rosShutDown();
}

void QNode::setupSocket() {
  udpSocket->bind(QHostAddress::Any, receiverPort);

  connect(udpSocket, &QUdpSocket::readyRead, this, [this]() {
    while (udpSocket->hasPendingDatagrams()) {
      QByteArray buffer;
      buffer.resize(udpSocket->pendingDatagramSize());
      QHostAddress sender;
      quint16 senderPort;

      udpSocket->readDatagram(buffer.data(), buffer.size(), &sender, &senderPort);
      QString receivedMessage = QString::fromUtf8(buffer);
      emit messageReceived(receivedMessage);
    }
  });
}

void QNode::setReceiverIPAddress(const std::string& ipAddress) {
  receiverAddress = QHostAddress(QString::fromStdString(ipAddress));
}

void QNode::sendUDPMessage(const std::string& message) {
  QByteArray data = QByteArray::fromStdString(message);
  udpSocket->writeDatagram(data, receiverAddress, receiverPort);
}