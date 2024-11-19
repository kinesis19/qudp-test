#include "../include/udp_connection/qnode.hpp"

QNode::QNode() : udpSocket(new QUdpSocket(this)), receiverPort(12345)
{
  int argc = 0;
  char** argv = NULL;
  rclcpp::init(argc, argv);
  node = rclcpp::Node::make_shared("udp_connection");
  this->start();


  sub_psd_left_ = node->create_subscription<std_msgs::msg::Int32>("/adc_value_left", 10, std::bind(&QNode::callbackPSDValueLeft, this, std::placeholders::_1));

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

void QNode::callbackPSDValueLeft(const std_msgs::msg::Int32::SharedPtr msg) 
{
  // ROS 2 데이터(Int64)를 QString으로 변환
  QString dataToSend = QString::number(msg->data);

  // UDP를 통해 데이터 송신
  QByteArray data = dataToSend.toUtf8();
  udpSocket->writeDatagram(data, receiverAddress, receiverPort);

  RCLCPP_INFO(node->get_logger(), "Sent data: %s", dataToSend.toStdString().c_str());
}