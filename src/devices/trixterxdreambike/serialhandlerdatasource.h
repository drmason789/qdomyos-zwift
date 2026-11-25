#pragma once
#include "serialdatasource.h"
#include <QObject>

/**
 * @brief An implementation of serialdatasource that uses the serialporthander from the CSAFE bike driver.
 */
class serialhandlerdatasource : public serialdatasource {
  private:
    class Serialport * serial;
    uint8_t readBuffer[4096];
  public:
    explicit serialhandlerdatasource();

    QStringList get_availablePorts() override;

    bool open(const QString& portName) override;
    qint64 write(const QByteArray& data) override;
    void flush() override;
    bool waitForReadyRead() override;
    QByteArray readAll() override;
    qint64 readBufferSize() override;
    QString error() override;
    void close() override;

    ~serialhandlerdatasource() override;
};



