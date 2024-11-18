/**
 * @file /include/udp_connection/qnode.hpp
 *
 * @brief Communications central!
 *
 * @date February 2011
 **/
/*****************************************************************************
** Ifdefs
*****************************************************************************/

#ifndef udp_connection_QNODE_HPP_
#define udp_connection_QNODE_HPP_

/*****************************************************************************
** Includes
*****************************************************************************/
#ifndef Q_MOC_RUN
#include <rclcpp/rclcpp.hpp>
#endif
#include <QThread>
#include <QUdpSocket>
#include <QString>

/*****************************************************************************
** Class
*****************************************************************************/
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
  void setupSocket();

Q_SIGNALS:
  void rosShutDown();
  void messageReceived(const QString& msg);
};

#endif /* udp_connection_QNODE_HPP_ */
