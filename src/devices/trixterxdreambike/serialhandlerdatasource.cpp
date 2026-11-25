#include "serialhandlerdatasource.h"
#include "devices/csafe/serialport.h"

#include <QDebug>
#include <QSerialPort>
#include <QSerialPortInfo>
#include <stdexcept>

QStringList serialhandlerdatasource::get_availablePorts() {
    QStringList result;

    auto ports = QSerialPortInfo::availablePorts();
    for(const auto &port : ports) {
        QString portName = port.portName();

#if defined(Q_OS_LINUX)
        if(!portName.startsWith("ttyUSB"))
        {
            qDebug() << "Skipping port: " << portName << " because it doesn't start with ttyUSB";
            continue;
        }
#endif
        result.push_back(portName);
        qDebug() << "Found portName:" << portName
                 << "," << "description:" << port.description()
                 << "," << "vender identifier:" << port.vendorIdentifier()
                 << "," << "manufacturer:" << port.manufacturer()
                 << "," << "product identifier:" << port.productIdentifier()
                 << "," << "system location:" << port.systemLocation()
                 << "," << "isBusy:" << port.isBusy()
                 << "," << "isNull:" << port.isNull()
                 << "," << "serialNumber:" << port.serialNumber();
    }
    return result;
}

serialhandlerdatasource::serialhandlerdatasource() : serialdatasource()
{
    this->serial = nullptr;
}

bool serialhandlerdatasource::open(const QString& portName) {

    if(this->serial) delete this->serial;

    this->serial = new Serialport(portName, 115200);

    //this->serial->setDataBits(QSerialPort::Data8);
    //this->serial->setStopBits(QSerialPort::OneStop);
    //this->serial->setFlowControl(QSerialPort::NoFlowControl);
    //this->serial->setParity(QSerialPort::NoParity);
    //this->serial->setReadBufferSize(4096);

    this->serial->openPort();

    return true;
}

qint64 serialhandlerdatasource::write(const QByteArray &data) {
    uint8_t * rawData = (uint8_t *)data.constData();
    return this->serial->rawWrite(rawData, data.length());
}

void serialhandlerdatasource::flush() {

}

bool serialhandlerdatasource::waitForReadyRead() {
    return this->serial->dataAvailable();
}

QByteArray serialhandlerdatasource::readAll() {
    if(this->serial==nullptr)   throw std::runtime_error("Attempted to read from closed port.");

    QByteArray result;

    while(this->serial->dataAvailable()) {
        int bytesRead = this->serial->rawRead(this->readBuffer, 4096, false);
        result.append((char *)this->readBuffer, bytesRead);
    }

    return result;
}

qint64 serialhandlerdatasource::readBufferSize() {
    return 0;
}

QString serialhandlerdatasource::error() {
    return "UNKOWN";
}

void serialhandlerdatasource::close() {
    if(this->serial==nullptr)
        return;
    auto port = this->serial;
    this->serial = nullptr;

    delete port;
}

serialhandlerdatasource::~serialhandlerdatasource() {
    serialhandlerdatasource::close();
}

