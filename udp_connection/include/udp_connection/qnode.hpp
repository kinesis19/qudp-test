#ifndef udp_connection_QNODE_HPP_
#define udp_connection_QNODE_HPP_
#ifndef Q_MOC_RUN
#include <rclcpp/rclcpp.hpp>
#endif
#include <QThread>
#include <QUdpSocket>
#include <QString>
#include <std_msgs/msg/int32.hpp>

class QNode : public QThread
{
  Q_OBJECT
public:
  QNode();
  ~QNode();

  void setReceiverIPAddress(const std::string& ipAddress);
  void sendUDPMessage(const std::string& message);

protected:
  void run();

private:

  std::shared_ptr<rclcpp::Node> node;
  QUdpSocket* udpSocket;
  QHostAddress receiverAddress;
  quint16 receiverPort;

  // 퍼블리셔, 서브스크라이버
  rclcpp::Subscription<std_msgs::msg::Int32>::SharedPtr sub_psd_left_;


  // 메서드
  void setupSocket();
  void callbackPSDValueLeft(const std_msgs::msg::Int32::SharedPtr msg);

Q_SIGNALS:
  void rosShutDown();
  void messageReceived(const QString& msg);
};

#endif /* udp_connection_QNODE_HPP_ */
