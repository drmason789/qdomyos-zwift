#ifndef TRIXTERXDREAMSERIAL_H
#define TRIXTERXDREAMSERIAL_H

#include <QMutex>
#include <QThread>
#include <QWaitCondition>
#include <QAtomicInt>

/**
 * @brief A basic serial port monitoring thread.
 * Avoids using signals to prevent complications with objects, threads and timers.
 */
class trixterxdreamv1serial : public QThread {
    Q_OBJECT

public:
    static class std::function<class serialdatasource*(QObject *)> serialDataSourceFactory;

    explicit trixterxdreamv1serial(QObject *parent = nullptr);
    ~trixterxdreamv1serial();

    /**
     * @brief Opens the port.
     * @param portName The name of the serial port.
     * @returns True if the port was opened, false if the port wasn't opened, or was already open.
     */
    bool open(const QString &portName);

    /**
     * @brief Writes the array of bytes to the serial port
     * @param buffer The bytes to send.
     */
    void write(const QByteArray& buffer);

    /**
     * @brief set_receiveBytes Set a delegate to receive bytes. This is an alternative
     * to sublcassing and overrding the virtual receive function.
     * @param value
     */
    void set_receiveBytes(std::function<void(const QByteArray& bytes)> value) { this->receiveBytes = value; }

    /**
     * @brief availablePorts Returns a list of port names for the serial ports found in the system
     * that could host the bike.     
     */
    static QStringList availablePorts();

protected:
    /**
     * @brief receive Override this to process received data.
     * @param bytes
     */
    virtual void receive(const QByteArray &bytes);

    /**
     * @brief error Log an error.
     * @param s The error text.
     */
    virtual void error(const QString &s);

  private:
    void run() override;

    QMutex writeBufferMutex;
    QByteArray writeBuffer;
    QAtomicInt writePending {0};
    QString portName;
    QMutex mutex;
    QAtomicInt openAttemptsPending{0};
    QAtomicInt quitPending{0};
    std::function<void(const QByteArray& bytes)> receiveBytes=nullptr;
};

#endif // TRIXTERXDREAMSERIAL_H